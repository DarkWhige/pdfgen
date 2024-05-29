#include "window.hpp"
#include "widgetInfo.hpp"
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
sf::Color gray = sf::Color(230, 230, 230, 255);

void UI(Window::my_Window& win)
{
    Window::WidgetInfo P_luffy_info;
    P_luffy_info.type = "PICTURE";
    P_luffy_info.pos = sf::Vector2f(0, 0);
    P_luffy_info.size = sf::Vector2f(200, 200);
    P_luffy_info.path = "./ressources/images/luffy.jpg";

    Window::WidgetInfo T_title_info;
    T_title_info.type = "TEXT";
    T_title_info.pos = sf::Vector2f(0, 0);
    T_title_info.size = sf::Vector2f(200, 200);
    T_title_info.color = green;
    T_title_info.path = "./ressources/fonts/";
    T_title_info.font_size = 24;
    T_title_info.font_type = "ARIAL";
    T_title_info.font_shape = "NORMAL";
    T_title_info.content = "Hello my friend, welcom in the first version of the app";

    Window::WidgetInfo TE_title_info;
    TE_title_info.type = "TEXT_EDITOR_B";
    TE_title_info.pos = sf::Vector2f(200, 200);
    TE_title_info.size = sf::Vector2f(200, 200);
    TE_title_info.color = black;
    TE_title_info.path = "./ressources/fonts/";
    TE_title_info.font_size = 24;
    TE_title_info.font_type = "ARIAL";
    TE_title_info.font_shape = "NORMAL";
    TE_title_info.back_color = gray;
    TE_title_info.outline_color = black;
    TE_title_info.content = "";
    TE_title_info.outline_thickness = 1.0;

    Window::WidgetInfo TE_title_info_1;
    TE_title_info_1.type = "TEXT_EDITOR_B";
    TE_title_info_1.pos = sf::Vector2f(0, 0);
    TE_title_info_1.size = sf::Vector2f(200, 200);
    TE_title_info_1.color = black;
    TE_title_info_1.path = "./ressources/fonts/";
    TE_title_info_1.font_size = 24;
    TE_title_info_1.font_type = "ARIAL";
    TE_title_info_1.font_shape = "NORMAL";
    TE_title_info_1.back_color = gray;
    TE_title_info_1.outline_color = black;
    TE_title_info_1.content = "";
    TE_title_info_1.outline_thickness = 1.0;

    win.addWidget(P_luffy_info);
    win.addWidget(T_title_info);
    // addWidget(TE_title_info_1, win.get());
    // addWidget(TE_title_info, win.get());
}