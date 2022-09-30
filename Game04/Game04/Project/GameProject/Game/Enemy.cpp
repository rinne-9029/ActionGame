#include "Enemy.h"
#include"Bullet.h"
#include"Map.h"

void Enemy::StateIdle()
{//�ړ���
	const float move_speed = 2;
	//�ړ��t���O
	bool move_flag = false;
	//�v���C���[��T��
	Base* player = Base::FindObject(eType_Player);

	if (player) {
		//���ړ�
		if (player->m_pos.x < m_pos.x && player->m_pos.x > m_pos.x-100 && player->m_pos.y > m_pos.y - 100 && player->m_pos.y < m_pos.y + 100) {
			//�ړ��ʂ�ݒ�
			m_pos.x += -move_speed;
			//���]�t���O
			m_flip = true;
			move_flag = true;
		}
		//�E�ړ�
		if (player->m_pos.x > m_pos.x && player->m_pos.x<m_pos.x+100 && player->m_pos.y > m_pos.y - 100 && player->m_pos.y < m_pos.y + 100) {
			//�ړ��ʂ�ݒ�
			m_pos.x += move_speed;
			//���]�t���O
			m_flip = false;
			move_flag = true;
		}
		//���ړ�
		if (player->m_pos.y < m_pos.y && player->m_pos.y>m_pos.y-100 && player->m_pos.x > m_pos.x - 100 && player->m_pos.x < m_pos.x + 100) {
			//�ړ��ʂ�ݒ�
			m_pos.y += -move_speed;
			//���]�t���O
			m_flip = true;
			move_flag = true;
		}
		//��ړ�
		if (player->m_pos.y > m_pos.y && player->m_pos.y<m_pos.y+100 && player->m_pos.x > m_pos.x - 100 && player->m_pos.x < m_pos.x + 100) {
			//�ړ��ʂ�ݒ�
			m_pos.y += move_speed;
			//���]�t���O
			m_flip = true;
			move_flag = true;
		}
	}

}

void Enemy::StateAttack()
{
}

Enemy::Enemy(const CVector2D& pos)
	:Base(eType_Enemy)
{
	m_img = COPY_RESOURCE("Enemy", CImage);
	m_pos = pos;
	//�傫��
	m_img.SetSize(64, 64);
	//���S��ݒ�
	m_img.SetCenter(32, 32);
	//��`�����蔻��
	m_rect = CRect(-32, -32, 32, 32);
	//���a
	m_rad = 32;
	//�ʏ��Ԃ�
	m_state = eState_Idle;
}

void Enemy::Update()
{
	m_pos_old = m_pos;
	/*//�J�E���g�A�b�v
	m_cnt++;
	//�v���C���[���擾
	Base* b = Base::FindObject(eType_Player);
	//�v���C���[�������
	if (b) {
		//�^�[�Q�b�g�ւ̃x�N�g��
		CVector2D vec = b->m_pos - m_pos;
		m_ang = atan2(vec.x, vec.y);
		if (m_cnt >= 120) {
			Base::Add(new Bullet(eType_Enemy_Bullet, m_pos, m_ang,4));
			m_cnt = 0;
		}
	}*/
	switch (m_state) {
		//�ʏ���
	case eState_Idle:
		StateIdle();
		break;
		//�U�����
	case eState_Attack:
		StateAttack();
		break;
	}
}

void Enemy::Draw()
{
	m_img.SetPos(m_pos);
	m_img.Draw();
	DrawRect();
}

void Enemy::Collision(Base* b)
{
	switch (b->m_type) {
	case eType_Field:
		if (Map* m = dynamic_cast<Map*>(b)) {
			int t = m->CollisionMap((CVector2D(m_pos.x, m_pos_old.y)),m_rect);
			if (t != 2)
				m_pos.x = m_pos_old.x;
			t = m->CollisionMap((CVector2D(m_pos_old.x, m_pos.y)),m_rect);
			if (t != 2)
				m_pos.y = m_pos_old.y;

		}
		break;

	}

}
