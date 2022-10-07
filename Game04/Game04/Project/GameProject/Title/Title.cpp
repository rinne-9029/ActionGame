#include "Title.h"
#include "../Game/Game.h"
#include "../Game/Manual.h"

Title::Title() :Base(eType_Scene),m_title_text("C:\\Windows\\Fonts\\msgothic.ttc",64){
	m_img = COPY_RESOURCE("Title", CImage);
}

Title::~Title(){

}

void Title::Update(){
	//ボタン１でタイトルを破棄
	if (PUSH(CInput::eButton1)) {
		//全てのオブジェクトを破棄
		Base::KillAll();
		//ゲームシーン
		Base::Add(new Game());
	}
	//ボタン２でタイトルを破棄
	if (PUSH(CInput::eButton2)) {
		//全てのオブジェクトを破棄
		Base::KillAll();
		//説明
		Base::Add(new Manual());
		
	}
}

void Title::Draw(){
	m_img.Draw();
	//文字表示
	m_title_text.Draw(400, 200, 0, 0, 0, "Title");
	m_title_text.Draw(800, 600, 0, 0, 0, "Push Z");
	m_title_text.Draw(200, 600, 0, 0, 0, "Push X");
	m_title_text.Draw(200, 450, 0, 0, 0, "説明");
	m_title_text.Draw(700, 450, 0, 0, 0, "ゲームスタート！");
}
