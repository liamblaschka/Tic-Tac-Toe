#ifndef X_H
#define X_H

#include "Piece.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

class X : public Piece {
    private:
        sf::RectangleShape cross[2];
    public:
        X(sf::Vector2i point, int move_created);
        void draw_piece(sf::RenderTarget& window, bool is_faded);
};

#endif