#include<string>
#include<iostream>
using namespace std;

string toUpperStr(string x){ //code เปลี่ยนตัวเป็นตัวใหญ่ทั้งหมด ของอาจารย์เห็นว่ามันใช้ได้
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}