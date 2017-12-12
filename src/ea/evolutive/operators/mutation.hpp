#ifndef __MUTATION__
#define __MUTATION__

#include "ea/evolutive/evolutive.hpp"

namespace Operators {
    class Mutation {
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
        virtual void mutate(Individual& individual, std::vector<Individual> population) {
            std::cout << "I'm a virtual mutation method. If you are reading this, you did something wrong." << std::endl;
        }
    };

    // Sort a Random Number from 0 to 2
    // 0 => change M1
    // 1 => change M2
    // 2 => change M3
    // The Mutation will add N to one of them and subtract N from another one
    // N is random from 0 to 10
    class SimpleMutation : public Mutation {
        public:
        void mutate(Individual& individual, std::vector<Individual> population) {
             int toAdd = rand() % 3;
             int toSubtract = rand() % 3;
             while(toAdd == toSubtract) toSubtract = rand() % 3;

            int oldM1 = individual.getM1();
            int oldM2 = individual.getM2();
            int oldM3 = individual.getM3();

             int factor = rand() % (int)(this->hashBudget * 0.1f);
             switch(toAdd) {
                 case 0:
                    individual.setM1(individual.getM1() + factor);
                    break;
                 case 1:
                    individual.setM2(individual.getM2() + factor);
                    break;
                 case 2:
                    individual.setM3(individual.getM3() + factor);
                    break;
             }

             switch(toSubtract) {
                 case 0:
                    individual.setM1(individual.getM1() - factor);
                    break;
                 case 1:
                    individual.setM2(individual.getM2() - factor);
                    break;
                 case 2:
                    individual.setM3(individual.getM3() - factor);
                    break;
             }

             if(individual.getM1() < 0 || individual.getM1() > this->hashBudget ||
                individual.getM2() < 0 || individual.getM2() > this->hashBudget ||
                individual.getM3() < 0 || individual.getM3() > this->hashBudget  ||
                !(this->notRepeated(individual, population))) {
                    individual.setM1(oldM1);
                    individual.setM2(oldM2);
                    individual.setM3(oldM3);
                }
        }
    };
}

#endif