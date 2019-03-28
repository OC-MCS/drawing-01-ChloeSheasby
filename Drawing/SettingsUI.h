#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "SettingsMgr.h"

// finish this code; add functions, data as needed

class SettingsUI
{
private:
	SettingsMgr *ptr;		
	CircleShape blueBtn;
	CircleShape redBtn;
	CircleShape greenBtn;
	CircleShape circleBtn;
	RectangleShape squareBtn;
public:
	SettingsUI(SettingsMgr *mgr) 
	{
		// initializes all buttons before the settings manager changes to the decisions
		initializeButtons(blueBtn, Color::Blue);
		initializeButtons(redBtn, Color::Red);
		initializeButtons(greenBtn, Color::Green);
		initializeButtons(circleBtn, Color::White);
		squareBtn.setOutlineColor(Color::White);
		squareBtn.setOutlineThickness(2);
		squareBtn.setSize(Vector2f(20, 20));
		squareBtn.setFillColor(Color::Transparent);

		ptr = mgr;
	}
	void handleMouseUp(Vector2f mouse)
	{
		if (blueBtn.getGlobalBounds().contains(mouse))
		{
			// the mouse is currently over blueBtn
			ptr->setCurColor(Color::Blue);
		}
		else if (redBtn.getGlobalBounds().contains(mouse))
		{
			ptr->setCurColor(Color::Red);
		}
		else if (greenBtn.getGlobalBounds().contains(mouse))
		{
			ptr->setCurColor(Color::Green);
		}

		if (circleBtn.getGlobalBounds().contains(mouse))
		{
			ptr->setCurShape(CIRCLE);
		}
		else if (squareBtn.getGlobalBounds().contains(mouse))
		{
			ptr->setCurShape(SQUARE);
		}
	}
	void draw(RenderWindow& win)
	{
		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
			die("couldn't load font");

		Text titleColor("Selected Color", font, 22);
		titleColor.setPosition(30, 30);
		win.draw(titleColor);

		if (ptr->getCurColor() == Color::Blue)
		{
			blueBtn.setFillColor(Color::Blue);
			redBtn.setFillColor(Color::Transparent);
			greenBtn.setFillColor(Color::Transparent);
		}
		else if (ptr->getCurColor() == Color::Red)
		{
			redBtn.setFillColor(Color::Red);
			blueBtn.setFillColor(Color::Transparent);
			greenBtn.setFillColor(Color::Transparent);
		}
		else if (ptr->getCurColor() == Color::Green)
		{
			greenBtn.setFillColor(Color::Green);
			blueBtn.setFillColor(Color::Transparent);
			redBtn.setFillColor(Color::Transparent);
		}

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

		Vector2f posB(100, 60);
		blueBtn.setPosition(posB);
		win.draw(blueBtn);

		Vector2f posR(100, 90);
		redBtn.setPosition(posR);
		win.draw(redBtn);

		Vector2f posG(100, 120);
		greenBtn.setPosition(posG);
		win.draw(greenBtn);

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
	void die(string msg)
	{
		cout << msg << endl;
		exit(-1);
	}
	void initializeButtons(CircleShape &button, Color color)
	{
		button.setRadius(10);
		button.setOutlineThickness(2);
		button.setOutlineColor(color);
		button.setFillColor(Color::Transparent);
	}
};
