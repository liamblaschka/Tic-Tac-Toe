#include "Piece.h"
#include "X.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

X::X(sf::Vector2i point, int move_created):Piece('X', point, move_created) {
    cross[0] = sf::RectangleShape(sf::Vector2f(10, 125));
    cross[0].setOrigin(10 / 2, 125 / 2.0);
    cross[0].rotate(45);

    cross[1] = sf::RectangleShape(sf::Vector2f(10, 125));
    cross[1].setOrigin(10 / 2, 125 / 2.0);
    cross[1].rotate(135);

    cross[0].setPosition(point.x, point.y);
    cross[1].setPosition(point.x, point.y);
}

void X::draw_piece(sf::RenderTarget& window, bool is_faded) {
    if (is_faded) {
        cross[0].setFillColor(sf::Color(200, 55, 55));
        cross[1].setFillColor(sf::Color(200, 55, 55));
    } else {
        cross[0].setFillColor(sf::Color::Red);
        cross[1].setFillColor(sf::Color::Red);
    }
    window.draw(cross[0]);
    window.draw(cross[1]);
}
