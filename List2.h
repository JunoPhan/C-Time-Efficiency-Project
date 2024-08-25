#include <iostream>
#include <vector>
using namespace std;


class List2 {
public:
  List2();
  ~List2();

  void PutItem(string c);
  void HasItem(string c, bool& found);
  void Print();
  int GetLength() { return length; }
  string Getitem();

  string* data; 
  int  maxSize;
  int  length;
};

List2::List2() {
  //default constructor
  maxSize = 5;
  data = new string[maxSize];
  length = 0;
}

List2::~List2() {
  delete [] data;
}

void List2::PutItem(string c) {
  if( length == maxSize ) { //increase the size and copy elements over
    //cout << "Increasing array size. " << endl;
    maxSize *= 2;
    string* newData = new string[maxSize];
    for(int i=0; i<length; i++) {
      newData[i] = data[i];
    }
    delete [] data;
    data = newData;
  }
  //cout << "PutItem num = " << num << endl;
  int loc = 0;
  while( loc < length ) {
    if( c > data[loc] ) {
      loc++; //increment num
    }
    else { //num will be added at loc
      break;
    }
  }//endwhile loc
  //cout << " adding at loc = " << loc << endl;
  //move everything over to make space
  for(int i = length-1; i>=loc; i--) {
    data[i+1] = data[i];
  }
  data[loc] = c;
  length++;
}

void List2::HasItem(string c, bool& found) {
  found = false;
  for(int i=0; i<length; i++) {
    if( data[i] == c ) {
      found = true;
      break;
    }
  }
}

void List2::Print() {
  for(int i=0; i<length; i++) {
    cout << data[i] << " ";
  }
  cout << endl;
}


string List2::Getitem() {
    // srand(time(NULL));
    int ran_num = rand() % (length);
    return data[ran_num];
}
