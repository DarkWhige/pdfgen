#pragma once

#include <SFML/Graphics.hpp>
#include "../Iwidget.hpp"
#include "../widgetInfo.hpp"
#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <fstream>

namespace Window
{
    class Gif : public Iwidget {
        public:
            Gif();
            ~Gif();

            void SetGif(const WidgetInfo& data, sf::RenderWindow* window);

            void draw(sf::RenderWindow& window) override;
            void update() override;

            sf::Sprite sprite;
            bool Loaded = false;
        private:
            sf::Vector2f pos;
            sf::Vector2f size;
            std::vector<sf::Texture> textures;
            std::string path;
            int currentFrame = 0;
            sf::Clock frameClock;
            sf::Time frameDuration = sf::milliseconds(100); // 10 frames per second
    };
}