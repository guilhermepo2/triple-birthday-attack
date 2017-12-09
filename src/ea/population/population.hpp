#ifndef __POPULATION__
#define __POPULATION__

#include "ea/individual/individual.hpp"

class Population {
private:
    int populationSize;
    bool initialized;
public:
    std::vector<Individual> individuals;
    Population(int);
    inline int getPopulationSize() const                      { return this->populationSize; }
    inline void setPopulationSize(int s)                      { this->populationSize = s;    }
    inline bool getInitialized() const                        { return this->initialized;    }
    inline void setInitialized(bool b)                        { this->initialized = b;       }
    inline std::vector<Individual> getIndividualsCopy() const { return this->individuals;    }
};

#endif