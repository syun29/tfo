#pragma once
#include "../Base/Base.h"
class Areachange : public Base {
private:
	//�摜�I�u�W�F�N�g
	CImage m_img;
	//�ړ��ʒu
	CVector2D m_next_pos;
	//�ړ���̃X�e�[�W
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