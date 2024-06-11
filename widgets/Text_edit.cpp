#include "Text_edit.hpp"

namespace Window
{
    TextBE::TextBE() {}

    TextBE::~TextBE() {}

    void TextBE::SetTextBE(const WidgetInfo& data, sf::RenderWindow* window)
    {
        this->pos = data.pos;
        this->size = data.size;
        this->font_path = data.path;
        this->font_type = data.font_type;
        this->color = data.color;
        this->back_color = data.back_color;
        this->font_shape = data.font_shape;
        this->font_size = data.font_size;
        this->outline_color = data.outline_color;
        this->outline_thickness = data.outline_thickness;

        SetFont(data, window);
        SetBack(data, window);
        Loaded = true;
    }

    void TextBE::SetFont(const WidgetInfo& data, sf::RenderWindow* window)
    {
        font_path += get_font_type();
        font_path += get_font_shape();
        if (!font.loadFromFile(font_path)) {
            std::cerr << "Failed to load font file!" << std::endl;
            return;
        }
        text.setFont(font);
        text.setCharacterSize(font_size);
        text.setFillColor(color);
        text.setPosition(pos.x + 5, pos.y + 5);
    }

    void TextBE::SetBack(const WidgetInfo& data, sf::RenderWindow* window)
    {
        back.setPosition(pos);
        back.setSize(size);
        back.setFillColor(back_color);
        back.setOutlineColor(outline_color);
        back.setOutlineThickness(outline_thickness);
    }

    std::string TextBE::get_font_type() const
    {
        if (font_type == "ARIAL") {
            return "arial/";
        // } else if (font_type == "")
        }
        std::cerr << "the font doesn't exist\n";
        return "";
    }

    std::string TextBE::get_font_shape() const
    {
        if (font_shape == "NORMAL") {
            return "Arial.ttf";
        }
        std::cerr << "the shape doesn't exist\n";
        return "";
    }

    // void TextBE::AddTextEditor(void)
    // {

        // std::wstring inputText;
        // int lines = 0;

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
        // }
    // }

    void TextBE::draw(sf::RenderWindow& window)
    {
        if (Loaded) {
            window.draw(back);
            window.draw(text);
        }
    }

    void TextBE::update()
    {

    }
}
