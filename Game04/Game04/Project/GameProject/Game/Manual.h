#pragma once
#include "../Base/Base.h"

class Manual : public Base{
	//画像オブジェクト
	CImage m_img;
	//文字表示オブジェクト
	CFont m_title_text;
public:
	Manual();
	~Manual();
	void Update();
	void Draw();
	bool pull;
};