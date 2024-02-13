#include "../Square/Square.h"

Square::Square(const unsigned int x, const unsigned int y)
{
	this->setX(x);
	this->setY(y);
}

Square::Square(const Square& other)
{
	this->setX(other.getX());
	this->setY(other.getY());
}

Square::Square()
{
	this->setX(0);
	this->setY(0);
}

/*
	Setter for the x field. Throws an exception if the input is out of range.

	Input:
			x - The value to change to.

	Output:
			void.
*/
void Square::setX(const unsigned int x)
{
	if (x > MAX_COL || x < 0)
	{
		//Throw outOfBounds exception.
	}
	this->_x = x;
}

/*
	Setter for the y field. Throws an exception if the input is out of range.

	Input:
			y - The value to change to.

	Output:
			void.
*/
void Square::setY(const unsigned int y)
{
	if (y > MAX_ROW || y < 0)
	{
		//Throw outOfBounds exception.
	}
	this->_y = y;
}

/*
	Getter for the x field.

	Input:
			void.

	Output:
			The x field.
*/
unsigned int Square::getX() const
{
	return this->_x;
}

/*
	Getter for the y field.

	Input:
			void.

	Output:
			The y field.
*/
unsigned int Square::getY() const
{
	return this->_y;
}


/*
	Operator copies the values in the other square to this square.

	Input:
			other - The sqare to copy from.

	Output:
			void.
*/
void Square::operator=(const Square& other)
{
	this->setX(other.getX());
	this->setY(other.getY());
}