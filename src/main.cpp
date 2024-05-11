#include "Board.h"
#include "Piece.h"
#include "Button.h"
#include "Scoreboard.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <string>

int main() {
    sf::RenderWindow window(sf::VideoMode(550, 550), "Tic Tac Toe", sf::Style::Titlebar | sf::Style::Close);
    // sf::View view(sf::Vector2f(137.5f, 137.5f), sf::Vector2f(225, 225));
    // window.setView(view);
    window.setVerticalSyncEnabled(true);

    sf::Font font;
    font.loadFromFile("../../assets/ARIAL.TTF");
    Board board = Board(font);

    Scoreboard scoreboard = Scoreboard(font);
    scoreboard.set_turn('X');

    sf::Vector2i outcome = sf::Vector2i(0, -1);
    sf::RectangleShape win_line;

    sf::Text outcome_message;
    outcome_message.setFillColor(sf::Color::White);
    outcome_message.setFont(font);
    outcome_message.setPosition(125, 506);
    outcome_message.setScale(0.9, 0.9);

    Button buttons[3];
    buttons[0] = Button(font, "Play again");
    buttons[1] = Button(font, "Exit");

    bool mouse_pressed = false;
    bool key_pressed = false;
    bool game_over = false;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (!board.get_is_move_history_mode() && outcome.x == 0) {
                            board.make_move(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
                            outcome = board.check_outcome();
                            if (outcome.x == 0) {
                                scoreboard.set_turn(board.get_turn());
                            }
                        } else if (outcome.x != 0) {
                            if (buttons[0].is_clicked(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))) { // play again
                                board.reset_board();
                                scoreboard.set_turn(board.get_turn());
                                outcome = sf::Vector2i(0, -1);
                                game_over = false;
                            } else if (buttons[1].is_clicked(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))) {
                                window.close();
                            }
                        }
                        break;
                    }
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Key::Left && board.get_displayed_move() > 0) {
                        board.change_displayed_move(-1);
                    } else if (event.key.code == sf::Keyboard::Key::Right && board.get_displayed_move() < board.get_count()) {
                        board.change_displayed_move(1);
                    } else if (event.key.code == sf::Keyboard::Key::Up && board.get_displayed_move() > 0) {
                        board.set_displayed_move(0);
                    } else if (event.key.code == sf::Keyboard::Key::Down && board.get_displayed_move() < board.get_count()) {
                        board.set_displayed_move(board.get_count());
                    }
                    break;
                default:
                    break;
            }
        }

        window.clear();
        
        window.draw(board);
        window.draw(scoreboard);

        if (!game_over && outcome.x != 0) {
            if (outcome.x != 3) {
                float rotation;
                int length;
                sf::Vector2f win_line_position;
                switch (outcome.y) {
                    case 0: // rows
                        win_line_position = sf::Vector2f(275, 125);
                        rotation = 0;
                        length = 420;
                        break;
                    case 1:
                        win_line_position = sf::Vector2f(275, 275);
                        rotation = 0;
                        length = 420;
                        break;
                    case 2:
                        win_line_position = sf::Vector2f(275, 425);
                        rotation = 0;
                        length = 420;
                        break;
                    case 3: // columns
                        win_line_position = sf::Vector2f(125, 275);
                        rotation = 90;
                        length = 420;
                        break;
                    case 4:
                        win_line_position = sf::Vector2f(275, 275);
                        rotation = 90;
                        length = 420;
                        break;
                    case 5:
                        win_line_position = sf::Vector2f(425, 275);
                        rotation = 90;
                        length = 420;
                        break;
                    case 6: // diagonals
                        win_line_position = sf::Vector2f(275, 275);
                        rotation = 45;
                        length = 590;
                        break;
                    case 7:
                        win_line_position = sf::Vector2f(275, 275);
                        rotation = 135;
                        length = 590;
                        break;
                }
                win_line = sf::RectangleShape(sf::Vector2f(length, 6));
                win_line.setOrigin(length / 2.0, 3);
                win_line.setRotation(rotation);
                win_line.setPosition(win_line_position);
                outcome_message.setString(std::string(1, board.get_last_turn()) + " wins");
            } else if (outcome.x == 3) {
                outcome_message.setString("Draw");
            }
            scoreboard.update_scores(outcome.x);
            game_over = true;
        }
        
        if (game_over) {
            if (!board.get_is_move_history_mode() && outcome.x != 3) {
                window.draw(win_line); 
            }

            sf::FloatRect message_bounds = outcome_message.getGlobalBounds();
            sf::Vector2f message_size = message_bounds.getSize();
            sf::Vector2f message_position = message_bounds.getPosition();

            buttons[0].set_position(sf::Vector2f(message_size.x + message_position.x + 30, 508));
            buttons[1].set_position(sf::Vector2f(message_size.x + message_position.x + 170, 508));

            window.draw(outcome_message);

            for (int i = 0; i < 2; i++) {
                buttons[i].draw_button(window);
            }
        }
        window.display();
    }
    return 0;
}