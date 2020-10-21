#ifndef CONSOLE_HPP
#define CONSOLE_HPP

/* hằng số màu */
#define ColorCode_Back			0
#define ColorCode_DarkBlue		1
#define ColorCode_DarkGreen		2
#define ColorCode_DarkCyan		3
#define ColorCode_DarkRed		4
#define ColorCode_DarkPink		5
#define ColorCode_DarkYellow	6
#define ColorCode_DarkWhite		7
#define ColorCode_Grey			8
#define ColorCode_Blue			9
#define ColorCode_Green			10
#define ColorCode_Cyan			11
#define ColorCode_Red			12
#define ColorCode_Pink			13
#define ColorCode_Yellow		14
#define ColorCode_White			15
#define default_ColorCode		7

/* hằng số phím di chuyển */
#define key_Up		1072
#define key_Down	1080
#define key_Left	1075
#define key_Right	1077
#define key_none	-1

/* code page */
#define UTF16	1200
#define UTF8	65001

enum KEY {KEY_UP, KEY_DOWN, KEY_SEARCH, KEY_EDIT, KEY_DELETE, KEY_ADD, KEY_EXIT, KEY_ENTER, KEY_NONE};

#include <windows.h>
#include <cwchar>
#include <stdio.h>
#include <conio.h>

/* LAY PHIM VUA NHAP */
KEY GetInputKey();

/* XOA MAN HINH */
void clrscr();

/* DI CHUYEN CON TRO CHUOT TOI VI TRI X, Y*/
void gotoXY (int column, int line);

/* LAY TOA DO CON TRO X */
int whereX();

/* LAY TOA DO CON TRO Y */
int whereY();

/* SET MAU CHU */
void TextColor (int color);

/* THAY DOI TIEU DE MAN HINH CONSOLE */
void SetTitle(char *title);

/* THAY DOI FONT CHU */
void SetFont(int size);

/* CHO PHEP SU DUNG CHUOT TRONG MAN HINH CONSOLE*/
void EnableMouse();

/* THAY DOI KICH THUOC CONSOLE */
void ResizeConsole(HANDLE handle, int width, int height);

/* THAY DOI CODEPAGE CONSOLE */
void SetCodePage(int codePage);

/* HIEN THI MESSAGE BOX */
int ShowMessageBox(char *message, char *caption, UINT type);

#include "../src/console.cpp"
#endif
