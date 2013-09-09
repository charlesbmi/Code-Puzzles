// File: topK.cpp
// Author: Charles Guan
// Last edit: 2013-09-08
// ---------------------
// Finds the top K integers of a given list
// Input format: 
// First line contains N , number of integers in list.
// N lines following, each contianing one integer
// Output format:
// Top K elements of list
// Note: In retrospect, a solution without a priority queue or with the Python
// pqueue would have been much cleaner.

#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

// constants
const int K = 4;

// function prototypes

// main function

int main()
{
    std::priority_queue<int> topK;

    int N, temp;
    scanf("%d", &N);
    int i = 0;
    for (; i < K; i++)
    {
        scanf("%d", &temp);
        // Use negative because c++ pqueue pops largest first
        topK.push(-temp);
    }
    for (; i < N; i++)
    {
        scanf("%d", &temp);
        topK.push(-temp);
        topK.pop();
    }
    // Reverse pqueue order to get largest first
    std::vector<int> reverser(K);
    for (i = 0; i < K; i++)
    {
       temp = topK.top();
       topK.pop();
       reverser[i] = -temp;
    }
    for (i = K-1; i >= 0; i--) printf("%d\n", reverser[i]);
    return 0;
}

