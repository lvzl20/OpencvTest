#include<opencv2\opencv.hpp>
#include "CGame.h"
#include "CBgm.h"
#include "CTools.h"
int main()
{
	CGame game;
	game.Welcome();
	game.Init();
	game.Run();
	game.Release();
	//cv::imshow("233",img);
	//cv::waitKey(0);
	return 0;
}