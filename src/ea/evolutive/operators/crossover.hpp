#ifndef __CROSSOVER__
#define __CROSSOVER__

#include "ea/evolutive/evolutive.hpp"

namespace Operators {
    class Crossover {
        protected:
        int hashBudget;

        bool notRepeated(Individual individual, std::vector<Individual> population) {
            for(int i = 0; i < population.size(); i++) {
                if(individual.getM1() == population[i].getM1() &&
                   individual.getM2() == population[i].getM2() &&
                   individual.getM3() == population[i].getM3()) {
                    return false;
                }
            }
            return true;
        } 

        public:
        inline void setHashBudget(int b) { this->hashBudget = b; }
        virtual void crossover(Individual firstParent, Individual secondParent, std::vector<Individual>& population) {
            std::cout << "I'm a virtual crossover method. If you are reading this, you did something wrong." << std::endl;
        }
    };

    class ThreeChildrenCrossover : public Crossover {
        public:
        void crossover(Individual firstParent, Individual secondParent, std::vector<Individual>& population) {
            Individual firstChild;
            Individual secondChild;
            Individual thirdChild;

            // First Child  => M1 from Parent 1, M2 from Parent 2
            firstChild.setM1(firstParent.getM1());
            firstChild.setM2(secondParent.getM2());
            firstChild.setM3((this->hashBudget - (firstChild.getM1() + firstChild.getM2())));
            // Second Child => M2 from Parent 1, M3 from Parent 2
            secondChild.setM2(firstParent.getM2());
            secondChild.setM3(secondParent.getM3());
            secondChild.setM1((this->hashBudget - (secondChild.getM2() + secondChild.getM3())));
            // Third Child  => M3 from parent 1, M1 from Parent 2
            thirdChild.setM3(firstParent.getM3());
            thirdChild.setM1(secondParent.getM1());
            thirdChild.setM2((this->hashBudget - (thirdChild.getM3() + thirdChild.getM1())));

            if(firstChild.getM1() > 0 && firstChild.getM2() > 0 && firstChild.getM3() > 0 && this->notRepeated(firstChild, population)) population.push_back(firstChild);
            if(secondChild.getM1() > 0 && secondChild.getM2() > 0 && secondChild.getM3() > 0 && this->notRepeated(secondChild, population))  population.push_back(secondChild);
            if(thirdChild.getM1() > 0 && thirdChild.getM2() > 0 && thirdChild.getM3() > 0 && this->notRepeated(thirdChild, population))  population.push_back(thirdChild);
        }
    };
}

#endif