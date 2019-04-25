#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

struct UniformBufferObject {
	glm::mat4 model[2];
	glm::mat4 view;
	glm::mat4 proj;
};

class VECamera {
public:
	static void updateCamera(float swapchainWidth, float swapchainHeight, UniformBufferObject *ubo);
	static void processInput(GLFWwindow *window);
	static void mouse_callback(GLFWwindow* window, double xpos, double ypos);
	static void setDeltaTime(float deltaTime);
	static int getUBOSize();
};
