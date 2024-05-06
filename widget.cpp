#include "window.hpp"

void Window::my_Window::my_widget::widget_settup()
{
    pos.x = 0;
    pos.y = 0;
    size.x = 0;
    size.y = 0;
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

    sprite.setScale(size);
    sprite.setPosition(position);
    window->draw(sprite);
}
