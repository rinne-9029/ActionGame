#include "Trap.h"
#include"AnimData.h"

Trap::Trap(const CVector2D& pos):
	Base(eType_Trap)
{
	//画像複製
	m_img = COPY_RESOURCE("Trap", CImage);
	//座標設定
	m_pos = pos;
	//再生アニメーション設定
	m_img.ChangeAnimation(0);

}

void Trap::Updata()
{
	//アニメーション更新
	m_img.UpdateAnimation();
}

void Trap::Draw()
{
	m_img.Draw();
}

void Trap::Collision(Base* b)
{
}
