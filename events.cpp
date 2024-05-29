#include "window.hpp"
#include <iostream>

namespace Window
{
    void my_Window::event_handler()
    {
        while (win->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                close_win();
            if (event.type == sf::Event::Resized) {
                resize_win();
            }
            if (event.type == sf::Event::KeyPressed) {
                key_pressed();
            }
            if (event.type == sf::Event::MouseMoved) {
                mouse_moved();
            }
        }
    }

    void my_Window::close_win()
    {
        delWidget();
        win->close();
    }

    void my_Window::resize_win()
    {
        sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
        win->setView(sf::View(visibleArea));
    }

    void my_Window::key_pressed()
    {
        if (event.key.code == sf::Keyboard::Space) {
            std::cout << "Number of widgets: " << widgets.size() << std::endl;
        }
    }

    void my_Window::mouse_moved()
    {
        mouse.x = event.mouseMove.x;
        mouse.y = event.mouseMove.y;

        bool customCursorSet = false;

        for (int i = 0; i < widgets.size(); i++) {
            const auto& widget = widgets[i];
            if (widget->getData().type == "TEXT") {
                if (mouse.x > widget->getData().pos.x && mouse.x < widget->getData().size.x &&
                    mouse.y > widget->getData().pos.y && mouse.y < widget->getData().size.y) {
                    cursor.loadFromSystem(sf::Cursor::Text);
                    win->setMouseCursor(cursor);
                } else {
                    cursor.loadFromSystem(sf::Cursor::Arrow);
                    win->setMouseCursor(cursor);
                }
            }
        }
    }
}