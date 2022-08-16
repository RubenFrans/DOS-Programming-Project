#ifndef MAPPINGS_H_
#define MAPPINGS_H_

#define VIDEO_INT		0X10	// BIOS video interrupt
#define WRITE_DOT		0x0C    // BIOS func to plot a pixel
#define SET_MODE		0x00	// BIOS func to set the video mode
#define VGA_256_COLOR_MODE	0x13    // use to set 256-color mode
#define TEXT_MODE		0x03	// use to set 80x25 text mode

#define SCREEN_WIDTH		320	// witdt in pixels of mode 0x13
#define SCREEN_HEIGHT		200	// height in pixels of mode 0x13
#define NUM_COLORS		256	// numbers of colors in mode 0x13

#define sgn(x) ((x<0)?-1:((x>0)?1:0))

typedef unsigned char far byte;
typedef unsigned short word;

byte *VGA=(byte *)0xA0000000L;
word *my_clock=(word *)0x0000046C;

#endif // MAPPINGS_H