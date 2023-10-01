#pragma once
#include"Board.h"

class Solitaire
{
	Board* B;
	int Game_Mode;
	int Moves;
	vector<Board>Undo;
	vector<Board>Redo;

public:
	Solitaire();
	//void DisplayBoard(RenderWindow& window);
	//void main_Shuffle();
	//bool SelectCard(RenderWindow&window, int& stack_index,int & House_index);
	//void DrawTemp(int x, int y, RenderWindow& window);
	//bool isvalidDestination(int mouse_X, int mouse_y, int stack_index,int& dest_stack_index, int& House_index);
	//void ReturnCards(int stack_index);
	//void PushIntoStack(int stack_index, int dest_index);
	//void PushIntoHouse(int dest_House_index, int stack_index);
	//void DisplayAnimation(RenderWindow& window, int dest_houseIndex);
	//void PushBackToHOuse(int House_index);
	//bool HelperDeckContain(int x, int y);
	//void ShiftHelperDeck();
	void Play(RenderWindow& window);
	int SelectMode(RenderWindow& window);
	void Starting(RenderWindow& window);
	//void DisplayDeckDistribution(RenderWindow& window);
	void Winning(RenderWindow& window);
	


};

