sprite1.getGlobalBounds().intersects(sprite2.getGlobalBounds()); //Проверка пересечения двух спрайтов

Keyboard::isKeyPressed(Keyboard::Left); //Обработка клавиатуры

Mouse::isButtonPressed(Mouse::Left); //Обработка мыши

sprite.move(x, y); //Движение спрайта

sprite.getPosition().x; //Получение координат спрайта по Х

sprite.getPosition().y; //Получение координат спрайта по У

sprite.setOrigin(w / 2, h / 2); //Установка центар спрайта (по умолчанию верхний левый угол)

sprite.setRotation(rotation); // Поворот спрайта на rotation градусов от абсолютного значения (0)

sprite.rotate(); // Поворот спрайта относительно текущей ориентации

class Player // Пример класса с коструктором
{
public:
	float x, y, w, h, dx, dy;
	String File;
	Image image;
	Texture texture;
	Sprite sprite;

	Player(String F, float X, float Y, float W, float H, float dX, float dY) // Конструктор
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
}