#pragma once
#include "../Base/Base.h"
class Button : public Base {
private:
	//時間
	int m_time;
public:
	Button(int type, const CVector2D& p);
	void Update();
	void Draw();
	//当たり判定検証
	void Collision(Base* b);
};

