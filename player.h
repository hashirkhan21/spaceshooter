#include "Bullet.h"
#include "Addon.h"


Bullet* bing = new Bullet[5];

class Player{
public:
Texture tex;
Sprite sprite;
float speed=0.3;
Bullet* bullets;
float x,y;
Player(string png_path)
{

tex.loadFromFile(png_path);
sprite.setTexture(tex);
x=340;y=500;
sprite.setPosition(x,y);
sprite.setScale(0.75,0.75);
bullets = bing;
}

void fire()
{
    for (int i = 0; i < 5; i++)
    {
        if (!bullets[i].active)
        {
            bullets[i].active = true;
            bullets[i].x = x + 30; // Set the x-coordinate to the current ship's x-coordinate
            bullets[i].y = y;
            break;
        }
    }
}

void updateBullets()
{
    for (int i = 0; i < 5; i++)
    {
        if (bullets[i].active)
        {
            bullets[i].y -= 0.9;
            bullets[i].sprite.setPosition(bullets[i].x, bullets[i].y); // Update bullet sprite position
            if (bullets[i].check())
                bullets[i].active = false;
        }
    }
}

void drawBullets(sf::RenderWindow& window)
    {
        for(int i = 0; i < 5; i++)
        {
            if (bullets[i].active)
                window.draw(bullets[i].sprite);
        }
    }




void check()
{
if(x <= -60 && y<=-60)
{x=700;y=700;}
else if(x>=760 && y>=760)
{x=0 ; y=0;}
else if(x<=-60 && y>=760)
{x=700 ; y=0;}
else if(x>=760 && y<=-60)
{x=0 ; y=700;}
else if(x <= -60 )
{x=700;}
else if(y <= -60 )
{y=700;}
else if(x >= 760 )
{x=0;}
else if(y >= 760 )
{y=0;}
}

void move(string s){
sprite.setRotation(0);
float delta_x=0,delta_y=0;
if(s=="l")
delta_x=-2;
else if(s=="r")
delta_x=2;
if(s=="u")
delta_y=-2;
else if(s=="d")
	delta_y=2;

delta_x*=speed;
delta_y*=speed;
x+=delta_x;
y+=delta_y;

sprite.move(delta_x, delta_y);
check();
sprite.setPosition(x,y);
}



void move(string s , string y)
{
sprite.setRotation(0);

float delta_x=0,delta_y=0,rot=0;
if((s=="l"&& y=="u") || (s=="u" && y=="l"))
{delta_x+=-1;delta_y+=-1;
rot=-45;}
else if((s=="r"&& y=="u") || (s=="u" && y=="r"))
{delta_x-=-1;delta_y+=-1;
rot=45;}
else if((s=="d"&& y=="l") || (s=="l" && y=="d"))
{delta_x+=-1;delta_y+=+1;
rot=210;}
else if((s=="r"&& y=="d") || (s=="d" && y=="r"))
{delta_x-=-1;delta_y+=1;
rot=-210;}
delta_x*=speed;
delta_y*=speed;

x+=delta_x;
this->y+=delta_y;

sprite.move(delta_x, delta_y);
sprite.rotate(rot);
check();
sprite.setPosition(x,this->y);
}

};









