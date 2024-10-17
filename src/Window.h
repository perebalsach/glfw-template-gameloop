#pragma once
#include <GLFW/glfw3.h>

class Window {
public:
	Window(int width, int height, const char* title);
	~Window();

	void SwapBuffers();
	bool ShouldClose();
	GLFWwindow* GetWindow() const;

private:
	GLFWwindow* mWindow;
};

