#pragma once
#include "CGameMap.h"
//using namespace cv;
class CCrump
{
public:
	CCrump();
	~CCrump();
	void Init(int x,int y);
	void Realease();
	void CopyToBack(cv::Mat& showimg);
	void CrumpChange(cv::Mat& showing,CGameMap& map);//改变显示序号，改变帧数序号

	int m_Flag;
	cv::Point m_pos;
	cv::Mat m_Image[4];
	int m_frameid;//帧编号

	cv::Mat m_ShockWavesImgs[2][4];//冲击波图像
	int m_TimeCount;//计时器
};

