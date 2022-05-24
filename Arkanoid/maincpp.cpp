#include <SFML/Graphics.hpp>

using namespace sf;

void main(void)
{

	// windowÃ¢ »ý¼º
	RenderWindow app(VideoMode(520, 450), "BrickBreak");
	app.setFramerateLimit(60);

	Texture t1, t2, t3, t4;
	t1.loadFromFile("images/block01.png");
	t2.loadFromFile("images/background.jpg");
	t3.loadFromFile("images/ball.png");
	t4.loadFromFile("images/paddle.png");


}
