// File: multiplyexceptself.cpp
// Author: Charles Guan
// Last edit: 2013-09-08
// ---------------------
// Given an integer list, outputs a second list of equal length corresponding
// to products of all integers of the first list except the one at that index.
// Input format:
// First line contains N, number of integers in list
// N lines contain single integer in list
// Output format:
// New multiply-except-self list

#include <iostream>
#include <vector>

// function prototypes
int vectorProduct(std::vector<int> & vec);

// main function

int main()
{
    // read list
    int N, i;
    scanf("%d", &N);
    std::vector<int> inputList(N);
    for (i = 0; i < N; i++) std::cin >> inputList[i];
    // compute new list by dividing vector product by each int in list
    int product = vectorProduct(inputList);
    for (i = 0; i < N; i++) std::cout << (product / inputList[i]) << std::endl;
    return 0;
}

// @desc    Computes the product of the elements in the vector
// @param   vec     vector of elements to multiply
// @return  product of elements
int vectorProduct(std::vector<int> & vec)
{
    int product = 1;
    for (int i = 0; i < vec.size(); i++) product *= vec[i];
    return product;
}
