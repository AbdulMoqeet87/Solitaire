#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include"Cards.h"
#include"MyStack.h"
#include"House.h"
#include<queue>
using namespace std;
using namespace sf;
class Board
{

	Cards** Deck;
	queue<Cards*>Helper_Deck; //left corner wala dec
	vector<Cards*>Chota_Helper;// jb main deck select krein to uska helping deck
	queue<Cards*>Temp_Deck;// jb main deck select krein to uska helping deck
	RectangleShape* Rects;	
	//MyStack<Cards*>*S;
	MyStack<Cards>*S;
	Texture CB;
	Sprite CardBAck;
	vector<Cards*>temp;
	House** Houses;
	Texture HD;
	Sprite HelperDeck_IMG;
	Texture HD_icon;
	Sprite Helper_icon;
	RectangleShape Helper_D_Rect;
	RectangleShape HelperDeckArea;
	bool HelperReloaded;
	int GameMOde;
	int Moves;

public:
	Board();
	void Display(RenderWindow& window);
	void Shuffle();
	void DisplayCardBack(int ri, int ci, RenderWindow& window);
	bool SelectCard(RenderWindow&window,int& stack_index, int& House_index,bool& HelperSelected);
	void DrawTemp(int x, int y, RenderWindow& window);
	bool isvalidDestination(int mouse_X, int mouse_y, int stack_index, int& dest_stack_index,int &House_index);
	void ReturnCards(int stack_index);
	void PushIntoStack(int stack_index, int dest_index);
	void PushIntoHouse(int dest_House_index, int stack_index);
	void DisplayAnimation(RenderWindow& window,int dest_houseIndex);
	void PushBackToHouse(int House_index);
	void DrawHelperDeck(RenderWindow&window);
	bool HelperDeckContain(int x, int y);
	void ShiftHelperDeck();
	void DrawChotaHelper(RenderWindow& window);
	void PushBackToChotaHelper();
	void UpdateChotaHelper();
	void SetGAmeMode(int GM);
	int GetMoves();
	void SetMoves(int);
	

}
;
