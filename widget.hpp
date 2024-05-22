#pragma once

#include <SFML/Graphics.hpp>
#include "Iwidget.hpp"
#include "widgetInfo.hpp"
#include "widgets/Image.hpp"
#include "widgets/Text.hpp"

namespace Window
{
    class my_widget : public Iwidget {
        public:
            my_widget();
            void set_widget(const WidgetInfo& data, sf::RenderWindow* window);
            void AddTextEditor();
            void draw(sf::RenderWindow& window) override;
            void update() override;

        private:
            Image image;
            Text text;
    };
}
