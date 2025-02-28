#!/bin/bash

make re

echo "=== Basic Tests ==="
./ScalarConverter 0
echo "\n --- \n"
./ScalarConverter 42
echo "\n --- \n"
./ScalarConverter -42
echo "\n --- \n"
./ScalarConverter 0.0f
echo "\n --- \n"
./ScalarConverter 4.2f
echo "\n --- \n"
./ScalarConverter 4.2
echo "\n --- \n"
./ScalarConverter "'a'"
echo "\n --- \n"
./ScalarConverter "2."
echo "\n --- \n"

echo "=== Special Values ==="
./ScalarConverter +inff
echo "\n --- \n"
./ScalarConverter -inff
echo "\n --- \n"
./ScalarConverter nanf
echo "\n --- \n"
./ScalarConverter +inf
echo "\n --- \n"
./ScalarConverter -inf
echo "\n --- \n"
./ScalarConverter nan
echo "\n --- \n"

echo "=== Error Cases ==="
./ScalarConverter hello
echo "\n --- \n"
./ScalarConverter ""
echo "\n --- \n"
