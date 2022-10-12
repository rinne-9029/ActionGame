#pragma once
#include "../Base/Base.h"

class Arrow : public Base {
	//�摜�I�u�W�F�N�g
	CImage m_img;
	//���]�t���O
	bool m_flip;
	//���x
	float m_speed;
public:
	Arrow(int type, const CVector2D& pos, float ang, float speed);
	void Update();
	void Draw();
	void Collision(Base* b);
};
