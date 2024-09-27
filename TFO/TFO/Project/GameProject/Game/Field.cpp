#include "Field.h"

float Field::m_ground_y = 540;
Field::Field() :Base(eType_Field)
{
	m_sky = COPY_RESOURCE("haikei1.png", CImage);

	m_ground_y = 1080;



}
void Field::Draw()
{
	float sc;
	m_sky.Draw();
	sc = m_scroll.x / 4;
	

	
}
