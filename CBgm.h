#pragma once
#include <Windows.h>
#include "mmsystem.h"
#pragma comment(lib,"winmm.lib")
class CBgm
{
public:
	CBgm();
	~CBgm();
	static void Playsound(int k);
};

