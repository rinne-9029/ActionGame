#pragma once
#include"../Base/Base.h"

class Trap : public Base {
	CImage m_img;
public:
	Trap(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);

};