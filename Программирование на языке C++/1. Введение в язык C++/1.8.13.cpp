#include <iostream>

long int log(long int a) {
    long int b = 1;
    int k = 0;
    while (b * 2 <= a) {
        b *= 2;
        if (b <= a)
            k++;
        }
    return k;
}

int main() {
    int T;
    long int a;
    std::cin >> T;
    for (int i = 0; i < T; i++) {
        std::cin >> a;
        std::cout << log(a) << std::endl;
    }
    return 0;
}
