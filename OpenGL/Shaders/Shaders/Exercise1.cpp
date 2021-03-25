//#include<glad\glad.h>
//#include<GLFW\glfw3.h>
//#include<iostream>
//using namespace std;
//
//void framebuffer_size_callback(GLFWwindow* window, int height, int width);
//void processInput(GLFWwindow* window);
//
//
//const char* vertexShaderProgram = "#version 440 core\n"
//"layout(location = 0) in vec3 apos;\n"
//"layout(location = 1) in vec4 aColor;\n"
//"out vec4 myColor;\n"
//"void main(){\n"
//"gl_Position = vec4(apos.x, -apos.y, apos.z, 1.0f);\n"
//"myColor = aColor;\n"
//"}\0";
//
//const char* fragmentShaderProgram = "#version 440 core\n"
//"out vec4 fragColor;\n"
//"in vec4 myColor;\n"
//"void main(){\n"
//"fragColor = myColor;\n"
//"}\n\0";
//
//int main() {
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow* window = glfwCreateWindow(800, 800, "Exercise 1", NULL, NULL);
//	if (window == NULL) {
//		cout << "Failed to create window" << endl;
//		char c;
//		cin >> c;
//		return -1;
//	}
//
//	glfwMakeContextCurrent(window);
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//		std::cout << "Faild to initialize GLAD" << std::endl;
//		char c;
//		cin >> c;
//	}
//	glViewport(0, 0, 800, 600);
//
//	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
//	glShaderSource(vertexShader, 1, &vertexShaderProgram, NULL);
//	glCompileShader(vertexShader);
//
//	int success;
//	char infoLog[512];
//	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//	if (!success) {
//		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//		char c;
//		cin >> c;
//	}
//
//	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fragmentShader, 1, &fragmentShaderProgram, NULL);
//	glCompileShader(fragmentShader);
//
//	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
//	if (!success) {
//		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
//		std::cout << "Error: frament shader compilation failed\n" << infoLog << std::endl;
//		char c;
//		cin >> c;
//
//	}
//
//	unsigned int shaderProgram = glCreateProgram();
//	glAttachShader(shaderProgram, vertexShader);
//	glAttachShader(shaderProgram, fragmentShader);
//	glLinkProgram(shaderProgram);
//
//	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//	if (!success)
//	{
//		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
//		std::cout << "Error: shader linking failed\n" << infoLog << std::endl;
//		char c;
//		cin >> c;
//	}
//
//	glDeleteShader(vertexShader);
//	glDeleteShader(fragmentShader);
//
//	float verticies[] = {
//		-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
//		0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
//		0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f
//	};
//	unsigned int vbo, vao;
//	glGenVertexArrays(1, &vao);
//	glGenBuffers(1, &vbo);
//
//	glBindVertexArray(vao);
//	
//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
//
//
//	glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//	
//
//	glUseProgram(shaderProgram);
//	while (!glfwWindowShouldClose(window)) {
//		
//		processInput(window);
//
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//		glBindVertexArray(vao);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//		glfwSwapBuffers(window);
//		//checks and handles any events that are triggered
//		glfwPollEvents();
//
//	}
//	char c;
//	cin >> c;
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