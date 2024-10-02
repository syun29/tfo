#include "Map.h"
#include "Areachange.h"
#include "Door.h"


static int stage1data[MAP_HEIGHT][MAP_WIDTH] = {
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,4,4,4,4,4,4,4,4,4,4,4,4,0,0,0,},
	{ 0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{ 0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{ 3,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{ 3,3,2,0,0,0,0,2,2,2,2,0,0,0,0,0,0,0,0,0,},
	{ 3,3,3,2,2,2,2,3,3,3,3,2,2,2,2,2,2,2,2,2,},
};
static int stage2data[MAP_HEIGHT][MAP_WIDTH] = {
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,},
	{ 0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{ 0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{ 3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{ 3,3,3,0,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0,0,},
	{ 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,},
};



Map::Map(int area) : Base(eType_Map)
{
	m_img = COPY_RESOURCE("MapTip", CImage);
	switch (area) {
	case 1:
		memcpy(m_stage_data, stage1data, sizeof(stage1data));
		Base::Add(new Door(CVector2D(18 * MAP_TIP_SIZE, 9 * MAP_TIP_SIZE),
			CVector2D(37 * MAP_TIP_SIZE, 6 * MAP_TIP_SIZE)));
		Base::Add(new Door(CVector2D(38 * MAP_TIP_SIZE, 7 * MAP_TIP_SIZE),
			CVector2D(18 * MAP_TIP_SIZE, 20 * MAP_TIP_SIZE)));
		Base::Add(new Areachange(CVector2D(20 * MAP_TIP_SIZE, 10 * MAP_TIP_SIZE),
			CVector2D(2 * MAP_TIP_SIZE, 20 * MAP_TIP_SIZE),
			2));

		break;
	case 2:
		memcpy(m_stage_data, stage2data, sizeof(stage2data));
		break;
	}
	
}


void Map::Draw()
{
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			//表示しない制御
			if (stage1data[i][j] == 0)continue;
			int t = stage1data[i][j];
			//画像切り抜き
			m_img.SetRect(32 * t, 0, 32 * t + 32, 32);
			//表示サイズ設定
			m_img.SetSize(MAP_TIP_SIZE, MAP_TIP_SIZE);
			//表示位置設定
			m_img.SetPos(MAP_TIP_SIZE * j - m_scroll.x,
				MAP_TIP_SIZE * i - m_scroll.y);
			//描画
			m_img.Draw();
		}
	}
}

int Map::GetTip(const CVector2D& pos, int* tx, int* ty)
{
	//列を計算
	int x = pos.x / MAP_TIP_SIZE;
	//列の制限
	if (x < 0) x = 0;
	if (x > MAP_WIDTH - 1) x = MAP_WIDTH - 1;
	//行を計算
	int y = pos.y / MAP_TIP_SIZE;
	//行の制限
	if (y < 0) y = 0;
	if (y > MAP_HEIGHT - 1) y = MAP_HEIGHT - 1;
	//行と列の出力
	if (ty) *ty = y * MAP_TIP_SIZE;
	if (tx) *tx = x * MAP_TIP_SIZE;
	//チップデータを返却
	return stage1data[y][x];
	
}

int Map::GetTip(int x, int y)
{
	return  stage1data[y][x];
}

int Map::CollisionPoint(const CVector2D& pos)
{
	//1点のみ検証
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













