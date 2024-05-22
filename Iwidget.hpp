#pragma once

#include <SFML/Graphics.hpp>

class Iwidget {
    public:
        virtual ~Iwidget() = default;
        virtual void draw(sf::RenderWindow& window) = 0;
        virtual void update() = 0;
};
