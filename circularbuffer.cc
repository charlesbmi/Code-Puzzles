// File: circularbuffer.cc
// Author: Charles Guan
// Last Edit: 2013-09-15
// ---------------------
// Implements the CircularBuffer class, a size-immutable FIFO data structure
// that overwrites old values when full. It then applies it to solving a coding
// challenge. Normally, declaration and implementation would be separate, but
// they have been written in the same file for the coding challenge.
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

// Class: CircularBuffer
// ---------------------
// This class implements a size-immutable circular buffer, in which elements
// are accessed in FIFO (first-in-first-out) order. Thus, elements are added
// and removed from the data structure from opposite ends. When the buffer
// becomes full, new elements overwrite the oldest elements.

class CircularBuffer {

public:

// Constructor: CircularBuffer(int capacity)
// ------------------------------------------
// Initializes a new empty CircularBuffer of the given fixed capacity.

    CircularBuffer(int capacity);

// Destructor: ~CircularBuffer()
// -----------------------------
// Frees heap storage associated with the buffer.

    ~CircularBuffer();

// Method: append
// --------------
// (Overloaded) The first version adds value to the end of the circular buffer.
// The second version reads a line from the std::cin and passes that value
// to the first append(value) for the given num_values times.

    void append(std::string value);
    void append(int num_values = 1);

// Method: remove
// --------------
// Removes the first (by chronology of insertion) num_values of the circular
// buffer.

    void remove(int num_values = 1);

// Method: list
// ------------
// Prints the values of the circular buffer in in chronological order by
// insertion time. Each value is separated by new-lines.

    void list();

// Method: clear
// -------------
// Clears the contents of the CircularBuffer, so it can be used as if newly
// declared.

    void clear();

// Private section
// ---------------
// Everything below until the main function is part of the implementation and
// should not be of interest to the client.

private:

// Instance variables
    std::string *buffer;
    int count;
    int capacity;
    int start;
    int end;

};

// Implementation notes: CircularBuffer data structure
// ---------------------------------------------------
// The CircularBuffer is implemented using an array to model the buffer. In
// order to allow for circularity while staying memory-efficient, the
// implementation keeps track of the start and end indices and uses modular
// arithmetic. Each time an element is removed, the head index moves up by 1 
// (modulo capacity). Each time an element is added, the tail index moves up
// by 1 (modulo capacity), and if the buffer is already full, the head index
// will increase by 1 because an old value is over-written. It is also
// necessary to keep track of the count, the number of values in the circular
// buffer, because modular arithmetic makes it impossible to distinguish
// between an empty and a full buffer using only start and end indices.

// Implementation notes: CircularBuffer constructor
// ------------------------------------------------
// Allocates an array with the given capacity to store the buffer elements.
CircularBuffer::CircularBuffer(int capacity) {
    this->capacity = capacity;
    buffer = new std::string[capacity];
    clear();
}

// Implementation notes: CircularBuffer destructor
// -----------------------------------------------
// De-allocates memory on heap used to store elements.
CircularBuffer::~CircularBuffer() {
    delete[] buffer;
}

// Implementation notes: append
// ----------------------------
// (Overloaded) Adds the value to the end of the circularbuffer and increments
// the end index. If the circular buffer is already full, it overwrites the
// start value and increments the start index.
void CircularBuffer::append(std::string value) {
    buffer[end] = value;
    end = (end + 1) % capacity;
    if (count == capacity) {
        start = (start + 1) % capacity;
    } else {
        count++;
    }
}

// Implementation notes: append
// ----------------------------
// (Overloaded) Reads a line from the input and passes it to the first append
// method. Repeats num_values times.
void CircularBuffer::append(int num_values) {
    std::string value;
    for (int i = 0; i < num_values; i++) {
        std::getline(std::cin, value);
        append(value);
    }
}

// Implementation notes: remove
// ----------------------------
// This method must first check whether there are enough elements to remove.
void CircularBuffer::remove(int num_values) {
    if (num_values > count) throw std::runtime_error("Attempted to remove " +
            "more elements than CircularBuffer contains.");
    start = (start + num_values) % capacity;
    count -= num_values;
}

void CircularBuffer::list() {
    for (int i = 0; i < count; i++) {
        std::cout << buffer[(start + i) % capacity] << std::endl;
    }
}

// Implementation notes
// --------------------
// Resets the object's counter and index variables. Does not modify the actual
// array storing values
void CircularBuffer::clear() {
    count = start = end = 0;
}

// End of CircularBuffer Implementation

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

