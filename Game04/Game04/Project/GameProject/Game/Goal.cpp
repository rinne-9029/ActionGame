#include "Goal.h"

Goal::Goal(const CVector2D& pos):Base(eType_Goal){
	m_img = COPY_RESOURCE("Goal", CImage);
	m_pos = pos;

	//ãÈå`Çê›íË
	m_rect = CRect(-0, -0, 65, 30);
	m_img.SetSize(65, 28);
}

void Goal::Update() {

}

void Goal::Draw(){
	m_img.SetPos(m_pos);
	m_img.Draw();
	//DrawRect();
}


