#!/bin/bash

RPN="./RPN"

# Test
echo "\n"
echo "------------------------"
echo "✅ Testing valid expressions..."
echo "8 9 * 9 - 9 - 9 - 4 - 1 + : (8 * 9 - 9 - 9 - 9 - 4 + 1 = 42)"
${RPN} "8 9 * 9 - 9 - 9 - 4 - 1 +"

echo "------------------------"
echo "7 7 * 7 - (7 * 7 - 7 = 42)"
${RPN} "7 7 * 7 -"

echo "------------------------"
echo "1 2 * 2 / 2 * 2 4 - + : ((1 * 2) / 2 * 2 + (2 - 4) = 0)"
${RPN} "1 2 * 2 / 2 * 2 4 - +"

echo "------------------------"
echo "5 5 + : (5 + 5 = 10)"
${RPN} "5 5 +"

echo "------------------------"
echo "3 4 * : (3 * 4 = 12)"
${RPN} "3 4 *"

echo "------------------------"
echo "\n"
echo "❌ Testing invalid expressions..."
echo "------------------------"
echo "(1 + 1) (Error: parentheses not allowed)"
${RPN} "(1 + 1)"

echo "------------------------"
echo "1 + 1 (Error: infix notation not allowed)"
${RPN} "1 + 1"

echo "------------------------"
echo "+ (Error: not enough operands)"
${RPN} "+"

echo "------------------------"
echo "1 0 / (Error: division by zero)"
${RPN} "1 0 /"

echo "------------------------"
echo "10 2 + (Error: value out of range)"
${RPN} "10 2 +"
echo "------------------------"

echo "\n"

