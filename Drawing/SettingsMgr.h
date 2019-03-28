#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

enum ShapeEnum { CIRCLE, SQUARE };

// finish this code; add functions, data as needed

class SettingsMgr
{
private:
	Color color;
	ShapeEnum shape;
public:
	SettingsMgr(Color startingColor, ShapeEnum startingShape )
	{
		color = startingColor;
		shape = startingShape;
	}
	Color getCurColor()
	{
		return color; 
	}
	ShapeEnum getCurShape()
	{
		return shape; 
	}
	void setCurColor(Color startingColor) 
	{
		color = startingColor;
	}
	void setCurShape(ShapeEnum startingShape)
	{
		shape = startingShape;
	}
	void load(fstream& binFile)
	{
		unsigned int colorNumber;
		binFile.read(reinterpret_cast<char*>(&colorNumber), sizeof(colorNumber));
		Color aColor(colorNumber);	
		color = aColor;
		binFile.read(reinterpret_cast<char*>(&shape), sizeof(shape));
	}
	void save(fstream& binFile)
	{
		unsigned int colorNumber = color.toInteger();
		binFile.write(reinterpret_cast<char*>(&colorNumber), sizeof(colorNumber));
		binFile.write(reinterpret_cast<char*>(&shape), sizeof(shape));
	}
};
