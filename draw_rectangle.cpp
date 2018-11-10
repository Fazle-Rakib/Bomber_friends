#include<SFML/Graphics.hpp>
#include<bits/stdc++.h>

using namespace sf;

int main()

{
    RenderWindow win;
    win.create(VideoMode(600,550),"sfml");
    RectangleShape rect (Vector2f(100.0f,105.0f));
    rect.setFillColor(Color::Yellow);
    rect.setPosition(150.f,170.5);
    rect.setOutlineColor(Color::Cyan);
    rect.setOutlineThickness(10.f);
    rect.setSize(Vector2f(150.f,190.f));

    rect.setScale(Vector2f(1.3,1.f));

    while(win.isOpen())
    {
        Event evn;
        while(win.pollEvent(evn))

        {
          switch(evn.type)
          {
        case Event::TextEntered:
          if(evn.text.unicode<128)
               std::cout<<evn.text.unicode;
        }
        }
//keyboard controll
   if(Keyboard ::isKeyPressed(Keyboard::Right))
   // rect.move(0.05,0.f);
    rect.setRotation(366.0);
    if(Keyboard ::isKeyPressed(Keyboard::Left))
//    rect.move(-0.05,0.f);
    rect.setRotation(354.0);
    if(Keyboard ::isKeyPressed(Keyboard::Up))
//    rect.move(0.0,-0.06);
     rect.setRotation(360.0);

    if(Keyboard ::isKeyPressed(Keyboard::Down))
//    rect.move(0.0,0.06);
     rect.setRotation(0.0);

    //mouse controll

    if(Mouse::isButtonPressed(Mouse::Left))
    {
        Vector2i Mouse_pos  = Mouse::getPosition(win);
        rect.setPosition((float)Mouse_pos.x,(float)Mouse_pos.y);
    }
        win.clear();
        win.draw(rect);
        win.display();
    }
}
