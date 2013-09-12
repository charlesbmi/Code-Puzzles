// File: multiplyexceptself.cpp
// Author: Charles Guan
// Last edit: 2013-09-08
// ---------------------
// Given an longeger list, outputs a second list of equal length corresponding
// to products of all longegers of the first list except the one at that index.
// Input format:
// First line contains N, number of longegers in list
// N lines contain single longeger in list
// Output format:
// New multiply-except-self list

#include <iostream>
#include <vector>

// function prototypes
long VectorProductExceptZeros(std::vector<long> & vec);

// main function

int main()
{
    // read list
    int num_rows = 0;
    scanf("%d", &num_rows);
    std::vector<long> input_list(num_rows);
    int num_zeros = 0;
    for (int i = 0; i < num_rows; i++)
    {
        scanf("%ld", &input_list[i]);
        if (input_list[i] == 0) num_zeros++;
    }
    // compute new list
    long product = VectorProductExceptZeros(input_list);
    if (num_zeros == 0)
    {
        // divide product by element at that polong
        for (int i = 0; i < num_rows; i++) printf("%ld\n", product / input_list[i]);
    }
    else if (num_zeros == 1)
    {
        for (int i = 0; i < num_rows; i++)
        {
            if (input_list[i] == 0) printf("%ld\n", product);
            else printf("%ld\n", 0);
        }
    }
    else
    {
        for (int i = 0; i < num_rows; i++) printf("%ld\n", 0); 
    }
    return 0;
}

// @desc    Computes the product of the non-zero elements of a vector
// @param   vec     vector of elements to multiply
// @return  product of nonzero elements
long VectorProductExceptZeros(std::vector<long> & vec)
{
    long product = 1;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] != 0) product *= vec[i];
    }
    return product;
}
