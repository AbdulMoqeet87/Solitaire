#include"Solitaire.h"

Solitaire::Solitaire()
{
	B = new Board();
    Game_Mode = 0;
}
//void Solitaire::DisplayBoard(RenderWindow& window)
//{
//	
//	B->Display(window);
//}
//
//void Solitaire::main_Shuffle()
//{
//	
//	B->Shuffle();
//}
//bool Solitaire::SelectCard(RenderWindow&window,int& stack_index, int& House_index)
//{
//	return B->SelectCard(window,stack_index,House_index);
//
//}
//void Solitaire::DrawTemp(int x, int y, RenderWindow& window)
//{
//	B->DrawTemp(x, y, window);
//}
//bool Solitaire::isvalidDestination(int mouse_X, int mouse_y, int stack_index, int& dest_stack_index, int& House_index)
//{
//
//	return B->isvalidDestination(mouse_X, mouse_y, stack_index,dest_stack_index,House_index);
//}
//void Solitaire::ReturnCards(int stack_index)
//{
//	B->ReturnCards(stack_index);
//
//}
//void Solitaire::PushIntoStack(int stack_index, int dest_index)
//{
//	B->PushIntoStack(stack_index,dest_index);
//
//}
//
//void Solitaire::PushIntoHouse(int House_index, int stack_index)
//{
//	B->PushIntoHouse(House_index,stack_index);
//}
//void Solitaire::DisplayAnimation(RenderWindow& window, int houseIndex)
//{
//	B->DisplayAnimation(window, houseIndex);
//}
//void Solitaire::PushBackToHOuse(int House_index)
//{
//	B->PushBackToHouse(House_index);
//}
//
//bool Solitaire::HelperDeckContain(int x, int y)
//{
//	return B->HelperDeckContain(x, y);
//}
//void Solitaire::ShiftHelperDeck()
//{
//	B->ShiftHelperDeck();
//}

int Solitaire::SelectMode(RenderWindow& window)
{
    Texture A;
    A.loadFromFile("SelectMode.jpg");
    Sprite Back(A);
    Back.setPosition(370, 10);
    Back.setScale(0.9, 0.9);
    Font Nightmare;
    Nightmare.loadFromFile("Nightmare.ttf");
    Text Easy;
    Text Medium;
    Text Hard;
    Easy.setFont(Nightmare);
    Medium.setFont(Nightmare);
    Hard.setFont(Nightmare);
    Easy.setPosition(220, 200);
    Medium.setPosition(170, 300);
    Hard.setPosition(220, 400);
    Easy.setString("EASY");
    Medium.setString("MEDIUM");
    Hard.setString("HARD");
    Easy.setCharacterSize(70);
    Medium.setCharacterSize(70);
    Hard.setCharacterSize(70);
    Easy.setFillColor(Color::Green);
    Hard.setFillColor(Color::Red);
    Vector2i MP ;
    while (window.isOpen())
    {
        sf::Event evnt;
        window.clear();
        while (window.pollEvent(evnt))
        {
            if (evnt.type == sf::Event::Closed)
                window.close();
        
            if (evnt.type == sf::Event::MouseMoved)
            {
                    MP = sf::Mouse::getPosition(window);
                    if (Easy.getGlobalBounds().contains(MP.x, MP.y))
                        Easy.setScale(1.2, 1.2);
                    else if (Medium.getGlobalBounds().contains(MP.x, MP.y))
                        Medium.setScale(1.2, 1.2);
                    else if (Hard.getGlobalBounds().contains(MP.x, MP.y))
                        Hard.setScale(1.2, 1.2);
                    else
                    {
                        Easy.setScale(1, 1);
                        Medium.setScale(1, 1);
                        Hard.setScale(1, 1);
                    }
            }

            if (evnt.type == sf::Event::MouseButtonPressed)
            {
                if (evnt.mouseButton.button == sf::Mouse::Left)
                {
                    MP = sf::Mouse::getPosition(window);

                    if (Easy.getGlobalBounds().contains(MP.x, MP.y))
                        return 1;
                    else if (Medium.getGlobalBounds().contains(MP.x, MP.y))
                        return 2;
                    else if (Hard.getGlobalBounds().contains(MP.x, MP.y))
                        return 3;

                }
            }


        }
        window.draw(Back);
        window.draw(Easy);
        window.draw(Medium);
        window.draw(Hard);
        window.display();
    }

}

void Solitaire::Play(RenderWindow& window)
{
    bool Cardselected = false;
    bool Selected = false;;
    bool IsReleased = false;
    sf::Vector2i mousePosition1;
    sf::Vector2i mousePosition2;
    int stack_index = -1;
    int dest_stack_index = -1;
    int House_index = -1;
    int dest_House_index = -1;
    //-----------------
    RectangleShape blur;
    blur.setSize(Vector2f(1375, 696));
    blur.setPosition(0, 0);
    blur.setFillColor(Color(128, 128, 128, 100));
    //---------------------------------------
    bool HelperUsed = false;

    //--------------------------------------
    B->Shuffle();
    B->Display(window);

    
    //--------------
    Game_Mode = SelectMode(window);
    //=-----------------
    
    while (window.isOpen())
    {
        sf::Event evnt;
        window.clear();
        while (window.pollEvent(evnt))
        {
            if (evnt.type == sf::Event::Closed)
                window.close();

            if (evnt.type == sf::Event::MouseButtonPressed)
            {
                if (evnt.mouseButton.button == sf::Mouse::Left)
                {

                    mousePosition1 = sf::Mouse::getPosition(window);
                    if (B->HelperDeckContain(mousePosition1.x, mousePosition1.y))
                    {
                        B->ShiftHelperDeck();
                    }
                    else if (!Cardselected)
                    {
                      if (B->SelectCard(window, stack_index, House_index,HelperUsed))
                      {
                            Selected = true;
                            Cardselected = true;
                      }
                    }
                }
            }

            if (evnt.type == sf::Event::MouseButtonReleased)
            {
                if (evnt.mouseButton.button == sf::Mouse::Left)
                {
                    mousePosition2 = sf::Mouse::getPosition(window);
                    if (Cardselected)
                    {
                        if (stack_index != -1 || House_index != -1||HelperUsed)
                        {

                            if (!B->isvalidDestination(mousePosition2.x, mousePosition2.y, stack_index, dest_stack_index, dest_House_index))
                            {
                                if (HelperUsed)
                                {
                                    B->PushBackToChotaHelper();
                                    HelperUsed = false;
                                }
                                
                                else if (House_index != -1)
                                {
                                    B->PushBackToHouse(House_index);
                                }
                                else
                                    B->ReturnCards(stack_index);

                                House_index = -1;
                                stack_index = -1;
                              
                            }                            
                            else if (dest_House_index != -1)
                            {
                                cout << "\nPushIntoHouse\n";
                                B->PushIntoHouse(dest_House_index, stack_index);
                                B->DisplayAnimation(window, dest_House_index);
                            }
                            else
                                B->PushIntoStack(stack_index, dest_stack_index);
                           
                            if (HelperUsed)
                            {
                                B->UpdateChotaHelper();
                                HelperUsed = false;
                            }

                            Selected = false;
                            Cardselected = false;
                            //yaha abhi shi se ni bnaya isko zra shi se krna ha abhi and houses bhi bnanay 
                            //hain and score and dark mode
                            //25/9/2023
                        }
                    }

                }
            }
        }

        B->Display(window);
        if (Selected)
        {
            mousePosition1 = sf::Mouse::getPosition(window);
            B->DrawTemp(mousePosition1.x, mousePosition1.y, window);
        }
        // window.draw(blur);
        window.display();
        //window.clear();
    }

}
