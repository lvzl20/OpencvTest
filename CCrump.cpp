#include "CCrump.h"
#include "CTools.h"
CCrump::CCrump(){

}

CCrump::~CCrump(){

}

void CCrump::Init(int x, int y) {
	m_Flag = 1;
	m_pos.x = x;
	m_pos.y = y;
	m_frameid = 0;
	m_TimeCount = 15;//��ʱ�� ����ʱ
	char name[1000] = { 0 };
	for (int i = 0; i < 4; i++) {
		sprintf_s(name, "map/crump%d.bmp", i);
		m_Image[i] = cv::imread(name);
	}
	//���س��������
	char name1[] = "map/shockwave-001.bmp";
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			sprintf_s(name1, "map/shockwave-%d%02d.bmp", i, j);
			m_ShockWavesImgs[i][j] = cv::imread(name1);
		}
	}
}

void CCrump::CopyToBack(cv::Mat& showimg) {
	if (m_Flag ==0)
		return;//ը����ը�򲻻���
	CTools::CopyToBack(showimg, m_Image[m_frameid], m_pos.x, m_pos.y, 255, 0, 0,true);
}

void CCrump::CrumpChange(cv::Mat& showimg,CGameMap& map) {
	if (m_Flag == 0) //ը���ѱ�ը��m_FlagΪ�㣬������Ч
		return;
	m_TimeCount--;
	if (m_TimeCount >= 5) {
		m_frameid++;
		if (m_frameid > 1)//��ѭ����ʾը��������ǰ��֡�����ڴ���ը״̬
			m_frameid = 0;
	}
	else if (m_TimeCount < 5) {
		m_frameid = 2;
		map.ClearMap(m_pos.x, m_pos.y);
		CTools::CopyToBack(showimg, m_Image[m_frameid], m_pos.x, m_pos.y, 255, 0, 0, true);
		//��ʾ�����
		int dir[4][2] = {
						-1,0,
						0,-1,
						1,0,
						0,1 };
		for (int i = 0; i < 4; i++)
		{
			if (map.m_Map[m_pos.x / 40][m_pos.y / 40] < 5
				&& m_pos.x / 40 + dir[i][0] >= 0  //��߽��ж�
				&& m_pos.y / 40 + dir[i][1] >= 0  //�ϱ߽��ж�
				&& m_pos.x / 40 + dir[i][0] <= 15 //�ұ߽��ж�
				&& m_pos.y / 40 + dir[i][1] <= 15)//�±߽��ж�
			{
				map.ClearMap(m_pos.x + dir[i][0] * 40, m_pos.y + dir[i][1] * 40);  //ը����������ݲ���

				CTools::CopyToBack(showimg, m_ShockWavesImgs[0][i], m_pos.x + 40 * dir[i][0], m_pos.y + 40 * dir[i][1], 255, 0, 0, true);
			}

			if (m_pos.x / 40 + 2 * dir[i][0] >= 0 
				&& m_pos.y / 40 + 2 * dir[i][1] >= 0
				&& m_pos.x / 40 + 2 * dir[i][0] <= 14
				&& m_pos.y / 40 + 2 * dir[i][1] <= 14)  //ը����Χ 2
			{
				map.ClearMap(m_pos.x + 2 * dir[i][0] * 40, m_pos.y + 2 * dir[i][1] * 40);
				if (i < 2)
					CTools::CopyToBack(showimg, m_ShockWavesImgs[1][i], m_pos.x + 2 * 40 * dir[i][0], m_pos.y + 2 * 40 * dir[i][1]
						, 255, 0, 0, true);
				else
					CTools::CopyToBack(showimg, m_ShockWavesImgs[1][i], m_pos.x + 40 * dir[i][0], m_pos.y + 40 * dir[i][1]
						, 255, 0, 0, true);
			}
		}
	}
	if (m_TimeCount == 0) {
		m_Flag = 0;
		m_TimeCount = 30;
		map.ClearMap(m_pos.x / 40, m_pos.y / 40);
	}
}

void CCrump::Realease() {

}