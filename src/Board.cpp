#include "Board.h"
#include "Piece.h"
#include "X.h"
#include "O.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

Board::Board(sf::Font& font) {
    board = new Piece*[3 * 3];

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            board[row * 3 + col] = new Piece();
        }
    }

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            squares[row][col] = sf::FloatRect(51.5 + 150 * col, 51.5 + 150 * row, 147, 147);
        }
    }

    //vertical
    grid_lines[0] = sf::RectangleShape(sf::Vector2f(3, 450));
    grid_lines[0].setOrigin(1.5, 225);
    grid_lines[0].setPosition(200, 275);
    grid_lines[1] = sf::RectangleShape(sf::Vector2f(3, 450));
    grid_lines[1].setOrigin(1.5, 225);
    grid_lines[1].setPosition(350, 275);
    //horizontal
    grid_lines[2] = sf::RectangleShape(sf::Vector2f(450, 3));
    grid_lines[2].setOrigin(225, 1.5);
    grid_lines[2].setPosition(275, 200);
    grid_lines[3] = sf::RectangleShape(sf::Vector2f(450, 3));
    grid_lines[3].setOrigin(225, 1.5);
    grid_lines[3].setPosition(275, 350);

    first_turn = 'X';
    turn = 'X';
    last_turn = ' ';
    count = 0;
    displayed_move = 0;
    is_move_history_mode = false;
}

void Board::reset_board() {
    if (first_turn == 'X') {
        first_turn = 'O';
    } else {
        first_turn = 'X';
    }
    turn = first_turn;
    last_turn = ' ';

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            delete board[row * 3 + col];
            board[row * 3 + col] = new Piece();
        }
    }
    displayed_move = 0;
    is_move_history_mode = false;
    count = 0;
}

sf::Vector2i Board::square_to_centre_point(sf::Vector2i square) {
    sf::Vector2i point;
    if (square.x == 0) {
        point.x = 125;
    } else if (square.x == 1) {
        point.x = 275;
    } else if (square.x == 2) {
        point.x = 425;
    }
    
    if (square.y == 0) {
        point.y = 125;
    } else if (square.y == 1) {
        point.y = 275;
    } else if (square.y == 2) {
        point.y = 425;
    }

    return point;
}

sf::Vector2i Board::point_to_square(sf::Vector2i point) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (squares[row][col].contains(sf::Vector2f(point.x, point.y))) {
                return sf::Vector2i(col, row);
            }
        }
    }
    // not in any square
    return sf::Vector2i(-1, -1);
}

void Board::make_move(sf::Vector2i point) {
    sf::Vector2i square = point_to_square(point);

    if (square.x >= 0 && square.y >= 0 && board[square.y * 3 + square.x]->get_type() == ' ') {
        sf::Vector2i point = square_to_centre_point(square);

        last_turn = turn;
        switch (turn) {
            case 'X':
                board[square.y * 3 + square.x] = new X(point, count + 1);
                turn = 'O';
                break;
            default: // case 'O'
                board[square.y * 3 + square.x] = new O(point, count + 1);
                turn = 'X';
        }

        displayed_move++;
        count++;

        sf::Vector2i outcome = check_outcome();
    }
}

void Board::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board[row * 3 + col]->get_move_created() <= displayed_move) {
                board[row * 3 + col]->draw_piece(window, is_move_history_mode);
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        window.draw(grid_lines[i]);
    }
}

char Board::get_turn() {
    return turn;
}

void Board::set_turn(char turn) {
    this->turn = turn;
}

char Board::get_last_turn() {
    return last_turn;
}

void Board::set_last_turn(char last_turn) {
    this->last_turn = last_turn;
}

sf::Vector2i Board::check_outcome() {
    // returns 0 for no outcome, 1 for P1 win, 2 for P2 win, 3 for draw
    // returns win position (0, 1, 2) rows, (3, 4, 5) cols, (6, 7) diags, (-1) draw/no outcome

    int player;
    if (last_turn == 'X') {
        player = 1;
    } else if (last_turn == 'O') {
        player = 2;
    }

    // check rows
    for (int i = 0; i < 3; i++) {
        if (board[i * 3 + 0]->get_type() != ' ' && board[i * 3 + 0]->get_type() == board[i * 3 + 1]->get_type()
            && board[i * 3 + 1]->get_type() == board[i * 3 + 2]->get_type())
        {
            return sf::Vector2i(player, i);
        }
    }

    // check columns
    for (int i = 0; i < 3; i++) {
        if (board[0 * 3 + i]->get_type() != ' ' && board[0 * 3 + i]->get_type() == board[1 * 3 + i]->get_type()
            && board[1 * 3 + i]->get_type() == board[2 * 3 + i]->get_type())
        {
            return sf::Vector2i(player, i + 3);
        }
    }

    // check diagonals
    char centre = board[1 * 3 + 1]->get_type();
    if (centre != ' ') {
        if (board[0 * 3 + 0]->get_type() == centre && board[2 * 3 + 2]->get_type() == centre) {
            return sf::Vector2i(player, 6); // diagonal
        }
        if (board[0 * 3 + 2]->get_type() == centre && board[2 * 3 + 0]->get_type() == centre) {
            return sf::Vector2i(player, 7); // antidiagonal
        }
    }

    // check draw
    if (count == 9) {
        return sf::Vector2i(3, -1);
    }

    return sf::Vector2i(0, -1);
}

int Board::get_displayed_move() {
    return displayed_move;
}

void Board::set_displayed_move(int displayed_move) {
    this->displayed_move = displayed_move;

    sf::Color grid_colour;
    if (displayed_move == count) {
        is_move_history_mode = false;
        grid_colour = sf::Color::White;
    } else {
        is_move_history_mode = true;
        grid_colour = sf::Color(200, 200, 200);
    }

    for (int i = 0; i < 4; i++) {
        grid_lines[i].setFillColor(grid_colour);
    }
}

void Board::change_displayed_move(int change) {
    displayed_move += change;

    sf::Color grid_colour;
    if (displayed_move == count) {
        is_move_history_mode = false;
        grid_colour = sf::Color::White;
    } else {
        is_move_history_mode = true;
        grid_colour = sf::Color(200, 200, 200);
    }

    for (int i = 0; i < 4; i++) {
        grid_lines[i].setFillColor(grid_colour);
    }
}

int Board::get_count() {
    return count;
}

bool Board::get_is_move_history_mode() {
    return is_move_history_mode;
}

Board::~Board() {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            delete board[row * 3 + col];
        }
    }
    delete[] board;
}