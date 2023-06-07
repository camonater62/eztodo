default:
	clang++ main.cpp -o todo -O3 -Wall -Wextra -pedantic -Werror

clean:
	rm -f todo