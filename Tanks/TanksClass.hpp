#include "map.hpp"

using namespace std;
using namespace sf;

class Player
{
public:
	float x, y, w, h, dx, dy, fx, fy;
	float speed = 0.0;
	int dir = 0, vie = 3, health = 100;
	bool life = true;
	String File;
	Image image;
	Texture texture;
	Sprite sprite;

	//Создание игрока, его местоположения
	Player(String F, float X, float Y, float W, float H, float dX, float dY)
	{
		File = F;
		w = W; h = H;
		x = X; y = Y;
		dx = dX; dy = dY;
		image.loadFromFile(File);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(x,y,w,h));
		sprite.setPosition(dx, dy);
	}

	//Управление игроком 1
	void control(float time)
	{
		if(life == true)
		{
			if(Keyboard::isKeyPressed(Keyboard::Left))
			{
				dir = 1; speed = 0.2;
				sprite.setTexture(texture);
				sprite.setTextureRect(IntRect(280, 70, -40, 40));
				vie = 1;
			}
			if(Keyboard::isKeyPressed(Keyboard::Right))
			{
				dir = 0; speed = 0.2;
				sprite.setTexture(texture);
				sprite.setTextureRect(IntRect(240, 70, 40, 40));
				vie = 2;
			}
			if(Keyboard::isKeyPressed(Keyboard::Up))
			{
				dir = 3; speed = 0.2;
				sprite.setTexture(texture);
				sprite.setTextureRect(IntRect(240, 20, 40, 40));
				vie = 3;
			}
			if(Keyboard::isKeyPressed(Keyboard::Down))
			{
				dir = 2; speed = 0.2;
				sprite.setTexture(texture);
				sprite.setTextureRect(IntRect(280, 60, -40, -40));
				vie = 4;
			}

		}
	}

	//Управление игроком 1
	void control2(float time)
	{
		if(life == true)
		{
			if(Keyboard::isKeyPressed(Keyboard::A))
			{
				dir = 1; speed = 0.2;
				sprite.setTexture(texture);
				sprite.setTextureRect(IntRect(280, 70, -40, 40));
				vie = 1;
			}
			if(Keyboard::isKeyPressed(Keyboard::D))
			{
				dir = 0; speed = 0.2;
				sprite.setTexture(texture);
				sprite.setTextureRect(IntRect(240, 70, 40, 40));
				vie = 2;
			}
			if(Keyboard::isKeyPressed(Keyboard::W))
			{
				dir = 3; speed = 0.2;
				sprite.setTexture(texture);
				sprite.setTextureRect(IntRect(240, 20, 40, 40));
				vie = 3;
			}
			if(Keyboard::isKeyPressed(Keyboard::S))
			{
				dir = 2; speed = 0.2;
				sprite.setTexture(texture);
				sprite.setTextureRect(IntRect(280, 60, -40, -40));
				vie = 4;
			}

		}
	}
	//Метод передвижения
	void update(float time)
	{
		switch(dir)
		{
			case 0:  fx = speed; fy = 0; break;
			case 1:  fx = -speed; fy = 0; break;
			case 2:  fx = 0; fy = speed; break;
			case 3:  fx = 0; fy = -speed; break;
		}
		dx += fx * time;
		dy += fy * time;

		speed = 0;
		sprite.setPosition(dx, dy);
		interactionWithMap();
	}
	//Метод проверки столкновения
	void interactionWithMap()
	{
		for(int i = dy / 32; i < (dy + h) / 32; i++)
		for(int j = dx / 32; j < (dx + w) / 32; j++)
		{
			if(TileMap[i][j] == '0')
			{
				if (fy > 0)//если мы шли вниз,
							dy = i * 32 - h;//то стопорим координату игрек персонажа. сначала получаем координату нашего квадратика на карте(стены) и затем вычитаем из высоты спрайта персонажа.
				if (fy < 0)
							dy = i * 32 + 32;//аналогично с ходьбой вверх. dy<0, значит мы идем вверх (вспоминаем координаты паинта)
				if (fx > 0)
							dx = j * 32 - w;//если идем вправо, то координата Х равна стена (символ 0) минус ширина персонажа
				if (fx < 0)
							dx = j * 32 + 32;//аналогично идем влево
			}
		}
	}

	
};

class Entity : public Player
{
public:
	Entity(String F, float X, float Y, float W, float H, float dX, float dY) : Player(F, X, Y, W, H, dX, dY)
	{

	}
	//Движение противника
	void Artificial_Intelligence(float time)
	{
		int randGus = 1 + rand() % 10;
			if (randGus == 1 || randGus == 5) 
			{ 
				dir = 1; speed = 0.2; vie = 1;
				sprite.setTextureRect(IntRect(230, 70, -40, 40));
			} 
			if (randGus == 12 || randGus == 6)
			{  	
				dir = 0; speed = 0.2; vie = 2;
				
				sprite.setTextureRect(IntRect(190, 70, 40, 40));
			}
			if (randGus == 3 || randGus == 7)
			{  
				dir = 3; speed = 0.2; vie = 3;
				sprite.setTextureRect(IntRect(190, 20, 40, 40));
			} 
			if (randGus == 4 || randGus == 8)
			{ 
				dir = 2; speed = 0.2; vie = 4;
				sprite.setTextureRect(IntRect(230, 60, -40, -40));
			}
	}
};

class objc : public Player
{
public:

	bool isMove = true;
	objc(String F, float X, float Y, float W, float H, float dX, float dY) : Player(F, X, Y, W, H, dX, dY)
	{

	}

	//Задание направления полета снаряда и проверка на столкновение с препядствием
	void strelba(float time, int vie)
	{
		if(TileMap[(int)sprite.getPosition().y / 32][(int)sprite.getPosition().x / 32] != '0' && isMove == true)
		{
			switch(vie)
			{
				case 1:  sprite.move(-0.5 * time, 0); sprite.setRotation(270); break;
				case 2:  sprite.move(0.5 * time, 0); sprite.setRotation(90); break;
				case 3:  sprite.move(0, -0.5 * time); sprite.setRotation(0); break;
				case 4:  sprite.move(0, 0.5 * time); sprite.setRotation(180); break;
				default: isMove = false;
			}
		}
    		else
		{
			isMove = false;
			sprite.move(0, 0);
			sprite.setPosition(-15, -15);
		}
	}
};
