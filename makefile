make:
	g++ -std=c++11 hash_algo.cpp Time.cpp -o test
	./test
	rm test