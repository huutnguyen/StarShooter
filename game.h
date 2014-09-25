#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#define MaxStar 20
#define MaxBullet 100
class basicShape
{
    private:

        int RectWidth;
        int RectHeight;
        int StarWidth;
        int StarHeight;
        sf::Clock Clock;
        sf::Color redColor;
        sf::Shape Circle;
        sf::Shape Ship;
        sf::Shape Rect;
        sf::Shape Star[MaxStar];
        sf::RenderWindow &myWindow;
        sf::Shape Bullet[MaxBullet];
        int bulletNumb;
        int highScore;
        int currentScore;
    public:
        basicShape(sf::RenderWindow &App);
        void draw();
        void getInput(const sf::Input &input);
        void setPositon();
        void moveStar();
        void collision();
        void fireBullet();
        void moveBullet();
        void getTime();
        void disHighScore();

};
