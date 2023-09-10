#include "Functions.h"

int getVal(string message, int lower, int upper)
{
  string input;
  int out;

  while (true)
    {
      try
        { 
          cout << message << "\n   >>>";
          cin >> input;
  
          out = stoi(input);
  
          if (out > upper || out < lower) //if the input is out of range given by lower and upper
          {
            throw runtime_error("Error in input: input is outside of the valid range. Try again");
          }

          return out;
        }
      catch (runtime_error& err)
        {
          cerr << err.what() << endl << "---" << endl << endl;
          continue;
        }
      catch (invalid_argument& err) //is exectued if the user entered a non-integer
        {
          cerr << "Error in input; be sure to enter an integer: " << err.what() << ".  Try again" << endl << "---" << endl << endl;
          continue;
        }

      catch (...)
        {
          cerr << "Unknown error in input.  Try again" << endl << "---" << endl << endl;
          continue;
        }
    }
}

string getValidFileName()
{
  ifstream testFin;
  string testFName;
  
  while (true)
    {
      //prompt the user for a file name and attempt to open it
      cout << "Please enter a valid file name\n   >>>";
      cin >> testFName;
      testFin.open(testFName);

      //if the file doesn't exist, notify the user and repeat
      if (!testFin.is_open())
      {
        cout << "File not found, try again" << endl << "---" << endl << endl;
        continue;
      }

      //if the file exists, return the file name
      return testFName;
    }
}

int* readData(ifstream& fin)
{
  istringstream sin;
  string currentLine;
  string elementToAdd;
  int* out = new int[100];

  try
    {
      for (unsigned int i = 0 ; i < 100 ; i += 10) //each iteration of the outer loop adds 10 elements to the array
        {
          
          getline(fin, currentLine); //store the current line of the file into currentLine
          sin.str(currentLine); //store currentLine into string stream buffer

          //add the 10 elements from the string stream buffer to the array
          for (unsigned int j = 0 ; j < 10 ; j++)
            {
              getline(sin, elementToAdd, ','); //store the next comma delimited value into elementToAdd

              //validate that elementToAdd isn't empty
              if (elementToAdd.empty())
              {
                throw runtime_error("Tried to add an empty string to the array.  Make sure the input file is formatted correctly");
              }
              
              //validate that the elementToAdd is numeric
              for (auto character : elementToAdd)
                {
                  if (!isdigit(character))
                  {
                    throw runtime_error("Tried to add a non-numerical value to the array.  Make sure the input file is formatted correctly");
                  }
                }
              
              
              out[i+j] = stoi(elementToAdd); //assign elementToAdd to the current index of the array 
            }
        }
    }

  catch(runtime_error& err)
    {
      cerr << err.what() << endl;
      exit(1);
    }

  catch(...)
    {
      cerr << "An unknown error occured.  Make sure the input file is formatted correctly" << endl;
      exit(1);
    }

  return out;

}

void printData(int* data, int size)
{
  cout << "Current Array:" << endl;
  cout << "-==========-" << endl;
  for (unsigned int i = 0 ; i < size ; i++)
    {
      cout << left << setw(2) << *data << " "; //print out the element

      //create a newline every 10 entries
      if ((i+1) % 10 == 0)
      {
        cout << endl;
      }

      data++;
    }
  cout << endl;
  cout << "-==========-" << endl;
}

int findIndex(int* arr, int size)
{
  int valueToFind = getVal("Enter an integer to find in the array", INT_MIN, INT_MAX); //get a valid integer from the user

  //compare each integer in the array to the one given by the user
  for (unsigned int i = 0 ; i < size ; i++)
    {
      //if the integer is found, return the index
      if (arr[i] == valueToFind)
      {
         return i; 
      }
    }

  return -1; //if the integer is not found, return -1
}

string replace(int* arr, int size)
{
  ostringstream sout;
  int index = getVal("Enter a valid index in the array", 0, size-1); //get a valid index from the user
  int valueToReplace = getVal("Enter an integer to be replaced at that index", INT_MIN, INT_MAX); //get a valid integer from the user
  int oldValue = arr[index]; //store the old value to return

  arr[index] = valueToReplace; //replace the integer at the index

  sout << oldValue << " " << valueToReplace; //store the old and the replaced value in a stringstream buffer
  return sout.str(); //return the string containing the old and new values
}

int* pushBack(int* arr, int size)
{
  int toAdd = getVal("Enter an integer to append to the array", INT_MIN, INT_MAX); //get a valid integer to add to the array from the user
  int* out = new int[size+1];

  for (unsigned int i = 0 ; i < size ; i++)
    {
      out[i] = arr[i]; //copy each element from the input array to the output array
    }
  
  out[size] = toAdd; //append the specified value to the end of the output array
  delete[] arr; //free up the memory
  
  return out;
}

int* remove(int* arr, int size)
{
  int indexToRemove = getVal("Enter an index to remove from the array", 0, size-1); //get a valid index from the user
  int* out = new int[size-1];
  bool reachedRemoveIndex = false; //a boolean variable to mark when the index has been reached

  for (unsigned int i = 0 ; i < size-1 ; i++)
    {
      //if the specified index has been reached, set reachedRemovedIndex to true
      if (i == indexToRemove)
        reachedRemoveIndex = true;

      if (reachedRemoveIndex)
        out[i] = arr[i+1]; //if the index has been reached, start copying the elements to the output array from the input
                           //array staggered one element to the right so as to skip over the desired index
      else
        out[i] = arr[i]; //if the index has not yet been reached, copy each element 1:1 from the input array to the output array
      
    }

  delete[] arr; //free up the memory
  return out;
}