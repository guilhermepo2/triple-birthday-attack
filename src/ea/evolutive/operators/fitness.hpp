#ifndef __FITNESS__
#define __FITNESS__

#include "ea/evolutive/evolutive.hpp"

namespace Operators {
    class FitnessFunction {
        public:
        virtual void calculateFitness(Individual& individual) {
            std::cout << "I'm a virtual function. If you are reading this you did something wrong!" << std::endl;
        }
    };

    class BruteForceCollisionCheck : public FitnessFunction {
        public:
        virtual void calculateFitness(Individual& individual) {
            hashwrapper * md5 = new md5wrapper();
            hashwrapper * sha1 = new sha1wrapper();

            // Searching for triple collisions (not optimized) 

            int m1 = individual.getM1(),
                m2 = individual.getM2(),
                m3 = individual.getM3(),
                collisions = 0;

            std::vector<std::string> stored_hashes_first_round;
            std::vector<std::string> stored_hashes_second_round;
            for(int i = 0; i < m1; i++) {
                stored_hashes_first_round.push_back(sha1->getHashFromString(md5->getHashFromString(std::to_string(i))));
            }

            for(int i = m1; i < (m1+m2); i++) {
                bool isOnFirstRound = false;
                for(int j = 0; j < stored_hashes_first_round.size(); j++) {
                    if(sha1->getHashFromString(md5->getHashFromString(std::to_string(i))) == stored_hashes_first_round[j]) {
                        isOnFirstRound = true;
                    }
                }
                if(isOnFirstRound) stored_hashes_second_round.push_back(sha1->getHashFromString(md5->getHashFromString(std::to_string(i))));
            }

            for(int i = (m1+m2); i < (m1+m2+m3); i++) {
                bool isOnSecondRound = false;
                for(int j = 0; j < stored_hashes_second_round.size(); j++) {
                    if(sha1->getHashFromString(md5->getHashFromString(std::to_string(i))) == stored_hashes_second_round[j]) {
                        isOnSecondRound = true;
                    }
                }
                if (isOnSecondRound) collisions++;
            }

            individual.setFitness(collisions);

            delete md5;
            delete sha1;
        }
    };
}

#endif