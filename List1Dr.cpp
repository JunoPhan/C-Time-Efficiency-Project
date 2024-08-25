#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>
using namespace std;

#include "List1.h"
	

#include <chrono>
#include <thread>

// There are other clocks, but this is usually the one you want.
// It corresponds to CLOCK_MONOTONIC at the syscall level.
using Clock = std::chrono::steady_clock;
using std::chrono::time_point;
using std::chrono::duration_cast;
using std::chrono::milliseconds;


int main() {
  //create the structure that will hold the input values
  List1 list1;

  //load up a test file full of integers
  ifstream infile;
  infile.open("Input1000.txt");
  int num;
  int numAdded = 0;
  time_point<Clock> start = Clock::now();
  while( infile >> num ) {  //for loop
    list1.PutItem(num);
    list1.Print();
    numAdded++;
  }
  time_point<Clock> end = Clock::now();
  milliseconds diff = duration_cast<milliseconds>(end - start);
  cout << "Added " << numAdded << " items. " << list1.GetLength() << " time=" << diff.count() << " ms" << endl;
  infile.close();

  list1.Print();

  //create the query numbers - they do not need to be the 
  //same as input numbers  
  ifstream queryInfile;
  queryInfile.open("Input1000.txt");
  vector<int> queryNumbers;
  while( queryInfile >> num ) {
    queryNumbers.push_back(num);
  }
  queryInfile.close();
  cout << "Num query numbers " << queryNumbers.size() << endl;

  //test if list has the numbers
  for(int i=0; i<(int)queryNumbers.size(); i++) {
    num = queryNumbers[i];
    bool found = false;
    list1.HasItem(num, found);
    if( found ) 
      cout << num << " was found. " << endl;
    else
      cout << num << " was NOT found. " << endl;
  }


  return 0;
}
