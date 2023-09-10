//CS201 || Jack Keys

#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include <iomanip>
#include <limits.h>

using namespace std;

int getVal(string message, int lower, int upper);
//pre  -- displays message to user (asking for a value)
//post -- if the value is between lower and upper, return the value.  If not, repeat until a valid value is gotten

string getValidFileName();
// pre  -- prompts user to enter a file name (string); continues until the file name is valid
// post -- returns a valid file name

int* readData(ifstream& fin);
// pre  -- takes a text file containing a comma delimited list of 100 integers with 10 integers per line (see InputSample.txt)
// post -- returns an array filled with the integers read from the file

void printData(int* data, int size);
// pre  -- takes an array and its size
// post -- outputs the contents of the array to the console



// required functions
//---------------------------------------//

int findIndex(int* arr, int size);
// pre  -- takes an array and its size; asks the user for an integer to search the array for
// post -- if the integer is found in the array, it will return its index; if not, it will return -1

string replace(int* arr, int size);
// pre  -- takes an array and its size; asks the user for an index of the array and a value to replace the current one at that index
// post -- replaces the existing integer at the specified index with the specified integer; returns both the old and the new value in a string

int* pushBack(int* arr, int size);
// pre  -- takes an array and its size; asks the user for an integer to append to the end of the array
// post -- creates and returns a copy of the array with its size +1 and the specified integer appended to the end

int* remove(int* arr, int size);
// pre  -- takes an array and its size; asks the user for an index to remove from the array
// post -- replaces the integer at the specified index with a 0


// note to grader: all user input and its respective error handling is done in the getVal() function instead of in each function individually to reduce redundancy
