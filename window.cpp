#include "window.hpp"
#include <iostream>

namespace Window
{
    void my_Window::window(int h, int l, std::string title)
    {
        win = std::make_unique<sf::RenderWindow>(sf::VideoMode(l, h), title);
        win->clear(sf::Color::White);
        win->setFramerateLimit(24);
        UI();
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


    void my_Window::event_handler()
    {
        while (win->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                win->close();
            if (event.type == sf::Event::Resized) {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                win->setView(sf::View(visibleArea));
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                std::cout << "Number of widgets: " << widgets.size() << std::endl;
            }
        }
    }

    void my_Window::addWidget(const WidgetInfo& data, sf::RenderWindow* window)
    {
        std::shared_ptr<my_widget> newWidget = std::make_shared<my_widget>();
        newWidget->set_widget(data, window);
        widgets.push_back(newWidget);
    }
}