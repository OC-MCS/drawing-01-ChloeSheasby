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
	CircleShape blueBtn, redBtn, greenBtn, magentaBtn, cyanBtn, yellowBtn, circleBtn;	// holds the information for the circular buttons
	RectangleShape squareBtn;	// holds the information for the square button
public:
	//==============================================================================
	// this constructor initializes all buttons that the user could choose from
	// it also calls the function initializeButtons, which initializes the similar
	// attributes of all the circular buttons
	//==============================================================================
	SettingsUI(SettingsMgr *mgr) 
	{
		// initializes all buttons before the settings manager changes to the decisions
		initializeButtons(blueBtn, Color::Blue);
		initializeButtons(cyanBtn, Color::Cyan);
		initializeButtons(greenBtn, Color::Green);
		initializeButtons(yellowBtn, Color::Yellow);
		initializeButtons(redBtn, Color::Red);
		initializeButtons(magentaBtn, Color::Magenta);
		initializeButtons(circleBtn, Color::White);
		squareBtn.setOutlineColor(Color::White);
		squareBtn.setOutlineThickness(2);
		squareBtn.setSize(Vector2f(20, 20));
		squareBtn.setFillColor(Color::Transparent);

		ptr = mgr;	// this initializes the pointer in this class with the passed SettingsMgr pointer
	}

	//==============================================================================
	// this function checks for which button the mouse is over and changes the 
	// current color and shape accordingly
	//==============================================================================
	void handleMouseUp(Vector2f mouse)
	{
		if (blueBtn.getGlobalBounds().contains(mouse))
			ptr->setCurColor(Color::Blue);		// i.e. the mouse is currently over blueBtn
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
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
			die("couldn't load font");

		Text titleColor("Selected Color", font, 22);
		titleColor.setPosition(30, 30);
		win.draw(titleColor);

		// sets the fill color based on the chosen color
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

		// sets the shape based on the chosen shape
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

		Vector2f posBlue(80, 60);
		blueBtn.setPosition(posBlue);
		win.draw(blueBtn);

		Vector2f posCyan(120, 60);
		cyanBtn.setPosition(posCyan);
		win.draw(cyanBtn);

		Vector2f posGreen(80, 90);
		greenBtn.setPosition(posGreen);
		win.draw(greenBtn);

		Vector2f posYellow(120, 90);
		yellowBtn.setPosition(posYellow);
		win.draw(yellowBtn);

		Vector2f posRed(80, 120);
		redBtn.setPosition(posRed);
		win.draw(redBtn);

		Vector2f posMagenta(120, 120);
		magentaBtn.setPosition(posMagenta);
		win.draw(magentaBtn);

		Text titleShape("Selected Shape", font, 22);
		titleShape.setPosition(30, 160);
		win.draw(titleShape);

		Vector2f posC(100, 190);
		circleBtn.setPosition(posC);
		win.draw(circleBtn);

		Vector2f posS(100, 220);
		squareBtn.setPosition(posS);
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
	// this initializes all the similar attributes of the circular buttons
	//======================================================================
	void initializeButtons(CircleShape &button, Color color)
	{
		button.setRadius(10);
		button.setOutlineThickness(2);
		button.setOutlineColor(color);
		button.setFillColor(Color::Transparent);
	}
};
