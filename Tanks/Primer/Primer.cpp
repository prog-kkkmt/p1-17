#include <SFML/Graphics.hpp> //Подключаем библиотеку для графикик
#include <iostream>

using namespace std;
using namespace sf; 

int main()
{
	RenderWindow window(VideoMode(600, 600), "Primer"); //Создаем окно 600х600 с названием "Primer"

	Clock clock; 		//Переменная для времени

	Image image; 		//Переменная для изображения
	Texture texture;	//Переменная для текстуры
	Sprite sprite;		//Переменнная для спрайта

	image.loadFromFile("Tanks.png"); 					//Загружаем изображение
	texture.loadFromImage(image);						//Преращаем изображение в текстуру
	sprite.setTexture(texture);							//Создаем спрайт на основе текстуры
	sprite.setTextureRect(IntRect(240, 20, 40, 40));	//"Обрезаем" текстуру для нужного квадрата спрайта.
														//В нашем случае это танк размером 40 на 40 пикселей. 
														//Берем начальную точку, на картинке "Tanks.png" это 240 по Х и 20 по Y
														//и создаем квадарат из этой точки - 40 по Х вправо и 40 по Y вниз(Y отрицательный будет вверх)
	sprite.setPosition(300, 300);						//Задаем начальную позицию появления спрайта
	sprite.setOrigin(40 / 2, 40 / 2);					//Устанавливаем центр спрайта, иначе центральной точкой будет считаться правый верхний угол


//Основной цикл событий
	//Один проход цикла считается за один кадр
	//Он работает пока окно открыто
	//Все действия нужно писать в нём
	while(window.isOpen())
	{
		window.clear(Color::White); //Заливка фона белым
		//Привазка всего ко времени
		//Если не использовать скорость обновления на разных по мощности компах будет отличаться
		srand(time(NULL));
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;

//Событие закрытя окна
	Event game;
		while(window.pollEvent(game))
		{
			if(game.type == Event::Closed)
				window.close();
		}
//Управление
		if(Keyboard::isKeyPressed(Keyboard::Up)) //Если нажата клавиша Up
		{
			sprite.move(0, -0.2 * time);	//То спрайт движется вверх
			sprite.setRotation(0);			//И поварачивается в напрвление движения
		}
		else if(Keyboard::isKeyPressed(Keyboard::Down)) //Аналогично, только вниз
		{
			sprite.move(0, 0.2 * time);
			sprite.setRotation(180);
		}
		else if(Keyboard::isKeyPressed(Keyboard::Left)) //Аналогично, только влево
		{
			sprite.move(-0.2 * time, 0);
			sprite.setRotation(270);
		}
		else if(Keyboard::isKeyPressed(Keyboard::Right)) //Аналогично, только вправо
		{
			sprite.move(0.2 * time, 0);
			sprite.setRotation(90);
		}

		window.draw(sprite); // Рисоване спрайта
		window.display();
	}

	return 0;
}