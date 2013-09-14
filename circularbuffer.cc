// File: circularbuffer.cc
// Author: Charles Guan
// Last Edit: 2013-09-14
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
#include <cstdlib>

// class prototypes
class CircularBuffer;
// Class: CircularBuffer
// ---------------------
// This class (TODO fill in)

class CircularBuffer {

public:

    CircularBuffer(int capacity);

    ~CircularBuffer();

    void append(std::string value);
    void append(int num_values = 1);

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
    delete[] buffer;
}

void CircularBuffer::append(std::string value) {
    buffer[end] = value;
    end = (end + 1) % capacity;
    if (count == capacity) {
        start = (start + 1) % capacity;
    } else {
        count++;
    }
}

void CircularBuffer::append(int num_values) {
    std::string value;
    for (int i = 0; i < num_values; i++) {
        std::getline(std::cin, value);
        append(value);
    }
}

void CircularBuffer::remove(int num_values) {
    // TODO: put an error message on throw
    if (num_values > count) throw;
    start = (start + num_values) % capacity;
    count -= num_values;
}

void CircularBuffer::list() {
    for (int i = 0; i < count; i++) {
        std::cout << buffer[(start + i) % capacity] << std::endl;
    }
}

void CircularBuffer::clear() {
    count = start = end = 0;
}

// main function
int main() {
    // Use getline instead of normal std::cin >> buffer_size to strip new-line
    std::string buffer_size_str;
    std::getline(std::cin, buffer_size_str);
    int buffer_size = atoi(buffer_size_str.c_str());
    CircularBuffer c_buffer(buffer_size); 
    std::string command;
    while (true)
    {
        std::getline(std::cin, command);
        // number of values to append or remove
        std::string num_values_str = command.substr(1);
        switch (command[0]) {
            case 'A':
                c_buffer.append(atoi(num_values_str.c_str()));
                break;
            case 'R':
                c_buffer.remove(atoi(num_values_str.c_str()));
                break;
            case 'L':
                c_buffer.list();
                break;
            default:
                return 0;
        }
    }
}

