#include "catch.hpp"

#include "../src/Instance/instance.h"

SCENARIO("Operations on Instances: ")
{
    GIVEN("An empty Instance, ")
    {
        lasvm::Instance<double> X;
    }
}