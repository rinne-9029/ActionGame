#pragma once
#include"../Base/Base.h"

class ArrowTrap : public Base {
	CImage m_img;
	bool m_flip;
	int cnt;
public:
	ArrowTrap(const CVector2D& pos,bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);
};