#include "ea/population/population.hpp"

Population::Population(int populationSize) {
    this->populationSize = populationSize;
    this->initialized = false;
}