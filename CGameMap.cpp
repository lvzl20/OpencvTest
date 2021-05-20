#include "CGameMap.h"
#include "CTools.h"
#include <fstream>
using namespace std;

CGameMap::CGameMap() {

}
CGameMap::~CGameMap() {

}

void CGameMap::Init() {
	m_StaticBack = cv::imread("map\\back1.jpg", 1);//加载备份地图
	m_Background = m_StaticBack.clone();//加载地图,绘制
	m_ShowImg = m_StaticBack.clone();//显示的地图
	char name1[1000] = { 0 };
	for (int i = 0; i < 3; i++) {
		sprintf_s(name1, "map/obstacle%d.jpg", i);
		m_ObstacleImg[i] = cv::imread(name1);
	}
	for (int i = 0; i < 6; i++) {
		sprintf_s(name1, "map/stone%d.jpg", i);
		m_ObstacleImg2[i] = cv::imread(name1);
	}
}

void CGameMap::ReadMaptext() {
	ifstream txt;
	if (level == 49)
		txt.open("map/map_lever1.txt");
	if (level == 50)
		txt.open("map/map_lever2.txt");
	int k;
	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			txt >> k;
			m_Map[i][j] = k;
		}
	}
	txt.close();
}
void CGameMap::CreateMap() {
	m_StaticBack.copyTo(m_Background);//还原背景
	if (level == 49) {
		for (int i = 0; i < MAP_SIZE; i++) {
			for (int j = 0; j < MAP_SIZE; j++) {
				int x = i * 40;
				int y = j * 40;
				int k = m_Map[i][j];
				if (k != -1)
					CTools::CopyToBack(m_Background, m_ObstacleImg[k], x, y, 235, 235, 235);
			}
		}
	}
	else {
		for (int i = 0; i < MAP_SIZE; i++) {
			for (int j = 0; j < MAP_SIZE; j++) {
				int x = i * 40;
				int y = j * 40;
				int k = m_Map[i][j];
				if (k != -1)
					CTools::CopyToBack(m_Background, m_ObstacleImg2[k], x, y, 235, 235, 235);
			}
		}
	}
}

void CGameMap::ClearMap(int x, int y) {
	int posx = x / 40;
	int posy = y / 40;
	m_Map[posx][posy] = -1;
}

cv::Mat CGameMap::GetBackShowImg() {
	CreateMap();
	m_Background.copyTo(m_ShowImg);
	return m_ShowImg;
}

bool CGameMap::Collision(int x, int y) {
	if (x < 0 || y < 0 || x > 640 || y > 600)
		return true;
	int posx = x / 40;
	int posy = y / 40;
	if (m_Map[posx][posy] != -1)
		return true;
	return false;
}
void CGameMap::Release() {

}