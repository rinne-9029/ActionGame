#include "GameOver.h"
#include "../Game/Game.h"
#include "Title.h"

GameOver::GameOver():Base(eType_GameOver), m_GameOver_text("C:\\Windows\\Fonts\\msgothic.ttc", 64) {
	m_img = COPY_RESOURCE("GameOver", CImage);
	SOUND("bgm")->Stop();
}

GameOver::~GameOver(){

}

void GameOver::Update(){
	//�{�^���P�ŃQ�[���I�[�o�[��ʂ�j��
	if (PUSH(CInput::eButton1)) {
		//�S�ẴI�u�W�F�N�g��j��
		Base::KillAll();
		//�^�C�g���V�[��
		Base::Add(new Title());
	}
}

void GameOver::Draw(){
	m_img.Draw();
	//�����\��
	m_GameOver_text.Draw(400, 200, 0, 0, 0, "");
}
