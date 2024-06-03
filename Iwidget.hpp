#pragma once

#include <SFML/Graphics.hpp>

/// @brief interface pour les widgets
class Iwidget {
    public:
        /// @brief destructeur de la classe
        virtual ~Iwidget() = default;

        /// @brief affichage de l'élément
        /// @param window variable de la window
        virtual void draw(sf::RenderWindow& window) = 0;

        /// @brief actualisation
        virtual void update() = 0;
};
