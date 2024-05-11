#include "Scoreboard.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>

#include <cmath>

#include <iostream>

Scoreboard::Scoreboard() {}

Scoreboard::Scoreboard(sf::Font& font) {
    this->font = font;

    x_win_count = 0;
    o_win_count = 0;
    draw_count = 0;

    scores.setFont(font);
    scores.setFillColor(sf::Color::White);
    scores.setString("0 : 0 : 0");
    scores.setScale(0.8, 0.8);
    sf::FloatRect scores_local_bounds = scores.getLocalBounds();
    sf::FloatRect scores_global_bounds = scores.getGlobalBounds();
    sf::Vector2f scores_global_size = scores_global_bounds.getSize();
    sf::Vector2f scores_local_size = scores_local_bounds.getSize();
    scores.setPosition(sf::Vector2f(225 + (scores_local_size.x - scores_global_size.x) / 2, 15));
    
    x_label.setFont(font);
    x_label.setString("X");
    x_label.setScale(0.8, 0.8);
    x_label.setFillColor(sf::Color::Red);
    x_label.setStyle(sf::Text::Bold);
    x_label.setPosition(sf::Vector2f(200, 15));

    o_label.setFont(font);
    o_label.setString("O");
    o_label.setScale(0.8, 0.8);
    o_label.setFillColor(sf::Color::Green);
    o_label.setStyle(sf::Text::Bold);
    o_label.setPosition(sf::Vector2f(332, 15));

}

void Scoreboard::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(scores);
    target.draw(x_label);
    target.draw(o_label);
}

void Scoreboard::update_scores(int outcome) {
    switch (outcome) {
        case 1:
            x_win_count++;
            break;
        case 2:
            o_win_count++;
            break;
        case 3:
            draw_count++;
            break;
    }

    scores.setString(std::to_string(x_win_count) + " : " + std::to_string(draw_count) + " : " + std::to_string(o_win_count));
}

void Scoreboard::set_turn(char turn) {
    if (turn == 'X') {
        x_label.setStyle(sf::Text::Bold | sf::Text::Underlined);
        o_label.setStyle(sf::Text::Bold);
    } else {
        o_label.setStyle(sf::Text::Bold | sf::Text::Underlined);
        x_label.setStyle(sf::Text::Bold);
    }
}

void Scoreboard::reset_scores() {
    x_win_count = 0;
    o_win_count = 0;
    draw_count = 0;

    scores.setString("0 : 0 : 0");
}