#include<SFML/Graphics.hpp>
#include<iostream>
#include"Solitaire.h"
#include<queue>
using namespace std;
using namespace sf;

int main1()
{

    sf::RenderWindow window(sf::VideoMode(1375, 696), "Abdul SFML", sf::Style::Close | sf::Style::Resize);
    Solitaire s();
    window.setPosition(Vector2i(-10, 0));
    Texture B;
    B.loadFromFile("Ace_spades.png");

    Sprite Board(B);
    Board.setPosition(100, 50);
    Texture C;
    C.loadFromFile("Ace_hearts.png");
    Sprite Ace(C);
    Ace.setPosition(300, 50);
    //Board.setScale(0.5, 0.5);

    Texture A;
    A.loadFromFile("background.jpg");

    Sprite Backg(A);
    Backg.setPosition(0, -80);
    Backg.setScale(1, 1);
    Font Lato;
    Lato.loadFromFile("Lato.ttf");

    Text NG("NEW GAME", Lato, 50);
    NG.setPosition(540, 60);
    NG.setFillColor(sf::Color::White);
    Text LG("LOAD GAME", Lato, 50);
    LG.setPosition(535, 170);
    LG.setFillColor(sf::Color::White);
    bool isSpriteSelected = false;;

    //--------------
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

                    // Check if the mouse click is inside the sprite
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                    sf::FloatRect spriteBounds = Board.getGlobalBounds();
                    if (spriteBounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
                    {
                        isSpriteSelected = true;
                    }
                }
            }
            if (evnt.type == sf::Event::MouseButtonReleased)
            {
                if (evnt.mouseButton.button == sf::Mouse::Left)
                {
                    isSpriteSelected = false;
                }
            }
        }

        if (isSpriteSelected)
        {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            Board.setPosition(static_cast<float>(mousePosition.x) - 50, static_cast<float>(mousePosition.y) - 65);
        }


        window.draw(Backg);
        window.draw(Ace);
        window.draw(Board);

        // window.draw(NG);
        //window.draw(LG);

        window.display();
    }

    return 0;




}
//int main2()
//{
//    cout << "entered main\n";
//
//    sf::RenderWindow window(sf::VideoMode(1375, 696), "Abdul SFML", sf::Style::Close | sf::Style::Resize);
//    window.setPosition(Vector2i(-10, 0));
//
//    Solitaire* S = new Solitaire();
//
//    bool Cardselected= false;
//    bool Selected = false;;
//    bool IsReleased = false;
//    sf::Vector2i mousePosition1; 
//    sf::Vector2i mousePosition2;
//    int stack_index = -1;
//    int dest_stack_index = -1;
//   int House_index=-1;
//    int dest_House_index=-1;
//    //-----------------
//
//    RectangleShape blur;
//    blur.setSize(Vector2f(1375, 696));
//    blur.setPosition(0, 0);
//    blur.setFillColor(Color(128, 128, 128, 100));
//   //---------------------------------------
//
//    S->main_Shuffle();
//    S->DisplayBoard(window);
//    
//    //--------------
//    while (window.isOpen())
//    {
//        sf::Event evnt;
//        window.clear();
//        while (window.pollEvent(evnt))
//        {
//            if (evnt.type == sf::Event::Closed)
//                window.close();
//            
//               if (evnt.type == sf::Event::MouseButtonPressed)
//                {
//                    if (evnt.mouseButton.button == sf::Mouse::Left)
//                    {
//                        
//                        mousePosition1 = sf::Mouse::getPosition(window);
//                        if (S->HelperDeckContain(mousePosition1.x, mousePosition1.y))
//                        {
//                            S->ShiftHelperDeck();
//                        }
//                        else if (!Cardselected)
//                        {
//
//                            if (S->SelectCard(window, stack_index, House_index))
//                            {
//                                Selected = true;
//                                Cardselected = true;
//                            }
//                        }
//                    }
//                }
//            
//            if (evnt.type == sf::Event::MouseButtonReleased)
//            {
//                if (evnt.mouseButton.button == sf::Mouse::Left)
//                {    if(Cardselected)
//                    {
//                        if (stack_index != -1 || House_index != -1)
//                        {
//                            mousePosition2 = sf::Mouse::getPosition(window);
//                            if (!S->isvalidDestination(mousePosition2.x, mousePosition2.y, stack_index, dest_stack_index, dest_House_index))
//                            {
//                                if (House_index != -1)
//                                {
//                                    S->PushBackToHOuse(House_index);
//                                }
//                                else
//                                    S->ReturnCards(stack_index);
//
//                                House_index = -1;
//                                stack_index = -1;
//                            }
//                            else if (dest_House_index != -1)
//                            {
//                                S->PushIntoHouse(dest_House_index, stack_index);
//                                S->DisplayAnimation(window, dest_House_index);
//                            }
//                            else
//                                S->PushIntoStack(stack_index, dest_stack_index);
//
//                            Selected = false;
//                            Cardselected = false;
//                            //yaha abhi shi se ni bnaya isko zra shi se krna ha abhi and houses bhi bnanay 
//                            //hain and score and dark mode
//                            //25/9/2023
//                        }
//                    }
//
//                }
//            }
//        }
//
//        S->DisplayBoard(window);
//        if(Selected)
//        {
//            mousePosition1 = sf::Mouse::getPosition(window);
//            S->DrawTemp(mousePosition1.x, mousePosition1.y, window);
//        }
//       // window.draw(blur);
//        window.display();
//        //window.clear();
//    }
//
//    return 0;
//}

int main3()
{
    queue<int>Q1;
    queue<int>Q2;
    Q1.push(1);
    Q1.push(1);
    Q1.push(1);
    Q1.push(1);
    Q1.push(1);
    Q1.push(1);
    Q1.push(1);
    Q1.push(1);
    Q1.push(1);
    Q1.push(1);
    Q1.push(1);
    Q1.push(1);
    Q1.push(1);
    Q1.push(1);
    Q1.push(1);

    cout<<Q1.size()<<endl;
    cout<<Q2.size()<<endl;
    swap(Q1, Q2);
    cout << Q1.size() << endl;
    cout << Q2.size() << endl;
    return 0;
}


int main()
{

    sf::RenderWindow window(sf::VideoMode(1375, 696), "Abdul SFML", sf::Style::Close | sf::Style::Resize);
    window.setPosition(Vector2i(-10, 0));

    Solitaire* S = new Solitaire();
    //S->Winning(window);
    
    S->Play(window);
    return 0;
}