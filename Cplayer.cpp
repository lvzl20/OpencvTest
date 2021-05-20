#pragma once
#include "Cplayer.h"
#include "CTools.h"
#include "CBgm.h"
Cplayer::Cplayer() {

}

Cplayer::~Cplayer() {

}

void Cplayer::Init() {
	m_ori = 1;
	char name[] = "player/player1.jpg";
	for (int i = 0; i < 4; i++) {
		sprintf_s(name, "player/player%d.jpg", i);
		m_img[i] = cv::imread(name);
	}
	m_pos.x = 300;
	m_pos.y = 300;
	m_speed = 20;
}

void Cplayer::CopyToBack(cv::Mat & back) {
	CTools::CopyToBack(back, m_img[m_ori], m_pos.x, m_pos.y, 225, 225, 225);
}
void Cplayer::Move(int key,CGameMap & map) {
	int x = m_pos.x;
	int y = m_pos.y;
	switch (key) {
	case 'w':
	case 'W':
		m_ori = 0;
		m_pos.y -= m_speed;
		break;
	case 'd':
	case 'D':
		m_ori = 1;
		m_pos.x += m_speed;
		break;
	case 'a':
	case 'A':
		m_ori = 2;
		m_pos.x -= m_speed;
		break;
	case 's':
	case 'S':
		m_ori = 3;
		m_pos.y += m_speed;
		break;
	}
	if (map.Collision(m_pos.x, m_pos.y)) {
		m_pos.x = x;
		m_pos.y = y;
	}
	if (key == 'w' || key == 'W' || key == 'A' || key == 'a' ||
		key == 's' || key == 'S' || key == 'd' || key == 'D') {
		CBgm::Playsound(2);
	}
	if (key == ' ') {
		CBgm::Playsound(3);
	}
	//CBgm::Playsound(1);//»¹Ô­±³¾°ÒôÀÖ
	//PlaySound(L"sound\\there_home.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}
void Cplayer::Release() {

}