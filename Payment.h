#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<windows.h>
#include<iomanip>
#include<vector>
#include<stdlib.h>
#include<sstream>
using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void Payment1(string name_movie,string time_movie,vector<string> R){
    string file = ".txt";
    string p_file = "_price.txt";
    ifstream seats(name_movie+file);
    ifstream pay(name_movie+p_file);
    string select,get,X;
    vector<string> m;
    
    //หาหลัก
    int M = 0;
    for(int i = 0;i < R.size();i++){
        if(R.at(i) == " ") M++;
    }
  
    //หาแถว
    int N = 0;
    for(int i = 0;i < R.size();i++){
        if(i%M == 0) N++;
    }

    ///////////////////////////////////////////////////
    string type,start,add;
     //เก็บประเภท ราคาเริ่มต้น ราคาที่เพิ่ม
    while(getline(pay,get)){
        if(get == time_movie) break;
    }

    if(get == time_movie){
        for(int j = 0;getline(pay,get);j++){
            if(get == " "){
                break;
            }else{
                m.push_back(get);
            }
        }
        start = m.at(0);
    }
    //แปลงstring เป็น int
        int s = stoi(start.c_str());
   
    /////////////////////////////////////////////////////
    
    //คิดตังค์//
    int total = 0;
    for(int i = 0;i < R.size();i++){
        if(R.at(i) == "S"){
            total += s;
        }
    }
 

    string seat;
    stringstream ss;
    int r,k = 0;
    for(int i = 0;i < N;i++){
        r = i+1;
        for(int j = 0;j < M;j++){
            int p = j + M*i;
            if(R.at(p) == "S"){
               seat += 'A'+j;
               //แปลง int เป็น string
               ss << r ;
               string newint = ss.str();
               /////////////
               seat += newint[k];
               k++;
               seat += " ";
               //////////////////////////แปลง r กลับมาเป็น int;
            }
        }  
    }

    //คำนวณเวลา
    int hr,min=0,time;
    time = stoi(time_movie.c_str());
    int tc = time;
    if(time >= 60){
        for(hr = 0;time >= 60;hr++){
            time -= 60;
        }
        min = tc-hr*60;
    }else if(time < 60){
        min = time;
    }
  
    cout << "_________________________________________" << "\n";
    cout << "-----------------------------------------" << endl;
    cout << "               RECEIPT" << endl;
    cout << "-----------------------------------------      " << endl;
    cout << "MOVIE: " << name_movie << "\n";
    cout << "TIME:  ";
    if(hr < 10){
        cout << "0" << hr << ":" ;
    }else{
        cout << hr << ":" ;
    }
    if(min < 10){
        cout << "0" << min << endl;
    }else{
        cout << min << endl;
    }
    cout << "Seat NO: " << endl;
    for(int i = 0;i < seat.size();i++){
        SetConsoleTextAttribute(h,14);
        cout << seat[i];
        if(i % 20 == 0 && i > 1) cout << "\n";
    }
    SetConsoleTextAttribute(h,7);
    cout << "\n";
    cout << "One seat : " << s << " BAHT." << endl;
    cout << "   Total : " << total << " BAHT." << endl;
    cout << "-----------------------------------------" << endl;
    cout << "   /\\,,,/\\" << endl;
    cout << "  (= * -*=)" ;
    SetConsoleTextAttribute(h,14);
    cout << "      THANK YOU" << endl;
    SetConsoleTextAttribute(h,7);
    cout << "  /__---__\\" << endl;
    SetConsoleTextAttribute(h,14);
    cout << "  hope you have a wonderful experience" << endl;
    SetConsoleTextAttribute(h,7);
    cout << "_________________________________________" << "\n";
}
