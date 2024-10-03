#include "Areachange.h"

Areachange::Areachange(const CVector2D& pos, const CVector2D& next, int next_area):Base(eType_Areachange)
{
	m_img = COPY_RESOURCE("Goal", CImage);
	m_img.SetCenter(32, 128);
	m_pos = pos;
	m_next_pos = next;
	m_next_area = next_area;
	m_rect = CRect(-32, -128, 32, 0);
	m_img.SetSize(64, 128);
}

void Areachange::Draw()
{
    m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
	DrawRect();
}
