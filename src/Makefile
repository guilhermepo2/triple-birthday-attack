searchForHash:
	g++ -std=c++11 -I. searchForHash.cpp libs/hash2lib/src/hl_sha1wrapper.cpp libs/hash2lib/src/hl_sha1.cpp libs/hash2lib/src/hl_md5wrapper.cpp libs/hash2lib/src/hl_md5.cpp

individualTest:
	g++ -std=c++11 -I. tests/individualTest.cpp ea/individual/individual.cpp
populationTest:
	g++ -std=c++11 -I. tests/populationTest.cpp ea/population/population.cpp
eaTest:
	g++ -std=c++11 -I. tests/eaTest.cpp ea/evolutive/evolutive.cpp ea/population/population.cpp ea/individual/individual.cpp libs/hash2lib/src/hl_sha1wrapper.cpp libs/hash2lib/src/hl_sha1.cpp libs/hash2lib/src/hl_md5wrapper.cpp libs/hash2lib/src/hl_md5.cpp

tests: tests/individualTest.cpp tests/populationTest.cpp tests/eaTest.cpp
	make individualTest && ./a.out && make populationTest && ./a.out && make eaTest && ./a.out

application:
	g++ -std=c++11 -I. application.cpp ea/evolutive/evolutive.cpp ea/population/population.cpp ea/individual/individual.cpp libs/hash2lib/src/hl_sha1wrapper.cpp libs/hash2lib/src/hl_sha1.cpp libs/hash2lib/src/hl_md5wrapper.cpp libs/hash2lib/src/hl_md5.cpp