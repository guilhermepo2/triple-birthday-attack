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
    const inline int getPopulationSize()                      { return this->populationSize; }
    inline void setPopulationSize(int s)                      { this->populationSize = s;    }
    const inline bool getInitialized()                        { return this->initialized;    }
    inline void setInitialized(bool b)                        { this->initialized = b;       }
    const inline std::vector<Individual> getIndividualsCopy() { return this->individuals;    }
};

#endif