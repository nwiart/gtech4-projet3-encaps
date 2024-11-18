#pragma once


class ColorRGBA
{
public:

	inline ColorRGBA()
		: r(0xFF), g(0xFF), b(0xFF), a(0xFF)
	{

	}

	inline ColorRGBA(float r, float g, float b, float a = 1.0F)
		: r(r * 255.0F), g(g * 255.0F), b(b * 255.0F), a(a * 255.0F)
	{

	}

	inline unsigned char getR() const { return r; }
	inline unsigned char getG() const { return g; }
	inline unsigned char getB() const { return b; }
	inline unsigned char getA() const { return a; }


private:

	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;
};
