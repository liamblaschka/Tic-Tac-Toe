#include "O.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

O::O(sf::Vector2i point, int move_created):Piece('O', point, move_created) {
    circle = sf::CircleShape(40.f);
    circle.setOrigin(40, 40);
    circle.setFillColor(sf::Color::Transparent);
    circle.setOutlineThickness(10);
    circle.setPosition(point.x, point.y);
}

void O::draw_piece(sf::RenderTarget& window, bool is_faded) {
    if (is_faded) {
        circle.setOutlineColor(sf::Color(55, 200, 55));
    } else {
        circle.setOutlineColor(sf::Color::Green);
    }
    window.draw(circle);
}