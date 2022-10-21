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
	//�{�^���P�Ń^�C�g����j��
	if (PUSH(CInput::eButton1)) {
		//�S�ẴI�u�W�F�N�g��j��
		Base::KillAll();
		GameData::stage = 1;
		//�Q�[���V�[��
		Base::Add(new Game());
	}
	//�{�^��3�Ń^�C�g����j��
	if (PUSH(CInput::eButton2)) {
		//�S�ẴI�u�W�F�N�g�� �j��
		Base::KillAll();
		GameData::stage = 2;
		//�Q�[���V�[��
		Base::Add(new Game());
	}
	//�{�^��4�Ń^�C�g����j��
	if (PUSH(CInput::eButton3)) {
		//�S�ẴI�u�W�F�N�g��j��
		Base::KillAll();
		GameData::stage = 3;
		//�Q�[���V�[��
		Base::Add(new Game());
	}
	//�{�^���Q�Ń^�C�g����j��
	if (PUSH(CInput::eButton4)) {
		//�S�ẴI�u�W�F�N�g��j��
		Base::KillAll();
		//����
		Base::Add(new Manual());
		
	}
	
	

	
}

void Title::Draw(){
	m_img.Draw();
	//�����\��
	m_title_text.Draw(200, 100, 0, 0, 0, "Title");
	m_title_text.Draw(700, 400, 0, 50, 0, "�X�e�[�W�P Z�L�[");
	m_title_text.Draw(700, 500, 20, 0, 50, "�X�e�[�W�Q X�L�[");
	m_title_text.Draw(700, 600, 50, 0, 0, "�X�e�[�W�R C�L�[");
	m_title_text.Draw(200, 500, 0, 0, 0, "V�L�[");
	m_title_text.Draw(200, 400, 0, 0, 0, "����");
	m_title_text.Draw(700, 300, 0, 0, 0, "�Q�[���X�^�[�g�I");
}
