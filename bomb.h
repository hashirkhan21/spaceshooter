#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <ctime>



class Bomb
{
public:
Texture tex;
Sprite sprite;
bool active=false;
float x,y;
int delay;
Bomb(){
tex.loadFromFile("img/enemy_laser.png");
sprite.setTexture(tex);
sprite.setScale(0.75,0.75);
}

bool check()
{
if(y>=+710)
return true;

else
return false;
}

};
