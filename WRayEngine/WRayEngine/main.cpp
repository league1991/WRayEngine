#include <iostream>
#include <cstdlib>
#include <vulkan/vulkan.h>
#include <vector>
#include <assert.h>
//#include <util_init.hpp>

#define APP_SHORT_NAME "vulkansamples_instance"
#define U_ASSERT_ONLY

int main(int argc, char* argv[]) {
    //struct sample_info info = {};
    //init_global_layer_properties(info);

    /* VULKAN_KEY_START */

    // initialize the VkApplicationInfo structure
    VkApplicationInfo app_info = {};
    app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    app_info.pNext = NULL;
    app_info.pApplicationName = APP_SHORT_NAME;
    app_info.applicationVersion = 1;
    app_info.pEngineName = APP_SHORT_NAME;
    app_info.engineVersion = 1;
    app_info.apiVersion = VK_API_VERSION_1_0;

    // initialize the VkInstanceCreateInfo structure
    VkInstanceCreateInfo inst_info = {};
    inst_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    inst_info.pNext = NULL;
    inst_info.flags = 0;
    inst_info.pApplicationInfo = &app_info;
    inst_info.enabledExtensionCount = 0;
    inst_info.ppEnabledExtensionNames = NULL;
    inst_info.enabledLayerCount = 0;
    inst_info.ppEnabledLayerNames = NULL;

    VkInstance inst;
    VkResult res;

    res = vkCreateInstance(&inst_info, NULL, &inst);
    if (res == VK_ERROR_INCOMPATIBLE_DRIVER) {
        std::cout << "cannot find a compatible Vulkan ICD\n";
        exit(-1);
    }
    else if (res) {
        std::cout << "unknown error\n";
        exit(-1);
    }

    uint32_t gpu_count = 1;
    res = vkEnumeratePhysicalDevices(inst, &gpu_count, NULL);
    std::vector<VkPhysicalDevice> gpus(gpu_count);
    res = vkEnumeratePhysicalDevices(inst, &gpu_count, &gpus[0]);

    VkDeviceQueueCreateInfo queue_info = {};
    uint32_t queue_family_count;
    vkGetPhysicalDeviceQueueFamilyProperties(gpus[0], &queue_family_count, NULL);
    assert(queue_family_count >= 1);

    std::vector<VkQueueFamilyProperties> queue_props;
    queue_props.resize(queue_family_count);
    vkGetPhysicalDeviceQueueFamilyProperties(gpus[0], &queue_family_count, queue_props.data());
    assert(queue_family_count >= 1);

    bool U_ASSERT_ONLY found = false;
    for (unsigned int i = 0; i < queue_family_count; i++) {
        if (queue_props[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) {
            queue_info.queueFamilyIndex = i;
            found = true;
            break;
        }
    }
    assert(found);
    assert(queue_family_count >= 1);

    float queue_priorities[1] = { 0.0 };
    queue_info.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
    queue_info.pNext = NULL;
    queue_info.queueCount = 1;
    queue_info.pQueuePriorities = queue_priorities;

    VkDeviceCreateInfo device_info = {};
    device_info.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    device_info.pNext = NULL;
    device_info.queueCreateInfoCount = 1;
    device_info.pQueueCreateInfos = &queue_info;
    device_info.enabledExtensionCount = 0;
    device_info.ppEnabledExtensionNames = NULL;
    device_info.enabledLayerCount = 0;
    device_info.ppEnabledLayerNames = NULL;
    device_info.pEnabledFeatures = NULL;

    VkDevice device;
    res = vkCreateDevice(gpus[0], &device_info, NULL, &device);
    assert(res == VK_SUCCESS);

    /* Create a command pool to allocate our command buffer from */
    VkCommandPoolCreateInfo cmd_pool_info = {};
    cmd_pool_info.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
    cmd_pool_info.pNext = NULL;
    cmd_pool_info.queueFamilyIndex = queue_info.queueFamilyIndex;
    cmd_pool_info.flags = 0;

    VkCommandPool cmd_pool;
    res = vkCreateCommandPool(device, &cmd_pool_info, NULL, &cmd_pool);
    assert(res == VK_SUCCESS);

    /* Create the command buffer from the command pool */
    VkCommandBufferAllocateInfo cmd = {};
    cmd.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    cmd.pNext = NULL;
    cmd.commandPool = cmd_pool;
    cmd.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    cmd.commandBufferCount = 1;

    VkCommandBuffer cmdBuffer;
    res = vkAllocateCommandBuffers(device, &cmd, &cmdBuffer);
    assert(res == VK_SUCCESS);

    /* VULKAN_KEY_END */

    VkCommandBuffer cmd_bufs[1] = { cmdBuffer };
    vkFreeCommandBuffers(device, cmd_pool, 1, cmd_bufs);
    vkDestroyCommandPool(device, cmd_pool, NULL);

    vkDestroyDevice(device, NULL);

    vkDestroyInstance(inst, NULL);

    /* VULKAN_KEY_END */

    return 0;
}
