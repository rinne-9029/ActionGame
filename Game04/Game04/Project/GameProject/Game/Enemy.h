#pragma once
#include "../Base/Base.h"

class Enemy :public Base {
private:
	//状態
	enum {
		eState_Idle,
		eState_Attack,
	};
	//状態変数
	int m_state;

	CImage m_img;
	int m_cnt;
	int m_flip;
	//各状態での挙動
	void StateIdle();
	void StateAttack();
public:
	Enemy(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
};

