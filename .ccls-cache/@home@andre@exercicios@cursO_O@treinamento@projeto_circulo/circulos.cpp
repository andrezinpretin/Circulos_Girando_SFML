#include <stdio.h>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp> 
#include <math.h>
float girar(int raio,float r);
int main(){
	
	int v=0;	
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode().width,sf::VideoMode::getDesktopMode().height),"Circulos girando",sf::Style::Default,settings);
	std::vector<sf::CircleShape> circulos_negativo;
	window.setFramerateLimit(30);
	for(int i=0;i<5;i++){
		sf::CircleShape ronaldos(15.f);
		ronaldos.setFillColor(sf::Color(255-20*i,255-30*i,255-75*i));	
		circulos_negativo.push_back(ronaldos);	
	}
	
	while(window.isOpen()){
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type==sf::Event::Closed){
				window.close();
			}
		}
	
		window.clear(sf::Color::Black);
		for(int k =0; k<5; k++){
		circulos_negativo[k].setPosition((cos(v+k*5)*60)+sf::Mouse::getPosition().x-circulos_negativo[k].getRadius(),(sin(v+k*5)*60)+sf::Mouse::getPosition().y-circulos_negativo[k].getRadius()*4);
		window.draw(circulos_negativo[k]);	
		}
		v--;
			if(v<-360){
				v=0;
			     	}
		window.display();
	}
	return 0;
	}
