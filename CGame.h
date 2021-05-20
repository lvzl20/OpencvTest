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

	int level;//ѡ�Ĺ�
	int k1, k2, k3;//�������Ž�Ʒ������
	CGift m_Gifts[10];
	void DrawGift();//��������
	vector <CCrump *> m_Crumps;
	void CreateCrump(int key);
	void DrawCrump();
	void UpdateCrump();
	void Welcome();
	void DrawRight();//�����ұ�ͼ�μ�����
	void AddScore(int k);//���Ƶ÷�,k�����Ž�Ʒ
};

