#include "CBgm.h"
//#include <Windows.h>
#include "vfw.h"

CBgm::CBgm() {

}

CBgm::~CBgm() {

}
// mciSendString�����back���1,5,6����������ͬ����Ḳ�ǣ������ͬ���ͬʱ���ţ���back1,back2,back3
// �ر�����ΪmciSendString(L"close back",NULL,0,NULL);
void CBgm::Playsound(int k) {
	switch (k) {
	case 1://��ͼ1����
		//PlaySound(L"sound\\there_home.wav", NULL, SND_FILENAME | SND_ASYNC);
		mciSendString(L"open sound/hero_6976.mp3 alias back", NULL, 0, NULL);
		mciSendString(L"play back repeat", NULL, 0, NULL);
		/*
		HWND m_hMCI;
		m_hMCI = MCIWndCreate(NULL,NULL,WS_POPUP | MCIWNDF_NOPLAYBAR | 
					MCIWNDF_NOMENU, L"sound/there_home.wav");
		MCIWndPlay(m_hMCI);*/
		break;
	case 2://ը�����ƶ���Ч
		PlaySound(L"sound\\move.wav", NULL, SND_FILENAME | SND_ASYNC);
		break;
	case 3://����ը����Ч
		PlaySound(L"sound\\win.wav", NULL, SND_FILENAME | SND_ASYNC);
		break;
	case 4:
		PlaySound(L"sound\\gift.wav", NULL, SND_FILENAME | SND_ASYNC);
	case 5://��ͼ2����
		mciSendString(L"open sound/hero_6977.mp3 alias back", NULL, 0, NULL);
		mciSendString(L"play back repeat", NULL, 0, NULL);
		break;
	case 6://��ӭ��������
		mciSendString(L"open sound/super_mary.mp3 alias back", NULL, 0, NULL);
		mciSendString(L"play back repeat", NULL, 0, NULL);
	default:
		break;
	}
}