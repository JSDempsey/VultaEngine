#include "VulkanRenderer/VulkanRender.h"
#include "Camera/Camera.h"
#include "main.h"

float lastFrame = 0.0f;

class VultaEngine {
public:
	VEVulkanRender vulkanRenderer;
	void run() {
		initWindow();
		vulkanRenderer.init(window);
		mainLoop();
		vulkanRenderer.cleanup();
	}

private:
	GLFWwindow* window;

	void initWindow() {
		glfwInit();

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

		window = glfwCreateWindow(WIDTH, HEIGHT, "VultaEngine Test App", nullptr, nullptr);
		glfwSetWindowUserPointer(window, this);
		glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		glfwSetCursorPosCallback(window, VECamera::mouse_callback);
	}
	static void framebufferResizeCallback(GLFWwindow* window, int width, int height) {
		auto app = reinterpret_cast<VultaEngine*>(glfwGetWindowUserPointer(window));
		VEVulkanRender::setFramebufferResized();
	}

	void mainLoop() {
		while (!glfwWindowShouldClose(window)) {
			float currentFrame = (float)glfwGetTime();
			float deltaTime = currentFrame - lastFrame;
			lastFrame = currentFrame;

			VECamera::setDeltaTime(deltaTime);
			VECamera::processInput(window);
			glfwPollEvents();
			vulkanRenderer.drawFrame();
		}
	}
};

int main() {
	VultaEngine app;

	try {
		app.run();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		VEVulkanRender::debugHaltClose();
		return EXIT_FAILURE;
	}

	VEVulkanRender::debugHaltClose();
	return EXIT_SUCCESS;
}