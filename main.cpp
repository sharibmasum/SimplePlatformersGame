#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "bullet.h"

using namespace std;

Player player(500, 300, 3);
bullet bullet1(-10,400);
bullet bullet2(-40, 600);

int main() {
    int gameState = 1;

    sf::RenderWindow window(sf::VideoMode(1344, 768), "SFML Application");

    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("/Users/sharibmasum/CLionProjects/PlatformersAgain/images/Background.jpg");
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    sf::Texture mainMenuTexture;
    mainMenuTexture.loadFromFile("/Users/sharibmasum/CLionProjects/PlatformersAgain/images/mainMenu.jpg");
    sf::Sprite mainMenuSprite;
    mainMenuSprite.setTexture(mainMenuTexture);


    sf::RectangleShape platforms[6];

    for (int i = 0; i < 6; i++) {
        platforms[i].setFillColor(sf::Color::Red);

    }

    platforms[0].setPosition(45, 560);
    platforms[0].setSize(sf::Vector2f(355, 39));

    platforms[1].setPosition(565, 450);
    platforms[1].setSize(sf::Vector2f(390, 50));

    platforms[2].setPosition(1106, 542);
    platforms[2].setSize(sf::Vector2f(211, 43));

    platforms[3].setPosition(942, 262);
    platforms[3].setSize(sf::Vector2f(377, 46));

    platforms[4].setPosition(602, 85);
    platforms[4].setSize(sf::Vector2f(372, 44));

    platforms[5].setPosition(207, 241);
    platforms[5].setSize(sf::Vector2f(283, 41));


    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
                gameState = 1;
            } else if (sf::Mouse::getPosition(window).x > 475 && sf::Mouse::getPosition(window).x < 892) {
                if (sf::Mouse::getPosition(window).y > 387 && sf::Mouse::getPosition(window).y < 441 ) {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                        gameState = 0;
                    }
                }
            }


        }

        if (gameState == 0) {
            window.clear();
            window.draw(backgroundSprite);


            if (player.getLives() <= 0) {
                gameState = 1;
            }


            for (auto & platform : platforms) {
                player.checkBoundaries(platform.getPosition().x, platform.getPosition().y,
                                       platform.getSize().x, platform.getSize().y);

            }

            player.checkPlayerMovement();
            player.applyGravity();
            window.draw(player.draw_player());


            bullet1.update_Bullet_position();
            window.draw(bullet1.draw_Bullet());

            if (bullet1.checkCollision(player.getPosition().x, player.getPosition().y) == true) {
                cout << player.updateLives() << endl;
            }

            bullet2.update_Bullet_position();
            window.draw(bullet2.draw_Bullet());

            if (bullet2.checkCollision(player.getPosition().x, player.getPosition().y) == true) {
                cout << player.updateLives() << endl;
            }

            for (int i=0; i<player.getLives(); i++) {
                window.draw(player.showLives(50+(i*70), 50));
            }
            window.display();

        } else if (gameState == 1) {
            window.clear();
            window.draw(mainMenuSprite);
            player.setLives(3);
            window.display();


        }
    }
}
