#ifndef __INITIALIZATION__
#define __INITIALIZATION__

#include <iostream>
#include "ea/evolutive/evolutive.hpp"

namespace Operators {
    class PopulationGeneration {
        public:
        virtual void generatePopulation(int size, std::vector<Individual>& population) {
            std::cout << "I'm a virtual function. If you are reading this you did something wrong!" << std::endl;
        }
    };

    class GenerateAllRandom : public PopulationGeneration {
        private:
        int maxHash;
        public:
        inline void setMaxHash(int m) { this->maxHash = m; }

        void generatePopulation(int size, std::vector<Individual>& population) {
            if(population.size() != 0) {
                population.clear();
            }

            srand( time(NULL) );
            for(int i = 0; i < size; i++) {
                int m1 = rand() % this->maxHash;
                int m2 = rand() % (this->maxHash - m1);
                int m3 = (this->maxHash - m1 - m2);
                population.push_back(Individual(m1, m2, m3));
            }
        }
    };
}

#endif