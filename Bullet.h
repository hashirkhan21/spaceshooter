#include <SFML/Graphics.hpp>
#include<string.h>
using namespace sf;
#include <iostream>
#include <time.h>
#include "enemies.h"

class Bullet
{
public:
Texture tex;
Sprite sprite;
bool active=false;
int i=1;
float x,y;
Bullet(){
tex.loadFromFile("img/laserBlue04.png");
sprite.setTexture(tex);
sprite.setScale(0.75,0.75);
}

bool check()
{
if(y<=-10)
return true;

else
return false;
}


};
