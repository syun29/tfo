#pragma once
#include "../Base/Base.h"
#include "Game/Map.h"

#define MAP_WIDTH    20
#define MAP_HEIGHT		12
#define MAP_TIP_SIZE	100


class Title : public Base {
	//�摜�I�u�W�F�N�g
	CImage m_img;
	//�����\���I�u�W�F�N�g
	CFont m_title_text;
	//�҂�����
	int m_cnt;
	
public:
	Title();
	void Update();
	void Draw();
	

};