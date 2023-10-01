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
	
public:

	virtual void DisplayCard(int ri, int ci, RenderWindow& window) = 0;	

	virtual bool IsLegal(int num2, string color, bool Is_Stack, bool Is_House) = 0;
	Cards& operator =(const Cards& C2)
	{
		number = C2.number;
		_color= C2._color;
		x = C2.x;
		y = C2.y;
		HouseName = C2.HouseName;
		outline = C2.outline;
		Card= C2.Card;
		return *this;
	}
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
		outline.setOutlineThickness(1);
		outline.setOutlineColor(sf::Color::Red);
	}
	void UnHighlightCard()
	{
		outline.setOutlineThickness(0);
		outline.setOutlineColor(sf::Color::Transparent);
	}
//make getlocal bound function inside every card class and get their local bounds

	
	string gethouseNAme()
	{
		return HouseName;

	}
	void SetRowCol(int _x, int _y)
	{
		
		x = _x, y = _y;
	}


};

