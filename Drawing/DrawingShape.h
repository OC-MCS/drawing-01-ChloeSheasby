#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace sf;

// finish this code; add functions, classes, data as needed

const float RADIUS = 5.0;
const float SIDE = 10.0;

struct Record
{
	Vector2f position;
	int color;
	ShapeEnum shape;
};

// DrawingShape should be an abstract base class 
// for Circle and Square
class DrawingShape 
{
public:
	virtual void draw(RenderWindow& win) {};
	virtual Record getRecordInfo() = 0;
};

// add Circle, Square classes below. These are derived from DrawingShape
class Circle : public DrawingShape
{
private:
	CircleShape circle;
public:
	Circle(Vector2f pos, Color color)		// constructor
	{
		circle.setPosition(pos);
		circle.setRadius(RADIUS);
		circle.setOutlineThickness(2);
		circle.setOutlineColor(color);
		circle.setFillColor(color);
	}
	void draw(RenderWindow& win)
	{
		win.draw(circle);
	}
	Record getRecordInfo()
	{
		Record record;
		record.position = circle.getPosition();
		record.color = circle.getFillColor().toInteger();
		record.shape = CIRCLE;
		return record;
	}
};

class Square : public DrawingShape
{
private:
	RectangleShape square;
public:
	Square(Vector2f pos, Color color)		// constructor
	{
		square.setPosition(pos);
		square.setOutlineColor(color);
		square.setOutlineThickness(2);
		square.setSize(Vector2f(SIDE, SIDE));
		square.setFillColor(color);
	}
	void draw(RenderWindow& win)
	{
		win.draw(square);
	}
	Record getRecordInfo()
	{
		Record record;
		record.position = square.getPosition();
		record.color = square.getFillColor().toInteger();
		record.shape = SQUARE;
		return record;
	}
};


