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

	int temp;//代表几号奖品
	cv::Mat m_Img;//奖品图像
	int m_flag;//奖品标记
	cv::Point m_pos;//奖品坐标位置
};