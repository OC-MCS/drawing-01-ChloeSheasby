#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "SettingsMgr.h"

class SettingsUI
{
private:
	SettingsMgr *ptr;		// pointer to SettingsMgr that holds the current settings
	CircleShape blueBtn, redBtn, greenBtn, magentaBtn, cyanBtn, yellowBtn, circleBtn;	
				// holds the information for the circular buttons
	RectangleShape squareBtn;	// holds the information for the square button
public:
	//==============================================================================
	// this constructor initializes all buttons that the user could choose from
	// it also calls the function initializeButtons, which initializes the similar
	// attributes of all the circular buttons (by passing it the button's name by 
	// reference, the desired color, and the desire position)
	//==============================================================================
	SettingsUI(SettingsMgr *mgr) 
	{
		// initializes all buttons before the settings manager changes to the decisions
		initializeButtons(blueBtn, Color::Blue, Vector2f(80, 60));
		initializeButtons(cyanBtn, Color::Cyan, Vector2f(120, 60));
		initializeButtons(greenBtn, Color::Green, Vector2f(80, 90));
		initializeButtons(yellowBtn, Color::Yellow, Vector2f(120, 90));
		initializeButtons(redBtn, Color::Red, Vector2f(80, 120));
		initializeButtons(magentaBtn, Color::Magenta, Vector2f(120, 120));
		initializeButtons(circleBtn, Color::White, Vector2f(100, 190));
		squareBtn.setOutlineColor(Color::White);
		squareBtn.setOutlineThickness(2);
		squareBtn.setSize(Vector2f(20, 20));
		squareBtn.setFillColor(Color::Transparent);
		squareBtn.setPosition(Vector2f(100, 220));

		ptr = mgr;	// this initializes the pointer in this class with the passed SettingsMgr pointer
					// so that it can access the information in SettingsMgr
	}

	//==============================================================================
	// this function checks for which button the mouse is over and changes the 
	// current color and shape accordingly
	//==============================================================================
	void handleMouseUp(Vector2f mouse)
	{
		if (blueBtn.getGlobalBounds().contains(mouse))
			ptr->setCurColor(Color::Blue);		// i.e. the mouse is currently over blueBtn so the current color should be blue
		else if (cyanBtn.getGlobalBounds().contains(mouse))
			ptr->setCurColor(Color::Cyan);
		else if (greenBtn.getGlobalBounds().contains(mouse))
			ptr->setCurColor(Color::Green);
		else if (yellowBtn.getGlobalBounds().contains(mouse))
			ptr->setCurColor(Color::Yellow);
		else if (redBtn.getGlobalBounds().contains(mouse))
			ptr->setCurColor(Color::Red);
		else if (magentaBtn.getGlobalBounds().contains(mouse))
			ptr->setCurColor(Color::Magenta);

		if (circleBtn.getGlobalBounds().contains(mouse))
			ptr->setCurShape(CIRCLE);
		else if (squareBtn.getGlobalBounds().contains(mouse))
			ptr->setCurShape(SQUARE);
	}

	//==============================================================================
	// this function draws the wording for the selected shape/color and checks what 
	// the current color and shape is and fills the corresponding buttons based on 
	// which color/shape is chosen and draws all the buttons accordingly
	//==============================================================================
	void draw(RenderWindow& win)
	{
		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))	// loads the font
			die("couldn't load font");

		Text titleColor("Selected Color", font, 22);	// prints text
		titleColor.setPosition(30, 30);
		win.draw(titleColor);

		// sets the fill color based on the chosen color and makes all other colors transparent
		if (ptr->getCurColor() == Color::Blue)
		{
			blueBtn.setFillColor(Color::Blue);
			cyanBtn.setFillColor(Color::Transparent);
			greenBtn.setFillColor(Color::Transparent);
			yellowBtn.setFillColor(Color::Transparent);
			redBtn.setFillColor(Color::Transparent);
			magentaBtn.setFillColor(Color::Transparent);
		}
		else if (ptr->getCurColor() == Color::Cyan)
		{
			cyanBtn.setFillColor(Color::Cyan);
			blueBtn.setFillColor(Color::Transparent);
			greenBtn.setFillColor(Color::Transparent);
			yellowBtn.setFillColor(Color::Transparent);
			redBtn.setFillColor(Color::Transparent);
			magentaBtn.setFillColor(Color::Transparent);
		}
		else if (ptr->getCurColor() == Color::Green)
		{
			greenBtn.setFillColor(Color::Green);
			blueBtn.setFillColor(Color::Transparent);
			cyanBtn.setFillColor(Color::Transparent);
			yellowBtn.setFillColor(Color::Transparent);
			redBtn.setFillColor(Color::Transparent);
			magentaBtn.setFillColor(Color::Transparent);
		}
		else if (ptr->getCurColor() == Color::Yellow)
		{
			yellowBtn.setFillColor(Color::Yellow);
			blueBtn.setFillColor(Color::Transparent);
			greenBtn.setFillColor(Color::Transparent);
			cyanBtn.setFillColor(Color::Transparent);
			redBtn.setFillColor(Color::Transparent);
			magentaBtn.setFillColor(Color::Transparent);
		}
		else if (ptr->getCurColor() == Color::Red)
		{
			redBtn.setFillColor(Color::Red);
			blueBtn.setFillColor(Color::Transparent);
			greenBtn.setFillColor(Color::Transparent);
			yellowBtn.setFillColor(Color::Transparent);
			cyanBtn.setFillColor(Color::Transparent);
			magentaBtn.setFillColor(Color::Transparent);
		}
		else if (ptr->getCurColor() == Color::Magenta)
		{
			magentaBtn.setFillColor(Color::Magenta);
			blueBtn.setFillColor(Color::Transparent);
			greenBtn.setFillColor(Color::Transparent);
			yellowBtn.setFillColor(Color::Transparent);
			redBtn.setFillColor(Color::Transparent);
			cyanBtn.setFillColor(Color::Transparent);
		}

		// sets the shape based on the chosen shape and makes the other one transparent
		if (ptr->getCurShape() == CIRCLE)
		{
			circleBtn.setFillColor(Color::White);
			squareBtn.setFillColor(Color::Transparent);
		}
		else if (ptr->getCurShape() == SQUARE)
		{
			squareBtn.setFillColor(Color::White);
			circleBtn.setFillColor(Color::Transparent);
		}

		//draws all buttons and more text
		win.draw(blueBtn);
		win.draw(cyanBtn);
		win.draw(greenBtn);
		win.draw(yellowBtn);
		win.draw(redBtn);
		win.draw(magentaBtn);

		Text titleShape("Selected Shape", font, 22);
		titleShape.setPosition(30, 160);
		win.draw(titleShape);

		win.draw(circleBtn);
		win.draw(squareBtn);
	}

	//==================================================
	// this exits the program if the font does not load
	//==================================================
	void die(string msg)
	{
		cout << msg << endl;
		exit(-1);
	}

	//======================================================================
	// this function is passed the button by reference along with the color 
	// and position, which allows for efficient initialization of all the 
	// similar attributes of the circular buttons
	//======================================================================
	void initializeButtons(CircleShape &button, Color color, Vector2f pos)
	{
		button.setRadius(10);
		button.setOutlineThickness(2);
		button.setOutlineColor(color);
		button.setFillColor(Color::Transparent);
		button.setPosition(pos);
	}
};
