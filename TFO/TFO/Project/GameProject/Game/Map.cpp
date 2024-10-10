#include "Map.h"
#include "Areachange.h"
#include "Door.h"
#include "Goal.h"

/*static int stage0data[MAP_HEIGHT][MAP_WIDTH] = {
	{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,},
	{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,},
	{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,},
	{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,},
	{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,},
	{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,},
	{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,},
	{ 3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,},
	{ 3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,},
	{ 3,3,3,2,2,0,2,3,3,3,3,2,2,0,2,2,2,2,0,2,},
};*/

static int stage1data[MAP_HEIGHT][MAP_WIDTH] = {
	{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,},
	{ 3,4,0,4,0,4,0,4,0,4,0,4,0,4,0,4,0,4,0,3,},
	{ 3,4,0,4,0,4,0,4,0,4,0,4,0,4,0,0,0,2,0,3,},
	{ 3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,3,},
	{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,},
	{ 3,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,0,3,},
	{ 3,0,0,0,0,0,0,0,0,0,0,2,0,3,0,0,0,3,0,3,},
	{ 3,0,0,0,0,0,0,0,0,2,0,0,0,3,0,0,0,3,0,3,},
	{ 3,0,0,0,0,2,0,2,0,0,0,0,0,3,0,0,0,0,0,3,},
	{ 3,3,3,0,0,0,0,0,0,0,0,0,0,3,2,2,0,2,0,2,},
};
static int stage2data[MAP_HEIGHT][MAP_WIDTH] = {
	{ 9,0,0,0,0,0,0,0,0,0,0,0,0,8,8,8,0,0,0,9,},
	{ 9,0,0,0,0,0,0,0,0,9,0,0,0,9,9,0,0,9,0,9,},
	{ 9,0,0,0,0,0,9,0,0,9,0,0,9,9,0,0,9,9,0,9,},
	{ 9,0,0,0,9,0,0,0,0,9,0,0,0,9,9,0,0,9,0,9,},
	{ 9,0,0,0,0,0,9,0,0,9,0,0,9,9,0,0,9,9,0,9,},
	{ 9,0,0,0,0,0,0,0,9,9,0,0,0,9,9,0,0,9,0,9,},
	{ 9,0,0,0,0,0,9,0,0,9,0,0,9,9,0,0,9,9,0,9,},
	{ 9,0,0,0,9,0,0,0,0,9,0,0,0,0,9,0,0,9,0,9,},
	{ 9,0,0,9,9,0,0,0,0,9,0,0,9,0,0,0,8,9,0,9,},
	{ 8,8,8,8,8,0,0,0,0,8,0,0,0,0,8,0,0,9,8,8,},
};



Map::Map(int area) : Base(eType_Map)
{
	m_img = COPY_RESOURCE("MapTip", CImage);
	switch (area) {
	case 1:
		memcpy(m_stage_data, stage1data, sizeof(stage1data));
		//Base::Add(new Door(CVector2D(15 * MAP_TIP_SIZE, 9 * MAP_TIP_SIZE),
			//CVector2D(37 * MAP_TIP_SIZE, 6 * MAP_TIP_SIZE)));
		//Base::Add(new Door(CVector2D(38 * MAP_TIP_SIZE, 7 * MAP_TIP_SIZE),
			//CVector2D(18 * MAP_TIP_SIZE, 20 * MAP_TIP_SIZE)));
		Base::Add(new Areachange(CVector2D(15 * MAP_TIP_SIZE, 9 * MAP_TIP_SIZE),
			CVector2D(2 * MAP_TIP_SIZE, 2 * MAP_TIP_SIZE),
			2));

		break;
	case 2:
		memcpy(m_stage_data, stage2data, sizeof(stage2data));
		Base::Add(new Goal(CVector2D(38 * MAP_TIP_SIZE, 21 * MAP_TIP_SIZE)));
		break;
	}
	
}


void Map::Draw()
{

	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			//�\�����Ȃ�����
			if (m_stage_data[i][j] == 0)continue;
			int t = m_stage_data[i][j];
			//�摜�؂蔲��
			m_img.SetRect(32 * t, 0, 32 * t + 32, 32);
			//�\���T�C�Y�ݒ�
			m_img.SetSize(MAP_TIP_SIZE, MAP_TIP_SIZE);
			//�\���ʒu�ݒ�
			m_img.SetPos(MAP_TIP_SIZE * j - m_scroll.x,
				MAP_TIP_SIZE * i - m_scroll.y);
			//�`��
			m_img.Draw();
		}
	}
}

int Map::GetTip(const CVector2D& pos, int* tx, int* ty)
{
	//����v�Z
	int x = pos.x / MAP_TIP_SIZE;
	//��̐���
	if (x < 0) x = 0;
	if (x > MAP_WIDTH - 1) x = MAP_WIDTH - 1;
	//�s���v�Z
	int y = pos.y / MAP_TIP_SIZE;
	//�s�̐���
	if (y < 0) y = 0;
	if (y > MAP_HEIGHT - 1) y = MAP_HEIGHT - 1;
	
	//�`�b�v�f�[�^��ԋp
	return m_stage_data[y][x];
	
}

int Map::GetTip(int x, int y)
{
	return  stage1data[y][x];
}

int Map::CollisionPoint(const CVector2D& pos)
{
	//1�_�̂݌���
	int t = GetTip(pos);
	if (t != 0)return t;
	return 0;
}

int Map::CollisionRect(const CVector2D& pos, const CRect& rect)
{
	CRect r = CRect(
		pos.x + rect.m_left,
		pos.y + rect.m_top,
		pos.x + rect.m_right,
		pos.y + rect.m_bottom);
	int t;
	t = CollisionPoint(CVector2D(r.m_left, r.m_top));
	if (t != 0) return t;
	t = CollisionPoint(CVector2D(r.m_right, r.m_top));
	if (t != 0) return t;
	t = CollisionPoint(CVector2D(r.m_left, r.m_bottom));
	if (t != 0) return t;
	t = CollisionPoint(CVector2D(r.m_right, r.m_bottom));
	if (t != 0) return t;
	return 0;

}













