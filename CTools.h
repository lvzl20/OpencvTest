#pragma once
#include<opencv2/core/core.hpp>
//using namespace cv;
class CTools
{
public:
	CTools();
	~CTools();
	static void CopyToBack(cv::Mat & back, cv::Mat & img, int x, int y, int keyR, int keyG, int keyB, bool equal = false);
};

