#ifndef PIECE_H
#define PIECE_H

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

class Piece {
    protected:
        char type;
        sf::Vector2i point;
        int move_created;
    public:
        Piece();
        Piece(char type, sf::Vector2i point, int move_created);
        char get_type();
        int get_move_created();
        sf::Vector2i get_point();
        void set_point(sf::Vector2i point);
        virtual void draw_piece(sf::RenderTarget& window, bool is_faded);
};

#endif