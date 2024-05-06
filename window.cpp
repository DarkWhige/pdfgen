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
    my_widget widget;
    widget.widget_settup();
    widget.image(win, "images/luffy.jpg", 0, 0, 1, 1, "NULL");
}
