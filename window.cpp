#include "window.hpp"
#include <iostream>

namespace Window
{
    my_Window::~my_Window()
    {
        widgets.clear();    // suppression de la liste de widget
        win.reset();    // suppréssion de la window
    }

    void my_Window::window(my_Window::Window_info data)
    {
        win = std::make_unique<sf::RenderWindow>(sf::VideoMode(data.height, data.lenght), data.title);   // création de la fenètre avec les dimension et le titre demandé
        win->clear(data.bg_color);   // setup le fond de la fenètre en blanc
        win->setFramerateLimit(data.FPS);     // setup la limite d'image par seconde de la fenètre au montant demandé
        win->display();
    }

    void my_Window::loop()
    {
        while (win->isOpen()) { // tant que la window est ouverte
            event_handler();    // fonction de gestion des évenements
            win->clear(sf::Color::White);  // actualisation du background
            for (size_t i = 0; i < widgets.size(); ++i) {   // iteration dans la liste des widgets
                widgets[i]->draw(*win); // affichage des widgets
            }
            win->display(); // affichage de l'enssemble de la window
        }
    }

    sf::RenderWindow* my_Window::get_win() const
    {
        return win.get();   // recupération de la window
    }

    void my_Window::addWidget(const WidgetInfo& data)
    {
        std::shared_ptr<my_widget> newWidget = std::make_shared<my_widget>();   // creation d'un nouveau pointeur vers un widget
        newWidget->set_widget(data, win.get()); // set le pointeur
        widgets.push_back(newWidget);   // ajout du pointeur dans la liste
    }

    void my_Window::delWidget()
    {
        widgets.clear();    // nettoyage de la lsite
        win->clear();       //netoyage de la venetre
    }
}