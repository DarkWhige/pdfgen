#include "Image.hpp"

namespace Window
{
    Image::Image() {}

    Image::~Image() {}

    void Image::SetImage(const WidgetInfo& data, sf::RenderWindow* window)
    {
        this->pos = data.pos;
        this->size = data.size;
        this->path = data.path;

        if (!texture.loadFromFile(path)) {
            std::cerr << "Failed to load image file!" << std::endl;
            return;
        }
        sprite.setTexture(texture);
        sprite.setPosition(pos);
        sf::Vector2f textureSize(texture.getSize());
        sprite.setScale(size.x / textureSize.x, size.y / textureSize.y);
        Loaded = true;
    }

    void Image::draw(sf::RenderWindow& window)
    {
        if (Loaded) {
            window.draw(sprite);
        }
    }

    void Image::update()
    {

    }
}
