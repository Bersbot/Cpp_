#include <SFML/Graphics.hpp>

using namespace sf;
RenderWindow window(VideoMode(640,480), "/-(.)_(.)-\\");



int main(){
    RectangleShape rect(Vector2f(512, 128 / 4));
    rect.setOrigin(rect.getSize().x / 2 , rect.getSize().y / 2);
    rect.setFillColor(Color(100, 0, 0, 255));
    rect.setPosition(window.getSize().x / 2, window.getSize().y / 1.25);

    Texture pl_t;
    pl_t.loadFromFile("/./img/pl.png");

    Sprite pl;
    pl.setTexture(pl_t);
    //pl.setOrigin(pl_t.getSize().x / 2, pl_t.getSize().y / 2);

    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type == Event::Closed){
                // Close window button clicked.
                window.close();
            }
        }  
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {window.close(); }
        window.clear(Color(40, 60, 90, 1));
        window.draw(rect);
        window.draw(pl);
        window.display();
    }
    return 0;
}
