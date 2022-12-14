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
	int Enemy_Type;
	CImage m_img;
	int m_cnt;
	int m_flip;
	//各状態での挙動
	void StateIdleA();
	void StateIdleB();
	void StateIdleC();
	void StateAttack();
public:
	Enemy(const CVector2D& pos,int enemy_type);
	void Update();
	void Draw();
	void Collision(Base* b);
};

