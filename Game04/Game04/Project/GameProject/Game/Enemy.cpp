#include "Enemy.h"
#include"Bullet.h"
#include"Map.h"


void Enemy::StateIdleA()
{//�ړ���
	const float move_speed = 2;
	//�ړ��t���O
	bool move_flag = false;
	//�v���C���[��T��
	Base* player = Base::FindObject(eType_Player);

	if (player) {
		//���ړ�
		if (player->m_pos.x < m_pos.x && player->m_pos.x > m_pos.x-200 && player->m_pos.y > m_pos.y - 200 && player->m_pos.y < m_pos.y + 200) {
			//�ړ��ʂ�ݒ�
			m_pos.x += -move_speed;
			//���]�t���O
			m_flip = true;
			move_flag = true;
		}
		//�E�ړ�
		if (player->m_pos.x > m_pos.x && player->m_pos.x<m_pos.x+200 && player->m_pos.y > m_pos.y - 200 && player->m_pos.y < m_pos.y + 200) {
			//�ړ��ʂ�ݒ�
			m_pos.x += move_speed;
			//���]�t���O
			m_flip = false;
			move_flag = true;
		}
		//���ړ�
		if (player->m_pos.y < m_pos.y && player->m_pos.y>m_pos.y - 200 && player->m_pos.x > m_pos.x - 200 && player->m_pos.x < m_pos.x + 200) {
			//�ړ��ʂ�ݒ�
			m_pos.y += -move_speed;
			//���]�t���O
			m_flip = true;
			move_flag = true;
		}
		//��ړ�
		if (player->m_pos.y > m_pos.y && player->m_pos.y<m_pos.y+200 && player->m_pos.x > m_pos.x - 200 && player->m_pos.x < m_pos.x + 200) {
			//�ړ��ʂ�ݒ�
			m_pos.y += move_speed;
			//���]�t���O
			m_flip = true;
			move_flag = true;
		}
	}

}

void Enemy::StateIdleB()
{//�ړ���
	const float move_speed = 10;
	//�ړ��t���O
	bool move_flag = false;
	//�v���C���[��T��
	Base* player = Base::FindObject(eType_Player);

	if (player) {
		//���ړ�
		if (player->m_pos.x < m_pos.x +32 && player->m_pos.y > m_pos.y -40 && player->m_pos.y < m_pos.y + 40) {
			//�ړ��ʂ�ݒ�
			m_pos.x += -move_speed;
			//���]�t���O
			m_flip = true;
			move_flag = true;
		}
		//�E�ړ�
		if (player->m_pos.x > m_pos.x +32 && player->m_pos.y > m_pos.y -40 && player->m_pos.y < m_pos.y +40 ) {
			//�ړ��ʂ�ݒ�
			m_pos.x += move_speed;
			//���]�t���O
			m_flip = false;
			move_flag = true;
		}
		//���ړ�
	/*	if (player->m_pos.y < m_pos.y && player->m_pos.y>m_pos.y - 200 && player->m_pos.x > m_pos.x - 200 && player->m_pos.x < m_pos.x + 200) {
			//�ړ��ʂ�ݒ�
			m_pos.y += -move_speed;
			//���]�t���O
			m_flip = true;
			move_flag = true;
		}
		//��ړ�
		if (player->m_pos.y > m_pos.y && player->m_pos.y<m_pos.y + 200 && player->m_pos.x > m_pos.x - 200 && player->m_pos.x < m_pos.x + 200) {
			//�ړ��ʂ�ݒ�
			m_pos.y += move_speed;
			//���]�t���O
			m_flip = true;
			move_flag = true;
		}*/
	}

}

void Enemy::StateIdleC(){
	//�ړ���
	const float move_speed = 2;
	//�ړ��t���O
	bool move_flag = false;
	//�v���C���[��T��
	Base* player = Base::FindObject(eType_Player);

	if (player) {
		//���ړ�
		if (player->m_pos.x < m_pos.x && player->m_pos.x > m_pos.x - 200 && player->m_pos.y > m_pos.y - 200 && player->m_pos.y < m_pos.y + 200) {
			//�ړ��ʂ�ݒ�
			m_pos.x += -move_speed;
			//���]�t���O
			m_flip = true;
			move_flag = true;
		}
		//�E�ړ�
		if (player->m_pos.x > m_pos.x && player->m_pos.x<m_pos.x + 200 && player->m_pos.y > m_pos.y - 200 && player->m_pos.y < m_pos.y + 200) {
			//�ړ��ʂ�ݒ�
			m_pos.x += move_speed;
			//���]�t���O
			m_flip = false;
			move_flag = true;
		}
		//���ړ�
		if (player->m_pos.y < m_pos.y && player->m_pos.y>m_pos.y - 200 && player->m_pos.x > m_pos.x - 200 && player->m_pos.x < m_pos.x + 200) {
			//�ړ��ʂ�ݒ�
			m_pos.y += -move_speed;
			//���]�t���O
			m_flip = true;
			move_flag = true;
		}
		//��ړ�
		if (player->m_pos.y > m_pos.y && player->m_pos.y<m_pos.y + 200 && player->m_pos.x > m_pos.x - 200 && player->m_pos.x < m_pos.x + 200) {
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

Enemy::Enemy(const CVector2D& pos,int enemy_type)
	:Base(eType_Enemy)
{
	Enemy_Type = enemy_type;
	if(Enemy_Type==0)
		m_img = COPY_RESOURCE("Enemy", CImage);
	else if (Enemy_Type == 1)
		m_img = COPY_RESOURCE("Enemy2", CImage);
	else
		m_img = COPY_RESOURCE("Enemy3", CImage);
	m_pos = pos;
	m_pos_old = pos;
	//�傫��
	m_img.SetSize(64, 64);
	//���S��ݒ�
	m_img.SetCenter(32, 32);
	//��`�����蔻��
	m_rect = CRect(-24, -24, 24, 24);
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
		if(Enemy_Type==0)
			StateIdleA();
		else if (Enemy_Type == 1)
			StateIdleB();
		else
			StateIdleC();
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
	//DrawRect();
}

void Enemy::Collision(Base* b)
{
	switch (b->m_type) {
	case eType_Field:
		if (Map* m = dynamic_cast<Map*>(b)) {
			int t = m->CollisionMap((CVector2D(m_pos.x, m_pos_old.y)),m_rect);
			if (t != 1)
				m_pos.x = m_pos_old.x;
			t = m->CollisionMap((CVector2D(m_pos_old.x, m_pos.y)),m_rect);
			if (t != 1)
				m_pos.y = m_pos_old.y;

		}
		break;
	
	}

}


