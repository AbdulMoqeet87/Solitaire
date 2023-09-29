#include"Diamond.h"

Diamond::Diamond(int ri, int ci, int num, string clr)
{
	this->x = ci;
	this->y = ri;
	this->number = num;
	this->_color = clr;
	this->HouseName = "Diamond";
	if (number == 1)
		Img.loadFromFile("Ace_diamonds.png");
	else if (number == 2)
		Img.loadFromFile("2_diamonds.png");
	else if (number == 3)
		Img.loadFromFile("3_diamonds.png");
	else if (number == 4)
		Img.loadFromFile("4_diamonds.png");
	else if (number == 5)
		Img.loadFromFile("5_diamonds.png");
	else if (number == 6)
		Img.loadFromFile("6_diamonds.png");
	else if (number == 7)
		Img.loadFromFile("7_diamonds.png");
	else if (number == 8)
		Img.loadFromFile("8_diamonds.png");
	else if (number == 9)
		Img.loadFromFile("9_diamonds.png");
	else if (number == 10)
		Img.loadFromFile("10_diamonds.png");
	else if (number == 11)
		Img.loadFromFile("Jack_diamonds.png");
	else if (number == 12)
		Img.loadFromFile("Queen_diamonds.png");
	else if (number == 13)
		Img.loadFromFile("King_diamonds.png");

	Card.setTexture(Img);

}

void Diamond::DisplayCard(int ri, int ci, RenderWindow& window)
{
	
	Card.setPosition(ri, ci);

	outline.setSize(Vector2f(102.0f, 136.0f));
	outline.setFillColor(Color::White);
	outline.setPosition(Card.getPosition().x - 1, Card.getPosition().y - 1);
	window.draw(outline);
	window.draw(Card);
}
bool Diamond::IsLegal(int num2, string clr, bool Is_Stack, bool Is_House)
{
	if (Is_House)
	{
		if ((number > num2) && (_color == clr))
			return true;
	}
	//add house inside every class i.e house rectangle inside spade class
	return true;

}
