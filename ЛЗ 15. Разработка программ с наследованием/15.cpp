/*
МДК.01.02 "Прикладное программирование"
Лабораторное занятие 15. Разработка программ с наследованием
Составитель: Гусятинер Л.Б., 16.05.2020, МГОТУ ККМТ, П1-17, П2-17

Задание.
На основании ЛЗ-14:
1. Создать игровой класс "Персонаж"
2. Унаследовать от него 2-3 класса из игрового проекта.
3. Внести изменения в проект
Задание разрабатывается той же группой, что и ЛЗ-14.
Можно создать специальный репозиторий или ветку на гитхабе
Файлы *.cpp и *.h (*.hpp), test.txt, Readme.md в созданной ветке или в репозитории (имя Lab-14).

Выбранная игра: World of Tanks(WoT).
Выполнили: Бобнев Алексей, Суркова Валерия и Канавская Мария.
Группа П1-17.
21.05.2020
*/

#include <iostream>
#include <locale>
#include <fstream>

using namespace std;

class Tank///Характеристика
{
    public:
        void param()
        {
            igra = 'WoT';
            int n, i;
            cin >> n;
            for (i = 0; i < n; ++i)
            {
                cin >> country[i] >> uron[i] >> bron[i] >> skorostrelnost[i]
                >> uron_minuta[i] >> time_sved[i] >> boezap[i];
            }
            for (i = 0; i < n; ++i)
            {
                cout << country[i] << " " << uron[i] << " " << bron[i] << " " << skorostrelnost[i]
                << " " << uron_minuta[i] << " " << time_sved[i] << " " << boezap[i] << endl;
            }
        }
    protected:
        string country[1000], uron[1000], bron[1000], igra;
        int uron_minuta[1000], boezap[1000];
        float skorostrelnost[1000], time_sved[1000];
};

class Skidka///Скидка
{
    public:
        void s()
        {
            cin >> tank >> cena;
            cin >> skidka;
            float pom;
            pom = cena - ((cena / 100) * skidka);
            cout << pom << endl;
        }
    protected:
        string tank;
        float cena, skidka;
};

class Ulu///Улучшения
{
    public:
        void ul()
        {
            cin >> part >> cena;
            float pom;
            pom = cena + (cena / 10);
            cout << pom << endl;
        }
    protected:
        string part;
        float cena;
};

class Copy : public Tank {};

class vig : public Skidka {};

class u2: public Ulu {};

struct His //Класс
{
    public:///Конструктор
    His()
    {
        string a;
        a = "История создания:";
        cout << "История создания:" << endl;
        cout << "Идея игры, по словам разработчиков, возникла 29 или 30 декабря 2008 года, хотя решение сделать игру о танках пришло после разговора в Москве 12 декабря 2008 года.Весной 2009 года в компанию" << endl;
        cout << "пришёл гейм-дизайнер Сергей Буркатовский, известный также как SerB.Официальный анонс игры был сделан студией Wargaming.net 24 апреля 2009 года. Альфа-тестирование игры началось в сентябре" << endl;
        cout << "того же года; на тот момент было создано всего пять моделей танков и одна незаконченная карта. За пять месяцев на участие в бета-тесте было подано около 40 000 заявок," << endl;
        cout << "в ходе тестирования проведено более 400 000 боёв. В марте 2010 года разработчики объявили, что предполагают развивать проект ещё как минимум 5-7 лет. 24 июня 2010 года началось открытое бета-тестирование игры; " << endl;
        cout << "в первой версии открытого бета-теста игрокам были доступны школы танкостроения СССР и Германии и семь различных карт." << endl;
        cout << "8 июля стартовал закрытый бета-тест англоязычной версии World of Tanks. 12 августа состоялся онлайн-выпуск World of Tanks, однако по техническим причинам" << endl;
        cout << "серверы игры заработали только 13 августа 2010 года. 27 января 2011 года англоязычная версия игры перешла в режим открытой бета-версии, её релиз состоялся 12 апреля 2011 года." << endl;
        cout << "Длина первой строки: " << a.length() << endl;
        string *b;
        b = &a;
        cout << "Указатель на первую строку: " << *b << endl;
    }

    ~His()///Деструктор
    {}
};

struct Pro
{
    public:///Конструктор
    Pro()
    {
        cout << "Игровой процесс:" << endl;
        cout << "Игровой процесс в World of Tanks основывается на битве двух случайно подобранных команд по 15 игроков — при этом в одной команде могут сочетаться танки разных стран и годов выпуска, " << endl;
        cout << "реальные танки и экспериментальные модели. Условие победы в битве — полное уничтожение команды противника либо захват его базы, для чего один или несколько танков должны находиться в" << endl;
        cout << "отмеченной зоне некоторое время, не получая при этом повреждений. С обновлением 0.7.4 были введены режимы «Штурм» и «Встречный бой» . С обновлением 8.9 был введён режим «Командный бой»." << endl;
        cout << "Общение между игроками во время боев и координация действий осуществляются через текстовый чат либо по голосовой связи. Игрок, танк которого уничтожен, выбывает из боя, " << endl;
        cout << "но может либо наблюдать за сражением в режиме свободно переключающейся камеры, либо покинуть поле боя и вернуться в ангар, откуда немедленно отправиться в другое сражение на другом танке, " << endl;
        cout << "или дождаться возвращения повреждённого танка из боя. Имеется рейтинговая система, которая отображает статистику побед и поражений и фиксирует достижения отдельного игрока." << endl;
    }

    ~Pro()///Деструктор
    {}
};

struct Re
{
    public:///Конструктор
    Re()
    {
        cout << "Режимы игры:" << endl;
        cout << "Случайный бой (стандартный бой, встречный бой, штурм, генеральное сражение);" << endl;
        cout << "Ранговый бой;" << endl;
        cout << "Укрепрайоны (вылазки, наступления);" << endl;
        cout << "Специальный бой (турниры, клановые битвы);" << endl;
        cout << "Экспедиция (линия фронта, стальной охотник);" << endl;
        cout << "Схватка;" << endl;
        cout << "Дорога на Берлин;" << endl;
        cout << "Тренировочный бой;" << endl;
        cout << "Учебный полигон." << endl;
    }

    ~Re()///Деструктор
    {}
};

struct o
{
    public:///Конструктор
    o()
    {
        cout << "Создали программу: Бобнев Алексей, Суркова Валерия и Канавская Мария. Группа П1-17." << endl;
    }

    ~o()///Деструктор
    {}
};

struct os///Игровая валюта
{
    public:
    os()
    {
        cout << "Введите количество игрового золота и курс игровой валюты:" << endl;
        cin >> k >> s;
        cout << "Общая цена за золото: " << k * s << " руб." << endl;
    }

    private:
        float s, k;

};

struct ot///Отзыв
{
    public:
    ot()
    {
        int n, i;
        float n1 = 0;
        cout << "Введите количество отзывов:" << endl;
        cin >> n;
        cout << "Введите имя, фамилию человека и оценку игры:" << endl;
        for (i = 0; i < n; ++i)
        {
            cin >> im[i] >> fam[i] >> ots[i];
            n1 += ots[i];
        }
        cout << "Средний балл игры: " << n1 / n << endl;
    }

    private:
        int ots[1000];
        string im[1000], fam[1000];

};

struct let///Сколько лет игре?
{
    public:
    let()
    {
        cout << "Какой сейчас год?" << endl;
        cin >> year;
        int a, k;
        k = year - year1;
        a = (year - year1) % 10;
        if ((k >= 11) && (k <= 19)) cout << k << " лет" << endl;
        else if (a == 1)
        cout << k << " год" << endl;
        else if ((a >= 2) && (a <= 4))
        cout << k << " года" << endl;
        else
        cout << k << " лет" << endl;

    }

    private:
        int year, year1 = 2010;
};

int main()///Основное меню
{
    setlocale(LC_ALL, "rus");
    string na;
    ifstream input("nazv.txt");
    getline(input, na);
    cout << na << endl;
    int menu;
    cout << "1 - История создания" << endl;
    cout << "2 - Игровой процесс" << endl;
    cout << "3 - Режимы игры" << endl;
    cout << "4 - О программе" << endl;
    cout << "5 - Игровая валюта" << endl;
    cout << "6 - Отзыв" << endl;
    cout << "7 - Сколько лет игре?" << endl;
    cout << "8 - Персонаж" << endl;
    cout << "0 - Выход" << endl;
    cin >> menu;
    while ((menu == 1) || (menu == 2) || (menu == 3) || (menu == 4)  || (menu == 5)  || (menu == 6)   || (menu == 7)   || (menu == 8))///Меню
    {
        if (menu == 1) His();
        if (menu == 2) Pro();
        if (menu == 3) Re();
        if (menu == 4) o();
        if (menu == 5) os();
        if (menu == 6) ot();
        if (menu == 7) let();
        if (menu == 8)
        {
            Tank t;
            t.param();
            Copy c;
            c.param();
            Skidka sk;
            sk.s();
            vig v;
            v.s();
            Ulu u;
            u.ul();
            u2 u22;
            u22.ul();
        }
        cout << "1 - История создания" << endl;
        cout << "2 - Игровой процесс" << endl;
        cout << "3 - Режимы игры" << endl;
        cout << "4 - О программе" << endl;
        cout << "5 - Игровая валюта" << endl;
        cout << "6 - Отзыв" << endl;
        cout << "7 - Сколько лет игре?" << endl;
        cout << "8 - Персонаж" << endl;
        cout << "0 - Выход" << endl;
        cin >> menu;
    }
    return 0;
}
