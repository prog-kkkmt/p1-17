#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstring>
#include <vector>
#include <sstream>

#include "TanksClass.hpp"

using namespace std;
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(1024, 1024), "Tanks"); //Окно 1024 х 1024

	Clock clock;

	int vie2 = 3, vie22 = 3; //Переменные направления взгляда игровок
	
	float timeresp = 0; //Время спавна противника
	int randResp = 0; //Место спавна противник

	int Score = 0, ScoreMax = 0, Destroyed = 0, DestroyedMax = 0;		//Очки первого игрока
	int Score2 = 0, ScoreMax2 = 0, Destroyed2 = 0, DestroyedMax2 = 0;	//Очки второго игрока


	Player player("Tanks.png", 240, 20 , 40, 40, 942, 942);  //Первого игрока
	Player player2("Tanks.png", 240, 20 , 40, 40, 942, 902); //Второй игрок

	Player map("itemsAll.png", 0, 0, 32, 32, 0, 0);	//Поле карты

	objc pul("itemsAll.png", 160, 1, 9, 17, -15, -15); //Создание снаряда первого игрока
	objc pul2("itemsAll.png", 160, 1, 9, 17, -15, -15); //Создание снаряда второго игрока

	vector<Entity*>VecEntity; //Противники 
	vector<objc*>VecPul; //Снаряды противников
	vector<int> vie3; //Напраяление взгляда противников


//Создание текста
	Font font;
	font.loadFromFile("FontText.otf");

	Text text;
	text.setFont(font);
	text.setCharacterSize(28);
	text.setFillColor(Color::White);
	text.setStyle(Text::Bold);

	Text text2;
	text2.setFont(font);
	text2.setCharacterSize(28);
	text2.setFillColor(Color::White);
	text2.setStyle(Text::Bold);

	//Создание первых 4-х противников и расстановка их на карте
	for(int i = 0; i < 5; i++)
	{
		VecEntity.push_back(new Entity("Tanks.png", 190, 20, 40, 40, 32, 32));
		VecPul.push_back(new objc("itemsAll.png", 160, 1, 9, 17, -15, -15));
		vie3.push_back(0);
	}

	//Основной цикл событий. Обязателен для SFML
	while(window.isOpen())
	{
		window.clear(Color::White); //Заливка фона белым
		srand(time(NULL));
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;

		//Спавн новых противников в 3-х рандомных местах через одинаковые промежутки времени
		timeresp += time;
		if(timeresp >= 5000)
		{
			randResp = 1 + rand() % 3;
			if(randResp == 1)
				VecEntity.push_back(new Entity("Tanks.png", 190, 20, 40, 40, 32, 32));
			if(randResp == 2)
				VecEntity.push_back(new Entity("Tanks.png", 190, 20, 40, 40, 942, 32));
			if(randResp == 3)
				VecEntity.push_back(new Entity("Tanks.png", 190, 20, 40, 40, 32, 942));

			VecPul.push_back(new objc("itemsAll.png", 160, 1, 9, 17, -15, -15));
			vie3.push_back(0);
			timeresp = 0;
		}

		//Событие, реагирующее на закрытие окна
		Event game;
		while(window.pollEvent(game))
		{
			if(game.type == Event::Closed)
				window.close();
		}

		//Стрельба Первого игрока
		if (player.life == true)
		{
			if(Keyboard::isKeyPressed(Keyboard::Space))
			{
				if(pul.isMove == false)
				{
					pul.sprite.setPosition(player.dx + 20, player.dy + 20);
					pul.isMove = true;
					vie2 = player.vie;
				}
			}
		}

		//Стрельба Второго игрока
		if (player2.life == true)
		{
			if(Keyboard::isKeyPressed(Keyboard::C))
			{
				if(pul2.isMove == false)
				{
					pul2.sprite.setPosition(player2.dx + 20, player2.dy + 20);
					pul2.isMove = true;
					vie22 = player2.vie;
				}
			}
		}


		//Вызов методов снарядов и самих игроков
		pul.strelba(time, vie2);
		pul2.strelba(time, vie22);
		player.control(time);
		player.update(time);
		player2.control2(time);
		player2.update(time);


	//Цикл движения, стрельбы, проверки на попадание и смерти противников
	for(int i = 0; i < int(VecEntity.size()); ++i)
		{
			VecEntity[i]->Artificial_Intelligence(time);
			VecEntity[i]->update(time);

			VecPul[i]->strelba(time, vie3[i]);
			if(VecPul[i]->isMove == false)
			{
				vie3[i] = VecEntity[i]->vie;
				VecPul[i]->sprite.setPosition(VecEntity[i]->dx + 20, VecEntity[i]->dy + 20);
				VecPul[i]->isMove = true;
			}

			if(pul.sprite.getGlobalBounds().intersects(VecEntity[i]->sprite.getGlobalBounds()))
			{
				VecEntity.erase(VecEntity.begin() + i);
				VecPul.erase(VecPul.begin() + i);
				pul.isMove = false;
				pul.sprite.setPosition(-15, -15);
				Score += 20;
				Destroyed++;
			}
			if(pul2.sprite.getGlobalBounds().intersects(VecEntity[i]->sprite.getGlobalBounds()))
			{
				VecEntity.erase(VecEntity.begin() + i);
				VecPul.erase(VecPul.begin() + i);
				pul2.isMove = false;
				pul2.sprite.setPosition(-15, -15);
				Score2 += 20;
				Destroyed2++;
			}

			if(VecPul[i]->sprite.getGlobalBounds().intersects(player.sprite.getGlobalBounds()))
			{
				player.dx = 952;
				player.dy = 952;
				Score = 0;
				Destroyed = 0;
			}
			if(VecPul[i]->sprite.getGlobalBounds().intersects(player2.sprite.getGlobalBounds()))
			{
				player2.dx = 952;
				player2.dy = 952;
				Score2 = 0;
				Destroyed2 = 0;
			}
		}


		//Условия обномления максимальных очком и уничтоженных танков
		if(ScoreMax < Score)
			ScoreMax = Score;
		if(DestroyedMax < Destroyed)
			DestroyedMax = Destroyed;

		if(ScoreMax2 < Score2)
			ScoreMax2 = Score2;
		if(DestroyedMax2 < Destroyed2)
			DestroyedMax2 = Destroyed2;


		//Отрисовка карты
		for(int i = 0; i < HEIGHT_MAP2; i++)
			for(int j = 0; j < WIDHT_MAP2; j++)
			{
				if(TileMap[i][j] == '0') map.sprite.setTextureRect(IntRect(0, 0, 32, 32));
				if(TileMap[i][j] == ' ') map.sprite.setTextureRect(IntRect(32, 0, 32, 32));

				map.sprite.setPosition(j * 32, i * 32);

				window.draw(map.sprite);
			}

		//Запись всех данных в поток
		ostringstream Scored;
		ostringstream Scored2;
		Scored << "Score: " << Score << "     " << "Destroyed: " << Destroyed << "     ";
		Scored << "Record Score: " << ScoreMax << "    " << "Record Destroyed: " << DestroyedMax;

		Scored2 << "Score2: " << Score2 << "     " << "Destroyed2: " << Destroyed2 << "     ";
		Scored2 << "Record Score2: " << ScoreMax2 << "    " << "Record Destroyed2: " << DestroyedMax2;

		//Перенос из потока в переменные отображения текста
		text.setString(Scored.str());
		text.setPosition(10, -2);
		text2.setString(Scored2.str());
		text2.setPosition(10, 992);

		
		// Рисование игроков, противников и их снарядов
		window.draw(player.sprite);
		window.draw(player2.sprite);
		window.draw(pul.sprite);
		window.draw(pul2.sprite);
		for(int i = 0; i < int(VecEntity.size()); ++i)
			{
				window.draw(VecEntity[i]->sprite);	
			}
		
		for(int i = 0; i < int(VecPul.size()); ++i)
		{
			window.draw(VecPul[i]->sprite);
		}

		// Рисование текста
		window.draw(text);
		window.draw(text2);

		window.display();
	}

	return 0;
}