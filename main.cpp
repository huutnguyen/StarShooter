#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "game.h"

int main()
{
    sf::RenderWindow App(sf::VideoMode(800,600,32),
                        "Star Shooter!");

    App.SetFramerateLimit(50);

    basicShape base(App);

    //float centex=0.0, centery=0.0, rad = 100.0;
   // sf::Color redColor = sf::Color::Color(214,71,0);
   // sf::Shape Circle = sf::Shape::Circle(centex, centery, rad, redColor);
   // Circle.SetPosition(400.0, 300.0);
    base.setPositon();
    while(App.IsOpened())
    {
        sf::Event Event;
        while(App.GetEvent(Event))
        {
            //Close window : exit
            if(Event.Type == sf::Event::Closed)
                App.Close();
            else if(Event.Type == Event.KeyPressed)
                base.getInput(App.GetInput());
        }

        //if(App.GetInput().IsKeyDown(sf::Key::Up))
            //Circle.Move(0,-2);
       // if(App.GetInput().IsKeyDown(sf::Key::Down))
            //Circle.Move(0,2);
        //if(App.GetInput().IsKeyDown(sf::Key::Right))
           // Circle.Move(2,0);
       // if(App.GetInput().IsKeyDown(sf::Key::Left))
            //Circle.Move(-2,0);

        //App.Clear(sf::Color(100,149,237));
        App.Clear();
        base.disHighScore();
        base.getTime();
        base.collision();
        //App.Draw(Circle);
        base.moveStar();
        base.moveBullet();
        base.draw();
        App.Display();

    }

    return 0;
}
