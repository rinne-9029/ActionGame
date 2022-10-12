#pragma once
#include"../Base/Base.h"

class Trap : public Base {
private:
	CImage m_img;
	int count;
	int x;
public:
	Trap(const CVector2D& pos );
	void Update();
	void Draw();
	void Collision(Base* b);
};
