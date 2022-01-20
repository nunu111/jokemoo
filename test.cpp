//C++ STL program to demonstrate use of
//std::max_element() function
#include <iostream>
#include <algorithm>
#include <vector>
#include<fstream>
using namespace std;

int a[5] = {1,2,3,4,5};
int N = 5;
int main(){ 
    ofstream outfile("test.txt"); 
    for(int i = 0;i<N;i++){
        outfile << a[i] << endl; 
}
outfile.close();
return 0;
}

