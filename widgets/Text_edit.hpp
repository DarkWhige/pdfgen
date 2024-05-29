#pragma once

#include <SFML/Graphics.hpp>
#include "../Iwidget.hpp"
#include "../widgetInfo.hpp"
#include <iostream>

namespace Window
{
    class TextBE : public Iwidget {
        public:
            TextBE();
            ~TextBE();
            void SetTextBE(const WidgetInfo& data, sf::RenderWindow* window);
            void SetFont(const WidgetInfo& data, sf::RenderWindow* window);
            void SetBack(const WidgetInfo& data, sf::RenderWindow* window);
            std::string get_font_type() const;
            std::string get_font_shape() const;
            void draw(sf::RenderWindow& window) override;
            void update() override;

            sf::Text text;
            sf::RectangleShape back;
            bool Loaded = false;
        private:
            sf::Vector2f pos;
            sf::Vector2f size;
            std::string font_path;
            std::string font_type;
            std::string content;
            sf::Color color;
            sf::Color back_color;
            sf::Color outline_color;
            float outline_thickness;
            std::string font_shape;
            int font_size;
            sf::Font font;
    };
}
