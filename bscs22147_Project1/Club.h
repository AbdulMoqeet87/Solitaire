#include<iostream>
#include"Cards.h"
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;


class Club :public Cards
{
	
public:
	Club(int ri, int ci, int number, string clr);
	//Club(int home_ci, int home_ri, const string);
	void DisplayCard(int ri, int ci, RenderWindow& window)override;
	bool IsLegal(int num2, string color, bool Is_Stack, bool Is_House)override;

};
