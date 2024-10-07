#pragma once
#include "../Base/Base.h"
class Button : public Base {
private:
	enum {
		eAnimOF,
		eAnimON
	};
	//ŠÔ
	int m_time;
	int m_cnt;
public:
	Button(int type, const CVector2D& p);
	void Update();
	void Draw();
	//“–‚½‚è”»’èŒŸØ
	void Collision(Base* b);
	int m_flip;
	Button(int m_time, int m_flip);
	
};

