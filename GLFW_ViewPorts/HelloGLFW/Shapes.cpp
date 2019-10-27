#include "Shapes.h"
#include<iostream>
#include<fstream>

//Constraints: A (-0.5, 0.5), B (0.5, -0.5), C (-0.5, -0.5), D (0.5, 0.5)

extern bool generate;

struct coordinate
{
	float posX;
	float posY;
};

//Primitives
void Shape::DrawCircle(float posX, float posY, float radius, float nPoints)
{
	float rd = radius;

	float angle = 0.0;
	float slice = 2 * Pi / nPoints;
	float x, y;

	float xi = posX;
	float yi = posY;

	glPointSize(0);
	glLineWidth(2);

	//Para desenhar o contorno
	//Habilitar o desenho do tipo de primitiva escolhido (ponto, linha, polígono etc)
	glColor3f(1, 1, 1);
	angle = 0.0;
	glBegin(GL_LINE_LOOP);
	while (angle <= 2 * Pi)
	{
		//Calcular posicao do ponto em x, y
		x = xi + rd * cos(angle);
		y = yi + rd * sin(angle);
		glVertex2f(x, y);
		//Atualizar o angulo
		angle += slice;
	}
	//Desabilita o desenho do tipo de primitiva
	glEnd();
}
void Shape::DrawGrid()
{
	glLineWidth(1);

	float xi = Xmin;
	float yi = Ymin;
	float ncells = 20.0;

	float cell = (Xmax - Xmin) / ncells;

	glPointSize(10);
	glColor3f(1, 0, 0);
	glBegin(GL_POINTS);
	glVertex2f(Xmin, Ymin);
	glVertex2f(Xmin, Ymax);
	glVertex2f(Xmax, Ymin);
	glVertex2f(Xmax, Ymax);
	glEnd();

	glColor3f(0.8, 0.8, 0.8);
	for (int i = 0; i < ncells; i++)
	{
		for (int j = 0; j < ncells; j++)
		{

			glBegin(GL_LINE_LOOP);
			glVertex2f(xi + cell * j, yi + cell * i);
			glVertex2f(xi + cell * (j + 1), yi + cell * i);
			glVertex2f(xi + cell * (j + 1), yi + cell * (i + 1));
			glVertex2f(xi + cell * j, yi + cell * (i + 1));
			glEnd();
		}
	}

}
void Shape::DrawTriangle()
{
	glLineWidth(2);

	glColor3f(0,0,0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(-0.5,-0.5);
		glVertex2f( 0.0, 0.5);
		glVertex2f( 0.5,-0.5);
	glEnd();
}
void Shape::DrawSquare()
{
	glLineWidth(2);

	glColor3f(1, 1, 1);
	glBegin(GL_LINE_LOOP);
		glVertex2f(-0.5, 0.5);
		glVertex2f(-0.5, -0.5);
		glVertex2f(0.5, -0.5);
		glVertex2f(0.5, 0.5);
	glEnd();
}

//Words
void Shape::DrawOla()
{
	glLineWidth(2);
	glColor3f(0, 0, 0);

	//Draw "O"
	glBegin(GL_LINE_LOOP);
		glVertex2f(-0.3, 0.1);
		glVertex2f(-0.3, -0.1);
		glVertex2f(-0.1, -0.1);
		glVertex2f(-0.1, 0.1);
	glEnd();

	//Draw "L"
	glBegin(GL_LINES);
		glVertex2f(0, 0.1);
		glVertex2f(0, -0.1);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(0, -0.1);
		glVertex2f(0.2, -0.1);
	glEnd();

	//Draw "A"
	glBegin(GL_LINES);
		glVertex2f(0.45, 0.15);
		glVertex2f(0.55, 0.25);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(0.3, -0.1);
		glVertex2f(0.35, 0);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(0.5, -0.1);
		glVertex2f(0.45, 0);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(0.35, 0);
		glVertex2f(0.45, 0);
		glVertex2f(0.4, 0.1);
	glEnd();

}
void Shape::DrawTitle()
{
	glLineWidth(2);
	glColor3f(1, 1, 1);

	#pragma region O
	//Line 1
	glBegin(GL_LINES);
	glVertex2f(-0.6, 0.9);
	glVertex2f(-0.6, 0.8);
	glEnd();

	//Line 2
	glBegin(GL_LINES);
	glVertex2f(-0.5, 0.9);
	glVertex2f(-0.6, 0.9);
	glEnd();

	//Line 3
	glBegin(GL_LINES);
		glVertex2f(-0.5, 0.9);
		glVertex2f(-0.5, 0.8);
	glEnd();

	//Line 5
	glBegin(GL_LINES);
	glVertex2f(-0.5, 0.8);
	glVertex2f(-0.5, 0.7);
	glEnd();

	////Line 6
	glBegin(GL_LINES);
	glVertex2f(-0.5, 0.7);
	glVertex2f(-0.6, 0.7);
	glEnd();

	////Line 7
	glBegin(GL_LINES);
	glVertex2f(-0.6, 0.8);
	glVertex2f(-0.6, 0.7);
	glEnd();
#pragma endregion
	#pragma region P
	//Line 1
	glBegin(GL_LINES);
	glVertex2f(-0.4, 0.9);
	glVertex2f(-0.4, 0.8);
	glEnd();

	//Line 2
	glBegin(GL_LINES);
	glVertex2f(-0.3, 0.9);
	glVertex2f(-0.4, 0.9);
	glEnd();

	//Line 3
	glBegin(GL_LINES);
	glVertex2f(-0.3, 0.9);
	glVertex2f(-0.3, 0.8);
	glEnd();

	//Line 4
	glBegin(GL_LINES);
		glVertex2f(-0.4, 0.8);
		glVertex2f(-0.3, 0.8);
	glEnd();

	////Line 7
	glBegin(GL_LINES);
		glVertex2f(-0.4, 0.8);
		glVertex2f(-0.4, 0.7);
	glEnd();
#pragma endregion
	#pragma region E
	//Line 1
	glBegin(GL_LINES);
	glVertex2f(-0.2, 0.9);
	glVertex2f(-0.2, 0.8);
	glEnd();

	//Line 2
	glBegin(GL_LINES);
	glVertex2f(-0.1, 0.9);
	glVertex2f(-0.2, 0.9);
	glEnd();

	//Line 4
	glBegin(GL_LINES);
	glVertex2f(-0.2, 0.8);
	glVertex2f(-0.1, 0.8);
	glEnd();

	//Line 6
	glBegin(GL_LINES);
		glVertex2f(-0.1, 0.7);
		glVertex2f(-0.2, 0.7);
	glEnd();

	////Line 7
	glBegin(GL_LINES);
		glVertex2f(-0.2, 0.8);
		glVertex2f(-0.2, 0.7);
	glEnd();
#pragma endregion
	#pragma region N
	//Line 1
	glBegin(GL_LINES);
		glVertex2f(0, 0.9);
		glVertex2f(0, 0.8);
	glEnd();

	//Line 3
	glBegin(GL_LINES);
		glVertex2f(0.1, 0.9);
		glVertex2f(0.1, 0.8);
	glEnd();

	////Line 5
	glBegin(GL_LINES);
		glVertex2f(0.1, 0.8);
		glVertex2f(0.1, 0.7);
	glEnd();

	////Line 7
	glBegin(GL_LINES);
		glVertex2f(0, 0.8);
		glVertex2f(0, 0.7);
	glEnd();

	glBegin(GL_LINES);
		glVertex2f(0, 0.9);
		glVertex2f(0.1, 0.7);
	glEnd();

#pragma endregion

	#pragma region G
	//Line 1
	glBegin(GL_LINES);
		glVertex2f(0.4, 0.9);
		glVertex2f(0.4, 0.8);
	glEnd();

	//Line 2
	glBegin(GL_LINES);
		glVertex2f(0.5, 0.9);
		glVertex2f(0.4, 0.9);
	glEnd();

	//Line 3
	glBegin(GL_LINES);
		glVertex2f(0.5, 0.8);
		glVertex2f(0.45, 0.8);
	glEnd();

	//Line 5
	glBegin(GL_LINES);
		glVertex2f(0.5, 0.8);
		glVertex2f(0.5, 0.7);
	glEnd();

	//Line 6
	glBegin(GL_LINES);
		glVertex2f(0.5, 0.7);
		glVertex2f(0.4, 0.7);
	glEnd();

	//Line 7
	glBegin(GL_LINES);
		glVertex2f(0.4, 0.8);
		glVertex2f(0.4, 0.7);
	glEnd();

#pragma endregion
	#pragma region L
	//Line 1
	glBegin(GL_LINES);
		glVertex2f(0.6, 0.9);
		glVertex2f(0.6, 0.8);
	glEnd();

	//Line 6
	glBegin(GL_LINES);
		glVertex2f(0.7, 0.7);
		glVertex2f(0.6, 0.7);
	glEnd();

	//Line 7
	glBegin(GL_LINES);
		glVertex2f(0.6, 0.8);
		glVertex2f(0.6, 0.7);
	glEnd();
#pragma endregion
}
void Shape::DrawNames()
{
	glLineWidth(1);
	glColor3f(1, 1, 1);

	#pragma region Luis
	//Draw "L"
	glBegin(GL_LINES);
		glVertex2f(-0.5, -0.65);
		glVertex2f(-0.5, -0.7);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(-0.5, -0.7);
		glVertex2f(-0.45, -0.7);
	glEnd();

	//Draw "U"
	glBegin(GL_LINES);
		glVertex2f(-0.4, -0.65);
		glVertex2f(-0.4, -0.7);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(-0.4, -0.7);
		glVertex2f(-0.35, -0.7);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(-0.35, -0.7);
		glVertex2f(-0.35, -0.65);
	glEnd();

	//Draw "I"
	glBegin(GL_LINES);
		glVertex2f(-0.3, -0.65);
		glVertex2f(-0.3, -0.7);
	glEnd();

	//Draw "S"
	glBegin(GL_LINES);
		glVertex2f(-0.2, -0.65);
		glVertex2f(-0.25, -0.65);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(-0.25, -0.65);
		glVertex2f(-0.25, -0.68);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(-0.25, -0.68);
		glVertex2f(-0.2, -0.68);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(-0.2, -0.68);
		glVertex2f(-0.2, -0.68);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(-0.2, -0.68);
		glVertex2f(-0.2, -0.7);
	glEnd();
		glBegin(GL_LINES);
		glVertex2f(-0.2, -0.7);
		glVertex2f(-0.25, -0.7);
	glEnd();

	#pragma endregion
	#pragma region Renata

	//Draw "R"
	glBegin(GL_LINES);
		glVertex2f(-0.05, -0.7);
		glVertex2f(-0.05, -0.65);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(-0.05, -0.65);
		glVertex2f(0, -0.65);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(-0.05, -0.67);
		glVertex2f(0, -0.67);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(0, -0.65);
		glVertex2f(0, -0.67);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(-0.05, -0.67);
		glVertex2f(0, -0.7);
	glEnd();

	//Draw "E"
	glBegin(GL_LINES);
		glVertex2f(0.05, -0.65);
		glVertex2f(0.05, -0.7);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(0.05, -0.65);
		glVertex2f(0.1, -0.65);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(0.05, -0.67);
		glVertex2f(0.1, -0.67);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(0.05, -0.7);
		glVertex2f(0.1, -0.7);
	glEnd();

	//Draw "N"
	glBegin(GL_LINES);
		glVertex2f(0.15, -0.65);
		glVertex2f(0.15, -0.7);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(0.15, -0.65);
		glVertex2f(0.19, -0.7);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(0.19, -0.65);
		glVertex2f(0.19, -0.7);
	glEnd();


	//Draw "A"
	glBegin(GL_LINES);
		glVertex2f(0.23, -0.7);
		glVertex2f(0.25, -0.65);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(0.25, -0.65);
		glVertex2f(0.27, -0.7);
	glEnd();

	//Draw "T"
	glBegin(GL_LINES);
		glVertex2f(0.33, -0.7);
		glVertex2f(0.33, -0.65);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(0.36, -0.65);
		glVertex2f(0.31, -0.65);
	glEnd();

	//Draw "A"
	glBegin(GL_LINES);
		glVertex2f(0.39, -0.7);
		glVertex2f(0.41, -0.65);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(0.41, -0.65);
		glVertex2f(0.43, -0.7);
	glEnd();

	#pragma endregion

}
void Shape::DrawNumber(int number)
{
	glLineWidth(0.5);
	glColor3f(1, 1, 1);

	if (number == 1)
	{
		glBegin(GL_LINES);
			glVertex2f(0.6, -0.8);
			glVertex2f(0.7, -0.7);
		glEnd();
		glBegin(GL_LINES);
			glVertex2f(0.7, -0.7);
			glVertex2f(0.7, -0.9);
		glEnd();
		glBegin(GL_LINES);
			glVertex2f(0.6, -0.9);
			glVertex2f(0.8, -0.9);
		glEnd();
	}
	if (number == 2)
	{
		glBegin(GL_LINES);
			glVertex2f(0.65, -0.7);
			glVertex2f(0.75, -0.7);
		glEnd();
		glBegin(GL_LINES);
			glVertex2f(0.75, -0.7);
			glVertex2f(0.75, -0.8);
		glEnd();
		glBegin(GL_LINES);
			glVertex2f(0.75, -0.8);
			glVertex2f(0.65, -0.8);
		glEnd();
		glBegin(GL_LINES);
			glVertex2f(0.65, -0.8);
			glVertex2f(0.65, -0.9);
		glEnd();
		glBegin(GL_LINES);
			glVertex2f(0.65, -0.9);
			glVertex2f(0.75, -0.9);
		glEnd();
	}
	if (number == 3)
	{
		glBegin(GL_LINES);
			glVertex2f(0.75, -0.7);
			glVertex2f(0.75, -0.9);
		glEnd();
		glBegin(GL_LINES);
			glVertex2f(0.65, -0.7);
			glVertex2f(0.75, -0.7);
		glEnd();
		glBegin(GL_LINES);
			glVertex2f(0.65, -0.8);
			glVertex2f(0.75, -0.8);
		glEnd();
		glBegin(GL_LINES);
			glVertex2f(0.65, -0.9);
			glVertex2f(0.75, -0.9);
		glEnd();
	}
	if (number == 4)
	{
		glBegin(GL_LINES);
			glVertex2f(0.65, -0.7);
			glVertex2f(0.65, -0.8);
		glEnd();
		glBegin(GL_LINES);
			glVertex2f(0.65, -0.8);
			glVertex2f(0.75, -0.8);
		glEnd();
		glBegin(GL_LINES);
			glVertex2f(0.75, -0.7);
			glVertex2f(0.75, -0.9);
		glEnd();
	}
	if (number == 5)
	{
		glBegin(GL_LINES);
			glVertex2f(0.65, -0.7);
			glVertex2f(0.75, -0.7);
		glEnd();
		glBegin(GL_LINES);
			glVertex2f(0.65, -0.7);
			glVertex2f(0.65, -0.8);
		glEnd();
		glBegin(GL_LINES);
			glVertex2f(0.65, -0.8);
			glVertex2f(0.75, -0.8);
		glEnd();
		glBegin(GL_LINES);
			glVertex2f(0.75, -0.8);
			glVertex2f(0.75, -0.9);
		glEnd();
		glBegin(GL_LINES);
			glVertex2f(0.75, -0.9);
			glVertex2f(0.65, -0.9);
		glEnd();
	}
	if (number == 6)
	{
		glBegin(GL_LINES);
			glVertex2f(0.65, -0.7);
			glVertex2f(0.65, -0.9);
		glEnd();
		glBegin(GL_LINE_LOOP);
			glVertex2f(0.75, -0.8);
			glVertex2f(0.65, -0.8);
			glVertex2f(0.65, -0.9);
			glVertex2f(0.75, -0.9);
		glEnd();
	}
	if (number == 7)
	{
		glBegin(GL_LINES);
			glVertex2f(0.65, -0.7);
			glVertex2f(0.75, -0.7);
		glEnd();
		glBegin(GL_LINES);
			glVertex2f(0.75, -0.7);
			glVertex2f(0.65, -0.9);
		glEnd();
	}
	if (number == 8)
	{
		glBegin(GL_LINE_LOOP);
			glVertex2f(0.65, -0.7);
			glVertex2f(0.75, -0.7);
			glVertex2f(0.75, -0.8);
			glVertex2f(0.65, -0.8);
		glEnd();
		glBegin(GL_LINE_LOOP);
			glVertex2f(0.75, -0.8);
			glVertex2f(0.65, -0.8);
			glVertex2f(0.65, -0.9);
			glVertex2f(0.75, -0.9);
		glEnd();
	}
	if (number == 9)
	{
		glBegin(GL_LINE_LOOP);
			glVertex2f(0.65, -0.7);
			glVertex2f(0.75, -0.7);
			glVertex2f(0.75, -0.8);
			glVertex2f(0.65, -0.8);
		glEnd();
		glBegin(GL_LINES);
			glVertex2f(0.75, -0.7);
			glVertex2f(0.75, -0.9);
		glEnd();
	}
}

//Draws
void Shape::DrawDoll()
{
	glLineWidth(2);
	glColor3f(0, 0, 0);

	//Body
	glBegin(GL_LINE_LOOP);
		glVertex2f(-0.06, 0.1);
		glVertex2f(-0.1, -0.1);
		glVertex2f(0.1, -0.1);
		glVertex2f(0.06, 0.1);
	glEnd();

	//Head
	glBegin(GL_LINE_LOOP);
		glVertex2f(-0.05, 0.3);
		glVertex2f(-0.1, 0.25);
		glVertex2f(-0.05, 0.2);
		glVertex2f(0.05, 0.2);
		glVertex2f(0.1, 0.25);
		glVertex2f(0.05, 0.3);
	glEnd();

	//Arms
	glBegin(GL_LINE_LOOP);
		glVertex2f(0.15, 0.1);
		glVertex2f(0.15, 0.05);
		glVertex2f(0.25, 0.05);
		glVertex2f(0.25, 0.1);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(-0.25, 0.1);
		glVertex2f(-0.25, 0.05);
		glVertex2f(-0.15, 0.05);
		glVertex2f(-0.15, 0.1);
	glEnd();

	//Legs
	glBegin(GL_LINE_LOOP);
		glVertex2f(-0.1, -0.15);
		glVertex2f(-0.2, -0.25);
		glVertex2f(-0.1, -0.25);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(0.1, -0.15);
		glVertex2f(0.1, -0.25);
		glVertex2f(0.2, -0.25);
	glEnd();

}
void Shape::DrawTruck()
{
	glLineWidth(2);
	glColor3f(0, 0, 0);

	//Front
	glBegin(GL_LINE_LOOP);
		glVertex2f(0.1, 0.1);
		glVertex2f(0.1, -0.2);
		glVertex2f(0.3, -0.2);
		glVertex2f(0.3, 0.05);
	glEnd();

	//Body
	glBegin(GL_LINE_LOOP);
		glVertex2f(-0.3, 0);
		glVertex2f(-0.3, -0.2);
		glVertex2f(0, -0.2);
		glVertex2f(0, 0);
	glEnd();

	//Wheels
	glBegin(GL_LINE_LOOP);
		glVertex2f(0.15, -0.25);
		glVertex2f(0.1, -0.3);
		glVertex2f(0.15, -0.35);
		glVertex2f(0.25, -0.35);
		glVertex2f(0.3, -0.3);
		glVertex2f(0.25, -0.25);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(-0.2, -0.25);
		glVertex2f(-0.25, -0.3);
		glVertex2f(-0.2, -0.35);
		glVertex2f(-0.1, -0.35);
		glVertex2f(-0.05, -0.3);
		glVertex2f(-0.1, -0.25);
	glEnd();

	//Boxes
	glBegin(GL_LINE_LOOP);
		glVertex2f(-0.15, 0.15);
		glVertex2f(-0.15, 0.05);
		glVertex2f(-0.05, 0.05);
		glVertex2f(-0.05, 0.15);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(-0.25, 0.15);
		glVertex2f(-0.25, 0.05);
		glVertex2f(-0.2, 0.05);
		glVertex2f(-0.2, 0.15);
	glEnd();
}
void Shape::DrawHelicopter()
{
	glLineWidth(2);
	glColor3f(0, 0, 0);

	//Front
	glBegin(GL_LINE_LOOP);
		glVertex2f(0.15, 0.1);
		glVertex2f(0.15, -0.1);
		glVertex2f(0.35, -0.1);
		glVertex2f(0.35, 0.05);
	glEnd();

	//Back
	glBegin(GL_LINE_LOOP);
		glVertex2f(-0.2, 0.1);
		glVertex2f(0.1, -0.1);
		glVertex2f(0.1, 0.1);
	glEnd();

	//Propellers
	glBegin(GL_LINE_LOOP);
		glVertex2f(0.1, 0.3);
		glVertex2f(0.1, 0.2);
		glVertex2f(0.15, 0.2);
		glVertex2f(0.15, 0.3);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(0.15, 0.15);
		glVertex2f(0.26, 0.18);
		glVertex2f(0.26, 0.12);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(0, 0.18);
		glVertex2f(0, 0.12);
		glVertex2f(0.1, 0.15);
	glEnd();

	//Tail
	glBegin(GL_LINE_LOOP);
		glVertex2f(-0.25, 0.1);
		glVertex2f(-0.28, 0.15);
		glVertex2f(-0.34, 0.15);
		glVertex2f(-0.37, 0.1);
		glVertex2f(-0.34, 0.05);
		glVertex2f(-0.28, 0.05);
	glEnd();
}
void Shape::DrawHouse()
{
	glLineWidth(2);
	glColor3f(0, 0, 0);

	//Base
	glBegin(GL_LINE_LOOP);
		glVertex2f(-0.2, 0.1);
		glVertex2f(-0.2, -0.3);
		glVertex2f(0.2, -0.3);
		glVertex2f(0.2, 0.1);
	glEnd();

	//Roof
	glBegin(GL_LINE_LOOP);
		glVertex2f(-0.2, 0.1);
		glVertex2f(0.2, 0.1);
		glVertex2f(0, 0.3);
	glEnd();

	//Door
	glBegin(GL_LINE_LOOP);
		glVertex2f(-0.05, -0.05);
		glVertex2f(-0.05, -0.3);
		glVertex2f(0.05, -0.3);
		glVertex2f(0.05, -0.05);
	glEnd();

}
void Shape::DrawStar()
{
	glLineWidth(2);
	glColor3f(0, 0, 0);

	//Center square
	glBegin(GL_LINE_LOOP);
		glVertex2f(-0.1, 0.1);
		glVertex2f(-0.1, -0.1);
		glVertex2f(0.1, -0.1);
		glVertex2f(0.1, 0.1);
	glEnd();

	//Triangles
	glBegin(GL_LINE_LOOP);
		glVertex2f(0, 0.4);
		glVertex2f(-0.1, 0.2);
		glVertex2f(0.1, 0.2);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(0.4, 0);
		glVertex2f(0.2, -0.1);
		glVertex2f(0.2, 0.1);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(0, -0.4);
		glVertex2f(-0.1, -0.2);
		glVertex2f(0.1, -0.2);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(-0.4, 0);
		glVertex2f(-0.2, 0.1);
		glVertex2f(-0.2, -0.1);
	glEnd();
}
void Shape::DrawCube()
{
	glLineWidth(2);
	glColor3f(0, 0, 0);

	//Squares
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.2, 0.1);
	glVertex2f(-0.2, -0.2);
	glVertex2f(0.1, -0.2);
	glVertex2f(0.1, 0.1);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.1, 0.2);
	glVertex2f(-0.1, -0.1);
	glVertex2f(0.2, -0.1);
	glVertex2f(0.2, 0.2);
	glEnd();

	//Lines
	glBegin(GL_LINES);
	glVertex2f(-0.2, 0.1);
	glVertex2f(-0.1, 0.2);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0.1, 0.1);
	glVertex2f(0.2, 0.2);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-0.2, -0.2);
	glVertex2f(-0.1, -0.1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0.1, -0.2);
	glVertex2f(0.2, -0.1);
	glEnd();
}
void Shape::DrawHyperCube()
{
	#pragma region MiniCube

	glLineWidth(1);
	glColor3f(1, 1, 1);

		//Squares
		glBegin(GL_LINE_LOOP);
			glVertex2f(-0.2, 0.1);
			glVertex2f(-0.2, -0.2);
			glVertex2f(0.1, -0.2);
			glVertex2f(0.1, 0.1);
		glEnd();
		glBegin(GL_LINE_LOOP);
			glVertex2f(-0.1, 0.2);
			glVertex2f(-0.1, -0.1);
			glVertex2f(0.2, -0.1);
			glVertex2f(0.2, 0.2);
		glEnd();

		//Lines
		glBegin(GL_LINES);
			glVertex2f(-0.2, 0.1);
			glVertex2f(-0.1, 0.2);
		glEnd();
		glBegin(GL_LINES);
			glVertex2f(0.1, 0.1);
			glVertex2f(0.2, 0.2);
		glEnd();
		glBegin(GL_LINES);
			glVertex2f(-0.2, -0.2);
			glVertex2f(-0.1, -0.1);
		glEnd();
		glBegin(GL_LINES);
			glVertex2f(0.1, -0.2);
			glVertex2f(0.2, -0.1);
		glEnd();

#pragma endregion
	#pragma region BigCube

		glLineWidth(2);
		glColor3f(1, 1, 1);

		//Squares
		glBegin(GL_LINE_LOOP);
			glVertex2f(-0.4, 0.2);
			glVertex2f(-0.4, -0.4);
			glVertex2f(0.2, -0.4);
			glVertex2f(0.2, 0.2);
		glEnd();
		glBegin(GL_LINE_LOOP);
			glVertex2f(-0.2, 0.4);
			glVertex2f(-0.2, -0.2);
			glVertex2f(0.4, -0.2);
			glVertex2f(0.4, 0.4);
		glEnd();

		//Lines
		glBegin(GL_LINES);
			glVertex2f(-0.4, 0.2);
			glVertex2f(-0.2, 0.4);
		glEnd();
		glBegin(GL_LINES);
			glVertex2f(0.2, 0.2);
			glVertex2f(0.4, 0.4);
		glEnd();
		glBegin(GL_LINES);
			glVertex2f(-0.4, -0.4);
			glVertex2f(-0.2, -0.2);
		glEnd();
		glBegin(GL_LINES);
			glVertex2f(0.2, -0.4);
			glVertex2f(0.4, -0.2);
		glEnd();

		glLineWidth(2);
		glColor3f(1, 0, 0);

		//Intern Join (Mini cube - Front)
		glBegin(GL_LINES);
			glVertex2f(-0.2, 0.1);
			glVertex2f(-0.4, 0.2);
		glEnd();
		glBegin(GL_LINES);
			glVertex2f(-0.4, -0.4);
			glVertex2f(-0.2, -0.2);
		glEnd();
		glBegin(GL_LINES);
			glVertex2f(0.1, -0.2);
			glVertex2f(0.2, -0.4);
		glEnd();
		glBegin(GL_LINES);
			glVertex2f(0.1, 0.1);
			glVertex2f(0.2, 0.2);
		glEnd();


		glLineWidth(1);
		glColor3f(1, 0, 0);

		//Intern Join (Mini cube - Back)
		glBegin(GL_LINES);
			glVertex2f(-0.1, 0.2);
			glVertex2f(-0.2, 0.4);
		glEnd();
		glBegin(GL_LINES);
			glVertex2f(-0.1, -0.1);
			glVertex2f(-0.2, -0.2);
		glEnd();
		glBegin(GL_LINES);
			glVertex2f(0.2, -0.1);
			glVertex2f(0.4, -0.2);
		glEnd();
		glBegin(GL_LINES);
			glVertex2f(0.2, 0.2);
			glVertex2f(0.4, 0.4);
		glEnd();

	#pragma endregion
}
void Shape::GrowCube(float n)
{
	//Squares
	glBegin(GL_LINE_LOOP);
		glVertex2f(-0.4 * n, 0.2 * n);
		glVertex2f(-0.4 * n, -0.4 * n);
		glVertex2f(0.2 * n, -0.4 * n);
		glVertex2f(0.2 * n, 0.2 * n);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(-0.2 * n, 0.4 * n);
		glVertex2f(-0.2 * n, -0.2 * n);
		glVertex2f(0.4 * n, -0.2 * n);
		glVertex2f(0.4 * n, 0.4 * n);
	glEnd();

	//Lines
	glBegin(GL_LINES);
		glVertex2f(-0.4 * n, 0.2 * n);
		glVertex2f(-0.2 * n, 0.4 * n);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(0.2 * n, 0.2 * n);
		glVertex2f(0.4 * n, 0.4 * n);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(-0.4 * n, -0.4 * n);
		glVertex2f(-0.2 * n, -0.2 * n);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(0.2 * n, -0.4 * n);
		glVertex2f(0.4 * n, -0.2 * n);
	glEnd();

	glLineWidth(2);
	glColor3f(1, 0, 0);

	//Intern Join (Mini cube - Front)
	glBegin(GL_LINES);
		glVertex2f(-0.2 * n, 0.1 * n);
		glVertex2f(-0.4 * n, 0.2 * n);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(-0.4 * n, -0.4 * n);
		glVertex2f(-0.2 * n, -0.2 * n);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(0.1 * n, -0.2 * n);
		glVertex2f(0.2 * n, -0.4 * n);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(0.1 * n, 0.1 * n);
		glVertex2f(0.2 * n, 0.2 * n);
	glEnd();

	glLineWidth(1);
	glColor3f(1, 0, 0);

	//Intern Join (Mini cube - Back)
	glBegin(GL_LINES);
		glVertex2f(-0.1 * n, 0.2 * n);
		glVertex2f(-0.2 * n, 0.4 * n);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(-0.1 * n, -0.1 * n);
		glVertex2f(-0.2 * n, -0.2 * n);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(0.2 * n, -0.1 * n);
		glVertex2f(0.4 * n, -0.2 * n);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(0.2 * n, 0.2 * n);
		glVertex2f(0.4 * n, 0.4 * n);
	glEnd();
}

//Exercises
void Shape::DrawRandomShapes()
{
	glLineWidth(2);

	float randR = 0 + rand() % ((1 + 1) - 0);
	float randG = 0 + rand() % ((1 + 1) - 0);
	float randB = 0 + rand() % ((1 + 1) - 0);

	float randX = ((float(rand()) / float(RAND_MAX)) * (1 + 1)) + (-1);
	float randY = ((float(rand()) / float(RAND_MAX)) * (1 + 1)) + (-1);

	float randSize = ((float(rand()) / float(RAND_MAX)) * (2 - 0.5)) + 0.5;

	glColor3f(randR, randG, randB);
	glTranslatef(randX, randY, 0);
	glScalef(randSize, randSize, randSize);

	glBegin(GL_TRIANGLES);
		glVertex2f(-0.5, -0.5);
		glVertex2f(0.0, 0.5);
		glVertex2f(0.5, -0.5);
	glEnd();

	if (randR < 0.5)
	{
		glBegin(GL_TRIANGLES);
			glVertex2f(-0.5, -0.5);
			glVertex2f(0.0, 0.5);
			glVertex2f(0.5, -0.5);
		glEnd();
	}
	else
	{
		glBegin(GL_QUADS);
			glVertex2f(-0.5, 0.5);
			glVertex2f(-0.5, -0.5);
			glVertex2f(0.5, -0.5);
			glVertex2f(0.5, 0.5);
		glEnd();
	}

	//generate = false;
}
void Shape::DrawAnimal(bool lineArt, int imageId)
{
	glLineWidth(2);

	if (lineArt)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	switch(imageId)
	{
		case 1:
			//Ears
			glColor3f(0.5, 0.5, 0.5);
			glBegin(GL_TRIANGLES);
			glVertex2f(1.0, 6.0);
			glVertex2f(3.0, 8.0);
			glVertex2f(1.0, 9.0);

			glVertex2f(11.0, 9.0);
			glVertex2f(11.0, 6.0);
			glVertex2f(9.0, 8.0);
			glEnd();

			//Nose
			glBegin(GL_QUADS);
			glVertex2f(6.0, 0.0);
			glVertex2f(2.0, 1.0);
			glVertex2f(4.0, 3.0);
			glVertex2f(6.0, 4.0);

			glVertex2f(6.0, 0.0);
			glVertex2f(10.0, 1.0);
			glVertex2f(8.0, 3.0);
			glVertex2f(6.0, 4.0);
			glEnd();

			//Head
			glColor3f(0.7, 0.7, 0.3);
			glBegin(GL_QUADS);
			glVertex2f(2.0, 1.0);
			glVertex2f(0.0, 3.0);
			glVertex2f(1.0, 6.0);
			glVertex2f(3.0, 8.0);

			glVertex2f(2.0, 1.0);
			glVertex2f(4.0, 3.0);
			glVertex2f(6.0, 4.0);
			glVertex2f(3.0, 8.0);

			glVertex2f(10.0, 1.0);
			glVertex2f(8.0, 3.0);
			glVertex2f(6.0, 4.0);
			glVertex2f(9.0, 8.0);

			glVertex2f(10.0, 1.0);
			glVertex2f(12.0, 3.0);
			glVertex2f(11.0, 6.0);
			glVertex2f(9.0, 8.0);
			glEnd();

			glBegin(GL_TRIANGLES);
			glVertex2f(6.0, 4.0);
			glVertex2f(9.0, 8.0);
			glVertex2f(3.0, 8.0);
			glEnd();

			glColor3f(0.1, 0.1, 0.1);

			//Face
			glBegin(GL_QUADS);
			glVertex2f(5.0, 4.0);
			glVertex2f(4.0, 4.0);
			glVertex2f(3.0, 5.0);
			glVertex2f(4.0, 5.0);

			glVertex2f(7.0, 4.0);
			glVertex2f(8.0, 4.0);
			glVertex2f(9.0, 5.0);
			glVertex2f(8.0, 5.0);
			glEnd();

			glBegin(GL_TRIANGLES);
			glVertex2f(6.0, 1.0);
			glVertex2f(7.0, 2.0);
			glVertex2f(5.0, 2.0);
			glEnd();
			break;

		case 2:
			//Ears
			glColor3f(0.25, 0.25, 0.25);
			glBegin(GL_TRIANGLES);
			glVertex2f(1.0, 6.0);
			glVertex2f(3.0, 8.0);
			glVertex2f(1.0, 9.0);

			glVertex2f(11.0, 9.0);
			glVertex2f(11.0, 6.0);
			glVertex2f(9.0, 8.0);
			glEnd();

			//Nose
			glBegin(GL_QUADS);
			glVertex2f(6.0, 0.0);
			glVertex2f(2.0, 1.0);
			glVertex2f(4.0, 3.0);
			glVertex2f(6.0, 4.0);

			glVertex2f(6.0, 0.0);
			glVertex2f(10.0, 1.0);
			glVertex2f(8.0, 3.0);
			glVertex2f(6.0, 4.0);
			glEnd();

			//Head
			glColor3f(0.8, 0.8, 0.8);
			glBegin(GL_QUADS);
			glVertex2f(2.0, 1.0);
			glVertex2f(0.0, 3.0);
			glVertex2f(1.0, 6.0);
			glVertex2f(3.0, 8.0);

			glVertex2f(2.0, 1.0);
			glVertex2f(4.0, 3.0);
			glVertex2f(6.0, 4.0);
			glVertex2f(3.0, 8.0);

			glVertex2f(10.0, 1.0);
			glVertex2f(8.0, 3.0);
			glVertex2f(6.0, 4.0);
			glVertex2f(9.0, 8.0);

			glVertex2f(10.0, 1.0);
			glVertex2f(12.0, 3.0);
			glVertex2f(11.0, 6.0);
			glVertex2f(9.0, 8.0);
			glEnd();

			glBegin(GL_TRIANGLES);
			glVertex2f(6.0, 4.0);
			glVertex2f(9.0, 8.0);
			glVertex2f(3.0, 8.0);
			glEnd();

			glColor3f(0.1, 0.1, 0.1);

			//Face
			glBegin(GL_QUADS);
			glVertex2f(4.0, 4.0);
			glVertex2f(5.0, 4.0);
			glVertex2f(4.0, 5.0);
			glVertex2f(5.0, 5.0);
			glEnd();
			glBegin(GL_QUADS);
			glVertex2f(6.9, 4.0);
			glVertex2f(7.9, 4.0);
			glVertex2f(6.9, 5.0);
			glVertex2f(7.9, 5.0);
			glEnd();

			glBegin(GL_TRIANGLES);
			glVertex2f(6.0, 1.0);
			glVertex2f(7.0, 1.5);
			glVertex2f(5.0, 1.5);
			glEnd();
			break;
	}
}
void Shape::SquareTxtCoordinates() 
{
	//Exemple square
	//glBegin(GL_LINE_LOOP);
	//	glVertex2f(-0.5, 0.5);
	//	glVertex2f(-0.5, -0.5);
	//	glVertex2f(0.5, -0.5);
	//	glVertex2f(0.5, 0.5);
	//glEnd();

	std::ifstream infile("animalCoordinates.txt");

	float coordinates[8] = {};

	float a, b;
	while (infile >> a)
	{
		int cont = 0;

		coordinates[cont] = a;
		cont++;
	}

	glLineWidth(2);
	glColor3f(1, 1, 1);

	glBegin(GL_QUADS);
		glVertex2f(coordinates[0], coordinates[1]);
		glVertex2f(coordinates[2], coordinates[3]);
		glVertex2f(coordinates[4], coordinates[5]);
		glVertex2f(coordinates[6], coordinates[7]);
	glEnd();
}
void Shape::DrawSportsCourt(int courtId) 
{
	switch (courtId)
	{
		//Basketball
		case 1:
			glLineWidth(2);

			glColor3f(0.6, 0.4, 0.15);

			glBegin(GL_QUADS); //quadra toda ok
				glVertex2f(-2, 2);
				glVertex2f(-2, -2);
				glVertex2f(2, -2);
				glVertex2f(2, 2);
			glEnd();

			glColor3f(0.8, 0.7, 0.25);

			glBegin(GL_QUADS); //quadra toda ok
				glVertex2f(-1, 1);
				glVertex2f(-1, -1);
				glVertex2f(1, -1);
				glVertex2f(1, 1);
			glEnd();

			glColor3f(1, 1, 1);

			glBegin(GL_LINE_LOOP); //entrada ->escrever entrada
				glVertex2f(1.6, 0.05);
				glVertex2f(1.6, -0.05);
			glEnd();

			glBegin(GL_LINE_LOOP); //linha que divide os times na quadra ok
				glVertex2f(-1, 0);
				glVertex2f(1, 0);
			glEnd();

			glBegin(GL_LINE_LOOP); //banco reserva A ok
				glVertex2f(1, 0.15);
				glVertex2f(1, 0.5);
				glVertex2f(1.1, 0.5);
				glVertex2f(1.1, 0.15);
			glEnd();

			glBegin(GL_LINE_LOOP); //banco reserva B ok
				glVertex2f(1, -0.15);
				glVertex2f(1, -0.5);
				glVertex2f(1.1, -0.5);
				glVertex2f(1.1, -0.15);
			glEnd();

			glBegin(GL_LINE_LOOP); //torcida A ok
				glVertex2f(1.3, 0.1);
				glVertex2f(1.3, 0.9);
				glVertex2f(1.6, 0.9);
				glVertex2f(1.6, 0.1);
			glEnd();

			glBegin(GL_LINE_LOOP); //torcida B ok
				glVertex2f(1.3, -0.1);
				glVertex2f(1.3, -0.9);
				glVertex2f(1.6, -0.9);
				glVertex2f(1.6, -0.1);
			glEnd();

			glBegin(GL_LINE_LOOP); //cesta A ok
				glVertex2f(0.2, 1);
				glVertex2f(0.1, 0.6);
				glVertex2f(-0.1, 0.6);
				glVertex2f(-0.2, 1);
			glEnd();

			glBegin(GL_LINE_LOOP); //cesta redonda A ok
				glVertex2f(0.1, 0.6);
				glVertex2f(0, 0.7);
				glVertex2f(-0.1, 0.6);
				glVertex2f(0, 0.5);
			glEnd();

			glBegin(GL_LINES); //meio circulo grande A ok
				glVertex2f(-1, 0.75);
				glVertex2f(0, 0.45);
			glEnd();

			glBegin(GL_LINES); //meio circulo grande A ok
				glVertex2f(0, 0.45);
				glVertex2f(1, 0.75);
			glEnd();

			glBegin(GL_LINE_LOOP); //cesta B ok
				glVertex2f(0.2, -1);
				glVertex2f(0.1, -0.6);
				glVertex2f(-0.1, -0.6);
				glVertex2f(-0.2, -1);
			glEnd();

			glBegin(GL_LINE_LOOP); //cesta redonda B ok
				glVertex2f(0.1, -0.6);
				glVertex2f(0, -0.7);
				glVertex2f(-0.1, -0.6);
				glVertex2f(0, -0.5);
			glEnd();

			glBegin(GL_LINES); //meio circulo grande B ok
				glVertex2f(-1, -0.75);
				glVertex2f(0, -0.45);
			glEnd();

			glBegin(GL_LINES); //meio circulo grande B ok
				glVertex2f(0, -0.45);
				glVertex2f(1, -0.75);
			glEnd();

			DrawCircle(0, 0, 0.125, 200);

			break;

		//Soccer
		case 2:
			glLineWidth(2);

			glColor3f(0.35, 0.65, 0.05);

			glBegin(GL_QUADS); //quadra toda ok
			glVertex2f(-2, 2);
			glVertex2f(-2, -2);
			glVertex2f(2, -2);
			glVertex2f(2, 2);
			glEnd();

			glColor3f(1, 1, 1);

			glBegin(GL_LINE_LOOP); //quadra toda ok
			glVertex2f(-1, 1);
			glVertex2f(-1, -1);
			glVertex2f(1, -1);
			glVertex2f(1, 1);
			glEnd();

			glBegin(GL_LINE_LOOP); //entrada ->escrever entrada
			glVertex2f(1.6, 0.05);
			glVertex2f(1.6, -0.05);
			glEnd();

			glBegin(GL_LINE_LOOP); //linha que divide os times na quadra ok
			glVertex2f(-1, 0);
			glVertex2f(1, 0);
			glEnd();

			glBegin(GL_LINE_LOOP); //banco reserva A ok
			glVertex2f(1, 0.15);
			glVertex2f(1, 0.5);
			glVertex2f(1.1, 0.5);
			glVertex2f(1.1, 0.15);
			glEnd();

			glBegin(GL_LINE_LOOP); //torcida A ok
			glVertex2f(1.3, 0.1);
			glVertex2f(1.3, 0.9);
			glVertex2f(1.6, 0.9);
			glVertex2f(1.6, 0.1);
			glEnd();

			glBegin(GL_LINE_LOOP); //goleiro A ok
			glVertex2f(0.25, 1);
			glVertex2f(0.25, 0.7);
			glVertex2f(-0.25, 0.7);
			glVertex2f(-0.25, 1);
			glEnd();

			glBegin(GL_LINE_LOOP); //goleiro A interno ok
			glVertex2f(0.1, 1);
			glVertex2f(0.1, 0.9);
			glVertex2f(-0.1, 0.9);
			glVertex2f(-0.1, 1);
			glEnd();

			glBegin(GL_LINE_LOOP); //goleiro A meio circulo ok
			glVertex2f(-0.11, 0.7);
			glVertex2f(-0.07, 0.65);
			//glVertex2f(0, 0.5);
			glVertex2f(0.07, 0.65);
			glVertex2f(0.11, 0.7);
			glEnd();

			glBegin(GL_LINE_LOOP); //escanteios do time A ok
			glVertex2f(-1, 1);
			glVertex2f(-1, 0.9);
			//glVertex2f(-0.95, 0.95);
			glVertex2f(-0.9, 1);
			glEnd();

			glBegin(GL_LINE_LOOP); //escanteios do time A ok
			glVertex2f(1, 1);
			glVertex2f(1, 0.9);
			//glVertex2f(0.95, 0.95);
			glVertex2f(0.9, 1);
			glEnd();

			glBegin(GL_LINE_LOOP); //banco reserva B ok
			glVertex2f(1, -0.15);
			glVertex2f(1, -0.5);
			glVertex2f(1.1, -0.5);
			glVertex2f(1.1, -0.15);
			glEnd();

			glBegin(GL_LINE_LOOP); //torcida B ok
			glVertex2f(1.3, -0.1);
			glVertex2f(1.3, -0.9);
			glVertex2f(1.6, -0.9);
			glVertex2f(1.6, -0.1);
			glEnd();

			glBegin(GL_LINE_LOOP); //goleiro B ok
			glVertex2f(0.25, -1);
			glVertex2f(0.25, -0.7);
			glVertex2f(-0.25, -0.7);
			glVertex2f(-0.25, -1);
			glEnd();

			glBegin(GL_LINE_LOOP); //goleiro B interno ok
			glVertex2f(0.1, -1);
			glVertex2f(0.1, -0.9);
			glVertex2f(-0.1, -0.9);
			glVertex2f(-0.1, -1);
			glEnd();

			glBegin(GL_LINE_LOOP); //goleiro B meio circulo ok
			glVertex2f(-0.11, -0.7);
			glVertex2f(-0.07, -0.65);
			//glVertex2f(0, -0.5);
			glVertex2f(0.07, -0.65);
			glVertex2f(0.11, -0.7);
			glEnd();

			glBegin(GL_LINE_LOOP); //escanteios do time B ok
			glVertex2f(-1, -1);
			glVertex2f(-1, -0.9);
			//glVertex2f(-0.95, -0.95);
			glVertex2f(-0.9, -1);
			glEnd();

			glBegin(GL_LINE_LOOP); //escanteios do time B ok
			glVertex2f(1, -1);
			glVertex2f(1, -0.9);
			//glVertex2f(0.95, -0.95);
			glVertex2f(0.9, -1);
			glEnd();

			DrawCircle(0, 0, 0.02, 200);
			DrawCircle(0, 0, 0.15, 200);

			break;

		//Tennis
		case 3:
			glLineWidth(2);

			glColor3f(0.3, 0.6, 0.3);

			glBegin(GL_QUADS); //quadra toda ok
				glVertex2f(-2, 2);
				glVertex2f(-2, -2);
				glVertex2f(2, -2);
				glVertex2f(2, 2);
			glEnd();

			glColor3f(0.7, 0.3, 0.35);

			glBegin(GL_QUADS); //quadra toda ok
			glVertex2f(-1, 1);
			glVertex2f(-1, -1);
			glVertex2f(1, -1);
			glVertex2f(1, 1);
			glEnd();

			glColor3f(1, 1, 1);

			glBegin(GL_LINE_LOOP); //entrada ->escrever entrada 
			glVertex2f(1.6, 0.05);
			glVertex2f(1.6, -0.05);
			glEnd();

			glBegin(GL_LINE_LOOP); //linha que divide os times na quadra ok
			glVertex2f(-1, 0);
			glVertex2f(1, 0);
			glEnd();

			glBegin(GL_LINE_LOOP); //banco reserva A ok
			glVertex2f(1, 0.15);
			glVertex2f(1, 0.5);
			glVertex2f(1.1, 0.5);
			glVertex2f(1.1, 0.15);
			glEnd();

			glBegin(GL_LINE_LOOP); //banco reserva B ok
			glVertex2f(1, -0.15);
			glVertex2f(1, -0.5);
			glVertex2f(1.1, -0.5);
			glVertex2f(1.1, -0.15);
			glEnd();

			glBegin(GL_LINE_LOOP); //torcida A ok
			glVertex2f(1.3, 0.1);
			glVertex2f(1.3, 0.9);
			glVertex2f(1.6, 0.9);
			glVertex2f(1.6, 0.1);
			glEnd();

			glBegin(GL_LINE_LOOP); //torcida B ok
			glVertex2f(1.3, -0.1);
			glVertex2f(1.3, -0.9);
			glVertex2f(1.6, -0.9);
			glVertex2f(1.6, -0.1);
			glEnd();
			glBegin(GL_LINE_LOOP); //linha de distancia jogadores rede ok
			glVertex2f(-1, 0.2);
			glVertex2f(1, 0.2);
			glEnd();

			glBegin(GL_LINE_LOOP); //linha de distancia jogadores rede ok
			glVertex2f(-1, -0.2);
			glVertex2f(1, -0.2);
			glEnd();

			break;
	}
}
void Shape::DrawCampus()
{
	glLineWidth(2);

	glColor3f(1, 1, 1);
	glTranslatef(-1, 0.7, 0);
	glScalef(1.9, 1, 1);

	//Lab 6 - Base
	glBegin(GL_LINE_LOOP);
		glVertex2f(-0.1, 0.1);
		glVertex2f(-0.1, -0.1);
		glVertex2f(0.1, -0.1);
		glVertex2f(0.1, 0.1);
	glEnd();

	//Lab 7 - Base
	glBegin(GL_LINE_LOOP);
		glVertex2f(0.1, 0.1);
		glVertex2f(0.1, -0.1);
		glVertex2f(0.23, -0.1);
		glVertex2f(0.23, 0.1);
	glEnd();

	//Lab 8 - Base
	glBegin(GL_LINE_LOOP);
		glVertex2f(0.1, -0.55);
		glVertex2f(0.1, -0.1);
		glVertex2f(0.23, -0.1);
		glVertex2f(0.23, -0.55);
	glEnd();

	//Lab 5 - Base
	glBegin(GL_LINE_LOOP);
		glVertex2f(-0.1, -0.1);
		glVertex2f(0, -0.1);
		glVertex2f(0, -0.35);
		glVertex2f(-0.1, -0.35);
	glEnd();

	//Corridor - Base
	glBegin(GL_LINE_LOOP);
		glVertex2f(0, -0.1);
		glVertex2f(0.1, -0.1);
		glVertex2f(0.1, -0.9);
		glVertex2f(0, -0.9);
	glEnd();
}