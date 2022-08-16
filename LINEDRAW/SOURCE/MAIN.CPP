#include <iostream.h>
#include <stdlib.h>
#include <dos.h>
#include <conio.h>
#include <time.h>
#include <stdio.h>
#include <mem.h>
#include "mappings.h"

void set_mode(byte mode);
void plot_pixel(int x, int y, byte color);
long get_clock();
void plot_pixel_fast(int x, int y, byte color);
void plot_pixel_faster(int x, int y, byte color);
void line_fast(int x1, int y1, int x2, int y2, byte color);

int main()
{
	srand(*my_clock);
	set_mode(VGA_256_COLOR_MODE);
	cout << "Line drawing started press ENTER to draw a line" << endl;
	getch();
	int i = 0;

	line_fast(100, 100, 150, 150, 100);
	cout << "Line Drawing ended press ENTER to exit program" << endl;
	getch();
	set_mode(TEXT_MODE);
	return 0;
}

void line_fast(int x1, int y1, int x2, int y2, byte color){
	int i, dx, dy, sdx, sdy, dxabs, dyabs, x, y, px, py;

	dx=x2-x1;
	dy=y2-y1;
	dxabs=abs(dx);
	dyabs=abs(dy);
	sdx=sgn(dx);
	sdy=sgn(dy);
	//sdx = ((x<0) ? -1: ((x>0)?1:0));
	//sdy = ((x<0)?-1:((x>0)?1:0));
	x=dyabs>>1;
	y=dxabs>>1;
	px=x1;
	py=y1;

	VGA[(py<<8)+(py<<6)+px] = color;

	if(dxabs >= dyabs) // the line is more horizontal than vertical
	{
		for(i = 0; i < dxabs; i++){
			y+=dyabs;
			if(y>=dxabs){
				y-=dxabs;
				py+=sdy;

			}
			px += sdx;
			plot_pixel(px, py, color);
		}
	}
	else // The line is more vertical than horizontal
	{
		cout << "More vertical lines not implemented yet" << endl;
	}
}

void set_mode(byte mode)
{
	union REGS regs;
	regs.h.ah = SET_MODE;
	regs.h.al = mode;
	int86(VIDEO_INT, &regs, &regs);
}

void plot_pixel(int x, int y, byte color)
{
	union REGS regs;
	regs.h.ah = WRITE_DOT;
	regs.h.al = color;
	regs.x.cx = x;
	regs.x.dx = y;
	int86(VIDEO_INT, &regs,&regs);
}

void plot_pixel_fast(int x, int y, byte color)
{
	VGA[y*SCREEN_WIDTH+x]=color;
}

void plot_pixel_faster(int x, int y, byte color)
{
	int offset = (y<<8) + (y<<6) + x;
	VGA[offset]=color;
}

long get_clock()
{
	long time = clock() / CLOCKS_PER_SEC;
	return (time);
}