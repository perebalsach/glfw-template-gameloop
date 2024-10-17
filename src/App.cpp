#include "App.h"

App::App() {
	if (!glfwInit()) {
		std::cerr << "Failed to initialize GLFW" << std::endl;
		std::exit(-1);
	}
	mWindow = new Window(800, 600, "OpenGL Window");
	mRenderer = new Renderer();


}

App::~App() {
	delete mRenderer;
	delete mWindow;
	glfwTerminate();
}

void App::Run() {
	while (!mWindow->ShouldClose()) {
		ProcessInput();
		Update();
		Render();
	}
}

void App::ProcessInput() {
	glfwPollEvents();
}

void App::Update() {

}

void App::Render() {
	mRenderer->Clear();
	mWindow->SwapBuffers();
}
