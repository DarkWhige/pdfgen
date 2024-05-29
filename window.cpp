#include "window.hpp"
#include <iostream>

namespace Window
{
    my_Window::~my_Window()
    {
        widgets.clear();
        win.reset();
    }

    void my_Window::window(int h, int l, std::string title)
    {
        win = std::make_unique<sf::RenderWindow>(sf::VideoMode(l, h), title);
        win->clear(sf::Color::White);
        win->setFramerateLimit(24);
        win->display();
    }

    void my_Window::loop()
    {
        while (win->isOpen()) {
            event_handler();
            win->clear(sf::Color::White);
            for (size_t i = 0; i < widgets.size(); ++i) {
                widgets[i]->draw(*win);
            }
            win->display();
        }
    }

    void my_Window::addWidget(const WidgetInfo& data)
    {
        std::shared_ptr<my_widget> newWidget = std::make_shared<my_widget>();
        newWidget->set_widget(data, win.get());
        widgets.push_back(newWidget);
    }

    void my_Window::delWidget()
    {
        widgets.clear();
        win->clear();
    }

    sf::RenderWindow* my_Window::get_win() const
    {
        return win.get();
    }
}