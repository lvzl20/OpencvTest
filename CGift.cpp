#include "CGift.h"
CGift::CGift(){

}

CGift::~CGift(){

}

void CGift::Init() {
	m_pos.x = (rand() % 14 + 1) * 40;//随机生成奖品坐标
	m_pos.y = (rand() % 12 + 1) * 40;
	m_flag = 1;
	temp = rand() % 3;//随机生成奖品类型
	char filename[] = "map/gift0.jpg";
	sprintf_s(filename,"map/gift%d.jpg",temp);
	m_Img = cv::imread(filename, 1);
}

void CGift::Release() {

}