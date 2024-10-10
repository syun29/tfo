#pragma once
#include "../Base/Base.h"
#include "Game/Map.h"

#define MAP_WIDTH    20
#define MAP_HEIGHT		12
#define MAP_TIP_SIZE	100


class Title : public Base {
	//画像オブジェクト
	CImage m_img;
	//文字表示オブジェクト
	CFont m_title_text;
	//待ち時間
	int m_cnt;
	
public:
	Title();
	void Update();
	void Draw();
	

};