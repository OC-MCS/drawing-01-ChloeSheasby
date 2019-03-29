#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "ShapeMgr.h"

const float WIDTH = 550.0;		// holds the width of the canvas
const float LENGTH = 370.0;		// holds the length of the canvas

class DrawingUI
{
private:
	RectangleShape drawingCanvas;	// holds the data for the canvas that the user draws in

public:
	//============================================================
	// this is a constructor that initializes the drawing canvas
	//============================================================
	DrawingUI(Vector2f p)	
	{
		drawingCanvas.setPosition(p);
		drawingCanvas.setOutlineColor(Color::White);
		drawingCanvas.setOutlineThickness(2);
		drawingCanvas.setSize(Vector2f(WIDTH, LENGTH));
		drawingCanvas.setFillColor(Color::White);
	}

	//==============================================================================
	// this function draws the drawing canvas and then the shapes by taking 
	// information from the vector of shapes and drawing each one
	// a pointer to ShapeMgr is made to hold the information from the vector of 
	// shapes by calling the function in ShapeMgr that will return a pointer to the 
	// vector
	//==============================================================================
	void draw(RenderWindow& win, ShapeMgr *mgr)
	{
		vector<DrawingShape*> *shapes;	// creates a pointer to the vector that holds the shapes
		shapes = mgr->returnVector();	// initializes the pointer to the vector with the address 
										// of the vector that is returned from returnVector() in ShapeMgr
		win.draw(drawingCanvas);	// draws the canvas
		for (int i = 0; i < shapes->size(); i++)
		{
			(*shapes)[i]->draw(win);	// draws each shape in the vector until it reaches the end of the vector
		}
	}
	
	//================================================================================
	// this function makes sure that the mouse is inside the drawing canvas and also
	// takes into account the size of the shapes so that they do not go over on the
	// right or bottom sides of the drawing canvas
	// it also returns a boolean depending on if the mouse is inside the canvas or not
	//================================================================================
	bool isMouseInCanvas(Vector2f mousePos)
	{
		bool isInCanvas;
		if (drawingCanvas.getGlobalBounds().contains(mousePos) &&
			drawingCanvas.getGlobalBounds().contains(Vector2f(mousePos.x + SIDE, mousePos.y + SIDE)))
		{
			isInCanvas = true;
		}
		else
			isInCanvas = false;
		return isInCanvas; 
	}
};

