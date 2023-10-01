#include"Solitaire.h"
#include<string>
Solitaire::Solitaire()
{
	B = new Board();
    Game_Mode = 0;
    UD.loadFromFile("UndoIcon.png");
    RD.loadFromFile("RedoIcon.png");
    undo.setTexture(UD);
    redo.setTexture(RD);
    undo.setPosition(20, 600);
    redo.setPosition(100, 600);
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
    bool DeskClicked = false;
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
    //--------------------------
    //Starting(window);
    //--------------
    Game_Mode = SelectMode(window);
    B->SetGAmeMode(Game_Mode);
    //=-----------------
    Undo.push_back(*B);

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

                        if (undo.getGlobalBounds().contains(mousePosition1.x, mousePosition1.y))
                        {
                            if(Undo.size()>=2)
                            {
                                delete B;
                                B=nullptr;
                                B = new Board(Undo[Undo.size() - 2]);
                                Redo.push_back(Undo.back());
                                Undo.pop_back();
                            }
                        }
                        else if (redo.getGlobalBounds().contains(mousePosition1.x, mousePosition1.y))
                        {
                            if (Redo.size() > 0)
                            {
                                delete B;
                                B = nullptr;
                                B = new Board(Redo.back());

                                Undo.push_back(Redo.back());
                                Redo.pop_back();
                            }
                        }
                        else if (B->HelperDeckContain(mousePosition1.x, mousePosition1.y))
                        {
                           
                            B->ShiftHelperDeck(window);
                            Undo.push_back(*B);
                            cout << "\nUndo Size " << Undo.size() << endl;
                            Redo.clear();
                        }

                        else if (!Cardselected)
                        {
                            if (B->SelectCard(window, stack_index, House_index, HelperUsed))
                            {
                                Selected = true;
                                Cardselected = true;
                                DeskClicked = true;
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
                            else
                            {


                                if (dest_House_index != -1)
                                {
                                    cout << "\nPushIntoHouse\n";
                                    B->PushIntoHouse(dest_House_index, stack_index);
                                    B->DisplayAnimation(window, dest_House_index);
                                    Moves = B->GetMoves();
                                    B->SetMoves(++Moves);
                                    Undo.push_back(*B);
                                    cout << "\nUndo Size " << Undo.size() << endl;
                                    Redo.clear();

                                }
                                else
                                {
                                    B->PushIntoStack(stack_index, dest_stack_index);
                                    Moves = B->GetMoves();
                                    B->SetMoves(++Moves);
                                    Undo.push_back(*B);
                                    cout << "\nUndo Size " << Undo.size() << endl;
                                    Redo.clear();
                                }
                                if (HelperUsed)
                                {
                                    B->UpdateChotaHelper();
                                    HelperUsed = false;
                                    Undo.push_back(*B);
                                    cout << "\nUndo Size " << Undo.size() << endl;
                                    Redo.clear();
                                }
                            }
                            Selected = false;
                            Cardselected = false;
                            DeskClicked = false;
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
        window.draw(undo);
        window.draw(redo);
        window.display();
        //window.clear();
    }

}

void Solitaire::Starting(RenderWindow& window)
{
    Texture B;
    Sprite BG;
    int i = 1;
    Font Nightmare;
    Nightmare.loadFromFile("GameOfThrones.ttf");
    Text Sol;
    Text Saga;
    Sol.setFont(Nightmare);
    Saga.setFont(Nightmare);
    Sol.setString("SOLITAIRE");
    Sol.setPosition(300, 250);
    Sol.setCharacterSize(120);
    Sol.setFillColor(Color::White);
    Sol.setOutlineColor(Color::Red);
    Sol.setOutlineThickness(2);
    //----------------------------
    Saga.setString("SAGA");
    Saga.setPosition(490, 400);
    Saga.setCharacterSize(120);
    Saga.setFillColor(Color::White);
    Saga.setOutlineColor(Color::Red);
    Saga.setOutlineThickness(2);
    int alpha = 255;
    int alpha2 = 255;

    while (window.isOpen())
    {
        sf::Event evnt;
        window.clear();
        while (window.pollEvent(evnt))
        {
            if (evnt.type == sf::Event::Closed)
                window.close();
        }

        string s = to_string(i);
        B.loadFromFile(s + ".png");
        BG.setTexture(B);
        BG.setPosition(-70, 0);
        BG.setScale(1.2, 1.2);
        window.draw(BG);
        if(i>15)
        {

            window.draw(Sol);
            if (i > 29)
                window.draw(Saga);
            if(i>56&&alpha>=0)
            {
                Sol.setOutlineColor(Color(255, 0, 0, alpha));
                Sol.setFillColor(Color(255, 255, 255, alpha));
                alpha -= 16;
            }
            if (i >66 && alpha2 >= 0)
            {
                Saga.setOutlineColor(Color(255, 0, 0, alpha2));
                Saga.setFillColor(Color(255, 255, 255, alpha2));
                alpha2 -= 16;
            }
        }
        window.display();
        i++;
        if (i == 87)return;
        sleep(milliseconds(40));
    }


}

void Solitaire::DisplayDeckDistribution(RenderWindow& window)
{
    for (int i = 0, ci = 0; i < 7; i++, ci += 140)
    {
        //int rev_size = S[i].getRevealedSize();
        //int un_rev_size = S[i].getUnRevealedSize();

        //for (int j = 0, ri = 0; j < rev_size + un_rev_size; j++, ri += 30)
            //for (int j = 0,ri=0; j <=i; j++, ri += 30)
        {
            if (1);// (j < un_rev_size)
                //          DisplayCardBack(220 + ci, 90 + ri, window);
            else;
        //        S[i][j - un_rev_size]->DisplayCard(220 + ci, 90 + ri, window);
        }
    }
}
