#pragma once
#include "Renderer.h"
class GSEGame
{
public: //������ �Ҹ��ڴ� �ݵ�� public���� ����
	GSEGame();
	~GSEGame();
	void RenderScene();
private:
	Renderer* m_renderer = NULL;
};

