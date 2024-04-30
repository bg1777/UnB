#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "romanos.hpp"

TEST_CASE("Numeros romanos - algarismos únicos", "[romanos]") {
    REQUIRE(romanos_para_decimal("I") == 1);
    REQUIRE(romanos_para_decimal("V") == 5);
    REQUIRE(romanos_para_decimal("X") == 10);
    REQUIRE(romanos_para_decimal("L") == 50);
    REQUIRE(romanos_para_decimal("C") == 100);
    REQUIRE(romanos_para_decimal("D") == 500);
    REQUIRE(romanos_para_decimal("M") == 1000);
}

TEST_CASE("Numeros romanos - Números compostos", "[romanos]") {
    REQUIRE(romanos_para_decimal("II") == 2);
    REQUIRE(romanos_para_decimal("III") == 3);
    REQUIRE(romanos_para_decimal("CCXXXI") == 231);
    REQUIRE(romanos_para_decimal("LXV") == 65);
    REQUIRE(romanos_para_decimal("XXX") == 30);
    REQUIRE(romanos_para_decimal("MCDLXI") == 1461);
    REQUIRE(romanos_para_decimal("IV") == 4);
    REQUIRE(romanos_para_decimal("CDXXXVI") == 436);
    REQUIRE(romanos_para_decimal("XIX") == 19);
}

TEST_CASE("Numeros romanos - algarismos inválidos", "[romanos]") {
    REQUIRE(romanos_para_decimal("G") == -1);
    REQUIRE(romanos_para_decimal("i") == -1);
    REQUIRE(romanos_para_decimal("VIB") == -1);
    REQUIRE(romanos_para_decimal("") == -1);
    REQUIRE(romanos_para_decimal(" ") == -1);
    REQUIRE(romanos_para_decimal("RENAULT KWID") == -1);
    REQUIRE(romanos_para_decimal("XM") == -1);
    REQUIRE(romanos_para_decimal("XXC") == -1);
    REQUIRE(romanos_para_decimal("IXIX") == -1);
    REQUIRE(romanos_para_decimal("IIII") == -1);
    REQUIRE(romanos_para_decimal("XXXLL") == -1);
    REQUIRE(romanos_para_decimal("IM") == -1);
    REQUIRE(romanos_para_decimal("IVXXXXXXXXXXXXXXX") == -1);
    REQUIRE(romanos_para_decimal("CCXXXIXXXLLL") == -1);
    REQUIRE(romanos_para_decimal("XIXII") == -1);
    REQUIRE(romanos_para_decimal("ILIL") == -1);
    REQUIRE(romanos_para_decimal("XIXI") == -1);
}
