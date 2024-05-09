#include "window.hpp"

void Window::my_Window::my_widget::widget_settup()
{
    pos.x = 0;
    pos.y = 0;
    size.x = 0;
    size.y = 0;
}

void Window::my_Window::my_widget::set_font(std::string path)
{
    if (!font.loadFromFile(path)) {
        std::cerr << "Failed to load font file!" << std::endl;
        return;
    }
}

void Window::my_Window::my_widget::image(std::unique_ptr<sf::RenderWindow>& window, std::string filepath, int x, int y, int H, int L, std::string Gpos)
{
    sf::Texture texture;
    sf::Vector2f position;

    pos.x = x;
    pos.y = y;
    size.x = L;
    size.y = H;
    if (!texture.loadFromFile(filepath)) {
        return;
    }
    sf::Sprite sprite(texture);
    windowSize = window->getSize();
    sf::Vector2f imageSize(texture.getSize());

    if (Gpos == "NULL") {
        position = pos;
    }

    
    sprite.setPosition(position);
    window->draw(sprite);
}

void Window::my_Window::my_widget::text_input(std::unique_ptr<sf::RenderWindow>& window, int x, int y, int H, int L, std::string Gpos)
{
    sf::RectangleShape textBox(sf::Vector2f(L, H));
    textBox.setPosition(x, y);
    textBox.setFillColor(sf::Color(230, 230, 230, 255));
    textBox.setOutlineColor(sf::Color::Black);
    textBox.setOutlineThickness(1.0f);

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    text.setPosition(x + 5, y + 5);

    std::wstring inputText;
    int lines = 0; // Track the number of lines

    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            else if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode < 128 || (event.text.unicode >= 192 && event.text.unicode <= 255)) {
                    if (event.text.unicode == '\b') {
                        if (!inputText.empty()) {
                            inputText.pop_back();
                            if (inputText.back() == L'\n') // If the last character deleted was a newline, reduce the line count
                                lines--;
                        }
                    } else {
                        // Check if adding the new character exceeds the width
                        sf::Text tempText = text;
                        tempText.setString(inputText + static_cast<wchar_t>(event.text.unicode));
                        // Calculate the height of the text
                        float textHeight = tempText.getLocalBounds().top + tempText.getLocalBounds().height;
                        // Check if the new height would exceed the rectangle's height or if the number of lines exceeds the limit
                        if (textHeight > y + H - 10 || lines >= H / 24) { // Adjusted margin and considering line height of 24 pixels
                            // Do nothing if exceeding the height
                        } else {
                            // Check if adding the new character exceeds the width
                            if (tempText.getLocalBounds().width > L - 7) {
                                // Move to the next line
                                inputText += L'\n';
                                lines++;
                            }
                            inputText += static_cast<wchar_t>(event.text.unicode);
                            if (event.text.unicode == L'\n') // Increase line count for new lines
                                lines++;
                        }
                    }
                }
                text.setString(inputText);
            }
        }

        window->clear(sf::Color::White);
        window->draw(textBox);
        window->draw(text);
        window->display();
    }
}

