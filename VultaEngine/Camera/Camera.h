#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include "../VulkanRenderer/VulkanRender.h"

class VECamera {
public:
	static void updateCamera(float swapchainWidth, float swapchainHeight, UniformBufferObject *ubo);
	static void processInput(GLFWwindow *window);
	static void mouse_callback(GLFWwindow* window, double xpos, double ypos);
	static void setDeltaTime(float deltaTime);
	static int getUBOSize();
};
