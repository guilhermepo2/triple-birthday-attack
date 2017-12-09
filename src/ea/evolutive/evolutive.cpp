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
    //delete population;
    //delete generation;
}

void Evolutive::initPopulation() {
    this->generation->generatePopulation(this->population->getPopulationSize(),
    this->population->individuals);
}