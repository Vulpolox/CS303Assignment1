//CS201 || Jack Keys

#include <iostream>
#include "Functions.h"

int main() 
{
  ifstream fin;
  int* array = new int[100];
  int choice, find, currentSize = 100;
  string rep;
  
  fin.open(getValidFileName());
  array = readData(fin);
  fin.close();

  printData(array, currentSize);
  
  while (true)
    {
      choice = getVal("Please choose one of the following:\n---\n1 - find index\n2 - replace\n3 - append\n4 - remove\n5 - quit\n", 1, 5);

      switch(choice)
        {
          case 1:
            find = findIndex(array, currentSize);
            cout << "Found at index: " << find << endl;;
            break;
          case 2:
            rep = replace(array, currentSize);
            cout << "Old and new values respectively: " << rep << endl;
            printData(array, currentSize);
            break;
          case 3:
            array = pushBack(array, currentSize);
            currentSize++;
            printData(array, currentSize);
            break;
          case 4:
            array = remove(array, currentSize);
            currentSize--;
            printData(array, currentSize);
            break;
          case 5:
            exit(0);
        }
      cout << "---" << endl;
    }
}
