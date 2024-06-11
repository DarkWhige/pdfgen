#pragma once

#include <SFML/Graphics.hpp>
#include "Iwidget.hpp"
#include "widgetInfo.hpp"

#include "widgets/Image.hpp"        // include du widget d'image
#include "widgets/Text.hpp"         // include du wifget de texte
#include "widgets/Text_edit.hpp"    // include du widget d'editeur de texte
#include "widgets/Gif.hpp"          // include du widget de gif

namespace Window
{
    class my_widget : public Iwidget {
        public:
            /// @brief constructeur
            my_widget();

            /// @brief destructeur
            ~my_widget();

            /// @brief setup du widget en fonction de son type
            /// @param data liste de donnée du widget
            /// @param window window
            void set_widget(const WidgetInfo& data, sf::RenderWindow* window);

            /// @brief getter
            /// @return liste de donnée du widget
            WidgetInfo get_data() const;

            /// @brief getter
            /// @return data widget image
            Image get_image() const;

            /// @brief getter
            /// @return data widget texte
            Text get_text() const;

            /// @brief getter
            /// @return data widget edisteur de texte basique
            TextBE get_text_editor_b() const;

            /// @brief set les positions
            /// @param position position du widget
            void set_pos(const sf::Vector2f& position);
            
            /// @brief affichage du widget
            /// @param window window
            void draw(sf::RenderWindow& window) override;

            /// @brief actualisation du widget
            void update() override;
        private:
            WidgetInfo data;        // data structure des infos du widget
            Image image;            // widget de type image
            Text text;              // widget de type text
            TextBE text_editor_b;   // widget de type editeur de texte basique
            Gif gif;                // widget de type gif (image animée)
    };
}
