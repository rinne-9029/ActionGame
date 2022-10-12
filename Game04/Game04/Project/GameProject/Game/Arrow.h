#pragma once
#include "../Base/Base.h"

class Arrow : public Base {
	//画像オブジェクト
	CImage m_img;
	//反転フラグ
	bool m_flip;
	//速度
	float m_speed;
public:
	Arrow(int type, const CVector2D& pos, float ang, float speed);
	void Update();
	void Draw();
	void Collision(Base* b);
};
