#include "CBgm.h"
//#include <Windows.h>
#include "vfw.h"

CBgm::CBgm() {

}

CBgm::~CBgm() {

}
// mciSendString里面的back如果1,5,6里面名字相同，则会覆盖，如果不同则会同时播放，如back1,back2,back3
// 关闭音乐为mciSendString(L"close back",NULL,0,NULL);
void CBgm::Playsound(int k) {
	switch (k) {
	case 1://地图1音乐
		//PlaySound(L"sound\\there_home.wav", NULL, SND_FILENAME | SND_ASYNC);
		mciSendString(L"open sound/hero_6976.mp3 alias back", NULL, 0, NULL);
		mciSendString(L"play back repeat", NULL, 0, NULL);
		/*
		HWND m_hMCI;
		m_hMCI = MCIWndCreate(NULL,NULL,WS_POPUP | MCIWNDF_NOPLAYBAR | 
					MCIWNDF_NOMENU, L"sound/there_home.wav");
		MCIWndPlay(m_hMCI);*/
		break;
	case 2://炸弹人移动音效
		PlaySound(L"sound\\move.wav", NULL, SND_FILENAME | SND_ASYNC);
		break;
	case 3://放置炸弹音效
		PlaySound(L"sound\\win.wav", NULL, SND_FILENAME | SND_ASYNC);
		break;
	case 4:
		PlaySound(L"sound\\gift.wav", NULL, SND_FILENAME | SND_ASYNC);
	case 5://地图2音乐
		mciSendString(L"open sound/hero_6977.mp3 alias back", NULL, 0, NULL);
		mciSendString(L"play back repeat", NULL, 0, NULL);
		break;
	case 6://欢迎界面音乐
		mciSendString(L"open sound/super_mary.mp3 alias back", NULL, 0, NULL);
		mciSendString(L"play back repeat", NULL, 0, NULL);
	default:
		break;
	}
}