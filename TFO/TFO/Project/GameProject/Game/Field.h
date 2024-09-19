#pragma once
#include "../Base/Base.h"

class Field : public Base {
private:

	CImage m_foreground;
	CImage m_town;
	CImage m_sky;
	static float m_ground_y;
public:
	Field();
	void Draw();
	static float GetGroundY() {
		return m_ground_y;
	}
};