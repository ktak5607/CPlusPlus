//#include<glad/glad.h>
//#include<GLFW\glfw3.h>
//#include<iostream>
//
//
//using namespace std;
//
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
//
//	const char *vertexShaderProgram = "#version 440 core\n"
//		"layout (location = 0) in vec3 aPos;\n"
//		"void main () {\n"
//		"gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0f);\n"
//		"}\0";
//
//	const char *fragmentShaderProgram = "#version 440 core\n"
//		"out vec4 fragColor;\n"
//		"void main(){\n"
//		"fragColor = vec4(0.3f, 1.0f, 0.1f, 1.0f);\n"
//		"}\n\0";
//
//	int main() {
//		glfwInit();
//		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
//		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
//		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//		GLFWwindow *window = glfwCreateWindow(800, 600, "Exercise2", NULL, NULL);
//		if (window == NULL) {
//			cout << "There was an error creating the window" << endl;
//			glfwTerminate();
//			char c;
//			cin >> c;
//			return -1;
//		}
//		glfwMakeContextCurrent(window);
//		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//			cout << "Failed to initialize GLAD" << endl;
//			char c;
//			cin >> c;
//			return -1;
//		}
//		//create vertex shader, set it's source, and compile it
//		int vertexShader = glCreateShader(GL_VERTEX_SHADER);
//		glShaderSource(vertexShader, 1, &vertexShaderProgram, NULL);
//		glCompileShader(vertexShader);
//
//		int success;
//		char infoLog[512];
//
//		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//		if (!success) {
//			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//			cout << "Failed to compile vertex shader\n" << infoLog << endl;
//		}
//
//		int fragShader = glCreateShader(GL_FRAGMENT_SHADER);
//		glShaderSource(fragShader, 1, &fragmentShaderProgram, NULL);
//		glCompileShader(fragShader);
//
//
//		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//		if (!success) {
//			glGetShaderInfoLog(fragShader, 512, NULL, infoLog);
//			cout << "Failed to compile fragment shader\n" << infoLog << endl;
//		}
//		int shaderProgram = glCreateProgram();
//		glAttachShader(shaderProgram, vertexShader);
//		glAttachShader(shaderProgram, fragShader);
//		glLinkProgram(shaderProgram);
//
//		glGetProgramiv(shaderProgram, GL_COMPILE_STATUS, &success);
//		if (!success) {
//			glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
//			cout << "Failed to compile shader program\n" << infoLog << endl;
//		}
//		glDeleteShader(vertexShader);
//		glDeleteShader(fragShader);
//
//		float verticies[] = {
//			-0.9f, -0.5f, 0.0f,
//			-0.45f, 0.5f, 0.0f,
//			0.0f, -0.5f, 0.0f,
//		};
//
//		float verticies2[] = {
//			0.0f, -0.5f, 0.0f,
//			0.45f, 0.5f, 0.0f,
//			0.9f, -0.5f, 0.0f
//		};
//		unsigned int VBO[2], VAO[2];
//		glGenVertexArrays(2, VAO);
//		glGenBuffers(2, VBO);
//
//		glBindVertexArray(VAO[0]);
//		glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
//		glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);
//		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//		glEnableVertexAttribArray(0);
//
//		glBindVertexArray(VAO[1]);
//		glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
//		glBufferData(GL_ARRAY_BUFFER, sizeof(verticies2), verticies2, GL_STATIC_DRAW);
//		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//		glEnableVertexAttribArray(0);
//		glBindVertexArray(0);
//
//			while (!glfwWindowShouldClose(window)) {
//				processInput(window);
//
//				glClearColor(0.2f, .3f, 0.3f, 1.0f);
//				glClear(GL_COLOR_BUFFER_BIT);
//
//				glUseProgram(shaderProgram);
//
//				glBindVertexArray(VAO[0]);
//				glDrawArrays(GL_TRIANGLES, 0, 3);
//				glBindVertexArray(VAO[1]);
//				glDrawArrays(GL_TRIANGLES, 0, 3);
//
//				glfwSwapBuffers(window);
//				glfwPollEvents();
//			}
//			glDeleteVertexArrays(2, VAO);
//			glDeleteBuffers(2, VBO);
//			glfwTerminate();
//			return 0;
//	}
