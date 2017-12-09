#define CATCH_CONFIG_MAIN
#include "ea/population/population.hpp"
#include "libs/catch.hpp"

TEST_CASE("Creating a Population", "[population]") {
    Population p(10);
    REQUIRE( p.getPopulationSize() == 10 );
    REQUIRE( p.getInitialized() == false );
}

TEST_CASE ("Changing Population Parameters", "[population]") {
    Population p(10);
    p.setPopulationSize(15);
    p.setInitialized(true);

    REQUIRE( p.getPopulationSize() == 15 );
    REQUIRE( p.getInitialized() == true );
}