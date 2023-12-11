#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

using namespace std;

int main() {

	// Initialize GLFW
	glfwInit();	

	// Tell GLFW which version of opengl we are using.
	// In this case, we are using 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);	// Major version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);	// Minor version

	// Tell GLFW we are using the core profile	(there are two profiles: code (Only modern) and compatible(Both modern + old) )
	// So that means we only have the modern function
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Creating GLFWwindow object of 800 by 800 pixels and naming it "First Opengl Project"
	GLFWwindow* window = glfwCreateWindow(800, 800, "First Opengl Project", NULL, NULL);

	// Error check if the window fails to create
	if (window == NULL) {
		cout << "Failed to create GLFW window" << endl;
		glfwTerminate();
		return -1;
	}

	// Introducing the windows in the current context
	glfwMakeContextCurrent(window);	

	// Load GLAD so it configured OpenGL
	gladLoadGL();
	
	// Specity the viewport of the window
	// In this case the viewport goes from x = 0, y = 0 to x = 800, y = 800
	glViewport(0, 0, 800, 800);	

	// specify the color of the background
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);

	// Clean the back buffer and assigning the new color to it
	glClear(GL_COLOR_BUFFER_BIT);

	// Swap the back buffer with the front buffer
	glfwSwapBuffers(window);

	// Main while loop
	while (!glfwWindowShouldClose(window)) {
		// Take care of all GLFW events
		glfwPollEvents();
	}

	// Delete window before ending the progress
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();

	return 0;
}