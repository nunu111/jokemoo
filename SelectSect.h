#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<windows.h>
#include<iomanip>
#include<vector>
#include<stdlib.h>
#include<sstream>
#include"Payment.h"
using namespace std;

string difile = "all movie/";

void show(vector<string> a,int N,int M){
    cout << "          ";
    for(int p=0;p<M;p++){
        cout << char('A'+p);
        cout << " ";
    }
    cout << endl;
    for(int i=0;i<N;i++){
        cout << "    ";
        int A = i+1;
        cout << setw(3) << left <<A;
        cout << "|  " ;
        for(int j=0;j<M;j++){
            cout << a[j+(i*M)];
            cout << " ";
        }
        cout << " |" <<endl; 
    }
    cout << endl;  
}

//เพิ่มฟังก์ชั่นจากPassword
string toUpper(string x){ 
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}



void SelectSeat(string name_movie,string time_movie){
    string file = ".txt";
    ifstream seats(difile +name_movie+file);
    ifstream seats_cinema(difile+name_movie+file);
    string p_file = "_price.txt";
    ifstream pay(dfile_price +name_movie+p_file);
    string All,select,get;
    vector<string> T;
    vector<string> t;
    string cinema,text;
    int p = 0;
    
    while(getline(seats,All)){
        T.push_back(All);
    }
    seats.close();
    /////////////////////////////////////////////////////
    while(getline(seats_cinema,select)){
        if(select == time_movie) break;
        p++; //ตัวเริ่มต้นของหัวโรง
    }
    
    //เพิ่มการโชว์รายจ่ายของโรง
    string type,start,add;
    while(getline(pay,get)){
        if(get == time_movie) break;
    }
    if(get == time_movie){
        for(int j = 0;getline(pay,get);j++){
            if(get == " "){
                break;
            }else{
                start = get;
            }
        }
    }
    //แปลงstring เป็น int
        int money = atoi(start.c_str());

    //เก็บที่นั่งของโรงที่ต้องการ
    if(select == time_movie){
        for(int j = 0;getline(seats_cinema,select);j++){
            if(select == "0" || select == " " || select == "X" ){
                t.push_back(select);
            }else{
                break;
            }
        }
    }
    //หาหลัก
    int M = 0;
    for(int i = 0;i < t.size();i++){
        if(t.at(i) == " ") M++;
    }
    //หาแถว
    int N = 0;
    for(int i = 0;i < t.size();i++){
        if(i%M == 0) N++;
    }


    int r,column;
    char c;
    string ANS,answer,sr;

    do{
         
        //วนรับคำตอบ MENU
        do{ 
            system("CLS");
            SetConsoleTextAttribute(h,6);
            cout << "-----------------------------------------" << endl;
            cout << "  | PRICE RATE | One seat : " << money << " BAHT." << endl;
            cout << "-----------------------------------------" << endl;
            cout << "\n";
            SetConsoleTextAttribute(h,7);
            show(t,N,M);
            SetConsoleTextAttribute(h,6);
            cout << "                        MENU               \n";
            cout << "--------------------------------------------------------\n";
            cout << " [H] : back to home (data of seats will be not reserve.)" << endl;
            cout << " [C] : continue" << endl ;
            cout << "--------------------------------------------------------\n";
            SetConsoleTextAttribute(h,7);
            cout << " [Answer] : ";
            cin >> ANS; 
            cin.ignore();
            cout <<"\n";
            
            if(toUpper(ANS) == "H" ||toUpper(ANS) == "C" ){
                break;
            }else{
               SetConsoleTextAttribute(h,4);
               cout << "input invalid" << endl;
            }
        }while(true);

        if(toUpper(ANS) == "C"){
            do{ 
                //"2" เข้า cancelled seat
                if(answer == "2"){
                    do{ 
                        //do ดักคำตอบ cancelled seat
                        do{ 
                          SetConsoleTextAttribute(h,7);
                          int count_seat = 0;
                          for(int i = 0;i < t.size();i++){
                              if(t.at(i) == "S"){
                                 count_seat++;
                                }
                          }
                          system("CLS");
                          SetConsoleTextAttribute(h,6);
                          cout << "------------------------------" << endl;
                          cout << "    Total Amount " << money*count_seat <<" THB." << endl;
                          cout << "------------------------------" << endl;
                          SetConsoleTextAttribute(h,7);
                          show(t,N,M);
             
                          SetConsoleTextAttribute(h,9);
                          cout << "input your seat that you want to cancelled";
                          SetConsoleTextAttribute(h,7);
                          cout << "(ex) A1 = column: A , row: 1" << endl;
                          SetConsoleTextAttribute(h,9);
                          cout << "Column: ";
                          SetConsoleTextAttribute(h,7);
                          cin >> c ;
                          SetConsoleTextAttribute(h,9);
                          cout << "   Row: ";
                          SetConsoleTextAttribute(h,7);
                          stringstream z;
                          z << sr;
                          z >> r;
                          cout << "\n";
                          c = toupper(c);

                          system("CLS");

                            if(c >= 'A' && c < 'A'+ M){
                                if(r >= 1 && r <= N){
                                    break;
                                }else{
                                    SetConsoleTextAttribute(h,4);
                                    cout << "*|  Row: " << r << " do not have. |*" << endl;
                                    cout << "*|  Please select again. |*" << "\n";
                                }
                            }else{
                                SetConsoleTextAttribute(h,4);
                                cout << "*|  Column: " << c <<  " do not have. |*" << endl;
                                cout << "*| Please select again. |*" << "\n";
                            }

                        }while(true);

                        //แปลงหลักเป็นเลข
                        for(int i = 0;i < 26;i++){
                            if(c == 'A'+i){
                                column = i;
                                break;
                            }
                        }
                
  
                        //ขึ้นสัญลักษณ์ ยกเลิก '0'; 
                        int point = column + M*(r-1);
                        if(t.at(point) == "S"){
                           t.at(point) = "0";
                           system("CLS");
                           SetConsoleTextAttribute(h,7);
                           show(t,N,M);
                        }else if(t.at(point) == "X" || t.at(point) == "0" || t.at(point) == " " ){
                           system("CLS");
                           SetConsoleTextAttribute(h,7);
                           show(t,N,M);
                           SetConsoleTextAttribute(h,4);
                           cout << "* you can not cancelled this seat. *" << endl;
                        }
                        
                        //ดักคำตอบ ทางเลือก ฝั่ง add seat
                        do{
                           SetConsoleTextAttribute(h,6);
                           cout << "--------------------------------\n";
                           cout << "      0. : Back.\n" << "      1. : add seat.\n" <<   "      2. : cancelled seat.  \n"<<   "      3. : Confirm.  \n"; 
                           cout << "--------------------------------\n";
                           cout << "answer: ";
                           cin >> answer ; 
                           cin.ignore();
                           cout << "--------------------------------\n";
                           system("CLS");
                            if(answer == "0" || answer == "1" || answer == "2" || answer == "3"){
                                break;
                            }else{
                                SetConsoleTextAttribute(h,4);
                                cout << answer << " do not have" << "\n";
                                SetConsoleTextAttribute(h,7);
                                show(t,N,M);
                            }
                        }while(true);

                    }while(answer == "2");
                    if(answer == "3" || answer == "0") break;
                }
                
                //do ดักคำตอบ add seat
                do{ 
                    SetConsoleTextAttribute(h,7);
                   //คำนวณจำนวนเงินทั้งหมด
                    int count_seat = 0;
                    for(int i = 0;i < t.size();i++){
                        if(t.at(i) == "S"){
                           count_seat++;
                        }
                    }
                    system("CLS");
                    SetConsoleTextAttribute(h,6);
                    cout << "------------------------------" << endl;
                    cout << "    Total Amount " << money*count_seat <<" THB." << endl;
                    cout << "------------------------------" << endl;
                    SetConsoleTextAttribute(h,7);
                    show(t,N,M);
             
              

                    SetConsoleTextAttribute(h,9);
                    cout << "input your seat.";
                    SetConsoleTextAttribute(h,7);
                    cout << "(ex) A1 = column: A , row: 1" << endl;
                    SetConsoleTextAttribute(h,9);
                    cout << "Column: ";
                    SetConsoleTextAttribute(h,7);
                    cin >> c ;
                    SetConsoleTextAttribute(h,9);
                    cout << "   Row: ";
                    SetConsoleTextAttribute(h,7);
                    cin >> sr;
                    stringstream aa;
                    aa << sr;
                    aa >> r;
                    cout << "\n";
                    c = toupper(c);
           
                   
                    if(c >= 'A' && c < 'A'+ M){
                        if(r >= 1 && r <= N){
                           break;
                        }else{
                           SetConsoleTextAttribute(h,4);
                           cout << "*|  Row: " << r << " do not have. |*" << endl;
                           cout << "*|  Please select again. |*" << "\n";
                           system("pause");
                        }
                    }else{
                        SetConsoleTextAttribute(h,4);
                        cout << "*|  Column: " << c <<  " do not have. |*" << endl;
                        cout << "*| Please select again. |*" << "\n";
                        system("pause");
                    }
                }while(true);

                //แปลงหลักเป็นเลข
                for(int i = 0;i < 26;i++){
                    if(c == 'A'+i){
                       column = i;
                       break;
                    }
                }
                //ขึ้นสัญลักษณ์ จอง 'X'; 
                int point = column + M*(r-1);
                if(t.at(point) == "0"){
                    t.at(point) = "S";
                    system("CLS");
                    SetConsoleTextAttribute(h,7);
                    show(t,N,M);
                }else if(t.at(point) == "X" || t.at(point) == "S" ){
                    system("CLS");
                    SetConsoleTextAttribute(h,7);
                    show(t,N,M);
                    SetConsoleTextAttribute(h,4);
                    cout << "   * This seat has been book. *" << endl;
                    cout << "     * Please select again. * " << endl;
                }else if(t.at(point) == " "){
                    system("CLS");
                    SetConsoleTextAttribute(h,7);
                    show(t,N,M);
                    SetConsoleTextAttribute(h,4);
                    cout << "* you can not select this seat. *" << "\n";
                }

                //ดักคำตอบ ทางเลือก ฝั่ง add seat
                 do{
                   SetConsoleTextAttribute(h,6);
                   cout << "--------------------------------\n";
                   cout << "      0. : Back.\n" << "      1. : add seat.\n" <<   "      2. : cancelled seat.  \n"<<   "      3. : Confirm.  \n"; 
                   cout << "--------------------------------\n";
                   cout << "answer: ";
                   cin >> answer ; 
                   cin.ignore();
                   cout << "--------------------------------\n";
                   system("CLS");
                    if(answer == "0" || answer == "1" || answer == "2" || answer == "3" ){
                        break;
                    }else{
                        SetConsoleTextAttribute(h,4);
                        cout << answer << " do not have" << "\n";
                        SetConsoleTextAttribute(h,7);
                        show(t,N,M);
                    }
                }while(true);
                system("CLS");

 
            }while(answer != "0" && answer != "3");

            //ทางเลือก COMPLETE
            if(answer == "3"){
                //โชว์สลิปและเก็บเข้าไฟล์
                Payment1(name_movie,time_movie,t);

                for(int j = 0;j < t.size();j++){
                    if(t.at(j) == "S"){
                       t.at(j) = "X";
                    }
                    T[j+p+1] = t[j];
                }
        
                ofstream s(difile + name_movie+file);
                for(int k = 0;k < T.size();k++){
                     s << T[k] << endl;
                }
                s.close();
                break;
            }
        }

    }while(toUpper(ANS) != "H");
    seats_cinema.close();
    seats.close(); 

}
