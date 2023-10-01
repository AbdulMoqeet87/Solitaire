#include<iostream>
#include"Cards.h"
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;


class Hearts :public Cards
{
	

public:
	Hearts(int ri, int ci, int number, string clr);
//	Hearts(int home_ci, int home_ri, const string);
	void DisplayCard(int ri, int ci, RenderWindow& window)override;
	bool IsLegal(int num2, string color, bool Is_Stack, bool Is_House)override;

};
