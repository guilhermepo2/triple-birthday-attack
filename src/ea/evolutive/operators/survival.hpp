#ifndef __SURVIVAL__
#define __SURVIVAL__

#include "ea/evolutive/evolutive.hpp"

namespace Operators {
    class Survival {
        public:
        virtual void survival(std::vector<Individual>& population) {
            std::cout << "I'm a virtual survival method. If you are reading this, you did something wrong." << std::endl;
        }
    };

    class Elitism : public Survival {
        private:
        int originalPopulationSize;
        float survivalRate;

        public:
        inline void setOriginalPopulationSize(int size) { this->originalPopulationSize = size; }
        inline void setSurvivalRate(float rate) { this->survivalRate = rate; }
        void survival(std::vector<Individual>& population) {
            
            int maxPopulationSize = this->originalPopulationSize + std::ceil(this->originalPopulationSize * (1.0f - this->survivalRate));
            while(population.size() > maxPopulationSize) population.pop_back();
            int offset = this->originalPopulationSize - 1;
            while(population.size() > this->originalPopulationSize) {
                population.erase(population.begin() + offset);
                offset--;
            }
        }
    };
}

#endif