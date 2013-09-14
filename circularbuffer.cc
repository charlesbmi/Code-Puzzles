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
int main() {
    int buffer_size = 0;
    scanf("%d", &buffer_size);
    // Make buffer 1 element larger to allow modular arithmetic
    int capacity = buffer_size + 1;
    std::string *buffer = new std::string[capacity];
     

    int start = 0;

    std::string line;
    while (true)
    {
        scanf("%s", &line);
        switch (line[0]) {
            case 'A':
                append_to_buffer();
                break;
            case 'R':
                remove_from_buffer();
                break;
            case 'L':
                list_buffer();
                break;
            default:
                delete buffer;
                return 0;
    }
}

// Lists the contents of a buffer, from indices start up to and including end,
// wrapping around to the front if necessary.
void list_buffer(std::string buffer[], int capacity, int start, int end) {
    for (int i = start; i != end; i = (i + 1) % capacity) {
        printf("%s", buffer[i]);
    }
}

// Class: CircularBuffer
// ---------------------
// This class (TODO fill in)

class CircularBuffer {

public:

    CircularBuffer(int capacity);

    ~CircularBuffer();

    void append(std::string value);

    void remove(int num_values = 1);

    void list();

    void clear();

// Private section

// Everything below is part of the implementation

// Implementation notes: CircularBuffer data structure
// ---------------------------------------------------
//

private:

    std::string *buffer;
    int count;
    int capacity;
    int start;
    int end;

};

// Implementation notes:

CircularBuffer::CircularBuffer(int capacity) {
    this->capacity = capacity;
    buffer = new std::string[capacity];
    clear();
}

CircularBuffer::~CircularBuffer() {
    delete buffer;
}

void CircularBuffer::append(std::string value) {
    if (count == capacity) {
    } else {
        count++;
    }
    
}

void CircularBuffer::remove(int num_values = 1) {
    // TODO: put an error message on throw
    if (num_values > count) throw;
    start = (start + num_values) % capacity;
    count -= num_values;
}

void CircularBuffer::list() {
    for (int i = 0; i < count; i++) {
        printf("%s", buffer[(start + i) % capacity]);
    }
}

void CircularBuffer::clear() {
    count = 0;
    start = 0;
    end = 0;
}
