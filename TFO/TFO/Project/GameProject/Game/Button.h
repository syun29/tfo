#pragma once
#include "../Base/Base.h"
class Button : public Base {
private:
	//����
	int m_time;
public:
	Button(int type, const CVector2D& p);
	void Update();
	void Draw();
	//�����蔻�茟��
	void Collision(Base* b);
};

