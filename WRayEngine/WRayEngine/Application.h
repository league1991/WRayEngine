#pragma once
#include <iostream>
#include <cstdlib>
#include <vulkan/vulkan.h>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <assert.h>

#include <WinUser.h>
#include <wingdi.h>
#include <windowsx.h>

#define GLM_FORCE_RADIANS
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "glslang/SPIRV/GlslangToSpv.h"

#include "Buffer.h"
#include "Shader.h"
#include "Mesh.h"

/* Number of descriptor sets needs to be the same at alloc,       */
/* pipeline layout creation, and descriptor set layout creation   */
#define NUM_DESCRIPTOR_SETS 1

/* Number of samples needs to be the same at image creation,      */
/* renderpass creation and pipeline creation.                     */
#define NUM_SAMPLES VK_SAMPLE_COUNT_1_BIT

/* Number of viewports and number of scissors have to be the same */
/* at pipeline creation and in any call to set them dynamically   */
/* They also have to be the same as each other                    */
#define NUM_VIEWPORTS 1
#define NUM_SCISSORS NUM_VIEWPORTS

#define APP_SHORT_NAME "WRayEngine"
#define U_ASSERT_ONLY


/* Amount of time, in nanoseconds, to wait for a command buffer to complete */
#define FENCE_TIMEOUT 100000000*100

#define VK_CHECK(x)                                                 \
	do                                                              \
	{                                                               \
		VkResult err = x;                                           \
		if (err)                                                    \
		{                                                           \
			printf("Detected Vulkan error: {%d}", (err)); \
			abort();                                                \
		}                                                           \
	} while (0)

/*
 * structure to track all objects related to a texture.
 */
struct texture_object {
    VkSampler sampler;

    VkImage image;
    VkImageLayout imageLayout;

    bool needs_staging;
    VkBuffer buffer;
    VkDeviceSize buffer_size;

    VkDeviceMemory image_memory;
    VkDeviceMemory buffer_memory;
    VkImageView view;
    int32_t tex_width, tex_height;
};

/*
 * Keep each of our swap chain buffers' image, command buffer and view in one
 * spot
 */
typedef struct _swap_chain_buffers {
    VkImage image;
    VkImageView view;
} swap_chain_buffer;

/*
 * A layer can expose extensions, keep track of those
 * extensions here.
 */
typedef struct {
    VkLayerProperties properties;
    std::vector<VkExtensionProperties> instance_extensions;
    std::vector<VkExtensionProperties> device_extensions;
} layer_properties;


struct PerFrame
{
    VkFence queue_submit_fence = VK_NULL_HANDLE;
    VkCommandPool primary_command_pool = VK_NULL_HANDLE;
    VkCommandBuffer primary_command_buffer = VK_NULL_HANDLE;
    VkSemaphore swapchain_acquire_semaphore = VK_NULL_HANDLE;
    VkSemaphore swapchain_release_semaphore = VK_NULL_HANDLE;
};

/*
 * Structure for tracking information used / created / modified
 * by utility functions.
 */
struct sample_info {
#ifdef _WIN32
#define APP_NAME_STR_LEN 80
    HINSTANCE connection;        // hInstance - Windows Instance
    TCHAR name[APP_NAME_STR_LEN]; // Name to put on the window/icon
    HWND window;                 // hWnd - window handle
#elif defined(VK_USE_PLATFORM_METAL_EXT)
    void* caMetalLayer;
#elif defined(__ANDROID__)
    PFN_vkCreateAndroidSurfaceKHR fpCreateAndroidSurfaceKHR;
#elif defined(VK_USE_PLATFORM_WAYLAND_KHR)
    wl_display* display;
    wl_registry* registry;
    wl_compositor* compositor;
    wl_surface* window;
    wl_shell* shell;
    wl_shell_surface* shell_surface;
#else
    xcb_connection_t* connection;
    xcb_screen_t* screen;
    xcb_window_t window;
    xcb_intern_atom_reply_t* atom_wm_delete_window;
#endif // _WIN32
    VkSurfaceKHR surface;
    bool prepared;
    bool use_staging_buffer;
    bool save_images;

    std::vector<const char*> instance_layer_names;
    std::vector<const char*> instance_extension_names;
    std::vector<layer_properties> instance_layer_properties;
    std::vector<VkExtensionProperties> instance_extension_properties;
    VkInstance inst;

    std::vector<const char*> device_extension_names;
    std::vector<VkExtensionProperties> device_extension_properties;
    std::vector<VkPhysicalDevice> gpus;
    VkDevice device;
    VkQueue graphics_queue;
    VkQueue present_queue;
    uint32_t graphics_queue_family_index;
    uint32_t present_queue_family_index;
    VkPhysicalDeviceProperties gpu_props;
    std::vector<VkQueueFamilyProperties> queue_props;
    VkPhysicalDeviceMemoryProperties memory_properties;

    VkFramebuffer* framebuffers;
    int width, height;
    VkFormat format;

    uint32_t swapchainImageCount;
    VkSwapchainKHR swap_chain;
    std::vector<swap_chain_buffer> buffers;
    VkSemaphore imageAcquiredSemaphore;

    //VkCommandPool cmd_pool;

    struct {
        VkFormat format;

        VkImage image;
        VkDeviceMemory mem;
        VkImageView view;
    } depth;

    std::vector<struct texture_object> textures;

    struct {
        VkBuffer buf;
        VkDeviceMemory mem;
        VkDescriptorBufferInfo buffer_info;
    } uniform_data;

    struct {
        VkDescriptorImageInfo image_info;
    } texture_data;

    //struct {
    //    VkBuffer buf;
    //    VkDeviceMemory mem;
    //    VkDescriptorBufferInfo buffer_info;
    //} vertex_buffer;
    VkVertexInputBindingDescription vi_binding;
    VkVertexInputAttributeDescription vi_attribs[2];

    glm::mat4 Projection;
    glm::mat4 View;
    glm::mat4 Model;
    glm::mat4 Clip;
    glm::mat4 MVP;

    //VkCommandBuffer cmd; // Buffer for initialization commands
    VkPipelineLayout pipeline_layout;
    std::vector<VkDescriptorSetLayout> desc_layout;
    VkPipelineCache pipelineCache;
    VkRenderPass render_pass;
    VkPipeline pipeline;

    VkPipelineShaderStageCreateInfo shaderStages[2];

    VkDescriptorPool desc_pool;
    std::vector<VkDescriptorSet> desc_set;

    PFN_vkCreateDebugReportCallbackEXT dbgCreateDebugReportCallback;
    PFN_vkDestroyDebugReportCallbackEXT dbgDestroyDebugReportCallback;
    PFN_vkDebugReportMessageEXT dbgBreakCallback;
    std::vector<VkDebugReportCallbackEXT> debug_report_callbacks;

    std::vector<PerFrame> per_frame;
    uint32_t current_buffer;
    uint32_t queue_family_count;

    VkViewport viewport;
    VkRect2D scissor;
};

VkResult init_global_extension_properties(layer_properties& layer_props);

VkResult init_global_layer_properties(sample_info& info);

VkResult init_device_extension_properties(struct sample_info& info,
    layer_properties& layer_props);

void init_instance_extension_names(struct sample_info& info);
VkResult init_instance(struct sample_info& info,
    char const* const app_short_name);
void init_device_extension_names(struct sample_info& info);
VkResult init_device(struct sample_info& info);
VkResult init_enumerate_device(struct sample_info& info,
    uint32_t gpu_count = 1);
VkBool32 demo_check_layers(const std::vector<layer_properties>& layer_props,
    const std::vector<const char*>& layer_names);
void init_connection(struct sample_info& info);
void init_window(struct sample_info& info, WNDPROC WndProc);
void init_queue_family_index(struct sample_info& info);
void init_presentable_image(struct sample_info& info);
void execute_queue_cmdbuf(struct sample_info& info,
    const VkCommandBuffer* cmd_bufs, VkFence& fence);
void execute_pre_present_barrier(struct sample_info& info);
void execute_present_image(struct sample_info& info);
void init_swapchain_extension(struct sample_info& info);
void init_command_pool(struct sample_info& info);
void init_command_buffer(struct sample_info& info);
void execute_begin_command_buffer(struct sample_info& info);
void execute_end_command_buffer(struct sample_info& info);
void execute_queue_command_buffer(struct sample_info& info);
void init_device_queue(struct sample_info& info);
void init_swap_chain(
    struct sample_info& info,
    VkImageUsageFlags usageFlags = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT |
    VK_IMAGE_USAGE_TRANSFER_SRC_BIT);
void init_depth_buffer(struct sample_info& info);
void init_uniform_buffer(struct sample_info& info);
void init_descriptor_and_pipeline_layouts(struct sample_info& info, bool use_texture,
    VkDescriptorSetLayoutCreateFlags descSetLayoutCreateFlags = 0);
void init_renderpass(struct sample_info& info, bool include_depth, bool clear = true,
    VkImageLayout finalLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,
    VkImageLayout initialLayout = VK_IMAGE_LAYOUT_UNDEFINED);
void init_vertex_buffer(struct sample_info& info, const void* vertexData,
    uint32_t dataSize, uint32_t dataStride,
    bool use_texture);
void init_framebuffers(struct sample_info& info, bool include_depth);
void init_descriptor_pool(struct sample_info& info, bool use_texture);
void init_descriptor_set(struct sample_info& info, bool use_texture);
void init_shaders(struct sample_info& info, const VkShaderModuleCreateInfo* vertShaderCI,
    const VkShaderModuleCreateInfo* fragShaderCI);
void init_shaders(struct sample_info &info, const char *vertShaderText, const char *fragShaderText);
void init_pipeline_cache(struct sample_info& info);
void init_pipeline(struct sample_info& info, VkBool32 include_depth,
    VkBool32 include_vi = true);
void init_sampler(struct sample_info& info, VkSampler& sampler);
void init_image(struct sample_info& info, texture_object& texObj,
    const char* textureName, VkImageUsageFlags extraUsages = 0,
    VkFormatFeatureFlags extraFeatures = 0);
void init_texture(struct sample_info& info, const char* textureName = nullptr,
    VkImageUsageFlags extraUsages = 0,
    VkFormatFeatureFlags extraFeatures = 0);
void init_viewports(struct sample_info& info);
void init_scissors(struct sample_info& info);
void init_fence(struct sample_info& info, VkFence& fence);
void init_submit_info(struct sample_info& info, VkSubmitInfo& submit_info,
    VkPipelineStageFlags& pipe_stage_flags);
void init_present_info(struct sample_info& info, VkPresentInfoKHR& present);
void init_clear_color_and_depth(struct sample_info& info,
    VkClearValue* clear_values);
void init_render_pass_begin_info(struct sample_info& info,
    VkRenderPassBeginInfo& rp_begin);
void init_window_size(struct sample_info& info, int32_t default_width,
    int32_t default_height);

VkResult init_debug_report_callback(struct sample_info& info,
    PFN_vkDebugReportCallbackEXT dbgFunc);


void init_per_frame(struct sample_info& info, PerFrame& per_frame);


void destroy_debug_report_callback(struct sample_info& info);
void destroy_pipeline(struct sample_info& info);
void destroy_pipeline_cache(struct sample_info& info);
void destroy_descriptor_pool(struct sample_info& info);
void destroy_vertex_buffer(struct sample_info& info);
void destroy_textures(struct sample_info& info);
void destroy_framebuffers(struct sample_info& info);
void destroy_shaders(struct sample_info& info);
void destroy_renderpass(struct sample_info& info);
void destroy_descriptor_and_pipeline_layouts(struct sample_info& info);
void destroy_uniform_buffer(struct sample_info& info);
void destroy_depth_buffer(struct sample_info& info);
void destroy_swap_chain(struct sample_info& info);
void destroy_command_buffer(struct sample_info& info);
void destroy_command_pool(struct sample_info& info);
void destroy_device(struct sample_info& info);
void destroy_instance(struct sample_info& info);
void destroy_window(struct sample_info& info);

bool memory_type_from_properties(struct VkPhysicalDeviceMemoryProperties& memory_properties, uint32_t typeBits, VkFlags requirements_mask, uint32_t* typeIndex);
bool GLSLtoSPV(const VkShaderStageFlagBits shader_type, const char *pshader, std::vector<unsigned int> &spirv);

class Application
{
public:
    void initialize();

    bool shouldExit() { return false; }

    void update();

    void destroy();

    static Application* instance();

    void onMouseMove(int x, int y);
    void onMouseWheel(float delta)
    {
        m_cameraDist += delta * 0.1f;
    }
    void onMouseButton(UINT button);
    void onKeyDown(UINT wParam, UINT lParam) {}
    void onKeyUp(UINT wParam, UINT lParam) {}
private:
    Application() {}
    ~Application();

    void acquireSemaphore();
    void render();
    void present();

    void updateCPUData();
    void updateTexture();

    static Application* s_instance;

    glm::ivec2 m_lastMousePos{ 0,0 };
    bool m_isLeftButton = false;
    bool m_isMiddleButton = false;
    bool m_isRightButton = false;

    glm::vec2 m_cameraAngle;
    float m_cameraDist = 10.f;
    glm::mat4x4 m_modelMatrix;

    Buffer vertexBuffer;
    Mesh m_mesh;
    Shader vertexShader, fragmentShader;
    std::vector<VkSemaphore> recycled_semaphores;
    VkFence drawFence = {};
    sample_info info;
};

