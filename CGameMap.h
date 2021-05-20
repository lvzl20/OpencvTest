#pragma once
#include<opencv2/opencv.hpp>
//using namespace cv;

#define MAP_SIZE 16

class CGameMap
{
public:
	CGameMap();
	~CGameMap();
	void Init();
	void ReadMaptext();//��ȡ��ͼ����
	void CreateMap();//������ͼ
	void Release();
	void ClearMap(int x, int y);//�����λ�õ���Ʒ

	cv::Mat GetBackShowImg();

	int level;//����ڼ�����ͼ
	cv::Mat m_ObstacleImg[3];//���������ϰ���
	cv::Mat m_ObstacleImg2[6];//�ڶ�����ͼ���ϰ���
	cv::Mat m_Background;//����ͼ��
	cv::Mat m_StaticBack;//��̬����ͼ��
	cv::Mat m_ShowImg;//��ʾ��ͼ��
	bool Collision(int x, int y);//�жϸõ��Ƿ�����ײ
	int m_Map[MAP_SIZE][MAP_SIZE];//��ͼ��Ʒλ��
};

