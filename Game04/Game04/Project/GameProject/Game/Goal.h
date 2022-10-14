#pragma once
#include"../Base/Base.h"

class Goal :public Base {
private:
	//
	CImage m_img;
public:
	Goal(const CVector2D& pos);
	void Update();
	void Draw();

};
