#include "window.hpp"

void Window::my_Window::window(int h, int l, std::string title)
{
    win = std::make_unique<sf::RenderWindow>(sf::VideoMode(l, h), title);
    win->clear(sf::Color::White);
}

void Window::my_Window::loop()
{
    while (win->isOpen()) {
        event_hendler();
        setup();
        win->display();
    }
}

void Window::my_Window::event_hendler()
{
    while (win->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            win->close();
        if (event.type == sf::Event::Resized) {
            win->clear();
        }
    }
}

void Window::my_Window::setup()
{
    win->setFramerateLimit(60);
    // my_widget::shapes shape;
    // my_widget::shapes::shape_data data {0, 0, 100, 200, "", sf::Color(0,0,0,255), sf::Color(0,0,0,255), 1.0f, win};
    // shape.triangle_rec1(&data);

    // my_widget widget;
    // widget.widget_settup();
    // widget.set_font("ressources/fonts/arial/Arial.ttf");
    // widget.text_input(win, 80, 200, 100, 200, "");
}
