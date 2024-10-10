#include "Goal.h"

Goal::Goal(const CVector2D& pos):Base(eType_Goal)
{
	m_img = COPY_RESOURCE("Goal", CImage);
	m_img.SetCenter(60, 100);
	m_rect = CRect(-32, -70, 16, 0);
	m_pos = pos;
	m_img.SetSize(100, 128);
	m_is_goal = false;
}

void Goal::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
	DrawRect();
}
