#pragma once

#include "../Base/Base.h"

class GameOver :public Base {
	//�摜�I�u�W�F�N�g
	CImage m_img;
	//�����\���I�u�W�F�N�g
	CFont m_GameOver_text;
public:
	GameOver();
	~GameOver();
	void Update();
	void Draw();
};