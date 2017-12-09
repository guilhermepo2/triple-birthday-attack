searchForHash:
	g++ -std=c++11 -I. searchForHash.cpp libs/hash2lib/src/hl_sha1wrapper.cpp libs/hash2lib/src/hl_sha1.cpp libs/hash2lib/src/hl_md5wrapper.cpp libs/hash2lib/src/hl_md5.cpp

ea:
	g++ -std=c++11 -I. test.cpp ea/individual/individual.cpp ea/population/population.cpp

individualTest:
	g++ -std=c++11 -I. tests/individualTest.cpp ea/individual/individual.cpp
populationTest:
	g++ -std=c++11 -I. tests/populationTest.cpp ea/population/population.cpp
eaTest:
	g++ -std=c++11 -I. tests/eaTest.cpp ea/evolutive/evolutive.cpp ea/population/population.cpp ea/individual/individual.cpp

tests: tests/individualTest.cpp tests/populationTest.cpp tests/eaPopulation.test
	make individualTest && ./a.out && make populationTest && ./a.out && make eaTest && ./a.out