#pragma once
#include "../Base/Base.h"
class Button : public Base {
private:
	//ŠÔ
	int m_time;
public:
	Button(int type, const CVector2D& p);
	void Update();
	void Draw();
	//“–‚½‚è”»’èŒŸØ
	void Collision(Base* b);
};

