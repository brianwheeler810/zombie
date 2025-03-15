#include <SFML/Graphics.hpp>
#include "Player.h"
#include "ZombieArena.h"

using namespace sf;

int main()
{
    enum class State {
        PAUSED, LEVELING_UP,
        GAME_OVER, PLAYING
    };

    State state = State::GAME_OVER;

    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
    RenderWindow window(VideoMode(resolution.x, resolution.y),"Zombie Arena", Style::Fullscreen);


    // Create a an SFML View for the main action
    View mainView(sf::FloatRect(0, 0,resolution.x, resolution.y));

    Clock clock;
    Time gameTimeTotal;

    Vector2f mouseWorldPosition;
    Vector2i mouseScreenPosition;

    Player player;
    IntRect arena;

    VertexArray background;
    Texture textureBackground;
    textureBackground.loadFromFile("graphics/background_sheet.png");

    while (window.isOpen())
    {
        ///////////
        // Input
        ///////////
        Event event;
        while (window.pollEvent(event))
        {
            // enter key
            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Return && state == State::PLAYING)
                {
                    state = State::PAUSED;
                }
                else if (event.key.code == Keyboard::Return && state == State::PAUSED)
                {
                    state = State::PLAYING;
                    // Reset the clock so there isn't a frame jump
                    clock.restart();
                }
                else if (event.key.code == Keyboard::Return && state == State::GAME_OVER)
                {
                    state = State::LEVELING_UP;
                }
                if (state == State::PLAYING)
                {
                }
            }
        }

        // escape key
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        // wasd keys
        if (state == State::PLAYING)
        {
            if (Keyboard::isKeyPressed(Keyboard::W))
            {
                player.moveUp();
            }
            else
            {
                player.stopUp();
            }
            if (Keyboard::isKeyPressed(Keyboard::S))
            {
                player.moveDown();
            }
            else
            {
                player.stopDown();
            }
            if (Keyboard::isKeyPressed(Keyboard::A))
            {
                player.moveLeft();
            }
            else
            {
                player.stopLeft();
            }
            if (Keyboard::isKeyPressed(Keyboard::D))
            {
                player.moveRight();
            }
            else
            {
                player.stopRight();
            }
        }

        // levelup keys 1-6
        if (state == State::LEVELING_UP)
        {
            switch (event.key.code) {
            case Keyboard::Num1:
                state = State::PLAYING;
                break;
            case Keyboard::Num2:
                state = State::PLAYING;
                break;
            case Keyboard::Num3:
                state = State::PLAYING;
                break;
            case Keyboard::Num4:
                state = State::PLAYING;
                break;
            case Keyboard::Num5:
                state = State::PLAYING;
                break;
            case Keyboard::Num6:
                state = State::PLAYING;
                break;
            }
        }

        ///////////
        // Update
        ///////////
        if (state == State::PLAYING)
        {
            arena.width = 500;
            arena.height = 500;
            arena.left = 0;
            arena.top = 0;
            int tileSize = createBackground(background, arena);
            player.spawn(arena, resolution, tileSize);

            // Reset clock so there isn't a frame jump
            clock.restart();
            Time dt = clock.restart();
            gameTimeTotal += dt;
            float dtAsSeconds = dt.asSeconds();

            mouseScreenPosition = Mouse::getPosition();
            mouseWorldPosition = window.mapPixelToCoords(Mouse::getPosition(), mainView);

            player.update(dtAsSeconds, Mouse::getPosition());
            Vector2f playerPosition(player.getCenter());
               
            mainView.setCenter(player.getCenter());
        }

        ///////////
        // Render
        ///////////
        if (state == State::PLAYING)
        {
            window.clear();
            window.setView(mainView);
            window.draw(background, &textureBackground);
            window.draw(player.getSprite());
        }
   
        if (state == State::LEVELING_UP)
        {
        }
   
        if (state == State::PAUSED)
        {
        }
    
        if (state == State::GAME_OVER)
        {
        }
    
        window.display();

    }

    return 0;

}
