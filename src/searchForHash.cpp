#include <iostream>
#include <vector>
#include "libs/hash2lib/src/hashlibpp.h"

void 
solveEverything(int m1, int m2, int m3) {
    // Creating our hash wrappers using hashlib++
    hashwrapper * myMD5Wrapper = new md5wrapper();
    hashwrapper * mySHA1Wrapper = new sha1wrapper();

    // Searching for triple collisions
    std::vector<std::string> stored_hashes_first_round;
    std::vector<std::string> stored_hashes_second_round;
    int collisions = 0;
    for(int i = 0; i < m1; i++) { // 0 to 332
        stored_hashes_first_round.push_back(mySHA1Wrapper->getHashFromString(myMD5Wrapper->getHashFromString(std::to_string(i))));
    }
    for(int i = m1; i < (m1+m2); i++) { // 333 to 665
        bool isOnFirstRound = false;
        for(int j = 0; j < stored_hashes_first_round.size(); j++) {
            if(mySHA1Wrapper->getHashFromString(std::to_string(i)) == stored_hashes_first_round[j]) {
                isOnFirstRound = true;
            }
        }
        if(isOnFirstRound) stored_hashes_second_round.push_back(mySHA1Wrapper->getHashFromString(std::to_string(i)));
    }

    for(int i = (m1+m2); i < (m1+m2+m3); i++) { // 666 to 1000
        bool isOnSecondRound = false;
        for(int j = 0; j < stored_hashes_second_round.size(); j++) {
            if(mySHA1Wrapper->getHashFromString(std::to_string(i)) == stored_hashes_second_round[j]) {
                isOnSecondRound = true;
            }
        }
        if (isOnSecondRound) collisions++;
    }

    std::cout << "M1: " << m1 << " M2: " << m2 << " M3: " << m3 << " - Collisions: " << collisions << " ." << std::endl;

    delete mySHA1Wrapper;
    delete myMD5Wrapper;
}

int 
main() {
    solveEverything(3333, 3333, 3334);
    return 0;
}