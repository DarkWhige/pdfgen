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
    class my_Window
    {
        public:
            void window(int h, int l, std::string title);
            void loop();
            void event_handler();
            void addWidget(const WidgetInfo& data, sf::RenderWindow* window);
            void UI();
        private:
            std::unique_ptr<sf::RenderWindow> win;
            std::vector<std::shared_ptr<my_widget>> widgets;
            sf::Event event;
    };
}
