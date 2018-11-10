#include<SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace sf;
using namespace std;
vector< pair <float,float> > vect;
vector< pair <int,int> > vect1;
int i=0;
int main()
{
    enum Direction{Down,Left,Right,Up};
    Vector2i source(1,Down);
    RenderWindow window;
    window.create(sf::VideoMode(925,600),"Bomber Friends");


    Texture textureFrame,texture,textureGrass,textureBlock,Block_footbe1,Block_footbe;


    textureFrame.loadFromFile("data/image/frame1.png");
    texture.loadFromFile("data/image/kavi.png");
    textureGrass.loadFromFile("data/image/grass.png");
    textureBlock.loadFromFile("data/image/block_fix.png");
    Block_footbe.loadFromFile("data/step0001.png");
     Block_footbe1.loadFromFile("data/image/footbe_type2.png");



    Sprite frame(textureFrame),grass(textureGrass),playerImage(texture),blocki(textureBlock),block_foot (Block_footbe),block_foot1 (Block_footbe1);


    frame.setPosition(0,0);
    grass.setPosition(125,0);


    block_foot.setScale(Vector2f(1.15f,.7f));
    block_foot1.setScale(Vector2f(1.21f,.99f));

    int arr1[39]={1,1,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,7,7,7,7,7,8,9,9,9,10,10,10,10,11,11,12,12,12,12};
    int arr2[39]={5,8,3,5,7,1,3,4,6,3,7,8,9,1,3,5,9,3,4,5,3,5,7,8,9,3,2,3,6,4,9,6,10,3,9,1,4,5,8};
    for(int n=0;n<39;n++)
              {
               vect1.push_back(make_pair(arr1[n],arr2[n]));
               }
     for (int i=0;i<vect1.size(); i++)
        {
        cout <<vect1[i].first<<"  "<<vect1[i].second<<endl;

        }

    playerImage.setPosition(vect1[0].first,vect1[0].second);
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            switch(event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if(event.key.code == sf::Keyboard::Down){
                    source.y = Down;
                    playerImage.move(0,10);
                }
                else if(event.key.code == sf::Keyboard::Left){
                    source.y = Left;
                    playerImage.move(-10,0);
                }
                else if(event.key.code == sf::Keyboard::Right){
                    source.y = Right;
                    playerImage.move(+50,0);
                }
                else if(event.key.code == sf::Keyboard::Up){
                    source.y = Up;
                    playerImage.move(0,-50);
                }
                    break;
            }
            source.x++;

            if(source.x*32 >= texture.getSize().x)
            source.x = 0;
            window.draw(frame);
            window.draw(grass);
            playerImage.setTextureRect(IntRect(source.x * 32,source.y * 48,32,48));
            window.draw(playerImage);

//            int x=239,y=100;
//            blocki.setPosition(239,100);
//            blocki.setScale(Vector2f(1.117f,.676f));
//            window.draw(blocki);
//            while(x<925)
//            {
//            if(y>=600)
//                {
//                y=100;
//                x=x+171.3;
//                }
//            else
//                y=y+100;
//            vect.push_back(make_pair(x,y));
//            blocki.setPosition(x,y);
//            blocki.setScale(Vector2f(1.117f,.676f));
//            if(x<800)
//            window.draw(blocki);
//            }
              ///foota block
            int j=0;
            while(j<=vect1.size())
            {

            int xf=vect1[j].first*57+125;
            int yf= vect1[j].second*50;

            block_foot.setPosition(xf,yf+2);
            block_foot1.setPosition(xf,yf);
            block_foot.setScale(Vector2f(1.15f,.7f));
            block_foot1.setScale(Vector2f(1.21f,.99f));
            window.draw(block_foot1);
            j++;
            }
            window.display();
            window.clear();
        }
    }
    cout<<"abcd";
     for (int i=0; i<13; i++)
    {
        cout << vect[i].first << " " << vect[i].second << endl;

    }
}


