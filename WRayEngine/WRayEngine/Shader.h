#pragma once
#include <string>
#include <fstream>

class Shader
{
public:
    enum class Type
    {
        SHADER_VERTEX,
        SHADER_FRAGMENT
    };
    Shader();
    ~Shader();

    void init(VkDevice device, Type type, const std::string & fileName, const std::string& entryName);
    void destroy(VkDevice device)
    {
        vkDestroyShaderModule(device, shaderStage.module, NULL);
    }

    std::string m_fileName;
    std::string m_entryName;
    VkPipelineShaderStageCreateInfo shaderStage;
};

