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

TEST_CASE("Testing Fitness Calculation", "[evolutive]") {
    Evolutive e("config/initializationTest.json");
    Operators::GenerateAllRandom * gen = new Operators::GenerateAllRandom();
    gen->setMaxHash(e.getHashBudget());
    e.generation = gen;
    e.fitness = new Operators::BruteForceCollisionCheck();
    e.initPopulation();
    e.calculateFitness();

    std::cout << "Printing Population with Fitness" << std::endl;
    for(int i = 0; i < e.population->getPopulationSize(); i++) {
        std::cout << "Individual " << i+1
                  << " has fitness of "
                  << e.population->individuals[i].getFitness()
                  << std::endl;
    }
}

TEST_CASE("Testing Parent Selection", "[evolutive]") {
    Evolutive e("config/initializationTest.json");
    Operators::GenerateAllRandom * gen = new Operators::GenerateAllRandom();
    gen->setMaxHash(e.getHashBudget());
    e.generation = gen;
    e.fitness = new Operators::BruteForceCollisionCheck();
    e.parentSelection = new Operators::RandomParentSelection();
    e.initPopulation();

    int parent1 = -1;
    int parent2 = -1;
    int parent3 = -1;
    parent1 = e.selectParent();
    parent2 = e.selectParent();
    parent3 = e.selectParent();
    std::cout << "Selected Parent: " << parent1 << std::endl;
    std::cout << "Selected Parent: " << parent2 << std::endl;
    std::cout << "Selected Parent: " << parent3 << std::endl;

    REQUIRE( parent1 != -1 );
    REQUIRE( parent2 != -1 );
    REQUIRE( parent3 != -1 );
}

TEST_CASE("Testing Crossover", "[evolutive]") {
    Evolutive e("config/initializationTest.json");
    Operators::GenerateAllRandom * gen = new Operators::GenerateAllRandom();
    gen->setMaxHash(e.getHashBudget());
    e.generation = gen;
    e.fitness = new Operators::BruteForceCollisionCheck();
    e.parentSelection = new Operators::RandomParentSelection();
    e.crossover = new Operators::ThreeChildrenCrossover();
    e.crossover->setHashBudget(e.getHashBudget());
    e.initPopulation();

    std::cout << "Testing Crossover..." << std::endl;
    std::cout << "BEFORE: population.size(): " << e.population->individuals.size() << std::endl;
    e.performCrossover();
    std::cout << "AFTER: population.size(): " << e.population->individuals.size() << std::endl;

    for(int i = 0; i < e.population->individuals.size(); i++) {
        int m1 = e.population->individuals[i].getM1();
        int m2 = e.population->individuals[i].getM2();
        int m3 = e.population->individuals[i].getM3();

        REQUIRE( ( (m1 + m2 + m3 ) == e.getHashBudget()) );

        std::cout << "Individual " << i+1 << " - M1: " << e.population->individuals[i].getM1()
                  << " M2: " << e.population->individuals[i].getM2()
                  << " M3: " << e.population->individuals[i].getM3()
                  << " SUM: " << e.population->individuals[i].getM1() + e.population->individuals[i].getM2() + e.population->individuals[i].getM3()
                  << std::endl; 
    }
}