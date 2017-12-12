#ifndef __STATISTICS__
#define __STATISTICS__

#include "ea/evolutive/evolutive.hpp"

namespace Statistics {

    void logExecution(Evolutive * e, const char * src) {
        std::ofstream file;
        file.open(src, std::ios::app);
        file << "----------EXECUTION----------\n";
        file << "Population Size: " << e->population->getPopulationSize() << "\n";
        file << "Generations: " << e->getGenerations() << "\n";
        file << "Crossover Rate: " << e->getCrossoverRate() << "\n";
        file << "Mutation Rate: " << e->getMutationRate() << "\n";
        file << "Hash Budget: " << e->getHashBudget() << "\n";
        file << "Hash Function: ";
        #if HASH_WITH_SHA1
        file << "SHA1 with " << (40 / BIT_DIV) * 4 << " bits. ";
        #else
        file << "MD5 with " << (32 / BIT_DIV) * 4 << " bits.;
        #endif

        file << "\n";
        file << "FINAL POPULATION:\n";

        int individualsWithCollision = 0;
        int collidedM1 = 0;
        int collidedM2 = 0;
        int collidedM3 = 0;
        for(int i = 0; i < e->population->getPopulationSize(); i++) {
            file << (i+1) << " - M1: " << e->population->individuals[i].getM1();
            file << " M2: " << e->population->individuals[i].getM2();
            file << " M3: " << e->population->individuals[i].getM3();
            file << " - Fitness: " << e->population->individuals[i].getFitness();
            file << "\n";

            if(e->population->individuals[i].getFitness() > 0) {
                individualsWithCollision++;
                collidedM1 += e->population->individuals[i].getM1();
                collidedM2 += e->population->individuals[i].getM2();
                collidedM3 += e->population->individuals[i].getM3();
            }
        }
        file << "Average of individuals with Collision:\n";
        if(individualsWithCollision > 0) {
            file << "M1: " << (float)(collidedM1 / individualsWithCollision);
            file << " M2: " << (float)(collidedM2 / individualsWithCollision);
            file << " M3: " << (float)(collidedM3 / individualsWithCollision);
            file << "\n";
        } else {
            file << "No Collisions.\n";
        }
        file.close();
    }

}

#endif