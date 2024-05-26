#include "game.h"
#include <fstream>

class Menu {
public:
    Menu() {
        // Constructor body
    }

    void display_menu() {
        sf::RenderWindow window(sf::VideoMode(780, 780), "Title");  // Create the RenderWindow object
        int ii = 1;
        sf::Texture bg;
        sf::Sprite s;
        int count = 0;
        std::string name;
        bool exist=0;
        std::string* Name;
        int* Score;
        int haah;

        sf::Font font;
        font.loadFromFile("Mega_Man_Battle_Network_Regular.ttf");


        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(30);
        text.setFillColor(sf::Color::White);
	bool foo=true;
        while (ii) {
        if(foo){
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                } else if (event.type == sf::Event::TextEntered) {
                    if (event.text.unicode < 128) {
                        if (event.text.unicode == '\b' && !name.empty()) {
                            name.pop_back();
                        } else if (event.text.unicode != '\b' && event.text.unicode != '\r') {
                            name += static_cast<char>(event.text.unicode);
                        }
                    }
                }
            }
		bg.loadFromFile("img/BG2.jpg");
            text.setString(name);
            text.setPosition(150,250);
            s.setTexture(bg);
            window.clear();
            window.draw(s);
            window.draw(text);
            window.display();
	}	
	    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	    {
	    foo=false;
	    }
	    if(!foo)
	    { bg.loadFromFile("img/bg.jpg");
	    window.clear();
            s.setTexture(bg);
            s.setScale(1.15,1);
            window.draw(s);
            window.display();}
		

		
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
                std::ifstream sreadFile("highscore.txt");
                ii = 0;
                string fame[4];
                if (sreadFile.is_open()) {
                    int i = 0;
                    int xx;
                    std::string h;
                    while (sreadFile.peek() != EOF) {
                        if (i < 3) {
                            sreadFile >> fame[i];i++;
                            sreadFile >> xx;
                        } else{
                            sreadFile >>fame[3];
                            if(fame[3]==name)
                            exist=true;
                            sreadFile >>xx;
                        }
                        count++;
                    }
                    if(name==fame[0]) 
                    haah=1;
                    else if(name==fame[1] ) 
                    haah=2;
                    else if(name==fame[2])
                    haah=3;
                    else 
                    haah=0;
                    
                    sreadFile.close();
                }
            }
	
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
                ii = 3;
                while (ii == 3) {
                    bg.loadFromFile("img/bg1.jpg");
                    s.setTexture(bg);
                    window.draw(s);
                    window.display();

                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                        ii = 1;
                    }
                }
            }
               if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
                ii = 2;
                while (ii == 2) {
                    bg.loadFromFile("img/Highscore.png");
                    s.setTexture(bg);
                    window.draw(s);
                   
			std::ifstream sreadFile("highscore.txt");
                string fame[4];int xx[4];
                if (sreadFile.is_open()) {
                    int i = 0;
                    std::string h;
                    while (sreadFile.peek() != EOF) {
                        if (i < 3) {
                            getline(sreadFile,fame[i]);i++;
                        } else{
                            getline(sreadFile,fame[3]);
                        }
                    }}
                    sreadFile.close();
	Text text,text1,text2;
	Font font;
	font.loadFromFile("Mega_Man_Battle_Network_Regular.ttf");
	text.setFont(font);text1.setFont(font);text2.setFont(font);
	text.setCharacterSize(24);text1.setCharacterSize(24);text2.setCharacterSize(24);
	text.setFillColor(sf::Color::Black);text1.setFillColor(sf::Color::Black);text2.setFillColor(sf::Color::Black);
	text.setString(fame[0]);
	text1.setString(fame[1]);
	text2.setString(fame[2]);
	text.setPosition(300,330);text1.setPosition(300,460);text2.setPosition(300,600);
		window.draw(text);window.draw(text1);window.draw(text2); 
		window.display();
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                        ii = 1;
                    }
                }}
        
        }
	
        Game game;  // Pass the RenderWindow to the Game constructor
        game.tem=haah;
        game.start_game(window);

	Text text1;
	text1.setFont(font);
	text1.setCharacterSize(18);
	text1.setFillColor(sf::Color::Black);
	text1.setString(std::to_string(game.score));
	text1.setPosition(350,290);
	
	int dummy=1;
	while(window.isOpen() && dummy)
	{Event e;
       while (window.pollEvent(e) && dummy)
        {
            if (e.type == sf::Event::Closed)
                window.close();
        	
        bg.loadFromFile("img/GameOver.jpg");
        s.setTexture(bg);
        s.setScale(1,1);	
       window.clear(Color::Black); //clears the screen
	window.draw(s);
	window.draw(text1);
	window.display();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        dummy=0;
        }
        }
        
        
        if(exist==true || haah!=0)
        {
        count--;
	Score= new int[count];
	Name=new string [count];
    	int i=0;
    	string h;
        
        std::ifstream sreadFile("highscore.txt");

    	 while (sreadFile.peek() != EOF) {
            if (i < count) {
           sreadFile >> Name[i];
           sreadFile >> Score[i];
           i++;
                }
                else
                getline(sreadFile,h);                       
                }
    	sreadFile.close();
    	
    	
    	
    	for(int ii=0; ii<count ; ii++)
    	{
    	if(name==Name[ii] && game.score>Score[ii])
    	Score[ii]=game.score;}
    	
    	}
    	
    	if(exist==false && haah==0)
        {
	Score= new int[count];
	Name=new string [count];
    	int i=0;
    	string h;
        
        std::ifstream sreadFile("highscore.txt");

    	 while (sreadFile.peek() != EOF) {
            if (i < count) {
           sreadFile >> Name[i];
           sreadFile >> Score[i];
           i++;
                }
                else
                getline(sreadFile,h);                       
                }
    	sreadFile.close();
    	
    	Name[count-1]=name;
    	Score[count-1]=game.score;
    	
    	}
    	
    	for (int ix = 0; ix < count - 1; ix++)
       { for (int j = 0; j < count - ix - 1; j++)
          {  if(Score[j] < Score[j + 1])
             {
             int temp =0; string Temp;
             
             temp =Score[j];
             Score[j]=Score[j+1];
             Score[j+1]=temp;
             
             Temp=Name[j];
             Name[j]=Name[j+1];
             Name[j+1]=Temp;
             
             } }}
             
         std::ofstream swrite("highscore.txt");  
         
         for(int i=0; i<count ; i++)
	{
	swrite<<Name[i]<<" "<<Score[i]<<endl;
	}
    	swrite.close();
    	
    	dummy=1;
    	while(window.isOpen() && dummy)
	{Event e;
       while (window.pollEvent(e) && dummy)
        {
            if (e.type == sf::Event::Closed)
                window.close();
        	
        bg.loadFromFile("img/Highscore.png");
        s.setTexture(bg);
        s.setScale(1,1);	
       window.clear(Color::Black); //clears the screen
	window.draw(s);
				std::ifstream sreadFile("highscore.txt");
                string fame[4];int xx[4];
                if (sreadFile.is_open()) {
                    int i = 0;
                    std::string h;
                    while (sreadFile.peek() != EOF) {
                        if (i < 3) {
                            getline(sreadFile,fame[i]);i++;
                        } else{
                            getline(sreadFile,fame[3]);
                        }
                    }}
                    sreadFile.close();
	Text text,text1,text2;
	Font font;
	font.loadFromFile("Mega_Man_Battle_Network_Regular.ttf");
	text.setFont(font);text1.setFont(font);text2.setFont(font);
	text.setCharacterSize(24);text1.setCharacterSize(24);text2.setCharacterSize(24);
	text.setFillColor(sf::Color::Black);text1.setFillColor(sf::Color::Black);text2.setFillColor(sf::Color::Black);
	text.setString(fame[0]);
	text1.setString(fame[1]);
	text2.setString(fame[2]);
	text.setPosition(300,330);text1.setPosition(300,460);text2.setPosition(300,600);
		window.draw(text);window.draw(text1);window.draw(text2); 
		window.display();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        dummy=0;
        }
        }
    	
    }
};


