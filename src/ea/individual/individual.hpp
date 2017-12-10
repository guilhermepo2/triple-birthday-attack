#ifndef __INDIVIDUAL__
#define __INDIVIDUAL__

#include "libs/dependencies.hpp"

class
Individual {
private:
int m1;
int m2;
int m3;
int fitness;

public:
Individual();
Individual(int, int, int);
inline void setM1(int m1) { this->m1= m1; }
inline void setM2(int m2) { this->m2 = m2; }
inline void setM3(int m3) { this->m3 = m3; }
inline void setFitness(int fit) { this->fitness = fit; }

inline int getM1() const { return this->m1; }
inline int getM2() const { return this->m2; }
inline int getM3() const { return this->m3; }
inline int getFitness() const { return this->fitness; }

};

#endif