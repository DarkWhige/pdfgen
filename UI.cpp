#include "window.hpp"
#include <iostream>

sf::Color black = sf::Color::Black;
sf::Color white = sf::Color::White;
sf::Color blue = sf::Color::Blue;
sf::Color cyan = sf::Color::Cyan;
sf::Color green = sf::Color::Green;
sf::Color magenta = sf::Color::Magenta;
sf::Color red = sf::Color::Red;
sf::Color transparent = sf::Color::Transparent;
sf::Color yellow = sf::Color::Yellow;
// add custom collors

namespace Window
{
    void my_Window::UI()
    {
        WidgetInfo P_luffy_info;
        P_luffy_info.type = "PICTURE";
        P_luffy_info.pos = sf::Vector2f(0, 0);
        P_luffy_info.size = sf::Vector2f(200, 200);
        P_luffy_info.path = "./ressources/images/luffy.jpg";

        WidgetInfo T_title_info;
        T_title_info.type = "TEXT";
        T_title_info.pos = sf::Vector2f(0, 0);
        T_title_info.size = sf::Vector2f(200, 200);
        T_title_info.color = black;
        T_title_info.path = "./ressources/fonts/";
        T_title_info.font_size = 24;
        T_title_info.font_type = "ARIAL";
        T_title_info.font_shape = "NORMAL";
        T_title_info.content = "Hello my friend, welcom in the first version of the app";

        // addWidget(P_luffy_info, win.get());
        addWidget(T_title_info, win.get());
    }
}