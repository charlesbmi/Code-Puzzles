// File: circularbuffer.cc
// Author: Charles Guan
// Last Edit: 2013-09-11
// ---------------------
// Implements a circular buffer.
//
// Input:
//      The first line contains the size 0 <= N <= 10000 of the buffer.
//      The rest of the lines support four commands or their corresponding info:
//      A n - Append the next n lines to the buffer, replaces older entries if
//          buffer is full
//      R n - Remove first n elements of the buffer
//      L - list elements in order
//      Q - Quit
//
// Output:
//      Print the buffer according to matching "L"-commands.

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

// function prototypes
void list_buffer(std::vector<std::string> & buffer, int start, int end);

// main function
int main()
{
    int capacity = 0;
    scanf("%d", &capacity);
    std::vector<std::string> buffer(capacity);
    int start = 0;

    std::string line;
    while (true)
    {
        scanf("%s", &line);
        if (line[0] == 'Q') break;
        if (line[0] == 'L') list_buffer(buffer, start, end);
    }
    return 0;
}

// Lists the contents of a buffer, from indices start up to and including end,
// wrapping around to the front if necessary.
void list_buffer(std::vector<std::string> & buffer, int start, int end)
{
    int capacity = buffer.size();
    // TODO: make buffer 1 size larger? or use an isFull case? I think 1 size larger might be better.
    for (int i = start; 
}
