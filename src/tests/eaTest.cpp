#define CATCH_CONFIG_MAIN
#include "ea/evolutive/evolutive.hpp"
#include "libs/catch.hpp"

TEST_CASE("Testing Initialization", "[evolutive]") {
    Evolutive e("config/initializationTest.json");

    REQUIRE( e.population->getPopulationSize() == 10 );
    REQUIRE( e.getCrossoverRate() == 0.8f );
    REQUIRE( e.getMutationRate() == 0.05f );
    REQUIRE( e.getGenerations() == 10 );
}