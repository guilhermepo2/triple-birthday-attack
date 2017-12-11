#ifndef __SORTING__
#define __SORTING__

#include "ea/evolutive/evolutive.hpp"

namespace Operators {
    class Sorting {
        public:
        virtual void sort(std::vector<Individual>& population) {
            std::cout << "I'm a virtual sorting method. If you are reading this, you did something wrong." << std::endl;
        }
    };

    class BubbleSort : public Sorting {
        public:
        void sort(std::vector<Individual>& population) {
            Individual aux;
            for(int i = 0; i < population.size(); i++) {
                for(int j = 0; j < population.size(); j++) {
                    if(population[i].getFitness() > population[j].getFitness()) {
                        // aux gets i
                        aux.setM1(population[i].getM1());
                        aux.setM2(population[i].getM2());
                        aux.setM3(population[i].getM3());
                        aux.setFitness(population[i].getFitness());
                        // i gets j
                        population[i].setM1(population[j].getM1());
                        population[i].setM2(population[j].getM2());
                        population[i].setM3(population[j].getM3());
                        population[i].setFitness(population[j].getFitness());
                        // j gets aux
                        population[j].setM1(aux.getM1());
                        population[j].setM2(aux.getM2());
                        population[j].setM3(aux.getM3());
                        population[j].setFitness(aux.getFitness());
                    }
                }
            }
        }
    };
}

#endif