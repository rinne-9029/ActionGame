#include "Title.h"
#include "../Game/Game.h"
#include "../Game/Manual.h"
#include "../Game/Map.h"
#include"../Game/GameData.h"

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
		GameData::stage = 1;
		//ゲームシーン
		Base::Add(new Game());
	}
	//ボタン3でタイトルを破棄
	if (PUSH(CInput::eButton2)) {
		//全てのオブジェクトを 破棄
		Base::KillAll();
		GameData::stage = 2;
		//ゲームシーン
		Base::Add(new Game());
	}
	//ボタン4でタイトルを破棄
	if (PUSH(CInput::eButton3)) {
		//全てのオブジェクトを破棄
		Base::KillAll();
		GameData::stage = 3;
		//ゲームシーン
		Base::Add(new Game());
	}
	//ボタン２でタイトルを破棄
	if (PUSH(CInput::eButton4)) {
		//全てのオブジェクトを破棄
		Base::KillAll();
		//説明
		Base::Add(new Manual());
		
	}
	
	

	
}

void Title::Draw(){
	m_img.Draw();
	//文字表示
	m_title_text.Draw(200, 100, 0, 0, 0, "Title");
	m_title_text.Draw(700, 400, 0, 50, 0, "ステージ１ Zキー");
	m_title_text.Draw(700, 500, 20, 0, 50, "ステージ２ Xキー");
	m_title_text.Draw(700, 600, 50, 0, 0, "ステージ３ Cキー");
	m_title_text.Draw(200, 500, 0, 0, 0, "Vキー");
	m_title_text.Draw(200, 400, 0, 0, 0, "説明");
	m_title_text.Draw(700, 300, 0, 0, 0, "ゲームスタート！");
}
