#include "CTools.h"

CTools::CTools(){
}

CTools::~CTools(){
}

void CTools::CopyToBack(cv::Mat& back, cv::Mat& img, int x, int y, int keyR, int keyG, int keyB, bool equal) {
	if (!back.empty() && !img.empty()) {
		for (int i = 0; i < img.rows; i++) {
			for (int j = 0; j < img.cols; j++) {
				int b = img.at<cv::Vec3b>(i, j)[0];
				int g = img.at<cv::Vec3b>(i, j)[1];
				int r = img.at<cv::Vec3b>(i, j)[2];
				bool flag;
				if (!equal)
					flag = !(b > keyB && g > keyG && r > keyR);
				else
					flag = !(b == keyB && g == keyG && r == keyR);
				if (flag) {
					back.at<cv::Vec3b>(i + y, j + x)[0] = b;
					back.at<cv::Vec3b>(i + y, j + x)[1] = g;
					back.at<cv::Vec3b>(i + y, j + x)[2] = r;
				}
			}
		}
	}
}