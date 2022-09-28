#pragma once
#include "../Base/Base.h"

class Enemy :public Base {
private:
	//ó‘Ô
	enum {
		eState_Idle,
		eState_Attack,
	};
	//ó‘Ô•Ï”
	int m_state;

	CImage m_img;
	int m_cnt;
	int m_flip;
	//Šeó‘Ô‚Å‚Ì‹““®
	void StateIdle();
	void StateAttack();
public:
	Enemy(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
};