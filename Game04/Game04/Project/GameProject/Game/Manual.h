#pragma once
#include "../Base/Base.h"

class Manual : public Base{
	//�摜�I�u�W�F�N�g
	CImage m_img;
	//�����\���I�u�W�F�N�g
	CFont m_title_text;
public:
	Manual();
	~Manual();
	void Update();
	void Draw();
	bool pull;
};