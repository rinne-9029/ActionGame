#include "Manual.h"
#include "../Title/Title.h"


Manual::Manual():Base(eType_Manual), m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 50) {
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
	//�{�^��4�Ő����I��
	if (PUSH(CInput::eButton4)) {
		if(pull==true)SetKill();
	}
	else
		pull = true;
}

void Manual::Draw(){
	//�摜�\��
	m_img.Draw();
	//�����\��
	m_title_text.Draw(64, 100, 0, 0, 0, "���Ȃ��͐����̒T�����ɒ��ԂƂ͂���Ă��܂���");
	m_title_text.Draw(64, 180, 0, 0, 0, "�G��g���b�v������Ȃ��璇�Ԃ̂��Ƃɂ��ǂ蒅��");
	m_title_text.Draw(64, 250, 20, 30,50, "������@");
	m_title_text.Draw(64, 310, 20, 30, 50, "WASD�L�[�ŏ㉺���E�ړ�");
	m_title_text.Draw(64, 360, 20, 30, 50, "�}�E�X�̍��N���b�N�Œe�̔���");
	m_title_text.Draw(400, 410, 50, 0, 0, "�T���͓|�����Ƃ��ł���I");
	m_title_text.Draw(800, 710, 20, 30,50, "�^�C�g���ɖ߂�@V");
}
