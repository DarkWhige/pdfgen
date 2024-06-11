#include "widget.hpp"
#include <iostream>

namespace Window
{
    my_widget::~my_widget() {}  // destructeur

    my_widget::my_widget() {}   // constructeur
    
    void my_widget::set_widget(const WidgetInfo& data, sf::RenderWindow* window)
    {
        this->data = data;  // stockage de la liste de donnée "data" dans la classe
        if (data.type == "PICTURE") {   // si le widget est une image,
            image.SetImage(data, window);   // appel de la fonction pour setup l'image
        } else if (data.type == "TEXT") {   // si le widget est un texte
            text.SetText(data, window);     // appel de la fonction pour setup le texte
        } else if (data.type == "TEXT_EDITOR_B") {  // si le widget est un editeur de texte basique
            text_editor_b.SetTextBE(data, window);  // appel de la fonction pour setup l'editeur de texte basique
        } else if (data.type == "GIF") {
            gif.SetGif(data, window);
        }
    }

    WidgetInfo my_widget::get_data(void) const
    {
        return this->data;      // renvoi les infos demandés
    }

    Image my_widget::get_image(void) const
    {
        return this->image;     // renvoi les infos demandés
    }

    Text my_widget::get_text(void) const
    {
        return this->text;      // renvoi les infos demandés
    }

    TextBE my_widget::get_text_editor_b(void) const
    {
        return this->text_editor_b;     // renvoi les infos demandés
    }

    void my_widget::set_pos(const sf::Vector2f& new_pos)
    {
        data.pos = new_pos;                         // set des positions du widget
        image.sprite.setPosition(data.pos);         // set des positions du widget
        text.text.setPosition(data.pos);            // set des positions du widget 
        text_editor_b.text.setPosition(data.pos);   // set des positions du widget
        gif.sprite.setPosition(data.pos);           // set des positions du widget
    }

    void my_widget::draw(sf::RenderWindow& window)
    {
        image.draw(window);         // draw de l'image
        text.draw(window);          // draw du texte
        text_editor_b.draw(window); //draw de l'editeur de texte basique
        gif.draw(window);           // draw du gif
    }

    void my_widget::update()
    {
        image.sprite.setPosition(data.pos);         // mise a jour de l'image
        text.text.setPosition(data.pos);            // mise a jour du texte
        text_editor_b.text.setPosition(data.pos);   // mise a jour de l'editeur de texte basique
        gif.sprite.setPosition(data.pos);           // mise a jour du gif
    }
}
