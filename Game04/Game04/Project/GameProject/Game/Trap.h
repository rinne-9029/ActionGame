#pragma once
#include"../Base/Base.h"

class Trap : public Base {
private:
	CImage m_img;
	//UŒ‚”Ô†
	int count;
	int x;
public:
	Trap(const CVector2D& pos );
	void Update();
	void Draw();
	void Collision(Base* b);
};

class Trap2 : public Base{
	CImage m_img;
	//UŒ‚”Ô†
	int m_attack_no;
public:
	Trap2(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
};