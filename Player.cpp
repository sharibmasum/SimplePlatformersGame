//
// Created by sharib masum on 2024-07-17.
//

#include "Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
float player_height = 90;
float player_width = 60;

Player::Player(float x, float y, int numOfLives) {
    player_position.x = x;
    player_position.y = y;
    lives = numOfLives;
    spriteSheetTexture.loadFromFile(
            "/Users/sharibmasum/CLionProjects/PlatformersAgain/images/FinalPlayerSpriteSheet.png");

    spritePlayer.setTexture(spriteSheetTexture);
    spritePlayer.setTextureRect(sf::IntRect(240, 820, 100, 100)); // Set the texture rectangle for sprite1

    livesTexture.loadFromFile("/Users/sharibmasum/CLionProjects/PlatformersAgain/images/heart.png");
    livesSprite.setTexture(livesTexture); // Set the texture for sprite1
    livesSprite.setScale(0.2, 0.2);
}


void Player::checkPlayerMovement() {

    velocity.x = 0.3;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canJump) {
        velocity.y = -0.40;
        canJump = false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        player_position.x += velocity.x;
        movingRight = true;
        lastMovedRight = true;
    } else {
        movingRight = false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        player_position.x -= velocity.x;
        movingLeft = true;
        lastMovedRight = false;
    } else {
        movingLeft = false;

    }


}


void Player::applyGravity() {
    if (player_position.y > 600) {
        velocity.y = 0;
        player_position.y = 600;
        canJump = true;
    } else {
        velocity.y += gravity;
        player_position.y += velocity.y;
    }
}

void Player::checkBoundaries(float x, float y, float xlength, float ylength) {

    // edges
    if (player_position.x < -32) {
        velocity.x = 0;
        player_position.x = -32;
    }

    // blocks

    if (player_position.x >= x - player_width && player_position.x <= (x + xlength) - (player_width / 2)) {
        if (player_position.y <= (y + ylength) && player_position.y > y) {
            velocity.y = 0;
            player_position.y = (y + ylength);

        }
    }

    if (player_position.y >= y - player_height && player_position.y < y - 30) {
        if (player_position.x >= x - player_width && player_position.x <= (x + xlength) - (player_width / 2)) {
            velocity.y = 0;
            player_position.y = y - player_height;
            canJump = true;

        }
    }

}


sf::Sprite Player::draw_player() {
    if (movingRight) {
        if (animationClock.getElapsedTime().asSeconds() >= 0.1f) {
            frame = (frame + 1) % 6;
            spritePlayer.setTextureRect(sf::IntRect(260 + frame * 200, 830, 100, 100));
            animationClock.restart();
        }
    } else if (movingLeft) {
        if (animationClock.getElapsedTime().asSeconds() >= 0.1f) {
            frame = (frame + 1) % 6;
            spritePlayer.setTextureRect(sf::IntRect(260 + frame * 200, 440, 100, 100));
            animationClock.restart();
        }
    } else if (lastMovedRight) {
        if (animationClock.getElapsedTime().asSeconds() >= 0.15f) {
            frame = (frame + 1) % 4;
            spritePlayer.setTextureRect(sf::IntRect(260 + frame * 200, 625, 100, 100));
            animationClock.restart();
        }
    } else {
        if (animationClock.getElapsedTime().asSeconds() >= 0.15f) {
            frame = (frame + 1) % 4;
            spritePlayer.setTextureRect(sf::IntRect(260 + frame * 200, 50, 100, 100));
            animationClock.restart();
        }

    }
    spritePlayer.setPosition(player_position.x, player_position.y);
    return spritePlayer;
}

int Player::updateLives() {
    lives = lives - 1;
    return lives;
}

int Player::getLives() const {
    return lives;
}

void Player::setLives(int num)  {
    lives = num;
}

sf::Vector2f Player::getPosition() {
    return player_position;
}


sf::Sprite Player::showLives(float x, float y) {
    livesSprite.setPosition(x, y);
    return livesSprite;
}
