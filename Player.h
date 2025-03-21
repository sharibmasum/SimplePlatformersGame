//
// Created by sharib masum on 2024-07-17.
//

#ifndef PLATFORMERSAGAIN_PLAYER_H
#define PLATFORMERSAGAIN_PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
private:
    sf::Vector2f player_position;
    sf::Vector2f velocity;

    float  gravity = 0.00045;
    bool movingLeft = false;
    bool movingRight = false;
    bool lastMovedRight = false;

    bool canJump;
    sf::Texture spriteSheetTexture;
    sf::Sprite spritePlayer;


    sf::Texture livesTexture;
    sf::Sprite livesSprite;

    int lives;


    sf::Clock animationClock; // Clock to manage animation timing
    int frame = 0; // Frame index for animation

public:
    Player (float x, float y, int numOfLives);

    void checkPlayerMovement();

    sf::Sprite draw_player();

    sf::Vector2f getPosition();
    void checkBoundaries(float, float, float, float);

    void applyGravity();

    int updateLives();

    int getLives() const;

    sf::Sprite showLives(float, float);

    void setLives(int num);
};


#endif //PLATFORMERSGAME_PLAYER_H
