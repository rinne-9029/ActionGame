#include "Manual.h"
#include "../Title/Title.h"


Manual::Manual():Base(eType_Manual), m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 50) {
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
	//ボタン4で説明終了
	if (PUSH(CInput::eButton4)) {
		if(pull==true)SetKill();
	}
	else
		pull = true;
}

void Manual::Draw(){
	//画像表示
	m_img.Draw();
	//文字表示
	m_title_text.Draw(64, 100, 0, 0, 0, "あなたは水中の探索中に仲間とはぐれてしまった");
	m_title_text.Draw(64, 180, 0, 0, 0, "敵やトラップを避けながら仲間のもとにたどり着け");
	m_title_text.Draw(64, 250, 20, 30,50, "操作方法");
	m_title_text.Draw(64, 310, 20, 30, 50, "WASDキーで上下左右移動");
	m_title_text.Draw(64, 360, 20, 30, 50, "マウスの左クリックで弾の発射");
	m_title_text.Draw(400, 410, 50, 0, 0, "サメは倒すことができる！");
	m_title_text.Draw(800, 710, 20, 30,50, "タイトルに戻る　V");
}
