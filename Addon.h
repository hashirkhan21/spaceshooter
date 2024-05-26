#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <ctime>


class Addon {
public:
    virtual void activate() = 0;
    virtual sf::Sprite getSprite() const = 0;
};

class Fire : public Addon {
public:
    sf::Texture texture;
    sf::Sprite sprite;

    Fire() {
        if (!texture.loadFromFile("fire.png")) {
            std::cout << "Failed to load fire.png" << std::endl;
        }
        sprite.setTexture(texture);
        sprite.setScale(0.5f, 0.5f);
    }

    void activate() override {
        std::cout << "Fire addon activated!" << std::endl;
	
    }

    sf::Sprite getSprite() const override {
        return sprite;
    }
};

class Lives : public Addon {
public:
    int extraLives;
    sf::Texture texture;
    sf::Sprite sprite;


    Lives(int numExtraLives) : extraLives(numExtraLives) {
        if (!texture.loadFromFile("heart.png")) {
            std::cout << "Failed to load heart.png" << std::endl;
        }
        sprite.setTexture(texture);
        sprite.setScale(0.5f, 0.5f);
    }

    void activate() override {
        std::cout << "Extra lives addon activated!" << std::endl;
        // Extra lives addon specific logic
        if (extraLives == 1) {
            std::cout << "Gained an extra life!" << std::endl;
        } else {
            std::cout << "Gained " << extraLives << " extra lives!" << std::endl;
        }
    }

    sf::Sprite getSprite() const override {
        return sprite;
    }
};


class Danger : public Addon {
public:
    void activate() override {

    }
};


