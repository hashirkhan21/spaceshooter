#include "bomb.h"

class Enemies
{
public:
Sprite** sprite =nullptr;int _num, _shape, shape,_numshape;Texture tex, Atex, Btex, Ctex;float** x=nullptr;float** y=nullptr;Bomb** b=nullptr;
bool active[20];
int delay;
int ii= 8;

////////////////////////////////////////////////////////////////////////////

/*
void shape(int x, int y)
{

}
*/
	

	
void hollow_square()
{
	_shape = 0;_numshape=12;shape=_numshape;
	sprite= new Sprite*[_numshape];b = new Bomb*[_numshape];x= new float*[_numshape];y= new float*[_numshape];
	for(int i=0; i<_numshape ; i++){sprite[i] = new Sprite;b[i]= new Bomb;x[i]=new float; y[i]= new float;}
	for(int i=0; i<4; i++){*x[i]= 250 + i*80;*y[i]=0;}
	for(int i=4; i<=6; i++){*x[i]= 490;*y[i]=80 + (i-4)*80;}
	for(int i=7; i<=9 ; i++){*x[i]= 490 - (i-6)*80;*y[i] = 240;}*x[10]=250;*y[10]=160;*x[11]=250;*y[11]=80;
	int lmao=0;srand(time(NULL));
	for(int i=0; i<_numshape ; i++)
	{
	active[i]=1;lmao=rand()%3;
	if(lmao==0)
	{sprite[i]->setTexture(Atex);b[i]->delay = 7;sprite[i]->setScale(0.5,0.5);}
	else if(lmao==1)
	{sprite[i]->setTexture(Btex);b[i]->delay= 5;sprite[i]->setScale(0.5,0.5);}
	else if(lmao==2)
	{sprite[i]->setTexture(Ctex);b[i]->delay= 4;sprite[i]->setScale(0.37,0.37);}
	sprite[i]->setPosition(*x[i],*y[i]);}}

void hollow_triangle()
{
	_shape = 1;
	_numshape=8;shape=_numshape;
	
	sprite= new Sprite*[_numshape];b = new Bomb*[_numshape];x= new float*[_numshape];y= new float*[_numshape];
	
	for(int i=0; i<_numshape ; i++)
	{sprite[i] = new Sprite;b[i]= new Bomb;x[i]=new float; y[i]= new float;}
	
	for(int i=0; i<5; i++)
	{*x[i]= 200 + i*80; *y[i]=0;}
	*x[5]= 250;*y[5]=80 ;
	*x[6]=470;*y[6]=80;
	*x[7]=360;*y[7]=160;
	
	int lmao=0;srand(time(NULL));
	for(int i=0; i<_numshape ; i++)
	{
	active[i]=1;lmao=rand()%3;
	if(lmao==0)
	{sprite[i]->setTexture(Atex);b[i]->delay = 7;sprite[i]->setScale(0.5,0.5);}
	else if(lmao==1)
	{sprite[i]->setTexture(Btex);b[i]->delay= 5;sprite[i]->setScale(0.5,0.5);}
	else if(lmao==2)
	{sprite[i]->setTexture(Ctex);b[i]->delay= 4;sprite[i]->setScale(0.37,0.37);}
	sprite[i]->setPosition(*x[i],*y[i]);}
}

void solid_triangle()
{
	_shape = 2;
	_numshape=9;shape=_numshape;
	
	sprite= new Sprite*[_numshape];b = new Bomb*[_numshape];x= new float*[_numshape];y= new float*[_numshape];
	
	for(int i=0; i<_numshape ; i++)
	{sprite[i] = new Sprite;b[i]= new Bomb;x[i]=new float; y[i]= new float;}
	
	for(int i=0; i<5; i++)
	{*x[i]= 200 + i*80; *y[i]=0;}
	*x[5]= 250;*y[5]=80 ;
	*x[6]=470;*y[6]=80;
	*x[7]=360;*y[7]=160;
	*x[8]=360; *y[8]=80;
	int lmao=0;srand(time(NULL));
	for(int i=0; i<_numshape ; i++)
	{
	active[i]=1;lmao=rand()%3;
	if(lmao==0)
	{sprite[i]->setTexture(Atex);b[i]->delay = 7;sprite[i]->setScale(0.5,0.5);}
	else if(lmao==1)
	{sprite[i]->setTexture(Btex);b[i]->delay= 5;sprite[i]->setScale(0.5,0.5);}
	else if(lmao==2)
	{sprite[i]->setTexture(Ctex);b[i]->delay= 4;sprite[i]->setScale(0.37,0.37);}
	sprite[i]->setPosition(*x[i],*y[i]);}
}


void cross()
{
	_shape = 3;
	_numshape=9;shape=_numshape;
	
	sprite= new Sprite*[_numshape];b = new Bomb*[_numshape];x= new float*[_numshape];y= new float*[_numshape];
	
	for(int i=0; i<_numshape ; i++)
	{sprite[i] = new Sprite;b[i]= new Bomb;x[i]=new float; y[i]= new float;}
	
	*x[0] = 200; *y[0]=0; *x[1]=520;*y[1]=0;
	*x[2]= 280; *y[2]=80; *x[3]=440; *y[3]= 80;
	*x[4]=360;*y[4]=160;
	*x[5] = 280; *y[5]=240; *x[6]=440;*y[6]=240;
	*x[7]= 200; *y[7]=320; *x[8]=520; *y[8]= 320;
	
	int lmao=0;srand(time(NULL));
	for(int i=0; i<_numshape ; i++)
	{
	active[i]=1;lmao=rand()%3;
	if(lmao==0)
	{sprite[i]->setTexture(Atex);b[i]->delay = 7;sprite[i]->setScale(0.5,0.5);}
	else if(lmao==1)
	{sprite[i]->setTexture(Btex);b[i]->delay= 5;sprite[i]->setScale(0.5,0.5);}
	else if(lmao==2)
	{sprite[i]->setTexture(Ctex);b[i]->delay= 4;sprite[i]->setScale(0.37,0.37);}
	sprite[i]->setPosition(*x[i],*y[i]);}
}

void hollow_heart()
{
	_shape = 4;
	_numshape=12;shape=_numshape;

	sprite= new Sprite*[_numshape];b = new Bomb*[_numshape];x= new float*[_numshape];y= new float*[_numshape];
	
	for(int i=0; i<_numshape ; i++)
	{sprite[i] = new Sprite;b[i]= new Bomb;x[i]=new float; y[i]= new float;}
	
	*x[0]=200;*x[1]=280;*x[2]=440;*x[3]=520;	
	*x[4]=120;*x[5]=360;*x[6]=600;*x[7]=200;
	*x[8]=520;*x[9]=280;*x[10]=440;*x[11]=360;
	
	*y[0]=0;*y[1]=0;*y[2]=0;*y[3]=0;	
	*y[4]=80;*y[5]=80;*y[6]=80;*y[7]=160;
	*y[8]=160;*y[9]=240;*y[10]=240;*y[11]=320;
	
	int lmao=0;srand(time(NULL));
	for(int i=0; i<_numshape ; i++)
	{
	active[i]=1;lmao=rand()%3;
	if(lmao==0)
	{sprite[i]->setTexture(Atex);b[i]->delay = 7;sprite[i]->setScale(0.5,0.5);}
	else if(lmao==1)
	{sprite[i]->setTexture(Btex);b[i]->delay= 5;sprite[i]->setScale(0.5,0.5);}
	else if(lmao==2)
	{sprite[i]->setTexture(Ctex);b[i]->delay= 4;sprite[i]->setScale(0.37,0.37);}
	sprite[i]->setPosition(*x[i],*y[i]);}
		
}
void solid_heart()
{
	_shape = 7;
	_numshape=20;shape=_numshape;

	sprite= new Sprite*[_numshape];b = new Bomb*[_numshape-10];x= new float*[_numshape];y= new float*[_numshape];
	
	for(int i=0; i<_numshape ; i++)
	{sprite[i] = new Sprite;x[i]=new float; y[i]= new float;}
	
	for(int i=0; i<_numshape-10;i++)
	b[i]= new Bomb;
	
	*x[0]=200;*x[1]=280;*x[2]=440;*x[3]=520;	
	*x[4]=120;*x[5]=200;*x[6]=280;*x[7]=360;*x[8]=440;*x[9]=520;*x[10]=600;
	*x[11]=200;*x[12]=280;*x[13]=360;*x[14]=440;*x[15]=520;
	*x[16]=280;*x[17]=360;*x[18]=440;
	*x[19]=360;
	
	*y[0]=0;*y[1]=0;*y[2]=0;*y[3]=0;	
	*y[4]=80;*y[5]=80;*y[6]=80;*y[7]=80;*y[8]=80;*y[9]=80;*y[10]=80;
	*y[11]=160;*y[12]=160;*y[13]=160;*y[14]=160;*y[15]=160;
	*y[16]=240;*y[17]=240;*y[18]=240;
	*y[19]=320;
	
	int lmao=0;srand(time(NULL));
	for(int i=0; i<_numshape ; i++)
	{
	active[i]=1;lmao=rand()%3;
	if(lmao==0)
	{sprite[i]->setTexture(Atex);if(i<10)b[i]->delay = 7;sprite[i]->setScale(0.5,0.5);}
	else if(lmao==1)
	{sprite[i]->setTexture(Btex);if(i<10)b[i]->delay= 5;sprite[i]->setScale(0.5,0.5);}
	else if(lmao==2)
	{sprite[i]->setTexture(Ctex);if(i<10)b[i]->delay= 4;sprite[i]->setScale(0.37,0.37);}
	sprite[i]->setPosition(*x[i],*y[i]);}
}

void solid_diamond()
{
	_shape = 5;
	_numshape=13;shape=_numshape;

	sprite= new Sprite*[_numshape];b = new Bomb*[_numshape];x= new float*[_numshape];y= new float*[_numshape];
	
	for(int i=0; i<_numshape ; i++)
	{sprite[i] = new Sprite;b[i]= new Bomb;x[i]=new float; y[i]= new float;}
	
	*x[0]=360;
	*x[1]=280;*x[2]=360;*x[3]=440;*x[4]=200;*x[5]=280;*x[6]=360;*x[7]=440;*x[8]=520;
	*x[9]=280;*x[10]=360;*x[11]=440;*x[12]=360;
	
	*y[0]=0;
	*y[1]=80;*y[2]=80;*y[3]=80;*y[4]=160;*y[5]=160;*y[6]=160;*y[7]=160;*y[8]=160;
	*y[9]=240;*y[10]=240;*y[11]=240;*y[12]=320;
	
	int lmao=0;srand(time(NULL));
	for(int i=0; i<_numshape ; i++)
	{
	active[i]=1;lmao=rand()%3;
	if(lmao==0)
	{sprite[i]->setTexture(Atex);b[i]->delay = 7;sprite[i]->setScale(0.5,0.5);}
	else if(lmao==1)
	{sprite[i]->setTexture(Btex);b[i]->delay= 5;sprite[i]->setScale(0.5,0.5);}
	else if(lmao==2)
	{sprite[i]->setTexture(Ctex);b[i]->delay= 4;sprite[i]->setScale(0.37,0.37);}
	sprite[i]->setPosition(*x[i],*y[i]);}
}

void hollow_diamond()
{
	_num = 0;
	_shape = 5;
	_numshape=8;shape=_numshape;

	sprite= new Sprite*[_numshape];b = new Bomb*[_numshape];x= new float*[_numshape];y= new float*[_numshape];
	
	for(int i=0; i<_numshape ; i++)
	{sprite[i] = new Sprite;b[i]= new Bomb;x[i]=new float; y[i]= new float;} 
	
	*x[0]=360;
	*x[1]=280;*x[2]=440;*x[3]=200;*x[4]=520;*x[5]=280;*x[6]=440;*x[7]=360;
	
	*y[0]=0;
	*y[1]=80;*y[2]=80;*y[3]=160;*y[4]=160;*y[5]=280;*y[6]=280;*y[7]=360;
	
	int lmao=0;srand(time(NULL));
	for(int i=0; i<_numshape ; i++)
	{
	active[i]=1;lmao=rand()%3;
	if(lmao==0)
	{sprite[i]->setTexture(Atex);b[i]->delay = 7;sprite[i]->setScale(0.5,0.5);}
	else if(lmao==1)
	{sprite[i]->setTexture(Btex);b[i]->delay= 5;sprite[i]->setScale(0.5,0.5);}
	else if(lmao==2)
	{sprite[i]->setTexture(Ctex);b[i]->delay= 4;sprite[i]->setScale(0.37,0.37);}
	sprite[i]->setPosition(*x[i],*y[i]);}	
}

void hollow_circle()
{
	_num = 0;
	_shape = -1;
	_numshape=10;shape=_numshape;

	sprite= new Sprite*[_numshape];b = new Bomb*[_numshape];x= new float*[_numshape];y= new float*[_numshape];
	
	for(int i=0; i<_numshape ; i++)
	{sprite[i] = new Sprite;b[i]= new Bomb;x[i]=new float; y[i]= new float;}
	
	*x[0]=360;
	*x[1]=280;*x[2]=440;*x[3]=200;*x[4]=520;*x[5]=200;*x[6]=520;*x[7]=270;*x[8]=440;*x[9]=360;
	
	*y[0]=40;
	*y[1]=80;*y[2]=80;*y[3]=160;*y[4]=160;*y[5]=240;*y[6]=240;*y[7]=320;*y[8]=320;*y[9]=355;
	
	int lmao=0;srand(time(NULL));
	for(int i=0; i<_numshape ; i++)
	{
	active[i]=1;lmao=rand()%3;
	if(lmao==0)
	{sprite[i]->setTexture(Atex);b[i]->delay = 7;sprite[i]->setScale(0.5,0.5);}
	else if(lmao==1)
	{sprite[i]->setTexture(Btex);b[i]->delay= 5;sprite[i]->setScale(0.5,0.5);}
	else if(lmao==2)
	{sprite[i]->setTexture(Ctex);b[i]->delay= 4;sprite[i]->setScale(0.37,0.37);}
	sprite[i]->setPosition(*x[i],*y[i]);}
			
}

void solid_circle()
{
	_num = 0;
	_shape = 11;
	_numshape=16;shape=_numshape;

	sprite= new Sprite*[_numshape];b = new Bomb*[_numshape];x= new float*[_numshape];y= new float*[_numshape];
	
	for(int i=0; i<_numshape ; i++)
	{sprite[i] = new Sprite;b[i]= new Bomb;x[i]=new float; y[i]= new float;}
	
	*x[0]=360;
	*x[1]=280;*x[2]=440;*x[3]=200;*x[4]=280;*x[5]=360;*x[6]=440;*x[7]=520;*x[8]=200;*x[9]=280;*x[10]=360;*x[11]=440;*x[12]=520;*x[13]=275;*x[14]=445;*x[15]=360;
	
	*y[0]=50;
	*y[1]=80;*y[2]=80;*y[3]=150;*y[4]=160;*y[5]=160;*y[6]=160;*y[7]=150;*y[8]=250;*y[9]=240;*y[10]=240;*y[11]=240;*y[12]=250;*y[13]=320;*y[14]=320;*y[15]=350;
	
	int lmao=0;srand(time(NULL));
	for(int i=0; i<_numshape ; i++)
	{
	active[i]=1;lmao=rand()%3;
	if(lmao==0)
	{sprite[i]->setTexture(Atex);b[i]->delay = 7;sprite[i]->setScale(0.5,0.5);}
	else if(lmao==1)
	{sprite[i]->setTexture(Btex);b[i]->delay= 5;sprite[i]->setScale(0.5,0.5);}
	else if(lmao==2)
	{sprite[i]->setTexture(Ctex);b[i]->delay= 4;sprite[i]->setScale(0.37,0.37);}
	sprite[i]->setPosition(*x[i],*y[i]);}
	
		
}

void drawSprite(sf::RenderWindow& window)
{
if(_shape!=20)
for(int i=0; i<shape ; i++)
{if (active[i])
window.draw(*sprite[i]);}

}

void fire()
{
srand(time(NULL));

if (_shape == 7) {
    for (int i = 5; i < shape - 6; i++) {
        if (active[i - 5] && rand() % b[i - 5]->delay == 0) {
            if (i - 5 >= 0 && i - 5 < 10 && b[i - 5]->active == false) {
                b[i - 5]->active = true;
                b[i - 5]->x = *x[i - 5] + 35;
                b[i - 5]->y = *y[i - 5] + 30;
            }
        }
    }
}

	
else
	
	for(int i=0; i<_numshape ; i++)
	{
	if(active[i] && rand()% b[i]->delay == 0)
	if(b[i]->active==false)
	{b[i]->active=true;b[i]->x = *x[i]+35;b[i]->y=*y[i]+30;}}
}

void UpdateBomb()
{
	if(_shape==7)
	{
	for(int i=0; i<shape-10 ; i++)
	if(b[i]->active && active[i])
	{b[i]->y += 0.4;
	b[i]->sprite.setPosition(b[i]->x, b[i]->y); // Update bullet sprite position
		    if (b[i]->check())
		        b[i]->active = false;}}

else
for(int i=0; i<shape ; i++)
{
if(b[i]->active && active[i])
{b[i]->y += 0.4;
b[i]->sprite.setPosition(b[i]->x, b[i]->y); // Update bullet sprite position
            if (b[i]->check())
                b[i]->active = false;}}
  


}

void drawBomb(sf::RenderWindow& window)
{
if(_shape==7)
 for(int i=0; i<shape-10 ; i++)
    {if (b[i]->active && active[i])
       window.draw(b[i]->sprite);}
else    
 for(int i=0; i<shape ; i++)
    {if (b[i]->active && active[i])
       window.draw(b[i]->sprite);}
       
       }

void level()
{
	if(sprite != nullptr && b!=nullptr && x != NULL && y != NULL)
	{
	delete[] sprite; sprite=nullptr;
	delete[] b; b=nullptr;
	delete[] x;
	delete[] y;
	x=NULL;y=NULL;
	}
	srand(time(0));

	ii++;
	
        if (ii == 1)
            hollow_square();
        else if (ii == 2)
            hollow_triangle();
        else if (ii == 3)
            cross();
        else if(ii==4)
         hollow_circle();
        else if (ii==5)
        hollow_heart();
        else if(ii==6)
        hollow_diamond();
        else if(ii==7)
        solid_diamond();
        else if(ii==8)
        solid_heart();
	else if(ii==9)
        dragon();
        
     if(ii<9)
    _num=0;
     else if(ii>=9)
    _num==-2;
}

void dragon() {
	sprite = new Sprite*[1];
	sprite[0]= new Sprite;
    Atex.loadFromFile("img/Dragon.png");
    sprite[0]->setTexture(Atex);
    sprite[0]->setScale(0.75, 0.75);
    sprite[0]->setPosition(200, -100);
    Btex.loadFromFile("img/enemy1_laser.png");
    b = new Bomb*[10];
    for (int i = 0; i < 10; i++) {
        b[i] = new Bomb;
        b[i]->sprite.setTexture(Btex);
        b[i]->sprite.setScale(1.5,1.5);
    }
    _shape=100;_numshape=10;shape=10;
    
}

void water()
{
for(int i=0; i<10 ; i++)
	if(b[i]->active==false)
	{b[i]->active=true;b[i]->x =350;b[i]->y=100;
}
}


void updateWater(float x=0)
{
	for(int i=0; i<shape ; i++)
	if(b[i]->active )
	{b[i]->y += 2;
	if(x<=0)
	b[i]->x-=0.7;
	if(x<=50)
	b[i]->x-=0.65;
	else if(x<=150)
	b[i]->x-=0.55;
	else if(x<=250)
	b[i]->x-=0.45;
	else if(x<=450)
	b[i]->x+=0.6;
	else if(x<=550)
	b[i]->x+=0.7;
	else if(x<=650)
	b[i]->x+=0.8;
	else 
	b[i]->x +=0.9;
	
	b[i]->sprite.setPosition(b[i]->x, b[i]->y); // Update bullet sprite position
		    if (b[i]->check())
		        {b[i]->active = false;}
		        }


}

void drawWater(sf::RenderWindow& window)
{
 for(int i=0; i<shape ; i++)
    {if (b[i]->active)
       window.draw(b[i]->sprite);}
}


};



class Invader : public Enemies
{
public:
	virtual void Level();

};

class Alpha : public Invader
{
public:

	void Level();
    Alpha()
    {
        tex.loadFromFile("img/enemy_1.png");delay = 5;
    }

    
};

class Beta : public Invader
{
public:

	void Level();
	
    Beta()
    {
        tex.loadFromFile("img/enemy_2.png");
        delay = 3;
    }

    
};

class Gamma : public Invader
{
public:
void Level();
    Gamma()
    {
        tex.loadFromFile("img/enemy_3.png");delay = 2;
    }

    
};

