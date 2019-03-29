#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace sf;


const float RADIUS = 5.0;		// holds the size of the radius for each circle drawn
const float SIDE = 10.0;		// holds the size of the sides for each square drawn

//==============================================================================
// this struct holds the information (position, color, and shape) for each shape
// drawn, this information can later be used when saving the drawing to a file
//==============================================================================
struct Record
{
	Vector2f position;	// holds the position
	int color;			// this saves color as an int instead of a Color
	ShapeEnum shape;	// holds the shape
};

//==============================================================================
// DrawingShape is an abstract base class for Circle and Square
// it has two polymorphic functions that Circle and Square override
//==============================================================================
class DrawingShape
{
public:
	virtual void draw(RenderWindow& win) = 0;
	virtual Record getRecordInfo() = 0;
};

class Circle : public DrawingShape
{
private:
	CircleShape circle;		// holds the information for circles
public:
	//==============================================================================
	// this is the constructor for circle, the position and color is passed to it
	// and it creates the circle with that information
	//==============================================================================
	Circle(Vector2f pos, Color color)		
	{
		circle.setPosition(pos);
		circle.setRadius(RADIUS);
		circle.setOutlineThickness(2);
		circle.setOutlineColor(color);
		circle.setFillColor(color);
	}

	//==============================================================================
	// this is just a one-liner that draws the circle
	//==============================================================================
	void draw(RenderWindow& win)
	{
		win.draw(circle);
	}

	//==============================================================================
	// this creates a record, which is defined as a struct, of a circle with the 
	// position, the color as an integer, and the shape defined as a circle
	//==============================================================================
	Record getRecordInfo()
	{
		Record record;
		record.position = circle.getPosition();
		record.color = circle.getFillColor().toInteger();	// this changes a Color color to an integer
		record.shape = CIRCLE;
		return record;
	}
};

class Square : public DrawingShape
{
private:
	RectangleShape square;	//holds the information for squares
public:	
	//==============================================================================
	// this is the constructor for square, the position and color is passed to it
	// and it creates the square with that information
	//==============================================================================
	Square(Vector2f pos, Color color)	
	{
		square.setPosition(pos);
		square.setOutlineColor(color);
		square.setOutlineThickness(2);
		square.setSize(Vector2f(SIDE, SIDE));
		square.setFillColor(color);
	}

	//=================================================
	// this is just a one-liner that draws the square
	//=================================================
	void draw(RenderWindow& win)
	{
		win.draw(square);
	}

	//==============================================================================
	// this creates a record, which is defined in a struct, of a square with the 
	// position, the color as an integer, and the shape defined as a square
	//==============================================================================
	Record getRecordInfo()
	{
		Record record;
		record.position = square.getPosition();
		record.color = square.getFillColor().toInteger();	// this changes a Color color to an integer
		record.shape = SQUARE;
		return record;
	}
};


