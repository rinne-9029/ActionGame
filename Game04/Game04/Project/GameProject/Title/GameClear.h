#pragma once

#include "../Base/Base.h"

class GameClear:public Base {
	//�摜�I�u�W�F�N�g
	CImage m_img;
	//�����\���I�u�W�F�N�g
	CFont m_GameClear_text;
public:
	GameClear();
	~GameClear ();
	void Update();
	void Draw();
};