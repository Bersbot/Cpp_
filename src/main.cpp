#include <SFML/All.hpp>

using namespace sf;
RenderWindow window(VideoMode(640,480), "\\/(O)_(O)\\/");
//float grav = 0.5f;
const float maxY = 50;
const Vector2f gravity(0.f, 5.f);
Vector2f velocity(2.f, 5.f);


int main(){
    RectangleShape rect(Vector2f(512, 128 / 4));
    rect.setOrigin(rect.getSize().x / 2 , rect.getSize().y / 2);
    rect.setFillColor(Color(100, 0, 0, 255));
    rect.setPosition(window.getSize().x / 2, window.getSize().y / 1.25);

    Texture pl_t;
    pl_t.loadFromFile("./src/img/pl.png");

    Sprite pl;
    pl.setTexture(pl_t);
    pl.setOrigin(pl_t.getSize().x / 2, pl_t.getSize().y / 2);
    pl.setPosition(window.getSize().x / 2, window.getSize().y / 2);

    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type == Event::Closed){
                // Close window button clicked.
                window.close();
            }
        }  
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {window.close(); }
        while (!pl.getGlobalBounds().intersects(rect.getGlobalBounds())){ 

            pl.move(velocity);
            if(velocity.y < maxY){
                velocity += gravity;
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Space)) {
            pl.move(0, -10);
            grav.y = 0.5;
        }
        window.clear(Color(40, 60, 90, 1));
        window.draw(rect);
        window.draw(pl);
        window.display();
    }
    return 0;
}
