#ifndef RENDERER_H_
#define RENDERER_H_

// Enums are just defines of ints :|
enum VideoMode {
	TEXT = 0,
	GRAPHICS = 1
};

class Renderer{
  public:
	Renderer();
	~Renderer();
	void PlotPixel(int x, int y, byte color);
	void PlotPixelFast(int x, int y, byte color);
	void DrawLine(int x1, int y1, int x2, int y2, byte color);
	void DrawBitmap();
	void SetVideoMode(byte mode);
	VideoMode GetVideoMode();
  private:
	VideoMode m_CurrentVideoMode;
};
#endif