#include <SFML/Graphics.hpp>
#include"level1.h"
#include "menu.h"
#include "menuplay.h"
#include"level2.h"
using namespace sf;
using namespace std;

int main()
{ 

	RenderWindow window(VideoMode(500, 500), "puzzel");
	Texture texture;
	texture.loadFromFile("back.png");
	Sprite sprite;
	sprite.setTexture(texture);
	menu menu((float)window.getSize().x, (float)window.getSize().y);
	menuplay menuplay((float)window.getSize().x, (float)window.getSize().y);
	level1 level1((float)window.getSize().x, (float)window.getSize().y);
	level2 level2((float)window.getSize().x, (float)window.getSize().y);

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case  Event::Closed:
				window.close();
				break;
			case Event::KeyReleased:
				switch (event.key.code)
				{
				case Keyboard::Up:
					menu.moveup();
					break;
				case Keyboard::Down:
					menu.movedown();
					break;
				case Keyboard::Return:
						bool m = 0;
					switch (menu.selectnow())
					{ 

						// menu play ;
					
					case 0 :
						
						while (window.isOpen())
						{
							while (window.pollEvent(event))
							{
								switch (event.type)
								{
								case  Event::Closed:
									window.close();
									break;
								case Event::KeyReleased:
									switch (event.key.code)
									{
									case Keyboard::Up:
										menuplay.moveup();
										break;
									case Keyboard::Down:
										menuplay.movedown();
										break;
									case Keyboard::Return :
										bool back = 0;
										switch (menuplay.selectnow())
										{
										case 0:
											while (window.isOpen())
											{
												while (window.pollEvent(event))
												{
													switch (event.type)
													{
													case Event::Closed:
														window.close();
														break;
													case Event::MouseButtonPressed:
														switch (event.key.code)
														{
														case Mouse::Left:
															level1.mousebutton(window);
															break;
														case Mouse::Right :
															back = 1;
															break;
														}

														break;
													}
												}
												if (back == 1)
													break;
												window.clear();
												level1.draw(window);
												window.display();

											}
											break;
										case 1 :
											while (window.isOpen( ) )
											{

												while (window.pollEvent(event))
												{
													switch (event.type)
													{
													case Event::Closed:
														window.close();
														break;
													case Event::MouseButtonPressed:
														switch (event.key.code)
														{
														case Mouse::Left:
															level2.mousebutton(window);
															break;
														case Mouse::Right:
															back = 1;
															break;
														}

														break;
													}
												}
												if (back == 1)
													break;
												window.clear();
												level2.draw(window);
												window.display();
											}
											break;
										case 4 : 
											m = 1 ;
										}
									}
								}
							}
							if (m == 1)
								break;

							window.clear();

							menuplay.draw(window);
							window.display();
						
						}
						break;

					case 2:
						window.close();
						break;
					}
				}
			}
		}
		window.clear()     ;
		window.draw(sprite);
		menu.draw(window)  ;
		window.display()   ;

	}

	return 0;

}