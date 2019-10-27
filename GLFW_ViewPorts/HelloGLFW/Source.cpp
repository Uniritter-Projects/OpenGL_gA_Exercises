//Mapeamento de teclas na GLFW: https://www.glfw.org/docs/latest/group__keys.html
#include <cstdlib>
#include <iostream>
#include "Shapes.h"
using namespace std;

Shape shape;

void ajustaCamera2D(int width, int height);

static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}

bool onMenu = true;
bool onEx1 = false;
bool onEx2 = false;
bool onEx3 = false;
bool onEx4 = false;

bool generate = true;
bool lineArt = true;
int sportCourtId = 1;
int imageId = 1;

static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	if ((button == GLFW_MOUSE_BUTTON_1 || button == GLFW_MOUSE_BUTTON_2) && action == GLFW_PRESS && onEx3 == true)
		generate = !generate;
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	//Navigation keys
	if ((key == GLFW_KEY_BACKSPACE || key == GLFW_KEY_0 || key == GLFW_KEY_KP_0)  && action == GLFW_PRESS)
	{
		onMenu = true;
		onEx1 = false;
		onEx2 = false;
		onEx3 = false;
		onEx4 = false;
	}
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}

	//Menu keys
	if ((key == GLFW_KEY_1 || key == GLFW_KEY_KP_1) && action == GLFW_PRESS)
	{
		onMenu = false;
		onEx1 = true;
		onEx2 = false;
		onEx3 = false;
		onEx4 = false;
	}
	if ((key == GLFW_KEY_2 || key == GLFW_KEY_KP_2) && action == GLFW_PRESS)
	{
		onMenu = false;
		onEx1 = false;
		onEx2 = true;
		onEx3 = false;
		onEx4 = false;
	}
	if ((key == GLFW_KEY_3 || key == GLFW_KEY_KP_3) && action == GLFW_PRESS)
	{
		onMenu = false;
		onEx1 = false;
		onEx2 = false;
		onEx3 = true;
		onEx4 = false;
	}
	if ((key == GLFW_KEY_4 || key == GLFW_KEY_KP_4) && action == GLFW_PRESS)
	{
		onMenu = false;
		onEx1 = false;
		onEx2 = false;
		onEx3 = false;
		onEx4 = true;
	}

	//Exercise keys
	if (key == GLFW_KEY_ENTER && action == GLFW_PRESS && onEx2)
	{
		if (sportCourtId < 3)
			sportCourtId++;
		else
			sportCourtId = 1;
	}
	if ((key == GLFW_KEY_Q || key == GLFW_KEY_T) && action == GLFW_PRESS && onEx3)
	{
		generate = !generate;
	}
	if (key == GLFW_KEY_ENTER && action == GLFW_PRESS && onEx4)
	{
		if (imageId < 2)
			imageId++;
		else
			imageId = 1;
	}
}

void reshape(GLFWwindow* window, int width, int height)
{
	if (height == 0)
		height = 1;

	ajustaCamera2D(width,height);
}

void ajustaCamera2D(int width, int height)
{
	//Ativa a matriz de projeção --> conceitos mais tarde!!
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (width < height) //altura menor que largura
	{
		float aspecto = (float)height / width; //proporcao altura/largura 
		gluOrtho2D(Xmin, Xmax, Ymin*aspecto, Ymax*aspecto); //corrige a proporção na largura
	}
	else {
		float aspecto = (float)width / height; //proporcao largura/altura
		gluOrtho2D(Xmin*aspecto, Xmax*aspecto, Ymin, Ymax); //corrige a proporção na altura
	}
}

void oneViewport(int w, int h, int layout)
{
	glViewport(0, 0, w, h);

	switch (layout)
	{
		case 0:
			shape.DrawTitle();
			shape.DrawHyperCube();
			shape.DrawNames();
			break;

		case 1:
			shape.DrawNumber(1);
			shape.DrawCampus();
			break;

		case 2:
			shape.DrawSportsCourt(sportCourtId);
			shape.DrawNumber(2);
			break;

		case 3:
			shape.DrawNumber(3);

			if(generate)
				shape.DrawRandomShapes();
			break;

		case 4:
			shape.DrawNumber(4);
			break;
	}
}

void twoViewports(int w, int h)
{
	shape.DrawNumber(4);

	lineArt = true;
	glViewport(0, 0, w / 2, h);
	glScalef(0.09, 0.06, 0);
	glTranslatef(-6, -5, 0);
	shape.DrawAnimal(lineArt, imageId);

	glViewport(w / 2, 0, w / 2, h);
	lineArt = false;
	shape.DrawAnimal(lineArt, imageId);
}

int main(void)
{
	srand(time(0));

	GLFWwindow* window;

	glfwSetErrorCallback(error_callback);

	if (!glfwInit())
		exit(EXIT_FAILURE);

	window = glfwCreateWindow(640, 480, "Exercises menu", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	glfwSetKeyCallback(window, key_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);

	glfwSetFramebufferSizeCallback(window, reshape);

	int width, height;
	float ratio;

	ajustaCamera2D(640, 480);

	while (!glfwWindowShouldClose(window))
	{	
		//aqui recupera o tamanho atual da janela
		glfwGetFramebufferSize(window, &width, &height);

		// Limpa a janela de visualização com a cor branca
		glClearColor(0, 0, 0, 0);
		glClear(GL_COLOR_BUFFER_BIT);

		//seta a matriz de modelo 
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		//Default view
		if (onMenu)
			oneViewport(width, height, 0);
			
		//Exercise views
		if (onEx1)
			oneViewport(width, height, 1);
		if (onEx2)
			oneViewport(width, height, 2);
		if (onEx3)
			oneViewport(width, height, 3);
		if (onEx4)
			twoViewports(width, height);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);

	glfwTerminate();
	exit(EXIT_SUCCESS);

	return 0;
}