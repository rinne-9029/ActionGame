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

	CImage m_img;
	int m_cnt;
	int m_flip;
	//�e��Ԃł̋���
	void StateIdle();
	void StateAttack();
public:
	Enemy(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
};