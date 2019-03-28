#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include "DrawingShape.h"

using namespace std;
using namespace sf;

// finish the ShapeMgr class.

class ShapeMgr
{
private:
	vector<DrawingShape*> shapes;
public:
	ShapeMgr()
	{
		// it's okay for this to be empty
	}
	void addShape(Vector2f pos, ShapeEnum whichShape, Color color)
	{
		if (whichShape == SQUARE)
		{
			Square *sqr;
			sqr = new Square(pos, color);
			shapes.push_back(sqr);
		}
		else if (whichShape == CIRCLE)
		{
			Circle *circ;
			circ = new Circle(pos, color);	// must allocate new memory so that the address does not go away at the end of the function
			shapes.push_back(circ);
		}
	}
	void load(fstream &binFile)
	{
		// change file I/O after everything else works
		Record temp;
		while (binFile.read(reinterpret_cast<char*>(&temp), sizeof(temp)))
		{
			addShape(temp.position, temp.shape, Color(temp.color));		//converts color integer back to a color
		}
	}
	void save(fstream &binFile)
	{
		Record temp;
		for (int i = 0; i < shapes.size(); i++)
		{
			temp = shapes[i]->getRecordInfo();
			binFile.write(reinterpret_cast<char*>(&temp), sizeof(temp));
		}
	}
	vector<DrawingShape*> *returnVector() 
	{
		return &shapes;
	}
};
