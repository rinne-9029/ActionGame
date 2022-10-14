#include "Player.h"
#include "Bullet.h"
#include"Map.h"
#include"Trap.h"
Player::Player(const CVector2D& pos, bool flip)
	:Base(eType_Player)
{
	m_img = COPY_RESOURCE("Player", CImage);
	m_pos = pos;
	m_pos_old = pos;
	//���S��ݒ�
	m_img.SetCenter(32.5,14);
	//��`��ݒ�
	m_rect = CRect(-32.5,-14,32.5, 14);
	m_img.SetSize(65,28);
	//���a
	m_rad = 16;
	m_count = 0;

}

void Player::Update()
{
	m_pos_old = m_pos;
	const float speed = 4;
	//���Ɉړ�
	if (HOLD(CInput::eLeft)) {
		m_pos.x -= speed;
	}
	//�E�Ɉړ�
	if (HOLD(CInput::eRight)) {
		m_pos.x += speed;
	}
	//��Ɉړ�
	if (HOLD(CInput::eUp)) {
		m_pos.y -= speed;
	}
	//���Ɉړ�
	if (HOLD(CInput::eDown)) {
		m_pos.y += speed;
	}
	//�}�E�X�ւ̃x�N�g��
	CVector2D vec = CInput::GetMousePoint() - m_pos;
	//��]�l���t�Z
	m_ang = atan2(vec.x,vec.y);

	if (m_count<5&&PUSH(CInput::eMouseL)) {
		Base::Add(new Bullet(eType_Player_Bullet, m_pos, m_ang, 4));
		m_count++;
		
		
	}


	
}

void Player::Draw()
{
	m_img.SetPos(m_pos);
	//m_img.SetAng(m_ang);
	m_img.Draw();
	DrawRect();
}

void Player::Collision(Base* b)
{
	switch (b->m_type) {
		case eType_Field:
			if (Map* m = dynamic_cast<Map*>(b)) {
				int t = m->CollisionMap(CVector2D(m_pos.x,m_pos_old.y),m_rect);
				if (t != 1)
					m_pos.x = m_pos_old.x;
			/*	t = m->CollisionMap(CVector2D(m_pos_old.x, m_pos.y), m_rect);
				if (t != 1)
					m_pos.y = m_pos_old.y;*/
			}
			break;
			//�S�[���� ��	case eType_Goal:
		if (Base::CollisionRect(this, b)) {
			b->SetKill();
		}
		break;
	case eType_Enemy:
		if (Base::CollisionRect(this, b)) {
			SetKill();
		}
		break;
	case eType_Trap:
		if (Base::CollisionRect(this, b)) {
			SetKill();
		}
		break;
	}
 
}

		//�g���b�v�ɓ�����������
	/*case  eType_Trap:
		if (Trap* s = dynamic_cast<Trap*>(b)) {
			if (Base::CollisionRect(this, s) {
				SetKill();
			}
			break;
		}*/