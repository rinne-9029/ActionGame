#include "ArrowTrap.h"
#include"Arrow.h"
#include"Game.h"

static TexAnim _ArrowTrap[] = {
	//パターン、速度
	{0,60},
	{1,3},
	{2,3},
	{3,3},
	{4,3},
	{5,3},
	{6,3},
	{7,3},
	{8,8},
	{10,8},
	{11,8},
	{12,3},
	{13,3},
	{14,3},
	{15,3},
	{16,60},
};

TexAnimData arrowtrapAnimData[] = {
	ANIMDATA(_ArrowTrap),
};

ArrowTrap::ArrowTrap(const CVector2D& pos,bool flip) :
	Base(eType_ArrowTrap)
{
	m_img.Load("Image/Arrow Trap.png", arrowtrapAnimData, 96, 32);
	m_pos = pos;
	m_pos_old = pos;
	//中心を設定
	m_img.SetCenter(64, 0);
    //再生アニメーション設定
	m_img.ChangeAnimation(0,true);
	//当たり判定用矩形設定
	m_rect = CRect(-30, 12, 5, 30);
	//反転フラグ
	m_flip = flip;
}

void ArrowTrap::Update()
{

	//プレイヤーを探索
	Base* player = Base::FindObject(eType_Player);
	//左発射
	if (player) {
		if (player->m_pos.x < m_pos.x && player->m_pos.x > m_pos.x - 250 && player->m_pos.y > m_pos.y - 250 && player->m_pos.y < m_pos.y + 250) {
			cnt++;
			m_img.UpdateAnimation();
			m_flip = false;
			CVector2D vec = player->m_pos - m_pos;
			m_ang = atan2(vec.x, vec.y);
			switch (cnt) {
			case 89:
				Base::Add(new Arrow(eType_Arrow, m_pos, m_ang, 4));
				break;
			case 177:
				cnt = 0;
				break;
			}
		}
		//右発射
		if (player->m_pos.x > m_pos.x && player->m_pos.x<m_pos.x + 250 && player->m_pos.y > m_pos.y - 250 && player->m_pos.y < m_pos.y + 250) {
			cnt++;
			m_img.UpdateAnimation();
			m_flip = true;
			CVector2D vec = player->m_pos - m_pos;
			m_ang = atan2(vec.x, vec.y);
			switch (cnt) {
			case 89:
				Base::Add(new Arrow(eType_Arrow, m_pos, m_ang, 4));
				break;
			case 177:
				cnt = 0;
				break;
			}
		}
	}



}

void ArrowTrap::Draw()
{
	m_img.SetPos(m_pos);
	m_img.Draw();
	//反転設定
	m_img.SetFlipH(m_flip);

	DrawRect();
}

void ArrowTrap::Collision(Base* b)
{
}