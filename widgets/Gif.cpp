#include "Gif.hpp"

using namespace Window;

Gif::Gif() {}

Gif::~Gif() {}

void Gif::SetGif(const WidgetInfo& data, sf::RenderWindow* window)
{
    this->pos = data.pos;
    this->size = data.size;
    this->path = data.path;

    // Clear previous textures if any
    textures.clear();

    // Assuming frames are named as frame_000_delay-0.03s.png, frame_001_delay-0.03s.png, ..., frame_nnn_delay-0.03s.png
    int frameIndex = 0;
    while (true) {
        sf::Texture texture;
        std::ostringstream framePath;
        framePath << path << "/frame_" << std::setw(3) << std::setfill('0') << frameIndex << "_delay-0.03s.png";
        
        // Utiliser std::ifstream pour vérifier si le fichier existe
        std::ifstream file(framePath.str());
        if (!file.good()) {
            break; // Stop when no more frames are found
        }
        
        if (!texture.loadFromFile(framePath.str())) {
            std::cerr << "Failed to load frame: " << framePath.str() << std::endl;
            break;
        }

        textures.push_back(texture);
        frameIndex++;
    }

    if (textures.empty()) {
        std::cerr << "Failed to load any Gif frames!" << std::endl;
        return;
    }

    sprite.setTexture(textures[0]);
    sprite.setPosition(pos);
    sf::Vector2f textureSize(textures[0].getSize());
    sprite.setScale(size.x / textureSize.x, size.y / textureSize.y);
    Loaded = true;
}

void Gif::draw(sf::RenderWindow& window)
{
    if (Loaded) {
        // Mettre à jour l'animation à chaque appel à draw
        if (frameClock.getElapsedTime() > sf::milliseconds(10)) { // Changer 10 à la valeur désirée
            currentFrame = (currentFrame + 1) % textures.size();
            sprite.setTexture(textures[currentFrame]);
            frameClock.restart();
        }
        
        window.draw(sprite);
    }
}



void Gif::update()
{
    if (Loaded && frameClock.getElapsedTime() > frameDuration) {
        currentFrame = (currentFrame + 1) % textures.size();
        sprite.setTexture(textures[currentFrame]);
        frameClock.restart();
    }
}
