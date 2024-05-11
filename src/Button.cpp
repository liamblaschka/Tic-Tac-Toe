#include "Button.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>

#include <iostream>

Button::Button(sf::Font& font, std::string text_string) {
    this->text_string = text_string;
    this->position = sf::Vector2f(0, 0);
    this->font = font;
    text.setFillColor(sf::Color::White);
    text.setFont(font);
    text.setString(text_string);
    text.setScale(0.7, 0.7);
    sf::FloatRect text_bounds = text.getGlobalBounds();
    text_size = text_bounds.getSize();
    border = sf::RectangleShape(sf::Vector2f(text_size.x + 8, 30));
    border.setOutlineColor(sf::Color(80, 175, 228));
    border.setOutlineThickness(3);
    border.setFillColor(sf::Color::Black);
}

Button::Button() {}

sf::Vector2f Button::get_position() {
    return position;
}

void Button::draw_button(sf::RenderWindow& window) {
    window.draw(border);
    window.draw(text);
}


bool Button::is_clicked(sf::Vector2i mouse_position) {
    return hitbox.contains(sf::Vector2f(mouse_position.x, mouse_position.y));
}

void Button::set_position(sf::Vector2f position) {
    this->position = position;

    text.setPosition(position);

    sf::Vector2f rectangle_position = sf::Vector2f(position.x - 3.2, position.y - 1);
    border.setPosition(rectangle_position);

    hitbox = sf::FloatRect(rectangle_position.x, rectangle_position.y, text_size.x + 8, 30);
}
