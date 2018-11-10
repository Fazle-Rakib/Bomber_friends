#include<SFML/Graphics.hpp>
#include<bits/stdc++.h>
using namespace sf;
using namespace std;
vector< pair <int,int> > vect1;
int main()
{
    enum Direction{Down,Left,Right,Up};
    Vector2i source(1,Down);
    RenderWindow window;
    window.create(sf::VideoMode(925,600),"Bomber Friends");


    ///texture_decl.
    Texture textureFrame,player_anime, enemy_anime,textureGrass,textureBlock,Block_footbe ,Block_footbe1;

    ///load_file
    textureFrame.loadFromFile("data/image/frame1.png");
    player_anime.loadFromFile("data/image/kavi.png");
    enemy_anime.loadFromFile("data/image/death_scythe.png");
    textureGrass.loadFromFile("data/image/grass.png");
    textureBlock.loadFromFile("data/image/block_fix.png");
    Block_footbe.loadFromFile("data/step0001.png");
     Block_footbe1.loadFromFile("data/image/footbe_type2.png");


     ///sprite_decl
    Sprite frame(textureFrame),playerImage(player_anime),grass(textureGrass),enemyImage(enemy_anime);
    Sprite blocki(textureBlock), block_foot (Block_footbe),block_foot1 (Block_footbe1);

    ///postion
    playerImage.setPosition(186,150);
    enemyImage.setPosition(386,50);
    frame.setPosition(0,0);
    grass.setPosition(125,0);

    ///pixel scale
        blocki.setScale(Vector2f(1.117f,.676f));
        block_foot.setScale(Vector2f(1.15f,.92f));
        block_foot1.setScale(Vector2f(1.21f,.99f));


    ///dataset_array
    int arr1[49]={2,5,8,11   ,1,1,3,3,3,4,4,6,7,7,9,9,10,10,12,12,12,2,2,2,3,4,4,5,5,5,5,6,6,7,7,7,8,9,10,10,11,11,12};
    int arr2[49]={2,4,6,8,10 ,5,8,1,4,6,3,9,5,3,8,3,6,4 ,6 ,1,5 ,8,5,7,3,3,7,8,1,3,5,9,3,4,5,7,9,3,2,9 ,10, 3 ,9  ,4 };
    for(int n=0;n<39;n++)
        {
               vect1.push_back(make_pair(arr1[n],arr2[n]));
        }


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

                ///keyboard_event
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
                    playerImage.move(+10,0);
                }
                else if(event.key.code == sf::Keyboard::Up){
                    source.y = Up;
                    playerImage.move(0,-10);
                }
                    break;
            }



            ///player_move
            source.x++;
            if(source.x*32 >= player_anime.getSize().x)
            source.x = 0;
            window.draw(frame);
            window.draw(grass);
            playerImage.setTextureRect(IntRect(source.x * 32,source.y * 48,32,48));


            ///fix block
            for(int column=1;column<=4;column++)
            {
                for(int row=1;row<=5;row++)
                {
                    int x=125+vect1[column-1].first*57;
                    int y=vect1[row-1].second*50;
                    blocki.setPosition(x,y);
                    window.draw(blocki);
                }
            }



            ///foota block
            int j=4;
            while(j<=vect1.size())
            {
            int xf=vect1[j].first*57+125;
            int yf= vect1[j+1].second*50;
            block_foot.setPosition(xf,yf);
            block_foot1.setPosition(xf,yf);

            if(j<21)
                window.draw(block_foot);

            else
                window.draw(block_foot1);
            j++;
                window.draw(playerImage);

            }
            window.display();
            window.clear();
        }

    }
}



