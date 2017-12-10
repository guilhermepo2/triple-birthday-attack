#include "individual.hpp"

Individual::Individual() {
    this->m1 = 0;
    this->m2 = 0;
    this->m3 = 0;
    this->fitness = 0;
}

Individual::Individual(int m1, int m2, int m3) {
    this->m1 = m1;
    this->m2 = m2;
    this->m3 = m3;
    this->fitness = 0;
}