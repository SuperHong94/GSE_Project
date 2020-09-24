/*
Copyright 2020 Lee Taek Hee (Korea Polytech University)

This program is free software: you can redistribute it and/or modify
it under the terms of the What The Hell License. Do it plz.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY.
*/

#include "stdafx.h"
#include <iostream>
#include "Dependencies\glew.h"
#include "Dependencies\freeglut.h"
#include "GSEGame.h"

GSEGame* g_game = NULL;
int g_prevTimeInMillisecond = 0;

int X= 0;
int Y = 0;
void RenderScene(int temp)
{
	int currentTime = glutGet(GLUT_ELAPSED_TIME);
	int elapsedTime = currentTime-g_prevTimeInMillisecond;
	g_prevTimeInMillisecond = currentTime;

	g_game->RenderScene();

	glutSwapBuffers(); //double buffering, front->back, back front 

	glutTimerFunc(16, RenderScene, 16);
}

void Idle(void)
{
}

void MouseInput(int button, int state, int x, int y)
{
}

void KeyDownInput(unsigned char key, int x, int y)
{
	if (key == 'a') X--;
	if (key == 'd') X++;
	if (key == 'w') Y++;
	if (key == 's') Y--;
}

void KeyUpInput(unsigned char key, int x, int y)
{
}

void SpecialKeyDownInput(int key, int x, int y)
{
}

void SpecialKeyUpInput(int key, int x, int y)
{
}

int main(int argc, char **argv)
{
	// Initialize GL things
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0); //���۽� ������ �»�� ��ġ
	glutInitWindowSize(500, 500); //������ âũ��
	glutCreateWindow("Game Software Engineering KPU");

	glewInit();
	if (glewIsSupported("GL_VERSION_3_0"))
	{
		std::cout << " GLEW Version is 3.0\n ";
	}
	else
	{
		std::cout << "GLEW 3.0 not supported\n ";
	}

	// Initialize GSEGame

	g_game = new GSEGame();
	glutDisplayFunc(Idle); //������ �������� ���÷��� ������Ʈ
	glutIdleFunc(Idle); //Idle����
	glutKeyboardFunc(KeyDownInput);
	glutKeyboardUpFunc(KeyUpInput);
	glutMouseFunc(MouseInput);
	glutSpecialFunc(SpecialKeyDownInput);
	glutSpecialUpFunc(SpecialKeyUpInput);

	g_prevTimeInMillisecond = glutGet(GLUT_ELAPSED_TIME); //�� ����ð� ���� �ɸ��ð�

	glutTimerFunc(16, RenderScene, 16);

	glutMainLoop(); //escape Ű �Ǵ� â������ ���� ��������

	delete g_game;
    return 0;
}

