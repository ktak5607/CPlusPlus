#include <glad\glad.h>
#include <GLFW\glfw3.h>
#include <iostream>

using namespace std;

void frameSizeBufferCallback(GLFWwindow* window, int height, int width);
void processInput(GLFWwindow* window);

int main() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(1300, 900, "Kevin's Experiment Window", NULL, NULL);

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Faild to initialize GLAD" << std::endl;
	}

	glViewport(0, 0, 1300, 900);
	glfwSetFramebufferSizeCallback(window, frameSizeBufferCallback);

	while (!glfwWindowShouldClose(window)) {
		processInput(window);
		glClearColor(0.4f, 0.7f, 0.1f, 0.8f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		//checks and handles any events that are triggered
		glfwPollEvents();
	}
	//properly clean all resources that were allocated
	glfwTerminate();
	return 0;
}

//changes the viewport of the window if the window is resized
void frameSizeBufferCallback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
	//check to see if esc key pressed
	//if it is close the window
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}


