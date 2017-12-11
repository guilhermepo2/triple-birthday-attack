#include "ea/evolutive/evolutive.hpp"

Evolutive::Evolutive(const char * settingsFile) {
    std::ifstream eaSettingsFile(settingsFile);

    if(!(eaSettingsFile.is_open())) {
        std::cout << "File " << settingsFile << " could not be found." << std::endl;
        exit (EXIT_FAILURE);
    }

    json eaSettings;
    eaSettingsFile >> eaSettings;

    int pSize = eaSettings["populationSize"];
    float cRate = eaSettings["crossoverRate"];
    float mRate = eaSettings["mutationRate"];
    int generations = eaSettings["generations"];
    int hashBudget = eaSettings["hashBudget"];

    this->population = new Population(pSize);
    this->crossoverRate = cRate;
    this->mutationRate = mRate;
    this->generations = generations;
    this->hashBudget = hashBudget;
}

Evolutive::~Evolutive() {
    // delete all pointers
    if(population!= NULL) delete population;
    if(generation != NULL) delete generation;
    if(fitness != NULL) delete fitness;
    if(parentSelection != NULL) delete parentSelection;
    if(crossover != NULL) delete crossover;
    if(mutation != NULL) delete mutation;
    if(survival != NULL) delete survival;
}

void Evolutive::initPopulation() {
    this->generation->generatePopulation(this->population->getPopulationSize(),
    this->population->individuals);
}

void Evolutive::calculateFitness() {
    for(int i = 0; i < this->population->getPopulationSize(); i++) {
        this->fitness->calculateFitness(this->population->individuals[i]);
    }
}

int Evolutive::selectParent() {
    return (this->parentSelection->selectParent(this->population->getPopulationSize(), this->population->individuals));
}

void Evolutive::performCrossover() {
    while(this->population->individuals.size() > this->population->getPopulationSize()) {
        this->population->individuals.pop_back();
    }

    int maxSize = this->population->getPopulationSize() + std::ceil(this->crossoverRate * this->population->getPopulationSize());
    while(this->population->individuals.size() < maxSize) {
        int p1 = this->selectParent();
        int p2 = this->selectParent();
        while(p2 == p1) p2 = this->selectParent();

        this->crossover->crossover(this->population->individuals[p1], this->population->individuals[p2], this->population->individuals);
    }
}

void Evolutive::performMutation() {
    int rate = this->mutationRate * 100;
    int choice;

    for(int i = this->population->getPopulationSize(); i <  this->population->individuals.size(); i++) {
        choice = rand() % 100;

        if(choice <= rate) {
            this->mutation->mutate(this->population->individuals[i]);
        }
    }
}

void Evolutive::survivalOfTheFittest() {
    this->survival->survival(this->population->individuals);
}

void Evolutive::sort() {
    this->sorting->sort(this->population->individuals);
}