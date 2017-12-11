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

    // EVOLUTIVE ALGORITHM STARTS HERE
    evolutiveAlgorithm->initPopulation();
    evolutiveAlgorithm->calculateFitness();
    std::cout << "Running for " << evolutiveAlgorithm->getGenerations() << " generations." << std::endl;
    for(int i = 0; i < evolutiveAlgorithm->getGenerations(); i++) {
        evolutiveAlgorithm->sort();
        std::cout << "Best Candidate has " << evolutiveAlgorithm->population->individuals[0].getFitness() << "collisions" << std::endl;
        evolutiveAlgorithm->performCrossover();
        evolutiveAlgorithm->performMutation();
        evolutiveAlgorithm->survivalOfTheFittest();
    }
    
    delete evolutiveAlgorithm;
    return 0;
}