#pragma once
#include <opencv2\opencv.hpp>
//using namespace cv;

class CGift
{
public:
	CGift();
	~CGift();
	void Init();
	void Release();

	int temp;//�����Ž�Ʒ
	cv::Mat m_Img;//��Ʒͼ��
	int m_flag;//��Ʒ���
	cv::Point m_pos;//��Ʒ����λ��
};