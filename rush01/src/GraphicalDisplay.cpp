#include "GraphicalDisplay.hpp"

#include <SFML/Graphics.hpp>

//~--------------------------------------------------------~
// Constructors & Destructor

GraphicalDisplay::GraphicalDisplay(void)
{
}

GraphicalDisplay::~GraphicalDisplay(void)
{
}

#include <iostream>
#include <unistd.h>

void	GraphicalDisplay::display(std::vector<IMonitorModule*> const& m) const
{
	sf::RenderWindow window(sf::VideoMode(1024, 720), "ft_gkrellm");

	sf::Font font;

	if (!font.loadFromFile("arial.ttf"))
		std::cout << "error " << std::endl;

	sf::Text text("", font);

	text.setCharacterSize(10);
	text.setFillColor(sf::Color::White);

	while(window.isOpen())
	{
		window.clear();
    	sf::Event event;
    	while(window.pollEvent(event))
    	{
    	     if(event.type == sf::Event::Closed){window.close();}
    	}

		std::vector<IMonitorModule*> v = m;
		int pos = 0;

		for (size_t j = 0; j < v.size(); ++j)
		{
			text.setString(v[j]->getName());
			text.setPosition(0, pos);
			window.draw(text);
			pos += 12;

			std::vector<std::string> fieldNames = v[j]->getFieldNames();
			std::vector<std::string> fieldInfo = v[j]->getFieldInfo();

			for (size_t i = 0; i < fieldNames.size(); ++i)
			{
				std::string curr = fieldNames[i] + ": " + fieldInfo[i];

				text.setString(curr);
				text.setPosition(0, pos);
				window.draw(text);
				pos += 12;
			}
			pos += 12;
		}
	
    	window.display();
		usleep(50000);
	}
}
