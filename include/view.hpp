#ifndef VIEW_HPP
#define VIEW_HPP

#include <stdio.h>
#include <conio.h>
#include "../include/console.hpp"
#include "../include/model.hpp"

#define WIDTH 114   // kich thuoc man hinh
#define HEIGHT 37  // kich thuoc man hinh
#define MAX_Y 34    // toa do y lon nhat
#define PRIMARY_COLOR 159   // mau chinh
#define SECONDARY_COLOR 52  // mau phu
#define POS_CENTER 0    // vi tri hien thi title button
#define POS_LEFT   1    // vi tri hien thi title button
#define POS_RIGHT  2    // vi tri hien thi title button

/* VE KHUNG */
void DrawFrame(int x1, int x2, int y1, int y2, int color);

/* VE THANH LOADING */
void LoadingBar();

/* VE BUTTON */
void Button(int x1, int x2, int y, char* title, int position_title, int color);

/* VE KHUNG XEM DANH SACH TU */
void FrameViewDict(int x1, int x2, int y1, int y2);

/* VE KHUNG XEM NGHIA CUA TU*/
void FrameViewDescription();

/* VE LOGO */
void DrawLogo(int x, int y);

#include "../src/view.cpp"
#endif
