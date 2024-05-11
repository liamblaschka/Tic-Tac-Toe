#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>

class Button {
    private:
        sf::Vector2f position;
        sf::Font font;
        sf::Text text;
        std::string text_string;
        sf::RectangleShape border;
        sf::FloatRect hitbox;
        sf::Vector2f text_size;

    public:
        Button();
        Button(sf::Font& font, std::string text_string);
        void set_position(sf::Vector2f position);
        sf::Vector2f get_position();

        void draw_button(sf::RenderWindow& window);

        bool is_clicked(sf::Vector2i mouse_position);
        
};

#endif