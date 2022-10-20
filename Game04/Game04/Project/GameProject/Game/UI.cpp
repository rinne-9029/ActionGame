#include "UI.h"
#include "GameData.h"

UI::UI() :Base(eType_UI) {
	m_img.Load("Image/UI.png");

}

void UI::Update()
{
//ˆê•b‚²‚Æ‚ÉŽžŠÔ‚ªŒ¸‚éˆ—
	cnt++;
	if (cnt >= 60) {
		GameData::s_count -= 1;
		cnt = 0;
	}
}

void UI::Draw()
{
	int count = GameData::s_count;
	for (int i = 0; i < 2; i++, count /= 10) {
		int s = count % 10;
		m_img.SetRect(16 * s, 16, 16 * s + 16, 32);
		m_img.SetSize(32, 32);
		m_img.SetPos(100 - 32 * i, 0);
		m_img.Draw();
	}
	int kosuu = GameData::kosuu;

		int s = kosuu % 10;
		m_img.SetRect(16 * s, 16, 16 * s + 16, 32);
		m_img.SetSize(32, 32);
		m_img.SetPos(280, 0);
		m_img.Draw();
	
}

UI2::UI2():Base(eType_UI2)
{
	m_img.Load("Image/UI2.png");
}

void UI2::Update()
{
}

void UI2::Draw()
{
	m_img.SetPos(200,5);
	m_img.SetSize(80, 20);
	m_img.Draw();
}
