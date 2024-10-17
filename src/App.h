#pragma once
#include <GLFW/glfw3.h>
#include "Window.h"
#include "Renderer.h"

#include <iostream>

class App {
public:
	App();
	~App();

	void Run();

private:
	Window* mWindow;
	Renderer* mRenderer;

	void ProcessInput();
	void Update();
	void Render();
};