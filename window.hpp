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
            ~my_Window();
            void window(int h, int l, std::string title);
            void loop();
            void addWidget(const WidgetInfo& data);
            void delWidget();

            void event_handler();
            void close_win();
            void resize_win();
            void key_pressed();
            void mouse_moved();
            
            sf::RenderWindow* get_win() const;
        private:
            std::unique_ptr<sf::RenderWindow> win;
            std::vector<std::shared_ptr<my_widget>> widgets;
            sf::Event event;

            sf::Vector2f mouse;
            sf::Cursor cursor;
    };
}

void UI(Window::my_Window& win);
