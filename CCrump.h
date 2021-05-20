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
	void CrumpChange(cv::Mat& showing,CGameMap& map);//�ı���ʾ��ţ��ı�֡�����

	int m_Flag;
	cv::Point m_pos;
	cv::Mat m_Image[4];
	int m_frameid;//֡���

	cv::Mat m_ShockWavesImgs[2][4];//�����ͼ��
	int m_TimeCount;//��ʱ��
};

