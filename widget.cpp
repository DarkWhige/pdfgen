#include "widget.hpp"
#include <iostream>

namespace Window
{
    my_widget::my_widget() {}

    void my_widget::set_widget(const WidgetInfo& data, sf::RenderWindow* window)
    {
        if (data.type == "PICTURE") {
            image.SetImage(data, window);
        } else if (data.type == "TEXT") {
            text.SetText(data, window);
        }
    }

    void my_widget::AddTextEditor(void)
    {
        // Exemple d'implémentation pour un éditeur de texte
        // sf::RectangleShape textBox(sf::Vector2f(data->L, data->H));   // mettre une image de rectangle arrondi à la place
        // textBox.setPosition(data->x, data->y);
        // textBox.setFillColor(sf::Color(230, 230, 230, 255));
        // textBox.setOutlineColor(sf::Color::Black);
        // textBox.setOutlineThickness(1.0f);

        // sf::Text text;
        // std::wstring inputText;
        // int lines = 0;

        // text = set_font(data);
        // while (data->window->isOpen()) {
        //     sf::Event event;
        //     while (data->window->pollEvent(event)) {
        //         if (event.type == sf::Event::Closed)
        //             data->window->close();
        //         else if (event.type == sf::Event::TextEntered) {
        //             if (event.text.unicode < 128 || (event.text.unicode >= 192 && event.text.unicode <= 255)) {
        //                 if (event.text.unicode == '\b') {
        //                     if (!inputText.empty()) {
        //                         inputText.pop_back();
        //                         if (inputText.back() == L'\n') // If the last character deleted was a newline, reduce the line count
        //                             lines--;
        //                     }
        //                 } else {
        //                     // Check if adding the new character exceeds the width
        //                     sf::Text tempText = text;
        //                     tempText.setString(inputText + static_cast<wchar_t>(event.text.unicode));
        //                     // Calculate the height of the text
        //                     float textHeight = tempText.getLocalBounds().top + tempText.getLocalBounds().height;
        //                     // Check if the new height would exceed the rectangle's height or if the number of lines exceeds the limit
        //                     if (textHeight > data->y + data->H - 10 || lines >= data->H / 24) { // Adjusted margin and considering line height of 24 pixels
        //                         // Do nothing if exceeding the height
        //                     } else {
        //                         // Check if adding the new character exceeds the width
        //                         if (tempText.getLocalBounds().width > data->L - 7) {
        //                             // Move to the next line
        //                             inputText += L'\n';
        //                             lines++;
        //                         }
        //                         inputText += static_cast<wchar_t>(event.text.unicode);
        //                         if (event.text.unicode == L'\n') // Increase line count for new lines
        //                             lines++;
        //                     }
        //                 }
        //             }
        //             text.setString(inputText);
        //         }
        //     }

        //     data->window->clear(sf::Color::White);
        //     data->window->draw(textBox);
        //     data->window->draw(text);
        //     data->window->display();
        // }
    }

    void my_widget::draw(sf::RenderWindow& window)
    {
        if (image.Loaded) {
            window.draw(image.sprite);
        }
        if (text.Loaded) {
            window.draw(text.text);
        }
    }

    void my_widget::update()
    {
        // Implémenter ici les logiques de mise à jour si nécessaire
    }
}