#include "Enemy.h"
#include"Bullet.h"
#include"Map.h"

void Enemy::StateIdle()
{//移動量
	const float move_speed = 2;
	//移動フラグ
	bool move_flag = false;
	//プレイヤーを探索
	Base* player = Base::FindObject(eType_Player);

	if (player) {
		//左移動
		if (player->m_pos.x < m_pos.x && player->m_pos.x > m_pos.x-100 && player->m_pos.y > m_pos.y - 100 && player->m_pos.y < m_pos.y + 100) {
			//移動量を設定
			m_pos.x += -move_speed;
			//反転フラグ
			m_flip = true;
			move_flag = true;
		}
		//右移動
		if (player->m_pos.x > m_pos.x && player->m_pos.x<m_pos.x+100 && player->m_pos.y > m_pos.y - 100 && player->m_pos.y < m_pos.y + 100) {
			//移動量を設定
			m_pos.x += move_speed;
			//反転フラグ
			m_flip = false;
			move_flag = true;
		}
		//下移動
		if (player->m_pos.y < m_pos.y && player->m_pos.y>m_pos.y-100 && player->m_pos.x > m_pos.x - 100 && player->m_pos.x < m_pos.x + 100) {
			//移動量を設定
			m_pos.y += -move_speed;
			//反転フラグ
			m_flip = true;
			move_flag = true;
		}
		//上移動
		if (player->m_pos.y > m_pos.y && player->m_pos.y<m_pos.y+100 && player->m_pos.x > m_pos.x - 100 && player->m_pos.x < m_pos.x + 100) {
			//移動量を設定
			m_pos.y += move_speed;
			//反転フラグ
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
	//大きさ
	m_img.SetSize(64, 64);
	//中心を設定
	m_img.SetCenter(32, 32);
	//矩形当たり判定
	m_rect = CRect(-32, -32, 32, 32);
	//半径
	m_rad = 32;
	//通常状態へ
	m_state = eState_Idle;
}

void Enemy::Update()
{
	m_pos_old = m_pos;
	/*//カウントアップ
	m_cnt++;
	//プレイヤーを取得
	Base* b = Base::FindObject(eType_Player);
	//プレイヤーが居れば
	if (b) {
		//ターゲットへのベクトル
		CVector2D vec = b->m_pos - m_pos;
		m_ang = atan2(vec.x, vec.y);
		if (m_cnt >= 120) {
			Base::Add(new Bullet(eType_Enemy_Bullet, m_pos, m_ang,4));
			m_cnt = 0;
		}
	}*/
	switch (m_state) {
		//通常状態
	case eState_Idle:
		StateIdle();
		break;
		//攻撃状態
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
