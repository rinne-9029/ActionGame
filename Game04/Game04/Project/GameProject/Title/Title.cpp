#include "Title.h"
#include "../Game/Game.h"
#include "../Game/Manual.h"

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
		//�Q�[���V�[��
		Base::Add(new Game());
	}
	//�{�^���Q�Ń^�C�g����j��
	if (PUSH(CInput::eButton2)) {
		//�S�ẴI�u�W�F�N�g��j��
		Base::KillAll();
		//����
		Base::Add(new Manual());
		
	}
}

void Title::Draw(){
	m_img.Draw();
	//�����\��
	m_title_text.Draw(64, 256, 0, 0, 0, "Title");
	m_title_text.Draw(64, 512, 0, 0, 0, "Push Z");
	m_title_text.Draw(128, 600, 0, 0, 0, "Push X");
	m_title_text.Draw(128, 600, 0, 0, 0, "Push X");
	m_title_text.Draw(128, 600, 0, 0, 0, "Push X");
}
