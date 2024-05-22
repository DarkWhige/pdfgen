#pragma once

#include <SFML/Graphics.hpp>
#include "../Iwidget.hpp"
#include "../widgetInfo.hpp"
#include <iostream>

namespace Window
{
    class Image : public Iwidget {
        public:
            Image();
            void SetImage(const WidgetInfo& data, sf::RenderWindow* window);
            void draw(sf::RenderWindow& window) override;
            void update() override;

            sf::Sprite sprite;
            bool Loaded = false;
        private:
            sf::Vector2f pos;
            sf::Vector2f size;
            sf::Texture texture;
            std::string path;
    };
}
