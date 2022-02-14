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
    ifstream seats(name_movie+file);
    ifstream pay("payment1.txt");
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
        type = m.at(0);
        start = m.at(1);
        add = m.at(2);
    }
    //แปลงstring เป็น int
        int s = stoi(start.c_str());
        int a = stoi(add.c_str());
   
    /////////////////////////////////////////////////////
    
    //คิดตังค์//
    int total = 0,count = 0;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            int p = j + M*i;
            if(R.at(p) == "S"){
               count++; //จำนวนเก้าอี้ที่จอง
               total += s + a*i;
            }else if(R.at(i) == " "){
               total += s + a*0;
               if(j == M) i--;
            }
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
   
    cout << "                RECEIPT" << endl;
    cout << "_________________________________________" << "\n";
    cout << "\n";
    cout <<  type << " theater." << endl;
    cout << "MOVIE: " << name_movie << "\n";
    cout << "Seat NO :" << "\n";
    for(int i = 0;i < seat.size();i++){
        cout << seat[i]; 
        if(i == 14) cout << "\n";
    }
    cout << "\n";
    cout << "one seat : " << s << " BAHT." << endl;
    cout << "   total : " << total << " BAHT" << endl;
    cout << "______________________________________________" << "\n";
}


