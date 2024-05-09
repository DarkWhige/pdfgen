#include "window.hpp"

void Window::my_Window::my_widget::shapes::rectangle(shape_data *data)
{
    sf::RectangleShape rect(sf::Vector2f(data->L, data->H));
    
    rect.setPosition(data->x, data->y);
    rect.setFillColor(data->color);
    rect.setOutlineColor(data->out_color);
    rect.setOutlineThickness(data->out_thik);

    data->window->clear(sf::Color::White);
    data->window->draw(rect);
    data->window->display();
}

void Window::my_Window::my_widget::shapes::circle(shape_data *data)
{
    sf::CircleShape circle(data->L / 2.0f);
    
    circle.setPosition(data->x, data->y);
    circle.setFillColor(data->color);
    circle.setOutlineColor(data->out_color);
    circle.setOutlineThickness(data->out_thik);

    data->window->clear(sf::Color::White);
    data->window->draw(circle);
    data->window->display();
}

void Window::my_Window::my_widget::shapes::triangle(shape_data *data)
{
    sf::ConvexShape triangle(3);
    triangle.setPoint(0, sf::Vector2f(data->x + data->L / 2, data->y)); // Sommet supérieur
    triangle.setPoint(1, sf::Vector2f(data->x, data->y + data->H)); // Coin inférieur gauche
    triangle.setPoint(2, sf::Vector2f(data->x + data->L, data->y + data->H)); // Coin inférieur droit
    
    triangle.setFillColor(data->color);
    triangle.setOutlineColor(data->out_color);
    triangle.setOutlineThickness(data->out_thik);

    data->window->clear(sf::Color::White);
    data->window->draw(triangle);
    data->window->display();
}

void Window::my_Window::my_widget::shapes::triangle_rec1(shape_data *data)
{
    sf::ConvexShape triangle(3);
    triangle.setPoint(0, sf::Vector2f(data->x + data->L, data->y)); // Sommet supérieur
    triangle.setPoint(1, sf::Vector2f(data->x, data->y + data->H)); // Coin inférieur gauche
    triangle.setPoint(2, sf::Vector2f(data->x + data->L, data->y + data->H)); // Coin inférieur droit
    
    triangle.setFillColor(data->color);
    triangle.setOutlineColor(data->out_color);
    triangle.setOutlineThickness(data->out_thik);

    data->window->clear(sf::Color::White);
    data->window->draw(triangle);
    data->window->display();
}

void Window::my_Window::my_widget::shapes::triangle_rec2(shape_data *data)
{
    sf::ConvexShape triangle(3);
    triangle.setPoint(0, sf::Vector2f(data->x, data->y)); // Sommet supérieur
    triangle.setPoint(1, sf::Vector2f(data->x, data->y + data->H)); // Coin inférieur gauche
    triangle.setPoint(2, sf::Vector2f(data->x + data->L, data->y + data->H)); // Coin inférieur droit
    
    triangle.setFillColor(data->color);
    triangle.setOutlineColor(data->out_color);
    triangle.setOutlineThickness(data->out_thik);

    data->window->clear(sf::Color::White);
    data->window->draw(triangle);
    data->window->display();
}
