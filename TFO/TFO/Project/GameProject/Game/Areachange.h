#pragma once
#include "../Base/Base.h"
class Areachange : public Base {
private:
	//画像オブジェクト
	CImage m_img;
	//移動位置
	CVector2D m_next_pos;
	//移動先のステージ
	int m_next_area;
public:
	Areachange(const CVector2D& pos, const CVector2D& next, int next_area);
	void Draw();
	CVector2D GetNextPos() {
		return m_next_pos;
	}
	int GetNextArea() {
		return m_next_area;
	}

};