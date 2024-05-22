#pragma once

#include <SFML/Graphics.hpp>
#include <string>

namespace Window
{
    struct WidgetInfo {
        std::string type;

        sf::Vector2f pos;
        sf::Vector2f size;

        sf::Color color;
        sf::Color outline_color;

        std::string path;

        std::string content;
        std::string font_type;
        std::string font_shape;
        int font_size;
    };
}
