#include "../include/console.hpp"

/* NHAN PHIM NHAN TU BAN PHIM */
KEY GetInputKey()
{
	int KeyPressed = 0;
	KEY key = KEY_NONE;

	while (!KeyPressed)
	{
		fflush(stdin);

		if (GetAsyncKeyState(VK_UP) & 0x8000)
        {
            KeyPressed = 1;
            key = KEY_UP;
        }
        else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
        {
            KeyPressed = 1;
            key = KEY_DOWN;
        }
        else if (GetAsyncKeyState(VK_F1) & 0x8000)
        {
            KeyPressed = 1;
            key = KEY_SEARCH;
        }
		else if (GetAsyncKeyState(VK_F2) & 0x8000)
        {
            KeyPressed = 1;
            key = KEY_ADD;
        }
		else if (GetAsyncKeyState(VK_F3) & 0x8000)
        {
            KeyPressed = 1;
            key = KEY_EDIT;
        }
		else if (GetAsyncKeyState(VK_F4) & 0x8000)
        {
            KeyPressed = 1;
            key = KEY_DELETE;
        }
        else if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
        {
            KeyPressed = 1;
            key = KEY_EXIT;
        }
		else if (GetAsyncKeyState(VK_RETURN) & 0x8000)
		{
			KeyPressed = 1;
            key = KEY_ENTER;
		}

		fflush(stdin);
	}


	fflush(stdin);
	return key;
}

/* XOA MAN HINH */
void clrscr()
{
	system("cls");
}

/* DI CHUYEN CON TRO CHUOT DEN VI TRI X, Y*/
void gotoXY (int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

/* TRA VE VI TRI CON TRO X*/
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}

/* TRA VE VI TRI CON TRO Y*/
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}

/* THAY DOI MAU CHU */
void TextColor (int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , color);
}

/* THAY DOI KICH THUOC CONSOLE */
void ResizeConsole(HANDLE handle, int width, int height)
{
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD size2 = {width, height};
	SMALL_RECT ra;
	ra.Bottom = height;
	ra.Left = 0;
	ra.Right = width;
	ra.Top = 0;
	SetConsoleScreenBufferSize(handle, size2);
	SetConsoleWindowInfo(handle, TRUE, &ra);
}

/* THAY DOI TIEU DE CONSOLE */
void SetTitle(char *title)
{
	SetConsoleTitleA(title);
}

/* CHO PHEP SU DUNG CHUOT */
void EnableMouse()
{
	HANDLE handle = GetStdHandle( STD_INPUT_HANDLE );
	SetConsoleMode( handle, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT );
}

/* THAY DOPI CODE PAGE*/
void SetCodePage(int codePage)
{
	SetConsoleOutputCP(codePage);
}

/* HIEN THI MESSAGE BOX*/
int ShowMessageBox(char *message, char *caption, UINT type)
{
	HWND cur_window = GetConsoleWindow();
	
	return MessageBoxA(cur_window, message, caption, type);
}

/* THAY DOI FONT CHU */
void SetFont(int size)
{
	CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;                   // Width of each character in the font
    cfi.dwFontSize.Y = size;                  // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}
