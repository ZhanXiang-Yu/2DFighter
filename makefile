game: main.o flyer.o bullet.o
	g++ -std=c++17 -Wall -Wextra -pedantic -Weffc++ -fsanitize=undefined,address main.o flyer.o bullet.o -o game  -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
main.o: main.cpp
	g++ -std=c++17 -Wall -Wextra -pedantic -Weffc++ -fsanitize=undefined,address -c main.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
flyer.o: flyer.cpp flyer.h
	g++ -std=c++17 -Wall -Wextra -pedantic -Weffc++ -fsanitize=undefined,address -c flyer.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 
bullet.o: bullet.cpp bullet.h
	g++ -std=c++17 -Wall -Wextra -pedantic -Weffc++ -fsanitize=undefined,address -c bullet.cpp  -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 
clean:
	rm *.o game


