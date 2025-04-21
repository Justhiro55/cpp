#!/bin/bash

echo "✅ Test"
echo "--------------------------"
./PmergeMe 5 3 4 1 2

# Reversed sequence
echo "\n--------------------------"
./PmergeMe 5 4 3 2 1

# Already sorted
echo "\n--------------------------"
./PmergeMe 1 2 3 4 5

# Duplicates
echo "\n--------------------------"
./PmergeMe 3 1 2 3 5 4

# Larger sequence
echo "\n--------------------------"
./PmergeMe 42 15 7 23 56 89 12 34 67 21 44

echo "--------------------------"
echo "\n"
echo "❌ Error cases:"
echo "--------------------------"
./PmergeMe 5 3 -1 4 2

echo "\n--------------------------"
./PmergeMe 5 3 abc 4 2
echo "\n"
