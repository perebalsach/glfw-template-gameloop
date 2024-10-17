#include <iostream>
#include "Window.h"

Window::Window(int width, int height, const char *title) {
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	mWindow = glfwCreateWindow(width, height, title, nullptr, nullptr);
	if (!mWindow)
	{
		std::cerr << "Failed to create GLFW window\n";
		glfwTerminate();
		std::exit(-1);
	}

	glfwMakeContextCurrent(mWindow);
	// Enable V-Sync
	glfwSwapInterval(1);
}

Window::~Window() {
	glfwDestroyWindow(mWindow);
}

void Window::SwapBuffers() {
	glfwSwapBuffers(mWindow);
}

bool Window::ShouldClose() {
	return glfwWindowShouldClose(mWindow);
}

GLFWwindow *Window::GetWindow() const {
	return mWindow;
}
