/* Ýòîò êîä ïðîñòî íàïîìèíàíèå êàê âûãëÿäèò êëàññ Foo è ôóíêöèÿ foo_says.
 * Íå íóæíî åãî ðàññêîìåíòèðîâàòü è/èëè ìåíÿòü.
 *
 * #include <iostream>
 *
 * struct Foo {
 *     void say() const { std::cout << "Foo says: " << msg << "\n"; }
 * protected:
 *     Foo(const char *msg) : msg(msg) { }
 * private:
 *     const char *msg;
 * };
 *
 * void foo_says(const Foo &foo) { foo.say(); }
 *
 */

// Âàì íóæíî îïðåäåëèòü ôóíêöèþ get_foo, êàê îïèñàíî â çàäàíèè,
// ÷òîáû êîìïèëèðîâàëñÿ è ðàáîòàë êàê îæèäàåòñÿ ñëåäóþùèé êîä:
//
// foo_says(get_foo("Hello!"));

struct I_will_get_you : Foo {
    I_will_get_you(const char *msg) : Foo(msg)
    {}
};
struct I_will_get_you get_foo(const char *msg) {
    I_will_get_you a(msg);
    return a;
}
