#include <SFML/Graphics.hpp>

int main()
{
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My First SFML Game!");
    
    // Main game loop
    while (window.isOpen())
    {
        // Event handling
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        // Clear screen
        window.clear();
        
        // Draw everything here...
        
        // Display what we drew
        window.display();
    }
    
    return 0;
}