#include<iostream>
#include<windows.h>
using namespace std;

int main(){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "HELLO WORLD" <<endl;
    SetConsoleTextAttribute(h,14);
    cout << "text" <<endl;
    SetConsoleTextAttribute(h,11);
    cout << "text";
\
}
