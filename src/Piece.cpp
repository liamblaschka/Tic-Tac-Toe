#include "Piece.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

Piece::Piece(char type, sf::Vector2i point, int move_created) {
    this->type = type;
    this->point = point;
    this->move_created = move_created;
}

Piece::Piece():Piece(' ', sf::Vector2i(), 0) {}

char Piece::get_type() {
    return type;
}

sf::Vector2i Piece::get_point() {
    return point;
}

void Piece::set_point(sf::Vector2i point) {
    this->point = point;
}

int Piece::get_move_created() {
    return move_created;
}

void Piece::draw_piece(sf::RenderTarget& window, bool is_faded) {}
