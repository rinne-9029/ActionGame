#include "Manual.h"
#include "../Title/Title.h"


Manual::Manual():Base(eType_Manual), m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64) {
	m_img = COPY_RESOURCE("Manual", CImage);
	pull = false;
}

Manual::~Manual(){
	//�S�ẴI�u�W�F�N�g��j��
	Base::KillAll();
	//�^�C�g���V�[����
	Base::Add(new Title());
}

void Manual::Update(){
	//�{�^���Q�Ő����I��
	if (PUSH(CInput::eButton2)) {
		if(pull==true)SetKill();
	}
	else
		pull = true;
}

void Manual::Draw(){
	//�摜�\��
	m_img.Draw();
	//�����\��
	m_title_text.Draw(64, 100, 0, 0, 0, "���߂��I");
	m_title_text.Draw(64, 180, 0, 0, 0, "���Ȃ��͐����ł̍�ƒ���");
	m_title_text.Draw(64, 240, 0, 0, 0, "���ԂƂ͂���Ă��܂���");
	m_title_text.Draw(64, 320, 0, 0, 0, "�P���|�����Ă���G��g���b�v��");
	m_title_text.Draw(64, 400, 0, 0, 0, "�����Ȃ��璇�Ԃ̂��Ƃɂ��ǂ蒅��");
}
