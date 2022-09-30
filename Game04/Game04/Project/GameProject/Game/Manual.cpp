#include "Manual.h"
#include "../Title/Title.h"


Manual::Manual():Base(eType_Manual), m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64) {
	m_img = COPY_RESOURCE("Manual", CImage);
	pull = false;
}

Manual::~Manual(){
	//全てのオブジェクトを破棄
	Base::KillAll();
	//タイトルシーンへ
	Base::Add(new Title());
}

void Manual::Update(){
	//ボタン２で説明終了
	if (PUSH(CInput::eButton2)) {
		if(pull==true)SetKill();
	}
	else
		pull = true;
}

void Manual::Draw(){
	//画像表示
	m_img.Draw();
	//文字表示
	m_title_text.Draw(64, 256, 0, 0, 0, "せつめい！");
}
