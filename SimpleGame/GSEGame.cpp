#include "stdafx.h" 
#include "GSEGame.h"


GSEGame::GSEGame() //持失切
{
	//Renderer initialize
	m_renderer = new Renderer(500, 500);
}

GSEGame::~GSEGame() //社瑚切
{
	//Renderer delete
}

void GSEGame::RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);

	// Renderer Test
	m_renderer->DrawSolidRect(0, 0, 0, 4, 1, 0, 1, 1);

}

