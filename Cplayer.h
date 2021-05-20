#pragma once
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include "CGameMap.h"
//using namespace cv;

class Cplayer {
public:
	Cplayer();
	~Cplayer();
	void Move(int key,CGameMap& map);
	void Release();
	void CopyToBack(cv::Mat & back);//人物绘制在背景
	void Init();//初始化人物
	cv::Mat m_img[4];//人物图像指针
	cv::Point m_pos;//人物坐标
	int m_speed;//人物移动速度
	int m_ori;//人物朝向
};