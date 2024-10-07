#pragma once
#include "../Base/Base.h"
class Button : public Base {
private:
	enum {
		eAnimOF,
		eAnimON
	};
	//時間
	int m_time;
	int m_cnt;
public:
	Button(int type, const CVector2D& p);
	void Update();
	void Draw();
	//当たり判定検証
	void Collision(Base* b);
	int m_flip;
};

