//#include<glad/glad.h>
//#include<GLFW/glfw3.h>
//
//#include<iostream>
//
//void framebuffer_size_callback(GLFWwindow* window, int height, int width);
//void processInput(GLFWwindow* window);
//
//int main() {
//	glfwInit();//initialize glfw
//	//set major and minor versions so that glfw will know what versions it can work with
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	//don't load legacy functions
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	//create the glfw window
//	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
//	if (window == NULL) {
//		std::cout << "Faild to create the window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//
//	//make the window the main object on the thread
//	glfwMakeContextCurrent(window);
//
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//		std::cout << "Faild to initialize GLAD" << std::endl;
//	}
//	glViewport(0, 0, 800, 600);
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//	//loop to make sure the window hasn't been closed (called render loop)
//	while (!glfwWindowShouldClose(window)) {
//		//handles color buffers
//		processInput(window);
//		//sets rgb color and alpha for window when clearing
//		glClearColor(0.7f, 0.8f, 0.6f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//		glfwSwapBuffers(window);
//		//checks and handles any events that are triggered
//		glfwPollEvents();
//	}
//	//properly clean all resources that were allocated
//	glfwTerminate();
//	return 0;
//}
//
////changes the viewport of the window if the window is resized
//void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
//	glViewport(0, 0, width, height);
//}
//
//void processInput(GLFWwindow* window) {
//	//check to see if esc key pressed
//	//if it is close the window
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
//		glfwSetWindowShouldClose(window, true);
//	}
//}