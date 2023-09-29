#include"Board.h"
#include"Spade.h"
#include"Diamond.h"
#include"Hearts.h"
#include"Club.h"
#include<time.h>
#include<ctime>
#include<iostream>
#include"House.h"
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;
Board::Board()
{

    Rects = new RectangleShape[7];
    for (int i = 0, j = 0; i < 7; i++, j += 140)
    {
        Rects[i].setFillColor(Color(0, 0, 0, 0));
        //Rects[i].setFillColor(Color::White);
        Rects[i].setSize(Vector2f(100.0f, 700.0f));
        Rects[i].setPosition(220 + j, 90);
    }


    Deck = new Cards * [52];
    int index = 0;


    for (int i = 0; i < 52; i++)
    {
        if (i%2== 0)
        {

            Deck[i] = new Spade(230, 160, 1, "black");

        }
        else
        {
            Deck[i] = new Hearts(230, 160, 2, "red");
        }
    }


   /* for (int i = 0; i < 4; i++)
    {

        for (int j = 0; j < 13; j++,index++)
        {
            if (i == 0)
            {

                Deck[index] = new Spade(230, 160, j+ 1, "black");

            }
            if (i == 1)
            {
                Deck[index] = new Club(230, 160, j + 1, "black");
            }
            if (i == 2)
            {
                Deck[index] = new Hearts(230, 160, j + 1, "red");

            }
            if (i == 3)
            {
                Deck[index] = new Diamond(230, 160, j+ 1, "red");

            }

        }

    }*/

    
    Houses = new House * [4];
    float x = 1235, y = 90;
    Houses[0] = new House("Club", "Club logo2.png", x, y);
    Houses[2] = new House("Diamond", "Diamond logo2.png", x, y+150);
    Houses[1] = new House("Spade", "Spades logo2.png", x, y+300);
    Houses[3] = new House("Hearts", "Heart logo2.png", x, y+450);
    //------------------------------------------------------------------
    CB.loadFromFile("Card_back.png");
    CardBAck.setTexture(CB);
    //--------------------------------------------------------------------
    HD.loadFromFile("Helper_stack2.png");
    HelperDeck_IMG.setTexture(HD);
    HD_icon.loadFromFile("Reload_button2.png");
    Helper_icon.setTexture(HD_icon);
    Helper_D_Rect.setFillColor(Color(128, 128, 128, 80));
    Helper_D_Rect.setPosition(25, 90);
    Helper_D_Rect.setSize(sf::Vector2f(90, 134));
    Helper_icon.setPosition(45, 130);
    this->HelperDeckArea.setSize(Vector2f(150.0f, 700.0f));
    HelperDeckArea.setPosition(0, 0);
    HelperDeckArea.setFillColor(Color(128, 128, 128, 70));
    HelperReloaded = true;
    //--------------------------------------------------------------------


    //Houses = new RectangleShape[4];
    //for (int i = 0, j = 0; i < 4; i++, j += 150)
    //{
    //    Houses[i].setFillColor(Color(128,128,128,128));
    //    Houses[i].setSize(Vector2f(100.0f, 134.0f));
    //    Houses[i].setPosition(1200, 90+j);
    //    Houses[i].setOutlineColor(Color::Red);
    //    Houses[i].setOutlineThickness(2);
    //}

}

void Board::Shuffle()
{
    cout << " inside B->Shuffle\n";
    srand(time(0));
 
    for (int i = 0; i < 150; i++)
    {
        int si = rand() % 52;
        int ei = rand() % 52;
        cout << "  si  " << si<< "  ei  "<<ei<<endl;
        if(si!=ei)
        swap(Deck[si], Deck[ei]);
    }
 
    S = new MyStack<Cards>[7];

    int index = 0;
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j <= i; j++, index++)
        {
            cout << "index " << index<<endl;
            S[i].PushElem(Deck[index]);
        }
    }
    for (int D = 28; D <52; D++)
    {
        Helper_Deck.push(Deck[D]);
    }

    //S = new MyStack<Cards>[7];
    //for (int j = 0; j < 7; j++)
    //{

    //    S[j].PushElem(Deck[j]);
    //}
    cout << "Exiting B->Shuffle\n";

}

//void Board::Display(RenderWindow& window)
//{
//    float x=1225, y=130;
//
//    Texture clb;
//    clb.loadFromFile("Club logo2.png");
//    Sprite Club(clb);
//    Club.setPosition(x,y);
//    
//    Texture dmnd;
//    dmnd.loadFromFile("Diamond logo2.png");
//    Sprite Diamond(dmnd);
//    Diamond.setPosition(x,y+150);
//
//    Texture spade;
//    spade.loadFromFile("Spades logo2.png");
//    Sprite Spade(spade);
//    Spade.setPosition(x, y+300);
//    
//    Texture heart;
//    heart.loadFromFile("Heart logo2.png");
//    Sprite Heart(heart);
//    Heart.setPosition(x, y+450);
//
//    Texture B;
//    B.loadFromFile("Ace new.png");
//    Sprite Board(B);
//    Board.setPosition(80, 160);
//    //Board.setColor(Color::White);
//
//    Texture C;
//    C.loadFromFile("Ace.png");
//    Sprite Ace(C);
//    Ace.setPosition(230,160);
//    //Board.setScale(0.5, 0.5);
//    //Ace.setColor(Color::Red);
//    Texture A;
//    A.loadFromFile("background.jpg");
//
//    RectangleShape outline;
//    outline.setPosition(Ace.getPosition().x-1, Ace.getPosition().y-1);
//    outline.setSize(Vector2f(102.0f, 136.0f));
//    outline.setFillColor(Color::White);
//    RectangleShape outline2;
//    outline2.setPosition(Board.getPosition().x-1, Board.getPosition().y-1);
//    outline2.setSize(Vector2f(102.0f, 136.0f));
//    outline2.setFillColor(Color::White);
//
//    Sprite Backg(A);
//    Backg.setPosition(0, -80);
//    Backg.setScale(1, 1);
//
//    sf::Vector2i P = sf::Mouse::getPosition(window);
//    for(int i=0;i<7;i++)
//    {
//        if (Rects[i].getGlobalBounds().contains(P.x, P.y))
//        {
//            Board.setScale(1.5, 1.5);
//        }
//    }
//
//    //window.draw(Backg);
//    for(int i=0;i<7;i++)
//    window.draw(Rects[i]);
//    for (int i = 0; i < 4; i++)
//        window.draw(Houses[i]);
//    window.draw(outline);
//    window.draw(Ace);
//    window.draw(outline2);
//    window.draw(Board);
//    window.draw(Spade);
//    window.draw(Heart);
//    window.draw(Club);
//    window.draw(Diamond);
//
//}
void Board:: DisplayCardBack(int ri, int ci, RenderWindow& window)
{
    CardBAck.setPosition(ri-1, ci);
    window.draw(CardBAck);
}
void Board::Display(RenderWindow& window)
{
    

    float x = 1225, y = 130;

    for (int i = 0; i < 7; i++)
        window.draw(Rects[i]);
    /*Texture A;
    A.loadFromFile("background.jpg");
    Sprite Backg(A);
    Backg.setPosition(0, -80);*/
   // window.draw(Backg);
    
    //DRawing MAin DECK

    DrawHelperDeck(window);
        
    for (int i = 0,ci=0; i < 7; i++,ci+=140)
    {
        int rev_size = S[i].getRevealedSize();
        int un_rev_size = S[i].getUnRevealedSize();

        for (int j = 0,ri=0; j <rev_size+un_rev_size; j++, ri += 30)
        //for (int j = 0,ri=0; j <=i; j++, ri += 30)
        {
            if (j < un_rev_size)
                DisplayCardBack(220 + ci, 90 + ri, window);
            else
                S[i][j-un_rev_size]->DisplayCard(220 + ci, 90 + ri, window);
        }
    }
 
    for (int i = 0; i < 4; i++)
    {
        Houses[i]->DrawHouse(window);
    }
    


    //for (int j = 0, ri = 0; j < 7; j++, ri += 30)
    //{
    //    //Cards* topcard = S[j];
    //    S[j]->DisplayCard(160, 80 + ri, window);
    //    //S[j]->DisplayCard(160, 80 + ri, window);

    //}
    
}

bool Board::SelectCard(RenderWindow& window, int& stack_index, int& House_index,bool &Helper_Selected)
{
    //takes mouse position where it was clicked and checks if it is inside any of the 7 invisible rectangles
    //if it is then it checks from bottom to top if its inside one of the revealed cards of the stack 
    //present in that rectangle if it is it removes that card and all the cards below it from stack and store them.
    //in a temp vector of cards 
    cout << "\nInside House Index\n";
    int Rect_index = -1;
    Helper_Selected = false;
    stack_index = -1;
    House_index = -1;
    bool released = false;
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

    if(!Chota_Helper.empty())
    {
        if (Chota_Helper[0]->Contains(mousePosition.x, mousePosition.y))
        {
            temp.push_back(Chota_Helper[0]);
            temp[0]->HighlightCard();
            Chota_Helper.erase(Chota_Helper.begin());
            Helper_Selected = true;
            return true;
        }
    }


    for (int i = 0; i < 4; i++)
    {
        if (Houses[i]->Contains(mousePosition.x, mousePosition.y))
        {
            House_index = i;
            break;
        }
    }
    cout << "\nHouse index " << House_index<<endl;

    if (House_index != -1)
    {
        if (Houses[House_index]->IsEmpty())
        {
            House_index = -1;
              return false;
        }
        else
        {
            temp.push_back(Houses[House_index]->Top());
            temp[0]->HighlightCard();
            Houses[House_index]->Pop();            
            return true;
        }
    }

    cout << "\nRect index bef" << Rect_index << endl;

    for (int i = 0; i < 7; i++)
    {
        if (Rects[i].getGlobalBounds().contains(mousePosition.x, mousePosition.y))
        {
            Rect_index = i;
            break;
        }
    }
    cout << "\nRect index aft" <<  Rect_index << endl;
    if (Rect_index == -1)return false ;

    stack_index = Rect_index;
    cout << "\nStack_index now" << stack_index << endl;

    int size = S[Rect_index].getRevealedSize();
    int card_index = -1;
    for (int i = size - 1; i >= 0; i--)
    {
        if (S[Rect_index][i]->Contains(mousePosition.x, mousePosition.y))
        {
            card_index = i;
            break;
        }
    }
    cout << "\card index" << card_index << endl;

    if (card_index == -1)
    {
        stack_index = -1;
        return false;
    }

    //S[Rect_index][card_index]->HighlightCard();
   
    int i = card_index;
    cout << "\nStack_index aft" << stack_index << endl;

    while (i < size)
    {
        
        temp.push_back(S[Rect_index][i]);
        S[Rect_index][i]->HighlightCard();
      
            i++;
    }
    
    int k = card_index;
    while (k < size)
    {
        S[Rect_index].PopElement();
        k++;
    }
    return true;
    
}

void Board::DrawTemp(int x, int y, RenderWindow& window)
{

    for (int i = 0, ri = 0; i < temp.size(); i++, ri += 30)
    {
        temp[i]->DisplayCard(x - 50,y + ri - 65, window);
    }

}

bool Board::isvalidDestination(int mouse_x, int mouse_y, int stack_index,int & dest_stack_index, int& House_index)
{
    House_index = -1;

    for (int i = 0; i < 4; i++)
    {
        if (Houses[i]->Contains(mouse_x, mouse_y))
        {
            House_index = i;
            break;
        }
    }
    if (House_index != -1)
    {
        if ((temp.size() == 1) && (temp[0]->gethouseNAme() == Houses[House_index]->GetName()))
        {
            if (Houses[House_index]->IsEmpty() )
            {
                if (temp[0]->getnum() == 1)
                    return true;
                else return false;
            }

            int temp_card_no= temp[0]->getnum();
            int House_card_no = Houses[House_index]->Top()->getnum();
            
            if ((temp_card_no - House_card_no) == 1)
                return true;
            else
            {
                House_index = -1;
                return false;
            }
        }
        else
        {
             House_index = -1;
             return false;
        }
    }

    dest_stack_index = -1;
    for (int i = 0; i < 7; i++)
    {
        if (Rects[i].getGlobalBounds().contains(mouse_x, mouse_y)&&i!=stack_index)
        {
            dest_stack_index = i;
            break;
        }
    }
    if (dest_stack_index == -1)return false;


    if (S[dest_stack_index].IsEmpty())
    {
        if (temp[0]->getnum() == 13)
            return true;        
        else return false;
    }
    

    if (S[dest_stack_index].Top()->GetColor() != temp[0]->GetColor())
    {
        int dest_num= S[dest_stack_index].Top()->getnum();
        int incoming_num= temp[0]->getnum();
        if (((abs(dest_num-incoming_num)) == 1)&&(dest_num>incoming_num))
            return true;
       
        else return false;
    }
    else return false;
}
void Board::ReturnCards(int stack_index)
{
    for (int i = 0; i < temp.size(); i++)
    {
        temp[i]->UnHighlightCard();
    }
    S[stack_index].PushRevealed(temp);
}
void Board::PushIntoStack(int stack_index,int dest_index)
{
    for (int i = 0; i < temp.size(); i++)
    {
        temp[i]->UnHighlightCard();
    }
    S[dest_index].PushRevealed(temp);
    S[stack_index].RevealNext();
}
//void Board::SelectCard(RenderWindow& window)
//{
//
//    int Rect_index = -1;
//    vector<Cards*>temp;
//    bool released = false;
//    sf::Event evnt{};
//
//
//    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
//
//    for (int i = 0; i < 7; i++)
//    {
//        if (Rects[i].getGlobalBounds().contains(mousePosition.x, mousePosition.y))
//        {
//            cout << "\nRectangle contains\n";
//            Rect_index = i;
//            break;
//        }
//    }
//    if (Rect_index == -1)return;
//
//    int size = S[Rect_index].getRevealedSize();
//    int card_index = -1;
//    for (int i = size - 1; i >= 0; i--)
//    {
//        if (S[Rect_index][i]->Contains(mousePosition.x, mousePosition.y))
//        {
//            cout << "\nCard Contains\n";
//
//            card_index = i;
//            break;
//        }
//    }
//    if (card_index == -1)return;
//
//
//
//    cout << "\ncard index  " << card_index << endl;
//    cout << "\nsize  " << size << endl;
//    int i = card_index;
//    while (i < size)
//    {
//        cout << "\i " << i << "\n";
//
//        temp.push_back(S[Rect_index][i]);
//        i++;
//    }
//    int k = card_index;
//    while (k < size)
//    {
//        S[Rect_index].PopElement();
//        k++;
//    }
//
//
//    bool isreleased = false;
//    sf::Vector2i mousePosition1;
//
//    while (1)
//    {
//        while (window.pollEvent(evnt))
//        {
//            if (evnt.type == sf::Event::MouseButtonReleased)
//            {
//                if (evnt.mouseButton.button == sf::Mouse::Left)
//                {
//                    isreleased = true;
//                }
//            }
//        }
//
//        if (isreleased)
//            break;
//
//        window.clear();
//        Display(window);
//        mousePosition1 = sf::Mouse::getPosition(window);
//        for (int i = 0, ri = 0; i < temp.size(); i++, ri += 30)
//        {
//            temp[i]->DisplayCard(mousePosition1.x - 50, mousePosition1.y + ri - 65, window);
//        }
//        window.display();
//
//    }
//
//}

void Board::PushIntoHouse(int House_index,int stack_index)
{
    Houses[House_index]->Push(temp[0]);
    temp[0]->UnHighlightCard();
    temp.clear();
    S[stack_index].RevealNext(); 
}
void Board:: DisplayAnimation(RenderWindow& window, int houseIndex)
{
    
    int size = Houses[houseIndex]->GetOutlineSize();
     int x = 102, y = 136;
     Houses[houseIndex]->SetoutlineSize(size + 4);    
    Houses[houseIndex]->SetFillColor(Color(0, 0, 0, 0));
    int alpha = 255;
  //  for (; i < 15;)
    {
        for (int pos=0, opac = 0, sz=0; opac < 45; opac+=5, sz += 4,pos+=2)
        {
             window.clear();
        Houses[houseIndex]->SetSize(x+sz,y+sz);
        Houses[houseIndex]->SetPosition(pos, pos);
                alpha -= opac;
                if (alpha > 0)
                    Houses[houseIndex]->SetOutlineColorRGB(0, 0, 255, alpha);
                    Board::Display(window);
                    window.display();
            sleep(milliseconds(30));
        }
    }
    Houses[houseIndex]->SetoutlineSize(size);
    Houses[houseIndex]->SetOutLineColor(Color::Blue);
    Houses[houseIndex]->SetSize(x, y);
    Houses[houseIndex]->SetFillColor(Color(128, 128, 128, 128));
    Houses[houseIndex]->SetPosition(0, 0);
}
void Board::PushBackToHouse(int House_index)
{
    Houses[House_index]->Push(temp[0]);
    temp[0]->UnHighlightCard();
    temp.clear();
}
void Board::DrawHelperDeck(RenderWindow& window)
{
    window.draw(HelperDeckArea);
    if(Helper_Deck.empty()&&!Chota_Helper.empty())
    { 
        Helper_D_Rect.setOutlineThickness(2);
        Helper_D_Rect.setOutlineColor(Color::Red);
        window.draw(Helper_D_Rect);
        DrawChotaHelper(window);
    }
    else if (Helper_Deck.empty() && Chota_Helper.empty())
    {
        Helper_D_Rect.setOutlineThickness(2);
        Helper_D_Rect.setOutlineColor(Color::Red);
        window.draw(Helper_D_Rect);
        window.draw(Helper_icon);
    }
    else
    {
        float size = Helper_Deck.size();
        for (float i = 0,ci=25+(0.5*size); i < size; i++,ci-=0.5)
        {
            HelperDeck_IMG.setPosition(ci, 90);
             window.draw(HelperDeck_IMG);
        }
        DrawChotaHelper(window);
    }
}



bool Board::HelperDeckContain(int x, int y)
{
    if (HelperDeck_IMG.getGlobalBounds().contains(x, y) || Helper_D_Rect.getGlobalBounds().contains(x, y))
        return true;
    return false;
}
void Board::ShiftHelperDeck()
{
    if (Helper_Deck.empty()&&Chota_Helper.empty())
    {
        swap(Temp_Deck, Helper_Deck);//it will make temp deck empty and will shift all elements of temp into Helper
        HelperReloaded = true;
    }
    else if (HelperReloaded)
    {
        Cards* T;
        for (int i = 0; i < 3; i++)
        {
            T = Helper_Deck.front();
            Chota_Helper.push_back(T);
            Helper_Deck.pop();
        }
        HelperReloaded = false;
    }
    else if (Helper_Deck.empty() && !Chota_Helper.empty())
    {
        Temp_Deck.push(Chota_Helper[0]);
        Chota_Helper.erase(Chota_Helper.begin());
    }
    else
    {
        Temp_Deck.push(Chota_Helper[0]);
        Chota_Helper.erase(Chota_Helper.begin());
        Chota_Helper.push_back(Helper_Deck.front());
        Helper_Deck.pop();
    }

}
void Board::DrawChotaHelper(RenderWindow& window)
{
        int size = Chota_Helper.size();
        for (int i = 0, ci = 0; i < size; i++, ci += 35)
        {
            Chota_Helper[size-1-i]->DisplayCard(26, 250 + ci, window);
        }
    
}
void Board::PushBackToChotaHelper()
{

    Chota_Helper.insert(Chota_Helper.begin(), temp[0]);
    temp[0]->UnHighlightCard();
    temp.clear();
}
void Board::UpdateChotaHelper()
{
    if (!Helper_Deck.empty())
    {
        Chota_Helper.push_back(Helper_Deck.front());
        Helper_Deck.pop();
        
    }
}