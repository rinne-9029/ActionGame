#pragma once
#include "../Base/Base.h"

class Player :public Base {
	CImage m_img;
	bool m_flip;
	int m_count;
public:
	Player(const CVector2D& pos,bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);
};