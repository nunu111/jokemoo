#include<iostream>
#include<windows.h>
using namespace std;

int main(){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "HELLO WORLD" <<endl;
    SetConsoleTextAttribute(h,13);
    cout << "text" <<endl;
    SetConsoleTextAttribute(h,15);
    cout << "text";
\
}
