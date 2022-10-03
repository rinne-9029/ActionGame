#include "Trap.h"
#include"AnimData.h"

Trap::Trap(const CVector2D& pos):
	Base(eType_Trap)
{
	//画像複製
	m_img = COPY_RESOURCE("Trap", CImage);
	//座標設定
	m_pos = pos;
	m_pos_old = pos;
	//再生アニメーション設定
	m_img.ChangeAnimation(0);
	m_img.SetCenter(32, 0);
	m_rect = CRect(-18, 0, 18, 64);

}

void Trap::Update()
{
	//アニメーション更新
	m_img.UpdateAnimation();
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
