#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include"Cards.h"
#include"MyStack.h"
#include"House.h"
#include<queue>
#include<SFML/Audio.hpp>
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
	RectangleShape CardBack_Rect;
	vector<Cards*>temp;
	House** Houses;
	Texture HD;
	Sprite HelperDeck_IMG;
	Texture HD_icon;
	Sprite Helper_icon;
	RectangleShape Helper_D_Rect;
	bool HelperReloaded;
	int GameMOde;
	int Moves;
	SoundBuffer CR;
	Sound CardReveal;
	SoundBuffer ATS;
	Sound AddToStack;
	Texture BG_;
	Sprite BackG;
	Texture UD;
	Texture RD;
	Sprite undo;
	Sprite redo;
	
public:
	Board();
	Board(const Board& B2);
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
	void ShiftHelperDeck(RenderWindow&window);
	void DrawChotaHelper(RenderWindow& window);
	void PushBackToChotaHelper();
	void UpdateChotaHelper();
	void SetGAmeMode(int GM);
	int GetMoves();
	void SetMoves(int);
	void CardAnimation(RenderWindow &window);
	bool AutoMoved(int stackindex,int houseindex,bool HelperUsed,RenderWindow&window);
	bool UndoContains(Vector2i MP);
	bool RedoContains(Vector2i MP);
	bool HasWon()
	{
		bool allrevealeed = true;
		for (int i = 0; i < 7; i++)
		{
			if (S[i].getUnRevealedSize() != 0)
			{
				allrevealeed = false;
				return allrevealeed;
			}
		}
		return allrevealeed;
	}

}
;
