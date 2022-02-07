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


void SelectSeat(string name_movie,string time_movie){
    string file = ".txt";
    ifstream seats(name_movie+file);
    ifstream seats_cinema(name_movie+file);
    string All,select;
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

     
    
    //show ที่นั่ง
    show(t,N,M);
 
    string input;
    int r;
    char c;
    int answer,column;
    do{  
        if(answer == 2){
           do{  
                do{
                   SetConsoleTextAttribute(h,10);
                   cout << "input your seat that you want to cancelled(ex C 4):" << endl;
                   cin >> c >> r;
                   c = toupper(c);

                   //ยังไม่เสร็จ
        
         
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
                if(t.at(point) == "X"){
                    t.at(point) = "0";
                }else if(t.at(point) == "0") {
                    cout << "lnvalid input." << endl;
                }
                
                SetConsoleTextAttribute(h,7);
                //show ที่นั่ง
                show(t,N,M);
 
                
                SetConsoleTextAttribute(h,6);
                cout << "--------------------------------\n";
                cout << "1 : add seat.\n" << "2 : cancelled seat.\n" << "3 : DONE.\n"; 
                cout << "--------------------------------\n";
                cout << "answer: ";
                cin >> answer ; 
                cout << "--------------------------------\n";
        

            }while(answer == 2);
        }

        if(answer == 3) break;
        
        do{
           SetConsoleTextAttribute(h,10);
           cout << "input your seat. (ex C 4) : " << endl;
           cin >> c >> r ;
           c = toupper(c);
           
            //ยังไม่เสร็จ
        

        }while(true);

    
        //ขึ้นสัญลักษณ์ จอง 'X'; 
        int point = column + M*(r-1);
        if(t.at(point) == "0"){
            t.at(point) = "X";
        }else if(t.at(point) == "X"){
            cout << "This seat has been book." << endl;
            cout << "Please select again." << endl;
        }

        SetConsoleTextAttribute(h,7);
        show(t,N,M);
 
   
        SetConsoleTextAttribute(h,6);
        cout << "--------------------------------\n";
        cout << "1. : add seat.\n" << "2. : cancelled seat.\n" << "3. : DONE.  \n"; 
        cout << "--------------------------------\n";
        cout << "answer: ";
        cin >> answer ; 
        cout << "--------------------------------\n";
        
    }while(answer != 3);
    
    
    
    SetConsoleTextAttribute(h,7);
    show(t,N,M);
 
    
    //เก็บเข้าไฟล์เดิม

    for(int j = 0;j < t.size();j++){
        T[j+p+1] = t[j];
    }

    ofstream s(name_movie+file);
    for(int k = 0;k < T.size();k++){
        s << T[k] << endl;
    }
    seats_cinema.close();
    
}



int main(){
    SelectSeat("theater","720");
    
    return 0;

}
