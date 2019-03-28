#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

enum ShapeEnum { CIRCLE, SQUARE };	// this enum holds the values for defining a circle or a shape so that they can be
									// defined as CIRCLE and SQUARE instead of integers
class SettingsMgr
{
private:
	Color color;		// holds the color
	ShapeEnum shape;	// holds the shape
public:
	//==================================================================================
	// this constructor initializes the passed color and shape and the starting settings
	//==================================================================================
	SettingsMgr(Color startingColor, ShapeEnum startingShape )
	{
		color = startingColor;	
		shape = startingShape;
	}

	//=================================================
	// this function returns just the color of a shape
	//=================================================
	Color getCurColor()
	{
		return color; 
	}

	//=================================================
	// this function returns just the shape of a shape
	//=================================================
	ShapeEnum getCurShape()
	{
		return shape; 
	}

	//=================================================
	// this function can set just the color of a shape
	//=================================================
	void setCurColor(Color startingColor) 
	{
		color = startingColor;
	}

	//=================================================
	// this function can set just the shape of a shape
	//=================================================
	void setCurShape(ShapeEnum startingShape)
	{
		shape = startingShape;
	}

	//==============================================================================
	// this function takes the color and shape from the file, and turns the color 
	// back into a Color color and places those in the settings
	//==============================================================================
	void load(fstream& binFile)
	{
		unsigned int colorNumber;
		binFile.read(reinterpret_cast<char*>(&colorNumber), sizeof(colorNumber));
		Color aColor(colorNumber);	// changes the int back into a color
		color = aColor;
		binFile.read(reinterpret_cast<char*>(&shape), sizeof(shape));
	}

	//==============================================================================
	// this function takes the set color and shape, changes the color to an int, 
	// and saves both of them to the file
	//==============================================================================
	void save(fstream& binFile)
	{
		unsigned int colorNumber = color.toInteger();	// changes the color into an int
		binFile.write(reinterpret_cast<char*>(&colorNumber), sizeof(colorNumber));
		binFile.write(reinterpret_cast<char*>(&shape), sizeof(shape));
	}
};
