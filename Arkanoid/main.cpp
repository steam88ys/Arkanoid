#include <SFML/Graphics.hpp>

using namespace sf;

void main(void)
{

	// windowâ ����
	RenderWindow app(VideoMode(520, 450), "BrickBreak");
	app.setFramerateLimit(60);

	Texture t1, t2, t3, t4;
	t1.loadFromFile("images/block01.png");
	t2.loadFromFile("images/background.jpg");
	t3.loadFromFile("images/ball.png");
	t4.loadFromFile("images/paddle.png");


	Sprite sBackground(t2), sBall(t3), sPaddle(t4);
	sPaddle.setPosition(300, 400);
	sBall.setPosition(300, 300);

	Sprite block[200];
	int n = 0;
	for (int x = 1; x <= 10; x++) 
	{
		for (int y = 0; y <= 10; y++)
		{
			block[n].setTexture(t1);
			block[n].setPosition(x * 43, y * 20);
			n++;
		}
	}
	float dx = 5.0f, dy = 6.0f;	// (�ӵ� ���� + ���� ����)

	while (app.isOpen())
	{
		Event e;
		while (app.pollEvent(e))
		{
			if (e.type == Event::Closed)
				app.close();
		}
		// �� �����̱�
		sBall.move(dx, 0);
		sBall.move(0, dy);

		// ���� ��ġ(��ǥ)
		Vector2f b = sBall.getPosition();

		// ȭ�� �ٱ��� �׵θ��� �浹�ϴ� ���
		if (b.x < 0 || b.x>520)
			dx = -dx;
		if (b.y < 0 || b.y>450)
			dy = -dy;

		app.clear();
		app.draw(sBackground);
		app.draw(sBall);
		app.draw(sPaddle);
		for (int i = 0; i < n; i++)
			app.draw(block[i]);

		app.display();
	}

}
