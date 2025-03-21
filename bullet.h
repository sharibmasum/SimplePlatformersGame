//
// Created by sharib masum on 2024-07-18.
//

#ifndef PLATFORMERSAGAIN_BULLET_H
#define PLATFORMERSAGAIN_BULLET_H
#include <SFML/Graphics.hpp>


class bullet {
private:
    sf::Vector2f current_bullet_position;

    sf::Texture bulletTexture;
    sf::Sprite bulletSprite;

    bool collided;

public:
    bullet(float startx, float starty);

    sf::Vector2f get_bullet_position;

    void update_Bullet_position();

    sf::Sprite draw_Bullet();

    static float RandomFloat(float min, float max);

    bool checkCollision(float, float);
};


#endif //PLATFORMERSAGAIN_BULLET_H
