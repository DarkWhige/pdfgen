#pragma once

#include <SFML/Graphics.hpp>
#include <string>

namespace Window
{
    struct WidgetInfo {
        std::string type;
        std::string mouse_type;
        std::string mouse_path;

        bool button;
        std::string action;

        sf::Vector2f pos;
        sf::Vector2f size;

        sf::Color color;
        sf::Color outline_color;
        sf::Color back_color;
        float outline_thickness;

        std::string path;

        std::string content;
        std::string font_type;
        std::string font_shape;
        int font_size;
    };
}
