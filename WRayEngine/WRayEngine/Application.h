#pragma once
#include <iostream>
#include <cstdlib>
#include <vulkan/vulkan.h>
#include <vector>
#include <assert.h>

#include <WinUser.h>
#include <wingdi.h>

#define APP_SHORT_NAME "WRayEngine"
#define U_ASSERT_ONLY

class Application
{
public:
    Application() {}
    ~Application();

    bool initialize()
    {
        createInstance();
        createDevice();
        createCommandBuffer();
        createWindow(640, 480);
        return true;
    }

private:
    void destroy()
    {
        destroyCommandBuffer();
        destroyDevice();
        destroyInstance();
    }

    void createInstance();
    void createDevice();
    void createCommandBuffer();
    void createWindow(int width, int height);

    void destroyCommandBuffer();
    void destroyDevice();
    void destroyInstance();

    VkInstance inst;
    VkDeviceQueueCreateInfo queue_info;
    VkDevice device;
    VkCommandPool cmd_pool;
    VkCommandBuffer cmdBuffer;
    HWND window;
};

