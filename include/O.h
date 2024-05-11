#ifndef O_H
#define O_H

#include "Piece.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

class O : public Piece {
    private:
        sf::CircleShape circle;
    public:
        O(sf::Vector2i point, int move_created);
        void draw_piece(sf::RenderTarget& window, bool is_faded);
};

#endif