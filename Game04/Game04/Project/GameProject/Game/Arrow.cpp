#include "Arrow.h"
#include "Map.h"

Arrow::Arrow(int type, const CVector2D& pos, float ang, float speed)
	:Base(eType_Arrow)
{
    m_img = COPY_RESOURCE("Bullet", CImage);

	m_pos = pos;


	m_img.SetCenter(16,16);
	m_rect = CRect(-16, -16, 16, 16);
	m_ang = ang;	m_speed = speed;
}

void Arrow::Update()
{
	m_pos_old = m_pos;
	m_vec = CVector2D(sin(m_ang), cos(m_ang)) * m_speed;
	m_pos += m_vec;
}

void Arrow::Draw()
{
	m_img.SetPos(m_pos);
	m_img.SetAng(m_ang);
	m_img.Draw();
	DrawRect();
}

void Arrow::Collision(Base* b)
{
	switch (b->m_type) {
		case eType_Field:
			if (Map* m = dynamic_cast<Map*>(b)) {
				int t = m->CollisionMap(m_pos);
				if (t != 1) {
					m_pos = m_pos_old;
					SetKill();
				}
			}
			break;
		/*case eType_Player:
			if (m_type == eType_Enemy_Bullet && Base::CollisionCircle(this, b)) {
				SetKill();
				b->SetKill();

			}
			break;*/
	case eType_Enemy:
		if (Base::CollisionCircle(this, b)) {
			SetKill();
			b->SetKill();
		}
		break;
	case eType_Player:
		if (Base::CollisionCircle(this, b)) {
			SetKill();
			b->SetKill();
		}
		break;
	}
}