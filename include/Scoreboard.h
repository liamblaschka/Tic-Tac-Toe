#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <SFML/Graphics.hpp>

class Scoreboard : public sf::Drawable {
    private:
        int x_win_count;
        int o_win_count;
        int draw_count;
        sf::Font font;
        sf::Text x_label;
        sf::Text o_label;
        sf::Text scores;

    public:
        Scoreboard();
        Scoreboard(sf::Font& font);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void update_scores(int outcome);
        void set_turn(char turn);
        void reset_scores();
};

#endif