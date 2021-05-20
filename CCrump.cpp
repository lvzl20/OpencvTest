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
	m_TimeCount = 15;//计时器 倒计时
	char name[1000] = { 0 };
	for (int i = 0; i < 4; i++) {
		sprintf_s(name, "map/crump%d.bmp", i);
		m_Image[i] = cv::imread(name);
	}
	//加载冲击波动画
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
		return;//炸弹爆炸则不绘制
	CTools::CopyToBack(showimg, m_Image[m_frameid], m_pos.x, m_pos.y, 255, 0, 0,true);
}

void CCrump::CrumpChange(cv::Mat& showimg,CGameMap& map) {
	if (m_Flag == 0) //炸弹已爆炸，m_Flag为零，则不再有效
		return;
	m_TimeCount--;
	if (m_TimeCount >= 5) {
		m_frameid++;
		if (m_frameid > 1)//仅循环显示炸弹动画的前两帧，处于待爆炸状态
			m_frameid = 0;
	}
	else if (m_TimeCount < 5) {
		m_frameid = 2;
		map.ClearMap(m_pos.x, m_pos.y);
		CTools::CopyToBack(showimg, m_Image[m_frameid], m_pos.x, m_pos.y, 255, 0, 0, true);
		//显示冲击波
		int dir[4][2] = {
						-1,0,
						0,-1,
						1,0,
						0,1 };
		for (int i = 0; i < 4; i++)
		{
			if (map.m_Map[m_pos.x / 40][m_pos.y / 40] < 5
				&& m_pos.x / 40 + dir[i][0] >= 0  //左边界判断
				&& m_pos.y / 40 + dir[i][1] >= 0  //上边界判断
				&& m_pos.x / 40 + dir[i][0] <= 15 //右边界判断
				&& m_pos.y / 40 + dir[i][1] <= 15)//下边界判断
			{
				map.ClearMap(m_pos.x + dir[i][0] * 40, m_pos.y + dir[i][1] * 40);  //炸弹过处，寸草不生

				CTools::CopyToBack(showimg, m_ShockWavesImgs[0][i], m_pos.x + 40 * dir[i][0], m_pos.y + 40 * dir[i][1], 255, 0, 0, true);
			}

			if (m_pos.x / 40 + 2 * dir[i][0] >= 0 
				&& m_pos.y / 40 + 2 * dir[i][1] >= 0
				&& m_pos.x / 40 + 2 * dir[i][0] <= 14
				&& m_pos.y / 40 + 2 * dir[i][1] <= 14)  //炸弹范围 2
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