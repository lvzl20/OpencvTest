#include "CGift.h"
CGift::CGift(){

}

CGift::~CGift(){

}

void CGift::Init() {
	m_pos.x = (rand() % 14 + 1) * 40;//������ɽ�Ʒ����
	m_pos.y = (rand() % 12 + 1) * 40;
	m_flag = 1;
	temp = rand() % 3;//������ɽ�Ʒ����
	char filename[] = "map/gift0.jpg";
	sprintf_s(filename,"map/gift%d.jpg",temp);
	m_Img = cv::imread(filename, 1);
}

void CGift::Release() {

}