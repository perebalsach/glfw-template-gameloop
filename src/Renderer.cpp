#include "Renderer.h"
#include <GLFW/glfw3.h>

Renderer::Renderer() {

}

Renderer::~Renderer() {

}

void Renderer::Clear() {
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}
