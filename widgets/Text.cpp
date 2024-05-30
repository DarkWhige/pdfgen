#include "Text.hpp"

namespace Window
{
    Text::Text() {}

    Text::~Text() {}

    void Text::SetText(const WidgetInfo& data, sf::RenderWindow* window)
    {
        this->pos = data.pos;
        this->size = data.size;
        this->font_path = data.path;
        this->font_type = data.font_type;
        this->content = data.content;
        this->color = data.color;
        this->font_shape = data.font_shape;
        this->font_size = data.font_size;

        SetFont(data, window);
        Loaded = true;
    }

    void Text::SetFont(const WidgetInfo& data, sf::RenderWindow* window)
    {
        font_path += get_font_type();
        font_path += get_font_shape();
        if (!font.loadFromFile(font_path)) {
            std::cerr << "Failed to load font file!" << std::endl;
            return;
        }
        text.setFont(font);
        text.setString(wrapText(content, size.x));
        text.setCharacterSize(font_size);
        text.setFillColor(color);
        text.setPosition(pos.x + 5, pos.y + 5);

        while (text.getGlobalBounds().width > size.x || text.getGlobalBounds().height > size.y) {
            font_size--;
            text.setCharacterSize(font_size);
        }
    }

    std::string Text::get_font_type() const
    {
        if (font_type == "ARIAL") {
            return "arial/";
        }
        std::cerr << "the font doesn't exist\n";
        return "";
    }

    std::string Text::get_font_shape() const
    {
        if (font_shape == "NORMAL") {
            return "Arial.ttf";
        }
        std::cerr << "the shape doesn't exist\n";
        return "";
    }

    void Text::draw(sf::RenderWindow& window)
    {
        if (Loaded) {
            window.draw(text);
        }
    }

    void Text::update()
    {

    }

    std::string Text::wrapText(const std::string& str, float maxWidth)
    {
        std::string wrapped;
        std::string line;
        std::istringstream words(str);
        std::string word;

        while (words >> word) {
            sf::Text tempText(line + " " + word, font, font_size);
            if (tempText.getGlobalBounds().width > maxWidth) {
                wrapped += line + "\n";
                line = word;
            } else {
                if (!line.empty()) line += " ";
                line += word;
            }
        }
        wrapped += line;
        return wrapped;
    }
}
