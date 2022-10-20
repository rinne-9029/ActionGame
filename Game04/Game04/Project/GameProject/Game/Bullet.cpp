#include "Bullet.h"
#include "Map.h"
#include"Effect.h"

Bullet::Bullet(int type,const CVector2D& pos,float ang,float speed)
	:Base(type)
{
	if (type == eType_Player_Bullet) {
		m_img = COPY_RESOURCE("Bullet3", CImage);
	}
	else {
		m_img = COPY_RESOURCE("Bullet2", CImage);
	}

	m_pos = pos;
	m_img.SetCenter(10, 70);
	m_rect = CRect(-10, -10, 10, 10);
	m_img.SetSize(20, 80);
	m_ang = ang;
	m_speed = speed;
}

void Bullet::Update()
{

	m_pos_old = m_pos;
	m_vec = CVector2D(sin(m_ang), cos(m_ang)) * m_speed;
	m_pos += m_vec;
}

void Bullet::Draw()
{
	m_img.SetPos(m_pos);
	m_img.SetAng(m_ang);
	m_img.Draw();
	DrawRect();
}

void Bullet::Collision(Base* b)
{
	switch (b->m_type) {
	case eType_Field:
		if (Map* m = dynamic_cast<Map*>(b)) {
			int t = m->CollisionMap(m_pos);
			if (t != 1) {
				if (t == 3)
					m->SetTip(m_pos, 1);
				SetKill();
			}
		}
		break;
		case eType_Player:
			if (m_type == eType_Enemy_Bullet && Base::CollisionCircle(this, b)) {
				SetKill();
				b->SetKill();

			}
			break;
		case eType_Enemy:
			if (Base::CollisionCircle(this, b)) {
				SetKill();
				b->SetKill();
				Base::Add(new Effect(b->m_pos));
			}
			break;
		}
	}
