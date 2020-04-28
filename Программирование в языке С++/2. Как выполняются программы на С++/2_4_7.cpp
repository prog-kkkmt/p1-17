#include <iostream>

using namespace std;

void strcat(char *to, const char *from)
{
    while (*to != '\0')
        to++;
    for ( ; *from != '\0'; to++, from++)
        *to = *from;
    *to = '\0';
}
