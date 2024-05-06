#pragma once

#include <SFML/Graphics.hpp>
#include "string"
#include "iostream"

namespace Window
{
    class my_Window
    {
        public:
            class my_widget
            {
                public:
                    void widget_settup(void);
                    void image(std::unique_ptr<sf::RenderWindow>& window, std::string filepath, int x, int y, int H, int L, std::string Gpos);
                private:
                    sf::Vector2f pos;
                    sf::Vector2f size;
                    std::string GeneralPos;
                    sf::Vector2u windowSize;
            };
            void window(int h, int l, std::string title);
            void loop(void);
            void event_hendler(void);
            void setup(void);
            std::unique_ptr<sf::RenderWindow> getwindow(void);
        private:
            std::unique_ptr<sf::RenderWindow> win;
            sf::Event event;
            int colorModeCounter = 0;
    };
}
