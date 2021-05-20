#pragma once
#include "Cplayer.h"
#include "CGameMap.h"
#include "CGift.h"
#include "CCrump.h"
#include "CTools.h"
#include "CBgm.h"
#include <vector>
//using namespace cv;
using namespace std;

class CGame
{
public:
	CGame();
	~CGame();
	void Init();
	void Run();
	void Release();
	Cplayer m_Player;
	CGameMap m_Map;
	cv::Mat m_bkImg;

	int level;//选的关
	int k1, k2, k3;//代表各编号奖品的数量
	CGift m_Gifts[10];
	void DrawGift();//绘制礼物
	vector <CCrump *> m_Crumps;
	void CreateCrump(int key);
	void DrawCrump();
	void UpdateCrump();
	void Welcome();
	void DrawRight();//绘制右边图形及文字
	void AddScore(int k);//绘制得分,k代表几号奖品
};

