#include "ea/evolutive/evolutive.hpp"

int main() {
    std::cout << "Initializing Evolutive Algorithm..." << std::endl;
    Evolutive * evolutiveAlgorithm = new Evolutive("config/init.json");

    // Setting Random Population Initialization
    Operators::GenerateAllRandom * gen = new Operators::GenerateAllRandom();
    gen->setMaxHash(evolutiveAlgorithm->getHashBudget()); // BAD (FIX)
    evolutiveAlgorithm->generation = gen;

    // Setting Fitness Function
    evolutiveAlgorithm->fitness = new Operators::BruteForceCollisionCheck();

    // Setting Parent Selection Method
    evolutiveAlgorithm->parentSelection = new Operators::RandomParentSelection();

    // Setting Crossover Method
    evolutiveAlgorithm->crossover = new Operators::ThreeChildrenCrossover();
    evolutiveAlgorithm->crossover->setHashBudget(evolutiveAlgorithm->getHashBudget()); // BAD (FIX)

    // Setting Mutation Method
    evolutiveAlgorithm->mutation = new Operators::SimpleMutation();
    evolutiveAlgorithm->mutation->setHashBudget(evolutiveAlgorithm->getHashBudget()); // BAD (FIX)

    // Setting Survival Method
    Operators::Elitism * eltsm = new Operators::Elitism(); // BAD (FIX)
    eltsm->setOriginalPopulationSize(evolutiveAlgorithm->population->getPopulationSize()); // BAD BAD (FIX)
    eltsm->setSurvivalRate(1.0f - evolutiveAlgorithm->getCrossoverRate()); //  BAD BAD BAD (FIX)
    evolutiveAlgorithm->survival = eltsm;

    // Setting Sort Method
    evolutiveAlgorithm->sorting = new Operators::BubbleSort();

    // EVOLUTIVE ALGORITHM STARTS HERE
    evolutiveAlgorithm->initPopulation();
    std::cout << "Running for " << evolutiveAlgorithm->getGenerations() << " generations." << std::endl;
    std::cout << "Population Size: " << evolutiveAlgorithm->population->getPopulationSize() << " Hash Budget: " << evolutiveAlgorithm->getHashBudget() << std::endl;
    std::cout << "Hash Function SHA1 with " << (40 / BIT_DIV) * 4 << " bits." << std::endl;
    for(int i = 0; i < evolutiveAlgorithm->getGenerations(); i++) {
        evolutiveAlgorithm->calculateFitness();
        evolutiveAlgorithm->sort();
        std::cout << i+1 << " - Best Candidate has " << evolutiveAlgorithm->population->individuals[0].getFitness() << " collisions" << std::endl;
        evolutiveAlgorithm->performCrossover();
        evolutiveAlgorithm->performMutation();
        evolutiveAlgorithm->survivalOfTheFittest();
    }

    std::cout << "The algorithm is over. final population below" << std::endl;
    for(int i = 0; i < evolutiveAlgorithm->population->getPopulationSize(); i++) {
        std::cout << "Individual " << (i+1) << " M1: " << evolutiveAlgorithm->population->individuals[i].getM1()
                                            << " M2: " << evolutiveAlgorithm->population->individuals[i].getM2()
                                            << " M3: " << evolutiveAlgorithm->population->individuals[i].getM3()
                                            << " Fitness: " << evolutiveAlgorithm->population->individuals[i].getFitness()
                                            << std::endl;
    }
    
    delete evolutiveAlgorithm;
    return 0;
}