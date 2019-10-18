#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/hash.hpp>
#include <iostream>
#include <stdexcept>
#include <functional>
#include <cstdlib>
#include <algorithm>
#include <unordered_map>
#include <optional>
#include <vector>
#include "../main.h"

struct QueueFamilyIndices {
	std::optional<uint32_t> graphicsFamily;
	std::optional<uint32_t> presentFamily;

	bool isComplete() {
		return graphicsFamily.has_value() && presentFamily.has_value();
	}
};

struct SwapChainSupportDetails {
	VkSurfaceCapabilitiesKHR capabilities;
	std::vector<VkSurfaceFormatKHR> formats;
	std::vector<VkPresentModeKHR> presentModes;
};

class VEVulkanRender {
public:
	void init(GLFWwindow* inputWindow);
	void drawFrame();
	static void setFramebufferResized();
	void cleanup();

	static void debugHaltClose();
};

struct UniformBufferObject {
	glm::mat4 model[gameObjects];
	glm::mat4 view;
	glm::mat4 proj;
};

void createInstance();
void setupDebugCallback();
void createSurface();
void pickPhysicalDevice();
void createLogicalDevice();
void createSwapChain();
void createImageViews();
void createRenderPass();
void createDescriptorSetLayout();
void createGraphicsPipeline();
void createCommandPool();
void createColorResources();
void createDepthResources();
void createFrameBuffers();
void createTextureImage(bool original);
void createTextureImageView(bool original);
void createTextureSampler();
void loadModel(bool original);
void createVertexBuffer();
void createIndexBuffer();
void createUniformBuffer();
void createDescriptorPool();
void createDescriptorSets();
void createCommandBuffers();
void createSyncObjects();
void cleanupSwapChain();

bool checkValidationLayerSupport();
std::vector<const char*> getRequiredExtensions();
int isDeviceSuitable(VkPhysicalDevice device);
VkSampleCountFlagBits getMaxUsableSampleCount();
QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
bool checkDeviceExtensionSupport(VkPhysicalDevice device);
SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
VkImageView createImageView(VkImage image, VkFormat format, VkImageAspectFlags aspectFlags, uint32_t mipLevels);
static std::vector<char> readFile(const std::string& filename);
VkShaderModule createShaderModule(const std::vector<char>& code);
VkFormat findDepthFormat();
void createBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory& bufferMemory);
void createImage(uint32_t width, uint32_t height, uint32_t mipLevels, VkSampleCountFlagBits numSamples, VkFormat format, VkImageTiling tiling, VkImageUsageFlags usage, VkMemoryPropertyFlags properties, VkImage& image, VkDeviceMemory& imageMemory);
void transitionImageLayout(VkImage image, VkFormat format, VkImageLayout oldLayout, VkImageLayout newLayout, uint32_t mipLevels);
void copyBufferToImage(VkBuffer buffer, VkImage image, uint32_t width, uint32_t height);
void generateMipmaps(VkImage image, VkFormat imageFormat, int32_t texWidth, int32_t texHeight, uint32_t mipLevels);
uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);
VkCommandBuffer beginSingleTimeCommands();
void endSingleTimeCommands(VkCommandBuffer commandBuffer);
void copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);
void updateUniformBuffer(uint32_t currentImage);