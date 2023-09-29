#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;


class Cards
{
protected:
	int number;
	int x, y;
	string _color;
	string HouseName;
	RectangleShape outline;
	Texture Img;
	Sprite Card;
	Texture hom;
	
public:
		
	RectangleShape MyHome;
	Sprite home_logo;
	virtual void DisplayCard(int ri, int ci, RenderWindow& window) = 0;	

	virtual bool IsLegal(int num2, string color, bool Is_Stack, bool Is_House) = 0;
	int getnum()
	{
		return number;
	}
	bool Contains(int x,int y)
	{
		if (Card.getGlobalBounds().contains(x, y))
			return true;
		return false;
	}
	void Setposition(int x,int y)
	{
		Card.setPosition(x, y);
	}
	string GetColor()
	{
		return this->_color;
	}
	void HighlightCard()
	{
		outline.setOutlineThickness(4);
		outline.setOutlineColor(sf::Color::Green);
	}
	void UnHighlightCard()
	{
		outline.setOutlineThickness(0);
		outline.setOutlineColor(sf::Color::Transparent);
	}
//make getlocal bound function inside every card class and get their local bounds

	void DisplayHome(RenderWindow&window)
	{
		window.draw(MyHome);
		window.draw(home_logo);
	}
	string gethouseNAme()
	{
		return HouseName;

	}

};

