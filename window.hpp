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
                    class shapes
                    {
                        public:
                            class shape_data
                            {
                                public:
                                    int x;
                                    int y;
                                    int L;
                                    int H;
                                    std::string Gpos;
                                    sf::Color color;
                                    sf::Color out_color; 
                                    float out_thik;
                                    std::unique_ptr<sf::RenderWindow>& window;
                            };
                            void rectangle(shape_data *data);
                            void circle(shape_data *data);
                            void triangle(shape_data *data);
                            void triangle_rec1(shape_data *data);
                            void triangle_rec2(shape_data *data);
                    };
                    void widget_settup(void);
                    void set_font(std::string path);
                    void image(std::unique_ptr<sf::RenderWindow>& window, std::string filepath, int x, int y, int H, int L, std::string Gpos);
                    void text_input(std::unique_ptr<sf::RenderWindow>& window, int x, int y, int H, int L, std::string Gpos);
                private:
                    sf::Vector2f pos;
                    sf::Vector2f size;
                    std::string GeneralPos;
                    sf::Vector2u windowSize;
                    sf::Font font;
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
