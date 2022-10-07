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
	m_title_text.Draw(64, 100, 0, 0, 0, "せつめい！");
	m_title_text.Draw(64, 180, 0, 0, 0, "あなたは水中での作業中に");
	m_title_text.Draw(64, 240, 0, 0, 0, "仲間とはぐれてしまった");
	m_title_text.Draw(64, 320, 0, 0, 0, "襲い掛かってくる敵やトラップを");
	m_title_text.Draw(64, 400, 0, 0, 0, "避けながら仲間のもとにたどり着け");
}
