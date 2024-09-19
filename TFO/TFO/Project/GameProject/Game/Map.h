#pragma once

#include"../Base/Base.h"
#define MAP_WIDTH    40
#define MAP_HEIGHT		22
#define MAP_TIP_SIZE	128

class Map : public Base {
private:
	CImage m_img;
	CImage m_background;
public:
	Map();
	void Draw();
	int GetTip(const CVector2D& pos, int* tx = nullptr, int* ty = nullptr);
	int GetTip(int x, int y);
	int CollisionMap(const CVector2D& pos, const CRect& rect, CVector2D* rev_pos);
};