#define CATCH_CONFIG_MAIN
#include "ea/evolutive/evolutive.hpp"
#include "libs/catch.hpp"

TEST_CASE("Testing Initialization", "[evolutive]") {
    Evolutive e("config/initializationTest.json");

    REQUIRE( e.population->getPopulationSize() == 10 );
    REQUIRE( e.getCrossoverRate() == 0.8f );
    REQUIRE( e.getMutationRate() == 0.05f );
    REQUIRE( e.getGenerations() == 10 );
    REQUIRE( e.getHashBudget() == 1000 );
}

TEST_CASE("Testing Population Initialization", "[evolutive]") {
    Evolutive e("config/initializationTest.json");
    Operators::GenerateAllRandom * gen = new Operators::GenerateAllRandom();
    gen->setMaxHash(e.getHashBudget());
    e.generation = gen;
    e.initPopulation();

    REQUIRE( e.population->individuals.size() == e.population->getPopulationSize() );
    for(int i = 0; i < e.population->getPopulationSize(); i++) {
        int m1 = e.population->individuals[i].getM1();
        int m2 = e.population->individuals[i].getM2();
        int m3 = e.population->individuals[i].getM3();

        REQUIRE( ( (m1 + m2 + m3 ) == e.getHashBudget()) );
    }

    for(int i = 0; i < e.population->getPopulationSize(); i++) {
        std::cout << "Individual " << i+1 << " - M1: " << e.population->individuals[i].getM1()
                  << " M2: " << e.population->individuals[i].getM2()
                  << " M3: " << e.population->individuals[i].getM3()
                  << " SUM: " << e.population->individuals[i].getM1() + e.population->individuals[i].getM2() + e.population->individuals[i].getM3()
                  << std::endl; 
    }
}