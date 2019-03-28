#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "ShapeMgr.h"

// finish this code; add functions, data as needed
const float WIDTH = 500.0;
const float LENGTH = 300.0;

class DrawingUI
{
private:
	RectangleShape drawingCanvas;

public:
	DrawingUI(Vector2f p)	// creates the box in which the user can draw
	{
		drawingCanvas.setPosition(p);
		drawingCanvas.setOutlineColor(Color::White);
		drawingCanvas.setOutlineThickness(2);
		drawingCanvas.setSize(Vector2f(WIDTH, LENGTH));
		drawingCanvas.setFillColor(Color::White);
	}

	void draw(RenderWindow& win, ShapeMgr *mgr)
	{
		vector<DrawingShape*> *shapes;
		shapes = mgr->returnVector();
		win.draw(drawingCanvas);
		for (int i = 0; i < shapes->size(); i++)
		{
			(*shapes)[i]->draw(win);
		}
	}
	
	bool isMouseInCanvas(Vector2f mousePos)
	{
		bool isInCanvas;
		if (drawingCanvas.getGlobalBounds().contains(mousePos) && 
			drawingCanvas.getGlobalBounds().contains(Vector2f(mousePos.x + SIDE, mousePos.y + SIDE)))
			isInCanvas = true;
		else
			isInCanvas = false;
		return isInCanvas; 
	}

};

