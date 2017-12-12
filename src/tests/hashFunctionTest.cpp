#define CATCH_CONFIG_MAIN

#include "ea/evolutive/evolutive.hpp"
#include "libs/catch.hpp"

TEST_CASE("Testing Initialization", "[evolutive]") {
    hashwrapper * md5;
    hashwrapper * sha1;
    md5 = new md5wrapper();
    sha1 = new sha1wrapper();
    int dv = 40;

    std::cout << "Testing from 0 to 9" << std::endl;
    for(int i = 0; i < 10; i++) {
        std::cout << "===================================" << std::endl;
        std::string msg = md5->getHashFromString(std::to_string(i));
        std::cout << "msg from md5: " << msg << "size: " << msg.size() << std::endl;
        std::string hash = sha1->getHashFromString(msg);
        std::cout << "hashed msg from sha1 " << hash << " size: " << hash.size() << std::endl;
        hash = hash.substr(0, (hash.size() / dv));
        std::cout << "cutted hash from sha1: " << hash << " size: " << hash.size() << std::endl;
    } 
}