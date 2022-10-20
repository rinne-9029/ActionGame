#pragma once
#include "../Base/Base.h"

class Enemy :public Base {
private:
	//���
	enum {
		eState_Idle,
		eState_Attack,
	};
	//��ԕϐ�
	int m_state;
	int Enemy_Type;
	CImage m_img;
	int m_cnt;
	int m_flip;
	//�e��Ԃł̋���
	void StateIdleA();
	void StateIdleB();
	void StateAttack();
public:
	Enemy(const CVector2D& pos,int enemy_type);
	void Update();
	void Draw();
	void Collision(Base* b);
};

