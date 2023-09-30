#pragma once
#include<iostream>
#include<stack>
#include"Cards.h"
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class House
{
	string name;
	RectangleShape MyHome;
	Texture icon;
	Sprite Home_icon;
	stack<Cards*> Stack;
	int ri, ci;
public:
	
	House(string _name, string image_Path, int rect_x, int rect_y)
	{
		name = _name;
		icon.loadFromFile(image_Path);
		Home_icon.setTexture(icon);
		MyHome.setPosition(rect_x, rect_y);
		MyHome.setFillColor(Color(0, 0, 0, 0));
		//MyHome.setFillColor(Color::Green);
		MyHome.setSize(Vector2f(102.0f, 136.0f));
		MyHome.setOutlineThickness(3);
		MyHome.setOutlineColor(Color::Red);
			
		Home_icon.setPosition(rect_x +30, rect_y + 39);
	
		ri = rect_y;
		ci = rect_x;
	}
	bool Contains(int x, int y)
	{
		if (MyHome.getGlobalBounds().contains(x, y))
			return true;
		return false;
	}

	string GetName()
	{
		return name;
	}

	void Push(Cards* C)
	{
		Stack.push(C);
	}
	void Pop()
	{
		Stack.pop();
	}
	bool IsEmpty()
	{
		return Stack.empty();
	}
	int Size()
	{
		return Stack.size();
	}
	void DrawHouse(RenderWindow& window)
	{
		window.draw(MyHome);
		if(Stack.empty())
		{
			window.draw(Home_icon);
		}
		else
		{
			Stack.top()->DisplayCard(ci+1,ri+1,window);
		}
	}
	Cards* Top()
	{
		return Stack.top();
	}
	void SetOutlineColorRGB(int r,int g,int b,int a)
	{
		MyHome.setOutlineColor(Color(r, g, b, a));
	}
	void SetOutLineColor(Color C)
	{
		MyHome.setOutlineColor(C);
	}
	void SetoutlineSize(int size)
	{
		MyHome.setOutlineThickness(size);
	}
	int GetOutlineSize()
	{
		return MyHome.getOutlineThickness();
	}
	void SetSize(float x, float y)
	{
		MyHome.setSize(Vector2f(x, y));
	}
	void SetFillColor(Color C)
	{
		MyHome.setFillColor(C);
	}
	void SetPosition(int x, int y)
	{
		MyHome.setPosition(ci-x,ri-y);
	}


};

