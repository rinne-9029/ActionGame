#pragma once
#include "../Base/Base.h"

class Bullet : public Base {
	CImage m_img;
	float m_speed = 5;
public:
	Bullet(int type, const CVector2D& pos, float ang, float speed);
	void Update();
	void Draw();
	void Collision(Base* b);
};