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
	void CopyToBack(cv::Mat & back);//��������ڱ���
	void Init();//��ʼ������
	cv::Mat m_img[4];//����ͼ��ָ��
	cv::Point m_pos;//��������
	int m_speed;//�����ƶ��ٶ�
	int m_ori;//���ﳯ��
};