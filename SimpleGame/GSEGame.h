#pragma once
#include "Renderer.h"
class GSEGame
{
public: //생성자 소멸자는 반드시 public으로 설정
	GSEGame();
	~GSEGame();
	void RenderScene();
private:
	Renderer* m_renderer = NULL;
};

