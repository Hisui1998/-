#include <DxLib.h>

int main()
{
	ChangeWindowMode(true);
	SetGraphMode(800,600,32);
	SetDrawScreen(DX_SCREEN_BACK);
	DxLib_Init();
	const int tilesize = 10;
	int window_x, window_y;
	GetWindowSize(&window_x,&window_y);

	

	while (!ProcessMessage()&&!CheckHitKey(KEY_INPUT_ESCAPE))
	{
		ClearDrawScreen();

		for (int y = 0;y< window_y /tilesize;++y)
		{
			for (int x = 0; x < window_x / tilesize; ++x)
			{
				DrawLine(x*tilesize, 0, x*tilesize, window_y, 0xffffff);
				DrawLine(0, y*tilesize, window_x, y*tilesize, 0xffffff);
			}
		}

		ScreenFlip();
	}

	DxLib_End();
	return 0;
}