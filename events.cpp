#include "window.hpp"
#include <iostream>


namespace Window
{
    void my_Window::set_mouse()
    {
        if (event.type == sf::Event::MouseMoved) {
            mouse.x = event.mouseMove.x;
            mouse.y = event.mouseMove.y;
        } else if (event.type == sf::Event::MouseButtonPressed) {
            mouse.x = event.mouseButton.x;
            mouse.y = event.mouseButton.y;
        }
    }

    void my_Window::event_handler()
    {
        while (win->pollEvent(event)) {
            set_mouse();
            if (event.type == sf::Event::Closed)
                close_win();
            if (event.type == sf::Event::Resized) {
                resize_win();
            }
            if (event.type == sf::Event::KeyPressed) {
                key_pressed();
            }
            if (event.type == sf::Event::MouseMoved || event.type == sf::Event::MouseButtonPressed || event.type == sf::Event::MouseButtonReleased) {
                mouse_moved();
                move_widget();
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
        sf::Vector2u sizemin(200,300);
        sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
        win->setView(sf::View(visibleArea));
        if (win->getSize().x <= 200) {
            win->setSize(sizemin);
        }
    }

    void my_Window::key_pressed()
    {
        if (event.key.code == sf::Keyboard::Space) {
            std::cout << "Number of widgets: " << widgets.size() << std::endl;
        }
    }

    void my_Window::mouse_moved()
    {
        for (int i = 0; i < widgets.size(); i++) {
            const auto& widget = widgets[i];
            if (widget->get_data().type == "TEXT") {
                if (mouse.x > widget->get_data().pos.x && mouse.x < widget->get_data().size.x &&
                    mouse.y > widget->get_data().pos.y && mouse.y < widget->get_data().size.y) {
                    cursor.loadFromSystem(sf::Cursor::Text);
                    win->setMouseCursor(cursor);
                } else {
                    cursor.loadFromSystem(sf::Cursor::Arrow);
                    win->setMouseCursor(cursor);
                }
            }
        }
    }

    void my_Window::move_widget()
    {
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            for (int i = 0; i < widgets.size(); i++) { // itération pour check tout les widgets de la window
                const auto& widget = widgets[i];
                if (widget->get_data().can_move) { // si le widget a les permissions de bouger
                    if (mouse.x > widget->get_data().pos.x && mouse.x < widget->get_data().pos.x + widget->get_data().size.x &&
                        mouse.y > widget->get_data().pos.y && mouse.y < widget->get_data().pos.y + widget->get_data().size.y) { // si la souris est sur le widget
                        cursor.loadFromSystem(sf::Cursor::Hand);
                        win->setMouseCursor(cursor); // load le nouveau curseur
                        is_dragging = true; // toutes les vérifications ont été faite, l'objet est ok pour etre déplacé
                        dragged_widget = widget.get(); // Capture le widget en cours de déplacement
                        drag_offset = sf::Vector2f(mouse.x - widget->get_data().pos.x, mouse.y - widget->get_data().pos.y); // Capture l'offset initial entre la position de la souris et celle du widget
                        break; // fin de la boucle
                    }
                }
            }
        }
        if (is_dragging && event.type == sf::Event::MouseMoved) { // si il est déplaçable et qu'on bouge la souris,
            sf::Vector2f new_pos(mouse.x - drag_offset.x, mouse.y - drag_offset.y); // on set les nouvelles positions
            dragged_widget->set_pos(new_pos);   // on set les nouvelles positions
        }
        if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) { // si le boutton est laché
            is_dragging = false;    // le widget ne doit plus pouvoir être déplacé
            dragged_widget = nullptr; // on retire le lien avec le widget
        }
        if (!is_dragging) { // si il n'est plus déplaceable,
            cursor.loadFromSystem(sf::Cursor::Arrow);   // on remet le curseur de la souris à la flèche
            win->setMouseCursor(cursor);
        }
    }
}
