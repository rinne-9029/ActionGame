#include "GameClear.h"
#include "../Game/Game.h"
#include "Title.h"

GameClear::GameClear():Base(eType_GameClear), m_GameClear_text("C:\\Windows\\Fonts\\msgothic.ttc", 64) {
	m_img = COPY_RESOURCE("GameClear", CImage);
}

GameClear::~GameClear(){

}

void GameClear::Update(){
	//�{�^���P�ŃN���A��ʂ�j��
	if (PUSH(CInput::eButton1)) {
		//�S�ẴI�u�W�F�N�g��j��
		Base::KillAll();
		//�^�C�g���V�[��
		Base::Add(new Title ());
	}
}

void GameClear::Draw(){
	m_img.Draw();
	//�����\��
	m_GameClear_text.Draw(400, 200, 0, 0, 0, "Title");
}
