#pragma once

#include <SFML/Graphics.hpp>
#include <string>

namespace Window
{
    /// @brief toutes les datas qu'un widget peut avoir
    struct WidgetInfo {
        // --------------------------------------------------------- général ---------------------------------------------------- //

        std::string type;   // type de widget (A PASSER EN ENUM ASSEZ RAPIDEMENT)
        sf::Vector2f pos;   // position du widget
        sf::Vector2f size;  // taille du widget

        // --------------------------------------------------------- souris ----------------------------------------------------- //

        std::string mouse_type; // type de curseur de souris attribuer (A PASSER EN ENUM ASSEZ RAPIDEMENT)

        // --------------------------------------------------------- bouton ----------------------------------------------------- //

        bool button;    // est-ce un bouton ou non ?
        std::string action; // quelle action peut provoquer le bouton ?

        // --------------------------------------------------- couleurs / forme ------------------------------------------------- //

        sf::Color color;    // couleur de l'élément du widget (ex : couleur du texte)
        sf::Color outline_color;    // couleur de la bordure
        sf::Color back_color;       // couleur de l'arrière du widget
        float outline_thickness;    // épaisseur de la bordure

        // --------------------------------------------------------- police ----------------------------------------------------- //

        std::string content;    // contenu du widget (ex : contenu du texte)
        std::string font_type;  // type de police (ex : arial)
        std::string font_shape; // forme de la police (ex : italique; normale, etc...)
        int font_size;  // taille de la police

        // --------------------------------------------------------- autre ------------------------------------------------------ //

        std::string path;   // chemin vers un élément demandé (ex : chemin vers l'image ou la font d'un texte)
        bool can_move;  // est-ce que le widget peut etre bougé par l'utilisateur
    };
}
