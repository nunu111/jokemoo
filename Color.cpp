#include<iostream>
#include<windows.h>
using namespace std;

int main(){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "HELLO WORLD" <<endl;
    SetConsoleTextAttribute(h,13);
    cout << "HELLO WORLD" <<endl;
    SetConsoleTextAttribute(h,1);
    cout << "HELLO WORLD" <<endl;
}
