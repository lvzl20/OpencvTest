#pragma once
#include<opencv2/opencv.hpp>
//using namespace cv;

#define MAP_SIZE 16

class CGameMap
{
public:
	CGameMap();
	~CGameMap();
	void Init();
	void ReadMaptext();//读取地图数据
	void CreateMap();//创建地图
	void Release();
	void ClearMap(int x, int y);//清除该位置的物品

	cv::Mat GetBackShowImg();

	int level;//代表第几个地图
	cv::Mat m_ObstacleImg[3];//定义三种障碍物
	cv::Mat m_ObstacleImg2[6];//第二个地图的障碍物
	cv::Mat m_Background;//背景图像
	cv::Mat m_StaticBack;//静态背景图像
	cv::Mat m_ShowImg;//显示的图像
	bool Collision(int x, int y);//判断该点是否发生碰撞
	int m_Map[MAP_SIZE][MAP_SIZE];//地图物品位置
};

