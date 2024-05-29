#include "widget.hpp"
#include <iostream>

namespace Window
{
    my_widget::my_widget() {}
    
    my_widget::~my_widget() {}

    void my_widget::set_widget(const WidgetInfo& data, sf::RenderWindow* window)
    {
        this->data = data;
        if (data.type == "PICTURE") {
            image.SetImage(data, window);
        } else if (data.type == "TEXT") {
            text.SetText(data, window);
        } else if (data.type == "TEXT_EDITOR_B") {
            text_editor_b.SetTextBE(data, window);
        }
    }

    WidgetInfo my_widget::getData(void)
    {
        return this->data;
    }

    void my_widget::draw(sf::RenderWindow& window)
    {
        image.draw(window);
        text.draw(window);
        text_editor_b.draw(window);
    }

    void my_widget::update()
    {
        // Implémenter ici les logiques de mise à jour si nécessaire
    }

}