#pragma once

#define MAX_ROW 8
#define MAX_COL 8

class Square
{
public:
	Square();
	Square(const Square& other);
	Square(const unsigned int x, const unsigned int y);
	
	unsigned int getX() const;
	unsigned int getY() const;

	void setX(const unsigned int x);
	void setY(const unsigned int y);

	void operator=(const Square& other);

private:
	unsigned int _x;
	unsigned int _y;
	
};

