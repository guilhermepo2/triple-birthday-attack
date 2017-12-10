#ifndef __EVOLUTIVE__
#define __EVOLUTIVE__

#include "ea/population/population.hpp"
#include "ea/evolutive/operators/operators.hpp"

class Evolutive {
private:
    float crossoverRate;
    float mutationRate;
    int generations;
    int hashBudget;
public:
    Population * population = NULL;
    Operators::PopulationGeneration * generation = NULL;
    Operators::FitnessFunction * fitness = NULL;
    Operators::ParentSelection * parentSelection = NULL;
    Operators::Crossover * crossover = NULL;
    Operators::Mutation * mutation = NULL;

    Evolutive(const char *);
    ~Evolutive();
    void initPopulation();
    void calculateFitness();
    int selectParent();
    void performCrossover();
    void performMutation();

    inline float getCrossoverRate() const  { return this->crossoverRate; }
    inline float getMutationRate() const   { return this->mutationRate;  }
    inline int getGenerations() const      { return this->generations;   }
    inline int getHashBudget() const       { return this->hashBudget;    }
    inline void setCrossoverRate(float c)  { this->crossoverRate = c;    }
    inline void setMutationRate(float m)   { this->mutationRate = m;     } 
    inline void setGenerations(int g)      { this->generations = g;      }
    inline void setHashBudget(int b)       { this->hashBudget = b;       }

};

#endif