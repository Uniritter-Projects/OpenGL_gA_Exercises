#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include <ctime>

const float Pi = 3.14159;

//Coordenadas da janela do mundo (Ortho2D)
const float Xmin = -1.0;
const float Xmax = 1.0;
const float Ymin = -1.0;
const float Ymax = 1.0;

using namespace std;

class Shape
{
public:
	Shape() {}
	~Shape() {}

	//Primitives
	void DrawGrid();
	void DrawCircle(float posX, float posY, float radius, float nPoints);
	void DrawTriangle();
	void DrawSquare();

	//Words
	void DrawOla();
	void DrawTitle();
	void DrawNames();
	void DrawNumber(int number);

	//Draws
	void DrawDoll();
	void DrawTruck();
	void DrawHelicopter();
	void DrawHouse();
	void DrawStar();
	void DrawCube();
	void DrawHyperCube();
	void GrowCube(float n);

	//Exercises
	void DrawRandomShapes();
	void DrawAnimal(bool wireframe, int imageId);
	void SquareTxtCoordinates();
	void DrawSportsCourt(int courtId);
	void DrawCampus();
};