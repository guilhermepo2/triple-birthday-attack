#define CATCH_CONFIG_MAIN
#include "ea/individual/individual.hpp"
#include "libs/catch.hpp"

TEST_CASE("Creating Individual without parameters", "[individual]") {
    Individual i;

    REQUIRE( i.getM1() == 0 );
    REQUIRE( i.getM2() == 0 );
    REQUIRE( i.getM3() == 0 );
}

TEST_CASE("Creating and initializing individual", "[individual]") {
    Individual i(2,5,7);

    REQUIRE( i.getM1() == 2 );
    REQUIRE( i.getM2() == 5 );
    REQUIRE( i.getM3() == 7 );
}

TEST_CASE("Changing Individual Values", "[individual]") {
    Individual i(2,5,7);
    i.setM1(5);
    i.setM2(11);
    i.setM3(15);

    REQUIRE( i.getM1() == 5 );
    REQUIRE( i.getM2() == 11 );
    REQUIRE( i.getM3() == 15 );
}