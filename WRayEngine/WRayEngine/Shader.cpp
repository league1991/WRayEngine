#include <vulkan/vulkan.h>

#include "Application.h"
#include "Shader.h"



Shader::Shader()
{
}


Shader::~Shader()
{
}

void Shader::init(VkDevice device, Type type, const std::string & fileName, const std::string& entryName)
{
    std::ifstream file(fileName);
    if (!file)
    {
        return;
    }

    m_fileName = fileName;
    m_entryName = entryName;
    //std::string code;
    //file >> code;
    std::string code((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    //void init_shaders(struct sample_info &info, const char *vertShaderText, const char *fragShaderText) {
    VkResult res;
    bool retVal;

    //init_glslang();
    glslang::InitializeProcess();
    VkShaderModuleCreateInfo moduleCreateInfo;

    VkShaderStageFlagBits stage;
    switch (type)
    {
    case Shader::Type::SHADER_VERTEX:
        stage = VK_SHADER_STAGE_VERTEX_BIT;
        break;
    case Shader::Type::SHADER_FRAGMENT:
        stage = VK_SHADER_STAGE_FRAGMENT_BIT;
        break;
    default:
        break;
    }
    //if (vertShaderText) {
        std::vector<unsigned int> vtx_spv;
        shaderStage.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
        shaderStage.pNext = NULL;
        shaderStage.pSpecializationInfo = NULL;
        shaderStage.flags = 0;
        shaderStage.stage = stage;
        shaderStage.pName = m_entryName.data();

        retVal = GLSLtoSPV(stage, code.data(), vtx_spv);
        assert(retVal);

        moduleCreateInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
        moduleCreateInfo.pNext = NULL;
        moduleCreateInfo.flags = 0;
        moduleCreateInfo.codeSize = vtx_spv.size() * sizeof(unsigned int);
        moduleCreateInfo.pCode = vtx_spv.data();
        res = vkCreateShaderModule(device, &moduleCreateInfo, NULL, &shaderStage.module);
        assert(res == VK_SUCCESS);
    //}

    //if (fragShaderText) {
    //    std::vector<unsigned int> frag_spv;
    //    info.shaderStages[1].sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
    //    info.shaderStages[1].pNext = NULL;
    //    info.shaderStages[1].pSpecializationInfo = NULL;
    //    info.shaderStages[1].flags = 0;
    //    info.shaderStages[1].stage = VK_SHADER_STAGE_FRAGMENT_BIT;
    //    info.shaderStages[1].pName = "main";

    //    retVal = GLSLtoSPV(VK_SHADER_STAGE_FRAGMENT_BIT, fragShaderText, frag_spv);
    //    assert(retVal);

    //    moduleCreateInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
    //    moduleCreateInfo.pNext = NULL;
    //    moduleCreateInfo.flags = 0;
    //    moduleCreateInfo.codeSize = frag_spv.size() * sizeof(unsigned int);
    //    moduleCreateInfo.pCode = frag_spv.data();
    //    res = vkCreateShaderModule(info.device, &moduleCreateInfo, NULL, &info.shaderStages[1].module);
    //    assert(res == VK_SUCCESS);
    //}

    glslang::FinalizeProcess();
    //}
}
