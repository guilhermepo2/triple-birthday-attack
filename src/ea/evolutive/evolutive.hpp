#ifndef __EVOLUTIVE__
#define __EVOLUTIVE__

#include "ea/population/population.hpp"

class Evolutive {
private:
    float crossoverRate;
    float mutationRate;
    int generations;
public:
    Population * population;

    Evolutive(const char *);
    ~Evolutive();
    inline float getCrossoverRate() const  { return this->crossoverRate; }
    inline float getMutationRate() const   { return this->mutationRate;  }
    inline int getGenerations() const      { return this->generations;   }
    inline void setCrossoverRate(float c)  { this->crossoverRate = c;    }
    inline void setMutationRate(float m)   { this->mutationRate = m;     } 
    inline void setGenerations(int g)      { this->generations = g;      }

};

#endif