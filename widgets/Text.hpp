#pragma once

#include <SFML/Graphics.hpp>
#include "../Iwidget.hpp"
#include "../widgetInfo.hpp"
#include <iostream>

namespace Window
{
    class Text : public Iwidget {
        public:
            Text();
            void SetText(const WidgetInfo& data, sf::RenderWindow* window);
            std::string get_font_type();
            std::string get_font_shape();
            void draw(sf::RenderWindow& window) override;
            void update() override;

            sf::Text text;
            bool Loaded = false;
        private:
            sf::Vector2f pos;
            sf::Vector2f size;
            std::string font_path;
            std::string font_type;
            std::string content;
            sf::Color color;
            std::string font_shape;
            int font_size;

            sf::Font font;
    };
}
