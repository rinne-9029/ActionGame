#include "Trap.h"
#include"AnimData.h"

Trap::Trap(const CVector2D& pos):
	Base(eType_Trap)
{
	//�摜����
	m_img = COPY_RESOURCE("Trap", CImage);
	//���W�ݒ�
	m_pos = pos;
	//�Đ��A�j���[�V�����ݒ�
	m_img.ChangeAnimation(0);

}

void Trap::Updata()
{
	//�A�j���[�V�����X�V
	m_img.UpdateAnimation();
}

void Trap::Draw()
{
	m_img.Draw();
}

void Trap::Collision(Base* b)
{
}
