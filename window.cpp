#include "window.hpp"
#include <iostream>

namespace Window
{
    my_Window::~my_Window()
    {
        widgets.clear();    // suppression de la liste de widget
        win.reset();    // suppréssion de la window
    }

    void my_Window::set_window_data(Window_info data)
    {
        this->height = data.height;
        this->lenght = data.lenght;
        this->title = data.title;
        this->FPS = data.FPS;
        this->bg_color = data.bg_color;
    }

    void my_Window::window()
    {
        win = std::make_unique<sf::RenderWindow>(sf::VideoMode(this->lenght, this->height), this->title);   // création de la fenètre avec les dimension et le titre demandé
        win->clear(this->bg_color);   // setup le fond de la fenètre en blanc
        win->setFramerateLimit(this->FPS);     // setup la limite d'image par seconde de la fenètre au montant demandé
        win->display();
    }

    void my_Window::loop()
    {
        while (win->isOpen()) { // tant que la window est ouverte
            event_handler();    // fonction de gestion des évenements
            win->clear(this->bg_color);  // actualisation du background
            for (size_t i = 0; i < widgets.size(); ++i) {   // iteration dans la liste des widgets
                widgets[i]->draw(*win); // affichage des widgets
            }
            win->display(); // affichage de l'enssemble de la window
        }
    }

    // --------------------------------------------- getters -------------------------------------------------------------- //

    sf::RenderWindow* my_Window::get_win() const
    {
        return win.get();   // recupération de la window
    }

    int my_Window::get_win_height() const
    {
        return this->height;   // recupération de la hauteur de la window
    }

    int my_Window::get_win_lenght() const
    {
        return this->lenght;   // recupération de la largeur de la window
    }

    int my_Window::get_win_FPS() const
    {
        return this->FPS;   // recupération des fps de la window
    }

    std::string my_Window::get_win_title() const
    {
        return this->title;   // recupération du titre de la window
    }

    sf::Color my_Window::get_win_bg_color() const
    {
        return this->bg_color;   // recupération de la couleur de la window
    }
    // --------------------------------------------- widgets -------------------------------------------------------------- //

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