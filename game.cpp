#include <ctime>
#include <cstdlib>
//#include<iostream>
#include <sstream>
using namespace std;
#include "game.h"

basicShape::basicShape(sf::RenderWindow &App) : myWindow(App)
{
    Clock.Reset();
    highScore = 0;
    currentScore = 0;
    bulletNumb = 0;

    float centex=0.0, centery=0.0, rad = 100.0;

    RectWidth = 10;
    RectHeight = 10;

    StarHeight = 20;
    StarWidth = 20;


    redColor = sf::Color::Color(214,71,0, 255);
    Circle = sf::Shape::Circle(centex, centery, rad, redColor);

    //Star = sf::Shape::Rectangle(0.0,0.0,20,20 ,sf::Color::White);
   // Star = sf::Shape::Line(0.0,0.0,0.0,30.0,2 ,sf::Color::White);

    for(int i = 0; i < MaxBullet; i++)
    {
        Bullet[i]= sf::Shape::Rectangle(0.0,0.0,5.0,5.0, sf::Color::Red);
    }

    for(int i = 0; i < MaxStar; i++)
    {
        Star[i] = sf::Shape::Line(0.0,0.0,0.0,30.0,2 ,sf::Color::White);
    }
    Rect = sf::Shape::Rectangle(-10.0,0.0,10.0,10.0, sf::Color::Black);

    Ship.AddPoint(0.0,0.0,sf::Color::Red);
    Ship.AddPoint(-10.0,10.0,sf::Color::Red);
    Ship.AddPoint(10.0,10.0,sf::Color::Red);
    Ship.SetOutlineWidth(1);
    Ship.EnableFill(true);
    Ship.EnableOutline(true);
    Ship.SetColor(redColor);


}

void basicShape::setPositon()
{
    //Circle.SetPosition(400.0, 300.0);
   // Star.SetPosition(10,10);
    srand(time(NULL));
    for(int i = 0; i < MaxStar; i++)
    {
        float Starx = 0 + (rand() % 700);
        float Stary = 1 + (rand() % 500);
        Star[i].SetPosition(Starx, Stary);
    }
    Ship.SetPosition(400.0,500.0);
    Rect.SetPosition(400.0,500.0);
}

void basicShape::getInput(const sf::Input &input)
{
    if(input.IsKeyDown(sf::Key::Up))
    {
        //Circle.Move(0,-2);
        Ship.Move(0,-10);
        Rect.Move(0,-10);
    }
    if(input.IsKeyDown(sf::Key::Down))
    {
       // Circle.Move(0,2);
        Ship.Move(0,10);
        Rect.Move(0,10);
    }
    if(input.IsKeyDown(sf::Key::Left))
    {
        //Circle.Move(-2,0);
        Ship.Move(-10,0);
        Rect.Move(-10,0);
    }
    if(input.IsKeyDown(sf::Key::Right))
    {
        //Circle.Move(2,0);
        Ship.Move(10,0);
        Rect.Move(10,0);
    }
    if(input.IsKeyDown(sf::Key::Space))
        fireBullet();

    if(Ship.GetPosition().x < 0)
    {
        Ship.SetPosition(800.0,Ship.GetPosition().y);
        Rect.SetPosition(800.0, Rect.GetPosition().y);
    }
    if(Ship.GetPosition().x > 800)
    {
        Ship.SetPosition(0.0,Ship.GetPosition().y);
        Rect.SetPosition(0.0, Rect.GetPosition().y);
    }
}

void basicShape::moveStar()
{
    for(int i = 0; i < MaxStar; i++)
    {
        Star[i].Move(0, 8+ (rand() % 10));
        if(Star[i].GetPosition().y > 600)
        {
            float Starx = 0 + (rand() % 700);
            float Stary = 0 + (rand() % 400);
            Star[i].SetPosition(Starx,Stary);
        }

    }
    //
}

void basicShape::collision()
{
   /* if(Rect.GetPosition().x + RectWidth < Star.GetPosition().x ||
       Rect.GetPosition().x > Star.GetPosition().x + StarWidth ||
       Rect.GetPosition().x < Star.GetPosition().x + StarWidth||
       Rect.GetPosition().x - RectWidth < Star.GetPosition().x + StarWidth||
       Rect.GetPosition().y + RectHeight < Star.GetPosition().y ||
       Rect.GetPosition().y > Star.GetPosition().y + StarHeight)
       {
           //No Coliison
       }

    else
    {
        Ship.SetPosition(400.0,500.0);
        Rect.SetPosition(400.0,500.0);
    }*/
    for(int i = 0; i < MaxStar; i++)
    {
        double xdiff = Star[i].GetPosition().x - Rect.GetPosition().x;
        double ydiff = Star[i].GetPosition().y - Rect.GetPosition().y;

        if((xdiff >= -9 && xdiff <= 9) && (ydiff >= 0 && ydiff <= 30))
        {
            Ship.SetPosition(400.0,500.0);
            Rect.SetPosition(400.0,500.0);
            Clock.Reset();
        }
    }
    for(int i = 0; i < MaxStar; i++)
    {
        for(int k = 0; k < MaxBullet; k++)
        {
            float diffx = Star[i].GetPosition().x - Bullet[k].GetPosition().x;
            float diffy = Star[i].GetPosition().y - Bullet[k].GetPosition().y;

            if((diffx >= -5 && diffx <= 5) && (diffy >= 0 && diffy <= 30))
            {
                float Starx = 0 + (rand() % 700);
                float Stary = 0 + (rand() % 5);
                Star[i].SetPosition(Starx,Stary);
                Bullet[k].SetPosition(-1.0,-1.0);
            }
        }

    }

  //
}

void basicShape::draw()
{
    //Circle.SetPosition(400.0, 300.0);
    //myWindow.Draw(Circle);
    myWindow.Draw(Rect);
    myWindow.Draw(Ship);
    for(int i = 0; i < 20; i++)
    {
        myWindow.Draw(Star[i]);
    }
    for(int i = 0; i < bulletNumb; i++)
    {
        myWindow.Draw(Bullet[i]);
    }
}

void basicShape::fireBullet()
{

    float xPosition = Ship.GetPosition().x;
    float yPosition = Ship.GetPosition().y;
    if(bulletNumb > MaxBullet - 1)//due to start at 0
        bulletNumb = 0;
    else
    {
        Bullet[bulletNumb].SetPosition(xPosition, yPosition);
        bulletNumb++;
    }
}

void basicShape::moveBullet()
{
    for(int i = 0; i < bulletNumb; i++)
    {
        Bullet[i].Move(0.0,-5.0);
    }
}

void basicShape::getTime()
{
    stringstream secSS (stringstream::in | stringstream::out);
    stringstream minSS (stringstream::in | stringstream::out);
    float GTime = Clock.GetElapsedTime();

    int min = GTime/60;
    int second = GTime - min*60;

    secSS << second;
    string Second = secSS.str();

    minSS << min;
    string Min = minSS.str();

    string Fort = ":";
    string Complete = Min+Fort+Second;

    sf::String TText;
    TText.SetText("Time : " + Complete);
    TText.SetSize(25);
    myWindow.Draw(TText);

    int score = GTime*10;
    currentScore = score;
    stringstream scoSS (stringstream::in | stringstream::out);
    scoSS << score;
    string Score = scoSS.str();
    sf::String SText;
    SText.SetText("Score: " + Score);
    SText.SetSize(25);
    SText.SetPosition(0,28);
    myWindow.Draw(SText);
}

void basicShape::disHighScore()
{
    if(currentScore > highScore)
        highScore = currentScore;

    stringstream getScore (stringstream::in | stringstream::out);
    getScore << highScore;
    string HighScore = getScore.str();
    sf::String Score;
    Score.SetText("High score: " + HighScore);
    Score.SetSize(25);
    Score.SetPosition(0,56);
    myWindow.Draw(Score);
}
