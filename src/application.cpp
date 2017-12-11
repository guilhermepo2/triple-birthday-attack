#include "ea/evolutive/evolutive.hpp"

int main() {
    std::cout << "Initializing Evolutive Algorithm..." << std::endl;
    Evolutive * evolutiveAlgorithm = new Evolutive("config/init.json");

    // Setting Random Population Initialization
    Operators::GenerateAllRandom * gen = new Operators::GenerateAllRandom();
    gen->setMaxHash(e->getHashBudget()); // BAD (FIX)
    e->generation = gen;

    // Setting Fitness Function
    e->fitness = new Operators::BruteForceCollisionCheck();

    // Setting Parent Selection Method
    e->parentSelection = new Operators::RandomParentSelection();

    // Setting Crossover Method
    e->crossover = new Operators::ThreeChildrenCrossover();
    e->crossover->setHashBudget(e->getHashBudget()); // BAD (FIX)

    // Setting Mutation Method
    e->mutation = new Operators::SimpleMutation();
    e->mutation->setHashBudget(e.getHashBudget()); // BAD (FIX)

    // Setting Survival Method
    Operators::Elitism * eltsm = new Operators::Elitism(); // BAD (FIX)
    eltsm->setOriginalPopulationSize(e->population->getPopulationSize()); // BAD BAD (FIX)
    eltsm->setSurvivalRate(1.0f - e.getCrossoverRate()); //  BAD BAD BAD (FIX)
    e->survival = eltsm;

    // EVOLUTIVE ALGORITHM STARTS HERE
    e->initPopulation();
    e->calculateFitness();
    for(int i = 0; i < e->getGenerations(); i++) {
        e->sort();
        std::cout << "Best Candidate has " << e->population->individuals[0].getFitness() << "collisions" << std::endl;
        e->performCrossover();
        e->performMutation();
        e->survivalOfTheFittest();
    }
    
    delete evolutiveAlgorithm;
    return 0;
}