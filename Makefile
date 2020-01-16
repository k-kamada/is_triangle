VPATH = ./test

main: main.cpp is_triangle.hpp
	clang++ main.cpp -o main -O2 -Wall -std=c++17 -lgtest -lgtest_main -lpthread

.PHONY: test
test: is_triangle_test.cpp is_triangle.hpp
	clang++ ./test/is_triangle_test.cpp -o is_triangle_test -Wall -std=c++17 -lgtest -lgtest_main -lpthread && ./is_triangle_test

.PHONY: clean
clean:
	rm -f main is_triangle_test *.o
