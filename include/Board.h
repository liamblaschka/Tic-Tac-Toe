#ifndef BOARD_H
#define BOARD_H

#include "Piece.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

class Board : public sf::Drawable {
    private:
        Piece** board;
        char turn;
        char first_turn;
        char last_turn;
        int count;
        sf::FloatRect squares[3][3];
        int displayed_move;
        bool is_move_history_mode;
        sf::RectangleShape grid_lines[4];
    public:
        Board(sf::Font& font);
        void reset_board();
        sf::Vector2i square_to_centre_point(sf::Vector2i square);
        sf::Vector2i point_to_square(sf::Vector2i point);
        void make_move(sf::Vector2i point);
        void draw(sf::RenderTarget& window, sf::RenderStates states) const;

        char get_turn();
        void set_turn(char turn);
        char get_last_turn();
        void set_last_turn(char last_turn);
        sf::Vector2i check_outcome();
        int get_displayed_move();
        void set_displayed_move(int displayed_move);
        void change_displayed_move(int change);
        int get_count();
        bool get_is_move_history_mode();
        ~Board();
};

#endif