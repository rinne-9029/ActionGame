#include "Trap.h"
#include"Game.h"

static TexAnim _Trap[] = {
	//�p�^�[���A���x
	{0,2},
	{1,2},
	{2,2},
	{3,2},
	{4,2},
	{5,2},
	{6,2},
	{7,2},
	{8,2},
	{9,2},
	{10,6},
	{11,6},
	{12,6},
	{13,30},
};

TexAnimData trapAnimData[] = {
	ANIMDATA(_Trap),
};

Trap::Trap(const CVector2D& pos):
	Base(eType_Trap)
{
	m_img.Load("Image/Trap.png", trapAnimData, 64, 64);
	//���W�ݒ�
	m_pos = pos;
	m_pos_old = pos;
	//�Đ��A�j���[�V�����ݒ�
	m_img.ChangeAnimation(0);
	//�傫��
	m_img.SetSize(64, 128);
	//���S�ݒ�
	m_img.SetCenter(32, 0);
	x = 1;
	count = 0;

}

void Trap::Update()
{
	//�A�j���[�V�����X�V
	m_img.UpdateAnimation();
	//��`����ݒ�
	m_rect = CRect(-18, 21*(x-1), 18, 21*x);
	count++;
	switch (count) {
	case 2:
		x = 6;
		break;
	case 8:
		x = 5;
		break;
	case 10:
		x = 4;
		break;
	case 12:
		x = 3;
		break;
	case 14:
		x = 2;
		break;
	case 16:
		x = 1;
		break;
	}
	if (count >= 68)
		count = 0;
	
}

void Trap::Draw()
{
	m_img.SetPos(m_pos);
	m_img.Draw();
	DrawRect();
	
}

void Trap::Collision(Base* b)
{

	}

static TexAnim _ArrowTrap[] = {
	//�p�^�[���A���x
	{0,2},
	{1,2},
	{2,2},
	{3,2},
	{4,2},
	{5,2},
	{6,2},
	{7,2},
	{8,2},
	{9,2},
	{10,2},
	{11,2},
	{12,2},
	{13,2},
	{14,2},
	{15,2},
	{16,2},
};

TexAnimData arrowtrapAnimData[] = {
	ANIMDATA(_ArrowTrap),
};

Trap2::Trap2(const CVector2D& pos):
	Base(eType_Trap2)
{
	m_img.Load("Image/Arrow Trap.png", trapAnimData, 96, 32);
	m_pos = pos;
	m_pos_old = pos;
	//���S��ݒ�
	m_img.SetCenter(16, 16);
	//�����蔻��p��`�ݒ�
	m_rect = CRect(-15, -15, 20, 20);
}

void Trap2::Update()
{
	//�A�j���[�V�����X�V
	m_img.UpdateAnimation();
}

void Trap2::Draw()
{
	m_img.SetPos(m_pos);
	m_img.Draw();
	DrawRect();
}

void Trap2::Collision(Base* b)
{
}
