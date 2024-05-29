#pragma once

#include <SFML/Graphics.hpp>
#include "Iwidget.hpp"
#include "widgetInfo.hpp"

#include "widgets/Image.hpp"
#include "widgets/Text.hpp"
#include "widgets/Text_edit.hpp"

namespace Window
{
    class my_widget : public Iwidget {
        public:
            my_widget();
            ~my_widget();
            void set_widget(const WidgetInfo& data, sf::RenderWindow* window);
            WidgetInfo getData();
            
            void draw(sf::RenderWindow& window) override;
            void update() override;
        private:
            WidgetInfo data;
            Image image;
            Text text;
            TextBE text_editor_b;
    };
}
