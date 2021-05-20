#include "CGame.h"

CGame::CGame(){

}

CGame::~CGame(){

}

void CGame::Welcome() {
	cv::namedWindow("QQTang", 1);
	cv::Mat begin = cv::imread("map\\welcome.jpg", 1);
	char text[] = "1:Level1   2:Level2   Space:RunGame";
	int font_face = cv::FONT_HERSHEY_COMPLEX;
	double font_scale = 0.7;
	int thickness = 1;
	int x = 100, y = 600;
	cv::Scalar color = cv::Scalar(200, 0, 0);
	cv::Point origin(x, y);
	cv::putText(begin, text, origin, font_face, font_scale, color, thickness, 8, 0);
	cv::imshow("QQTang", begin);

	CBgm::Playsound(6);
	while (true) {
		level = cv::waitKey();
		if (level == 49 || level == 50)
			break;
	}
	std::string text1 = "Welcome to Level1,Please enter space to run game!";
	if(level == 50)
		text1 = "Welcome to Level2,Please enter space to run game!";
	y = 500;
	cv::Point  origin1(x, y);
	cv::putText(begin, text1, origin1, font_face, font_scale, color, thickness, 8, 0);
	cv::imshow("QQTang", begin);
	while (true) {
		int key = cv::waitKey();
		if (key == ' ')
			break;
	}
}

void CGame::Init() {
	k1 = k2 = k3 = 0;
	cv::namedWindow("QQTang", 1);
	m_Player.Init();
	m_Map.level = level;
	m_Map.Init();
	m_Map.ReadMaptext();
	m_Map.CreateMap();
	for (int i = 0; i < 10; i++)
		m_Gifts[i].Init();
}

void CGame::Run() {
	mciSendString(L"close back", NULL, 0, NULL);//关闭欢迎界面的音乐
	if (level == 49)
		CBgm::Playsound(1);//背景音乐
	else
		CBgm::Playsound(5);
	while (true) {
		m_bkImg = m_Map.GetBackShowImg();
		m_Player.CopyToBack(m_bkImg);
		DrawRight();
		DrawGift();//绘制礼物
		DrawCrump();//绘制炸弹
		UpdateCrump();
		cv::imshow("QQTang", m_bkImg);
		int key = 0;
		key = cv::waitKey(50);
		if (key == 27)
			break;
		//创建及更新炸弹
		CreateCrump(key);
		m_Player.Move(key, m_Map);
		if (key == 'C' || key == 'c') {
			mciSendString(L"close back", NULL, 0, NULL);//关闭欢迎界面的音乐
			Welcome();
			Init();
			mciSendString(L"close back", NULL, 0, NULL);//关闭欢迎界面的音乐
			if (level == 49)
				CBgm::Playsound(1);//背景音乐
			else
				CBgm::Playsound(5);
		}
	}
}
void CGame::DrawGift() {
	int flag = 0;
	for (int i = 0; i < 10; i++) {
		//如果人物的坐标和奖品坐标一样，则奖品标记为0
		if (m_Player.m_pos.x == m_Gifts[i].m_pos.x && m_Player.m_pos.y == m_Gifts[i].m_pos.y) {
			m_Gifts[i].m_flag = 0;
			m_Gifts[i].m_pos.x = 16 * 40;
			m_Gifts[i].m_pos.y = 0;
			flag = 1;
			AddScore(m_Gifts[i].temp);
		}
	}
	if(flag)
		CBgm::Playsound(4);//如果获取奖品放出音效
	for (int i = 0; i < 10; i++) {
		if (m_Gifts[i].m_flag == 1) {
			CTools::CopyToBack(m_bkImg, m_Gifts[i].m_Img, m_Gifts[i].m_pos.x, m_Gifts[i].m_pos.y, 235, 235, 235);
		}
	}
}

void CGame::CreateCrump(int key) {
	CCrump * pcrump = NULL;
	if (key == ' '){    //放炸弹
		pcrump = new CCrump;
		pcrump->Init(m_Player.m_pos.x, m_Player.m_pos.y);
		m_Crumps.push_back(pcrump);
	}
}

void CGame::DrawCrump() {
	for (int i = 0; i < m_Crumps.size(); i++){
		if(m_Crumps[i]->m_TimeCount >= 5)
			m_Crumps[i]->CopyToBack(m_bkImg);
	}
}

void CGame::UpdateCrump() {
	for (int i = 0; i < m_Crumps.size(); i++){
		m_Crumps[i]->CrumpChange(m_bkImg,m_Map);
	}
}

void CGame::DrawRight() {

	char text[] = "gift1";
	int font_face = cv::FONT_HERSHEY_COMPLEX;
	double font_scale = 0.5;
	int thickness = 1;
	int x = 700, y = 40;
	cv::Scalar color = cv::Scalar(255, 0, 0);
	for (int i = 0; i < 3; i++) {
		cv::Point origin(x, y);
		sprintf_s(text, "gift%d", i);
		cv::putText(m_bkImg, text,origin,font_face,font_scale,color,thickness,8,0);
		y += 52;
	}

	char filename1[] = "map/gift0.jpg";
	char filename2[] = "map/gift1.jpg";
	char filename3[] = "map/gift2.jpg";
	cv::Mat gift1 = cv::imread(filename1);
	cv::Mat gift2 = cv::imread(filename2);
	cv::Mat gift3 = cv::imread(filename3);
	x = 710, y = 45;
	for (int i = 0; i < k1; i++) {//绘制出每一号的奖品的数量
		CTools::CopyToBack(m_bkImg, gift1, x, y, 235, 235, 235);
		x += 40;
	}
	x = 710, y = 95;
	for (int i = 0; i < k2; i++) {
		CTools::CopyToBack(m_bkImg, gift2, x, y, 235, 235, 235);
		x += 40;
	}
	x = 710, y = 150;
	for (int i = 0; i < k3; i++) {
		CTools::CopyToBack(m_bkImg, gift3, x, y, 235, 235, 235);
		x += 40;
	}

	color = cv::Scalar(13, 23, 227);
	std::string s[10];
	s[0] = "Help:";
	s[1] = "Esc : End game";
	s[2] = "C or c : Welcome";
	s[3] = "Space : Bomb";
	s[4] = "W or w : Up";
	s[5] = "S or s : Down";
	s[6] = "A or a : Left";
	s[7] = "D or d : Right";

	x = 700, y = 255;
	for (int i = 0; i < 8; i++) {
		cv::Point ori(x, y);
		cv::putText(m_bkImg, s[i], ori, font_face, font_scale, color, thickness, 8, 0);
		y += 20;
	}
}

void CGame::AddScore(int k){
	if (k == 0)
		k1++;
	else if (k == 1)
		k2++;
	else if (k == 2)
		k3++;
}

void CGame::Release() {
	cv::destroyWindow("QQTang");
	m_Player.Release();
	m_Map.Release();
}