#include "../include/view.hpp"

/* VE KHUNG */
void DrawFrame(int x1, int x2, int y1, int y2, int color)
{
	char ch = ' ';
	TextColor(color);

	// vẽ thanh trên
	for (int i = 0; i < (x2 - x1); i++)
	{
		gotoXY(x1 + i, y1);
		putch(ch);
	}

	// vẽ thanh phải
	for (int i = 0; i < (y2 - y1); i++)
	{
		gotoXY(x2, y1 + i);
		putch(ch);
	}

	// vẽ thanh dưới
	for (int i = 0; i < (x2 - x1); i++)
	{
		gotoXY(x2 - i, y2);
		putch(ch);
	}

	// vẽ thanh phải
	for (int i = 0; i < (y2 - y1); i++)
	{
		gotoXY(x1, y2 - i);
		putch(ch);
	}
}

/* VE THANH LOADING BAR */
void LoadingBar()
{ 
	int count = 0;
	gotoXY(50, 14);
	puts("Loading ...");

	DrawFrame(18, 93, 16, 19, PRIMARY_COLOR);

	for (int i = 1; i < 75; i++)
	{
		TextColor(SECONDARY_COLOR);
		for (int j = 0; j < 2; j++)
		{
			gotoXY(18 + i, 17 + j);
			putch(' ');
		}

		count = (int)(i*1.36);
		TextColor(default_ColorCode);
		gotoXY(52, 22);
		printf("%d %%", count);

		Sleep(50);
	}

	TextColor(default_ColorCode);
}

/* VE NUT */
void Button(int x1, int x2, int y, char* title, int position_title, int color)
{
	TextColor(color);
	int x;
	
	// vẽ khung cho button
	for (int j = y; j < (y + 3); j++)
	{
		for (int i = x1; i < x2; i++)
		{
			gotoXY(i, j);
			putch(' ');
		}
	}

	switch (position_title)
	{
		case POS_CENTER:
			x = (((x2 - x1)/2 + x1) - (strlen(title)/2 - 2));
			break;
		case POS_LEFT:
			x = x1 + 1;
			break;
		case POS_RIGHT:
			x = x2 - strlen(title);
			break;
	}

	gotoXY(x, y + 1);
	puts(title);
}

/* VE KHUNG BANG DUYET TU */
void FrameViewDict(int x1, int x2, int y1, int y2)
{
	DrawFrame(x1, x2, y1, y2, PRIMARY_COLOR);

	gotoXY(14, 0);
	puts("DANH SÁCH TỪ");

	TextColor(default_ColorCode);
	for (int i = 1; i < 39; i++)
	{
		gotoXY(i, 1);
		putch('=');
	}

	for (int i = 1; i < 39; i++)
	{
		gotoXY(i, 3);
		putch('=');
	}

	gotoXY(1, 2);
	puts("Từ khoá |");

	gotoXY(0, MAX_Y);
}

/* VE LOGO */
void DrawLogo(int x, int y)
{
	char logo[5][100] = 
	{
		//          T 								U									Đ						  I								E								N																		A											N						H														V									I					E							T
		{'*', '*', '*', '*', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ',' ', ' ', '*', '*', '*', ' ', ' ', ' ', '*', ' ', ' ', '*', '*', '*', '*', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ',' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', '*', '*', '*', ' ', ' ', '*', '*', '*', '*', '*'},
		{' ', ' ', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ',' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ',' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' '},
		{' ', ' ', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ',' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', '*', '*', '*', ' ', ' ', '*', ' ', '*', ' ', '*', ' ', ' ', ' ', ' ',' ', ' ', ' ', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', '*', ' ', '*', ' ', '*', ' ', ' ', '*', '*', '*', '*', ' ', ' ', '*', '*','*', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', '*', '*', '*', '*', ' ', ' ', ' ', ' ', '*', ' ', ' '},
		{' ', ' ', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ',' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ',' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' '},
		{' ', ' ', '*', ' ', ' ', ' ', ' ', '*', '*', '*', '*', ' ', ' ', ' ', ' ',' ', ' ', '*', '*', '*', ' ', ' ', ' ', '*', ' ', ' ', '*', '*', '*', '*', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ',' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', '*', '*', '*', ' ', ' ', ' ', ' ', '*', ' ', ' '}
	};

	for (int i = 0; i < 5; i++)
	{
		gotoXY(x, y++);
		TextColor(default_ColorCode);
		for (int j = 0; j < 94; j++)
		{
			putch(logo[i][j]);
		}
	}
}
