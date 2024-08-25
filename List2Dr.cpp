#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>
using namespace std;

#include "List2.h"


#include <chrono>
#include <thread>
void rand_str(int length, string& str);

void rand_str(int length, string& str) {

    str = "";
    for (int i = 0; i < length; i++) {
        char c = rand() % (122 - 48 + 1) + 48;
        //string str = string(length, c);
        str.push_back(c);
        //cout << c;
    }

}

// There are other clocks, but this is usually the one you want.
// It corresponds to CLOCK_MONOTONIC at the syscall level.
using Clock = std::chrono::steady_clock;
using std::chrono::time_point;
using std::chrono::duration_cast;
using std::chrono::milliseconds;

int main() {

    int mysize;
   // int mySize[6] = {10000,20000,50000,100000,200000,300000 };
    int mySize[5] = { 20000,40000,80000,100000,200000};
    for (int i = 0; i < 5; i++) {
        mysize = mySize[i];

        for (int i = 0; i < 5; i++) {
            //create the structure that will hold the input values
            List2 list2;


            int numAdded = 0;
            string line;
            time_point<Clock> start = Clock::now();

            for (int i = 0; i < mysize; i++) {  // loop for input size
                int num = rand() % (10 - 4 + 1) + 4; //length random from 4-10
                rand_str(num, line);
                list2.PutItem(line);
               // list2.Print();
                numAdded++;

            }
            time_point<Clock> end = Clock::now();
            milliseconds diff = duration_cast<milliseconds>(end - start);
            cout << "Added " << numAdded << " items. " << list2.GetLength() << " time=" << diff.count() << " ms" << endl;


            int n = rand() % 7 + 4;
            string* arr = new string[mysize];
            for (int i = 0; i < mysize; i++) {
                if (i % 2 == 0) {
                    arr[i] = list2.Getitem();
                }
                else {
                    string ran;
                    rand_str(n, ran);
                    arr[i] = ran;
                }
                //  cout << arr[i] << endl;
            }


            start = Clock::now();
            for (int i = 0; i < mysize; i++) {
                string test;
                if (rand() % 2)
                    rand_str(n, test);
                else
                    test = arr[rand() % mysize];
                bool found = false;
                list2.HasItem(test, found);
            }

            end = Clock::now();
            // milliseconds diff = duration_cast<milliseconds>(end - start);
            diff = duration_cast<milliseconds>(end - start);
            cout << "Hasitem " << " - time = " << diff.count() << " ms" << endl;
        }
    }
  
  
  return 0;
}
