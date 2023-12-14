#include <iostream>
#include <SFML/Graphics.hpp>
#include "../include/matrix.hpp"
#include "../test/matrix_test.hpp"

#define MAX_X 1280.0f
#define MAX_Y 720.0f

using namespace sf;

int main() {
    matrixTest();
    int cuboid[]={-200, -100, 200, 200, 100, -300};
    RenderWindow window(VideoMode(MAX_X, MAX_Y), "3D Engine");

    //Créer le fond
    RectangleShape background(Vector2f(MAX_X, MAX_Y));
    background.setFillColor(Color(48, 48, 64));
    int f=0;
    while(window.isOpen()) {
        //std::cout << f << "\n";
        f++;

        Event event{};
        window.draw(background);
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        window.display();
    }

    return 0;
}
