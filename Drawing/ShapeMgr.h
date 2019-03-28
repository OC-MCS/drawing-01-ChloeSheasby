#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include "DrawingShape.h"

using namespace std;
using namespace sf;

class ShapeMgr
{
private:
	vector<DrawingShape*> shapes;	// holds each individual shape when they are created
public:
	//==============================================================================
	// this is here just so that there is a syntax error, nothing needs to be placed
	// inside a new ShapeMgr
	//==============================================================================
	ShapeMgr()
	{
	}

	//==============================================================================
	// this takes the information of a shape (position, shape, and color), and based
	// on the shape, adds a shape with it's information to the vector of shapes
	// new memory is allocated for each new shape so that the vector of pointers
	// can continue pointing to the shapes after the function has ended
	//==============================================================================
	void addShape(Vector2f pos, ShapeEnum whichShape, Color color)
	{
		if (whichShape == SQUARE)
		{
			Square *sqr;	// creates a pointer to a square so that new memory can be allocated
			sqr = new Square(pos, color);
			shapes.push_back(sqr);	// pushes the new square into the vector of shapes
		}
		else if (whichShape == CIRCLE)
		{
			Circle *circ;	// creates a pointer to a circle so that new memory can be allocated
			circ = new Circle(pos, color);	
			shapes.push_back(circ);		// pushes the new circle into the vector of shapes
		}
	}

	//==============================================================================
	// this function takes the information from the file, which was saved as an
	// object of the struct Record, and calls addShape to put the saved shapes
	// back into the vector of shapes
	//==============================================================================
	void load(fstream &binFile)
	{
		Record temp;	// temporarily holds the record information for each shape
		while (binFile.read(reinterpret_cast<char*>(&temp), sizeof(temp)))
		{
			addShape(temp.position, temp.shape, Color(temp.color));		//converts color integer back to a color
		}
	}

	//==============================================================================
	// this function takes the information of each shape in the form of a Record,
	// which is a struct, and writes the records to a binary file
	//==============================================================================
	void save(fstream &binFile)
	{
		Record temp;	// temporarily holds the record info for each shape
		for (int i = 0; i < shapes.size(); i++)
		{
			temp = shapes[i]->getRecordInfo();		// this gets the information in Record form for each shape
			binFile.write(reinterpret_cast<char*>(&temp), sizeof(temp));
		}
	}

	//=======================================================================================
	// this returns the address of the vector of shapes so that other functions (and pointers
	// in other functions) can access it
	//=======================================================================================
	vector<DrawingShape*> *returnVector() 
	{
		return &shapes;
	}
};
