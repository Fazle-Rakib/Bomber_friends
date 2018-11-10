#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Network.hpp>
using namespace sf;
int main()
{
    int x=100,y=100;
    int y1=100;
    int x1=600;

 sf::RenderWindow window( sf::VideoMode(900,800),"project");
 window.setFramerateLimit(100);
 while(window.isOpen()){
        sf::Event evn;
        while(window.pollEvent(evn)){
            if(evn.type==sf::Event::Closed){
                window.close();
            }
        }

window.clear(sf::Color::White);
    CircleShape cs,cs1;
    cs.setPosition(x,y);
    cs.setRadius(15.f);
    cs.setFillColor(Color::Blue);
window.draw(cs);
     cs1.setPosition(x1,y1);
    cs1.setRadius(15.f);
    cs1.setFillColor(Color::Red);
   window.draw(cs1);
window.display();

if(y==800)
    y=30,y1=50;
if(x==800)
    x=40,x1=200;
if(Keyboard::isKeyPressed(Keyboard::Left))
   x-=10,x1-=10;


if(Keyboard::isKeyPressed(Keyboard::Right))
   x+=10,x1+=10;

if(Keyboard::isKeyPressed(Keyboard::Up))
   y-=10,y1-=10;

if(Keyboard::isKeyPressed(Keyboard::Down))
   y+=10,y1+=10;
 }
return 0;
}
