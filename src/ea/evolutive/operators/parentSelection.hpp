#ifndef __PARENT_SELECTION__
#define __PARENT_SELECTION__

#include "ea/evolutive/evolutive.hpp"

namespace Operators {
    class ParentSelection {
        public:
        virtual int selectParent(int populationSize, std::vector<Individual>& population) {
            std::cout << "I'm a virtual Parent Selection method. If you are reading this, you did something wrong." << std::endl;

            return -1;
        }
    };

    class RandomParentSelection : public ParentSelection {
        public:
        int selectParent(int populationSize, std::vector<Individual>& population) {
            return (rand() % populationSize);
        }
    };
}

#endif