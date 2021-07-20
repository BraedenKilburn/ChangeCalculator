a.out: main.cpp
	g++ main.cpp -Wall -Wextra -pedantic

clean:
	rm a.out