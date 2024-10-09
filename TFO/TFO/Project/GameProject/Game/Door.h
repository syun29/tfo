#pragma once
#include "../Base/Base.h"
class Door : public Base {
private:
	//画像オブジェクト
	CImage m_img;
	//移動位置
	CVector2D m_next_pos;
public:
	int m_cnt;
	Door(const CVector2D& pos, const CVector2D& next);
	void Draw();
	CVector2D GetNextPos() {
		return m_next_pos;
	}
	void Collision(Base* b);
};