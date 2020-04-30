all: exe lib

exe: mylib.hpp main.cpp lib
	g++ main.cpp -L. -lMylib -o mylib
lib: mylib.hpp mylib.cpp
	g++ -shared mylib.cpp -o libMylib.so
clean:
	 -rm mylib libMylib.so 2>/dev/null


