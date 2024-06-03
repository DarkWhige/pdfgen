#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include <string>
#include "widgetInfo.hpp"
#include "widget.hpp"
#include "widgets/Image.hpp"

namespace Window
{
    /// @brief classe principale pour la window
    class my_Window
    {
        public:                                                 // toutes les données suivante seront lisible depuis d'autres fonctions
            struct Window_info {                                // structure des données nécéssaires a la création idéale de la fenêtre
                int height;                                     // VARIABLE : hauteur de la fenêtre
                int lenght;                                     // VARIABLE : largeur de la fenêtre
                std::string title;                              // VARIABLE : titre
                int FPS;                                        // VARIABLE : images par secondes
                sf::Color bg_color;                             // VARIABLE : couleur de l'arrère plan
            };                                                  // d'autres éléments peuvent être ajouté par la suite

            // ------------------------------------ fontions relative a la window ------------------------------------------------//

            /// @brief destructeur de la window.
            ~my_Window();

            /// @brief stocker les valeurs par défaut de la fenètre
            /// @param data structure de données de la window
            void set_window_data(Window_info data);

            /// @brief Création de la window.
            void window();

            /// @brief Boucle principale de la window
            void loop();

            /// @brief get la variable de la window actuelle
            /// @return variable de la window
            sf::RenderWindow* get_win() const;

            /// @brief getter
            /// @return hauteur de la fenetre
            int get_win_height() const;

            /// @brief getter
            /// @return largeur de la fenetre
            int get_win_lenght() const;

            /// @brief getter
            /// @return FPS de la fenetre
            int get_win_FPS() const;

            /// @brief getter
            /// @return titre de la fenetre
            std::string get_win_title() const;

            /// @brief getter
            /// @return couleur de la fenetre
            sf::Color get_win_bg_color() const;
            // ------------------------------------ fontions relative au widgets ------------------------------------------------//

            /// @brief ajout d'un widget dans une liste avec les infos donnés
            /// @param data liste de données de widget nécessaire pour le créer
            void addWidget(const WidgetInfo& data);

            /// @brief Suppréssion de tout les widgets de la lsite
            void delWidget();

            // ------------------------------------ fontions relative a la souris ------------------------------------------------//

            /// @brief initialisation des données de la souris
            void set_mouse();

            // ------------------------------------ fontions relative au évenements ----------------------------------------------//

            /// @brief gestion des événements
            void event_handler();

            /// @brief fermeture de la window
            void close_win();

            /// @brief changement de la size de la window
            void resize_win();

            /// @brief gestion des touches préssées
            void key_pressed();

            /// @brief gestion des événements lorsque la souris est déplacée
            void mouse_moved();

            /// @brief gestion du déplacement des widget
            void move_widget();
        private:
            // ------------------------------------ Variables relatives a la window ----------------------------------------------//

            std::unique_ptr<sf::RenderWindow> win;              // VARIABLE : valleur de la window
            sf::Event event;                                    // VARIABLE : valeur des evenements
            int height;                                         // VARIABLE : hauteur de la fenêtre
            int lenght;                                         // VARIABLE : largeur de la fenêtre
            std::string title;                                  // VARIABLE : titre
            int FPS;                                            // VARIABLE : images par secondes
            sf::Color bg_color;                                 // VARIABLE : couleur de l'arrère plan

            // ------------------------------------ Variables relatives au périphériques -----------------------------------------//

            sf::Vector2f mouse;                                 // VARIABLE : souris
            sf::Cursor cursor;                                  // VARIABLE : forme de la souris

            // ------------------------------------ Variables relatives au widgets -----------------------------------------------//

            std::vector<std::shared_ptr<my_widget>> widgets;    // VARIABLE : liste de vecteurs
            bool is_dragging = false;                           // VARIABLE : est-ce qu'on est prêt a déplacer un objet ?
            my_widget* dragged_widget = nullptr;                // VARIABLE : quel widget on doit déplacer
            sf::Vector2f drag_offset;                           // VARIABLE : position de l'offset pour le positionnement de la souris sur le widget
    };
}

/// @brief interface utilisateur
/// @param win window actuelle
void UI(Window::my_Window& win);
