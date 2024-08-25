#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>
using namespace std;

#include "TreeType.h"


#include <chrono>
#include <thread>

// There are other clocks, but this is usually the one you want.
// It corresponds to CLOCK_MONOTONIC at the syscall level.
using Clock = std::chrono::steady_clock;
using std::chrono::time_point;
using std::chrono::duration_cast;
using std::chrono::milliseconds;

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


int main() {
    srand(time(NULL));
    int mysize;
    int mySize[5] = {20000,40000,80000,100000,200000};
    for (int i = 0; i < 5; i++) {
        mysize = mySize[i];

        for (int i = 0; i < 5; i++) {
            //create the structure that will hold the input values
            TreeType tree;

            //load up a test file full of integers
            int numAdded = 0;

            string line;
            bool unique;

            string* myarr = new string[mysize];
            for (int i = 0; i < mysize; i++) {
                do {
                    int n = rand() % (7) + 4;
                    rand_str(n, line);
                    unique = true;
                   // cout << "testing " << line << endl;
                    for (int j = 0; j < i; j++) {
                        if (myarr[j] == line)
                            unique = false;

                    }
                } while (!unique);

                myarr[i] = line;

            }

            time_point<Clock> start = Clock::now();

            for (int i = 0; i < mysize; i++) {  // loop for input size
               // int num = rand() % (10 - 4 + 1) + 4; //length random from 4-10
               // rand_str(num, line);
                tree.PutItem(myarr[i]);
                //list1.Print();
                numAdded++;

            }
        time_point<Clock> end = Clock::now();
        milliseconds diff = duration_cast<milliseconds>(end - start);
        cout << "Added " << numAdded << " items. " << tree.GetLength() << " time=" << diff.count() << " ms" << endl;

        //create new array to test hasitem function: half of the array filled with string from the 
        // initial array of unique string and half filled with random string
        string* testArr = new string[mysize];
        for (int i = 0; i < mysize; i++) {
            int n = rand() % 5;
            if (i % 2 == 0) {
                testArr[i] = myarr[n];

            }
            else {
                string teststr;
                rand_str(n, teststr);
                testArr[i] = teststr;
            }
        }

        int n = rand() % (7) + 4;
        start = Clock::now();
        for (int i = 0; i < mysize; i++) {
            string test;
            if (rand() % 2)
                rand_str(n, test);
            else
                test = testArr[rand() % mysize];
            bool found = false;
            tree.HasItem(test, found);
        }

        end = Clock::now();
        // milliseconds diff = duration_cast<milliseconds>(end - start);
        diff = duration_cast<milliseconds>(end - start);
        cout << "Hasitem " << " - time = " << diff.count() << " ms" << endl;
    }
}

  return 0;
}
