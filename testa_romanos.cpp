/*Copyright 2021 Maria Eduarda Alves de Sousa*/
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "romanos.hpp"

TEST_CASE("verifica se tem numero repetido mais de 3 vezes"){
    REQUIRE(transformar("IIII") == -1);
    REQUIRE(transformar("XXXX") == -1);
    REQUIRE(transformar("CCCC") == -1);
    REQUIRE(transformar("VVVVV") == -1);
    REQUIRE(transformar("DDDDDX") == -1);
    REQUIRE(transformar("MMMMMXI") == -1);
}

TEST_CASE("verifica se tem I antes de D ou M"){
    REQUIRE(transformar("ID") == -1);
    REQUIRE(transformar("IM") == -1);
}

TEST_CASE("verifica se tem VV,LL e DD seguidos"){
    REQUIRE(transformar("VV") == -1);
    REQUIRE(transformar("LL") == -1);
    REQUIRE(transformar("DD") == -1);
}

TEST_CASE("verifica se e maior que 3000"){
    REQUIRE(transformar("MMMDD") == -1);
}

TEST_CASE("testes simples"){
    REQUIRE(transformar("I") == 1);
    REQUIRE(transformar("V") == 5);
    REQUIRE(transformar("X") == 10);
    REQUIRE(transformar("L") == 50);
    REQUIRE(transformar("C") == 100);
    REQUIRE(transformar("D") == 500);
    REQUIRE(transformar("M") == 1000);
}

TEST_CASE("testes aleatorios"){
    REQUIRE(transformar("CIV") == 104);
    REQUIRE(transformar("DCXL") == 640);
    REQUIRE(transformar("CM") == 900);
    REQUIRE(transformar("MLXXX") == 1080);
    REQUIRE(transformar("MCLXXXVIII") == 1188);
    REQUIRE(transformar("MCCCXX") == 1320);
    REQUIRE(transformar("MMCCCVII") == 2307);
    REQUIRE(transformar("MMDLX") == 2560);
    REQUIRE(transformar("MMCDXC") == 2490);
    REQUIRE(transformar("MMDCCLXXXI") == 2781);
    REQUIRE(transformar("MMM") == 3000);    
    REQUIRE(transformar("MMCML") == 2950);  
}






