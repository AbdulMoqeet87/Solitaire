#include"Hearts.h"

Hearts::Hearts(int ri, int ci, int num, string clr)
{
	this->x = ci;
	this->y = ri;
	this->number = num;
	this->_color = clr;
	this->HouseName = "Hearts";
	if (number == 1)
		Img.loadFromFile("Ace_hearts.png");
	else if (number == 2)
		Img.loadFromFile("2_hearts.png");
	else if (number == 3)
		Img.loadFromFile("3_hearts.png");
	else if (number == 4)
		Img.loadFromFile("4_hearts.png");
	else if (number == 5)
		Img.loadFromFile("5_hearts.png");
	else if (number == 6)
		Img.loadFromFile("6_hearts.png");
	else if (number == 7)
		Img.loadFromFile("7_hearts.png");
	else if (number == 8)
		Img.loadFromFile("8_hearts.png");
	else if (number == 9)
		Img.loadFromFile("9_hearts.png");
	else if (number == 10)
		Img.loadFromFile("10_hearts.png");
	else if (number == 11)
		Img.loadFromFile("Jack_hearts.png");
	else if (number == 12)
		Img.loadFromFile("Queen_hearts.png");
	else if (number == 13)
		Img.loadFromFile("King_hearts.png");

	Card.setTexture(Img);

}

void Hearts::DisplayCard(int ri, int ci, RenderWindow& window)
{
	
	Card.setPosition(ri, ci);

	outline.setSize(Vector2f(102.0f, 136.0f));
	outline.setFillColor(Color::Red);
	outline.setPosition(Card.getPosition().x - 1, Card.getPosition().y - 1);
	window.draw(outline);
	window.draw(Card);
}
bool Hearts::IsLegal(int num2, string clr, bool Is_Stack, bool Is_House)
{
	if (Is_House)
	{
		if ((number > num2) && (_color == clr))
			return true;
	}
	//add house inside every class i.e house rectangle inside spade class
	return true;

}
