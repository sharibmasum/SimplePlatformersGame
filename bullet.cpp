//
// Created by sharib masum on 2024-07-18.
//

#include "bullet.h"

bullet::bullet(float startx, float starty) {

    bulletTexture.loadFromFile("/Users/sharibmasum/CLionProjects/PlatformersAgain/images/bullet.png");
    bulletSprite.setTexture(bulletTexture);
    bulletSprite.setScale(0.05, 0.05);

    current_bullet_position.x = startx;
    current_bullet_position.y = starty;

}

sf::Sprite bullet::draw_Bullet() {
    bulletSprite.setPosition(current_bullet_position.x, current_bullet_position.y);
    return bulletSprite;
}

void bullet::update_Bullet_position() {
    current_bullet_position.x += RandomFloat(0.1, 0.3);

    if (current_bullet_position.x > 1344 || collided) {
        current_bullet_position.y = RandomFloat(0.0, 700.0);
        current_bullet_position.x = 0;
        collided = false;
    }
}


bool bullet::checkCollision (float x, float y) {
    if (current_bullet_position.x >= x && current_bullet_position.x < x + 60) {
        if (current_bullet_position.y > y - 5 && current_bullet_position.y < y + 90) {
            collided = true;

            return true;
        }
    }

    return false;
}

float bullet::RandomFloat(float min, float max) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = max - min;
    float r = random * diff;
    return min + r;
}