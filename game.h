
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
using namespace std;
#include "player.h"
const char title[] = "OOP-Project, Spring-2023";
using namespace sf;



class Game
{
public:
Sprite background; //Game background sprite
Sprite award;
Texture bg_texture;
Texture textss;
int t=0;float t1;
Player* p; //player 
int tem;
// add other game attributes
Enemies K;
bool foo=false;
int level=1,score=0,lives=3;
Game()
{
p=new Player("img/player_ship.png");
bg_texture.loadFromFile("img/background.jpg");
background.setTexture(bg_texture);
background.setScale(1, 1.5);
K._num=-1;
K.Atex.loadFromFile("img/enemy_1.png");
K.Btex.loadFromFile("img/enemy_2.png");
K.Ctex.loadFromFile("img/enemy_3.png");


}

void start_game(RenderWindow& window)
{

	
    srand(time(NULL));
    
    Clock clock;
    float timer=0,Timer=0;
    int k=0;
    
    
if(tem==1)
{
textss.loadFromFile("img/Gold.png");
award.setTexture(textss);
}
if(tem==2)
{

textss.loadFromFile("img/Silver.png");
award.setTexture(textss);
}
if(tem==3)
{
textss.loadFromFile("img/Bronze.png");
award.setTexture(textss);
}

if(tem)
{award.setPosition(615,0);award.setScale(0.15,0.15);}
    
    
    while (window.isOpen() && K.ii<=9 && lives>0)
    {
        
 	Event e;
       while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
                window.close();
        }
        
	Font font;
	font.loadFromFile("Mega_Man_Battle_Network_Regular.ttf");
	
	Text text,text1,text2;
	text.setFont(font);text1.setFont(font);text2.setFont(font);
	text.setCharacterSize(12);text1.setCharacterSize(12);text2.setCharacterSize(12);
	text.setFillColor(sf::Color::White);text1.setFillColor(sf::Color::White);text2.setFillColor(sf::Color::White);
	text.setString("Level "+ std::to_string(level));text1.setString("Score "+ std::to_string(score));
	text2.setString("Lives "+ std::to_string(lives));
	text.setPosition(10,10);text1.setPosition(650,10);text2.setPosition(10,30);

	
	
	if(Keyboard::isKeyPressed(Keyboard::Escape))
	{
	int i=0;
	while(!i)
	{
	if(Keyboard::isKeyPressed(Keyboard::E))
	i=1;
	else if(window.isOpen())
	{
	window.clear(Color::Black); //clears the screen
	window.draw(background);
	window.display();
	}
	
	}
	
	}
	
       else if (Keyboard::isKeyPressed(Keyboard::Left) && Keyboard::isKeyPressed(Keyboard::Up))
            p->move("l","u");
       else if (Keyboard::isKeyPressed(Keyboard::Right) && Keyboard::isKeyPressed(Keyboard::Up))
            p->move("r","u");
       else if (Keyboard::isKeyPressed(Keyboard::Right) && Keyboard::isKeyPressed(Keyboard::Down))
            p->move("r","d");
       else if (Keyboard::isKeyPressed(Keyboard::Left) && Keyboard::isKeyPressed(Keyboard::Down))
            p->move("l","d");
       else if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Left))
            p->move("u","l");
       else if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Right))
            p->move("u","r");  
       else if (Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::Left))
            p->move("d","l"); 
       else if (Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::Right))
            p->move("r","d");                                   
	else{
	if (Keyboard::isKeyPressed(Keyboard::Left)) //If left key is pressed
            p->move("l");    // Player will move to left
	if (Keyboard::isKeyPressed(Keyboard::Right)) // If right key is pressed
            p->move("r");  //player will move to right
	if (Keyboard::isKeyPressed(Keyboard::Up)) //If up key is pressed
            p->move("u");    //playet will move upwards
	if (Keyboard::isKeyPressed(Keyboard::Down)) // If down key is pressed
            p->move("d");  //player will move downwards
            }
         
         //
         /*{
         K = new Alpha[4];
         K1= new Beta[4];
         K2 = new Gamma[4];
         }  */ 
      
	
          float time = clock.restart().asSeconds();
          
          timer += time;

            if (timer >= 2 && foo==1)
            {
                p->fire();
                timer = 0;
            }
	
        timer += time;   
 
if (K._num == 0 && foo==1) {
    for (int i = 0; i < 5; i++) {
        if (p->bullets[i].active == 1) {
            for (int lm = 0; lm < K.shape; lm++) {
            if(K.active[lm] ==1){
                sf::FloatRect bulletBounds = p->bullets[i].sprite.getGlobalBounds();
                sf::FloatRect spriteBounds = K.sprite[lm]->getGlobalBounds();

                if (spriteBounds.intersects(bulletBounds)) {
                              
                            if(K._shape != 7) 
                            {if(K.b[lm]->delay==7)
                            score+=30;
                            else if(K.b[lm]->delay==5)
                            score+=20;
                            else
                            score+=10;}
                            

                            if(K._shape==7)
                            score+=15;
                             
                                                         
                            delete K.sprite[lm];

                            if(K._shape!=7)
                            {delete K.b[lm];}
                            else if(K._shape==7 && lm<K.shape-10)
                            {delete K.b[lm];}
                            
                            delete K.x[lm];
                            delete K.y[lm];
                            K.active[lm] = 0;
                            p->bullets[i].active = 0;
                            
                            K._numshape -=1;
                     if(K._numshape==0) {
                        K._num = -1;
                        foo=false;
                        }
                        
                    }}}
                    
            }
        }
    }
	if(K.ii>6)
	{
	level=3;
	}
	else if(K.ii>3)
	level=2;
	
if(K._num==0 && foo==1)
{
if(K._shape!=7)
{
for(int i=0; i<K.shape ; i++)
if(K.active[i]!=0){
sf::FloatRect bulletBounds = K.b[i]->sprite.getGlobalBounds();
sf::FloatRect spriteBounds = p->sprite.getGlobalBounds();
if (spriteBounds.intersects(bulletBounds)) {
K.b[i]->active = 0;
lives--;
p->x=0;
p->y=580;
p->sprite.setPosition(0,580);

}}}
if(K._shape==7)
{
for(int i=0; i<K.shape-10 ; i++)
if(K.active[i]!=0){
sf::FloatRect bulletBounds = K.b[i]->sprite.getGlobalBounds();
sf::FloatRect spriteBounds = p->sprite.getGlobalBounds();
if (spriteBounds.intersects(bulletBounds)) {
K.b[i]->active = 0;
lives--;
p->x=0;
p->y=580;
p->sprite.setPosition(0,580);

}
}
}}
if(K.ii==9)
{
for(int i=0; i<K.shape ; i++)
if(K.b[i]->active!=0){
sf::FloatRect bulletBounds = K.b[i]->sprite.getGlobalBounds();
sf::FloatRect spriteBounds = p->sprite.getGlobalBounds();
if (spriteBounds.intersects(bulletBounds)) {
K.b[i]->active = 0;
lives--;
p->x=0;
p->y=580;
p->sprite.setPosition(0,580);

}}}



       
	////////////////////////////////////////////////
	p->updateBullets();
	
	if(K._num == -1 && foo==false )
	{ //clears the screen
	window.draw(background);  // setting background
	window.draw(p->sprite);
    	window.display();
    	
    	
    	for(int i=0; i<5 ;i++)
    	{p->bullets[i].active=0;
    	p->bullets[i].sprite.setPosition(0,700);
    	}
    	
	    sf::Clock clock;
	    sf::Time delay = sf::seconds(2);

    auto endTime = clock.getElapsedTime() + delay;
    	
    	
        while (clock.getElapsedTime() < endTime) {
        // Waiting...
    	}
	K.level();
	foo=true;
	}

	if(K.ii==9 && rand()%3==1)
	{
	t++;
	}
	
	if(K.ii==9 && rand()%4==2)
	t1=p->x;
	
	if(K.ii<9)
	{
	K.fire();
	K.UpdateBomb();}
	
	if(K.ii==9)
	{
	K.water();
	K.updateWater(t1);
	}
	if(t>3000)
	{
	K.ii++;score+=40;
	}
	//////////////////////////////////////////////
	
	window.clear(Color::Black); //clears the screen
	window.draw(background);  // setting background
	window.draw(p->sprite);
	p->drawBullets(window);
	
	if(K.ii<9) 
	{K.drawBomb(window);K.drawSprite(window);}
	window.draw(text);window.draw(text1);window.draw(text2);
	if(K.ii==9)
	{window.draw(*(K.sprite[0]));K.drawWater(window);}
	if(tem)
	{window.draw(award);}
	window.display();  //Displying all the sprites
	}
    }





};

