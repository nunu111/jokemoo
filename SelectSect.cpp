#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<windows.h>
#include<iomanip>
#include<vector>
#include<sstream>
using namespace std;

void SelectSeat(string name_movie,string time_movie){
    string file = ".txt";
    ifstream seats(name_movie+file);
    ifstream seats_cinema(name_movie+file);
    string All,select;
    vector<string> T;
    vector<string> t;
    string cinema,text;
    int total = 0,p = 0;
    
    while(getline(seats,All)){
        T.push_back(All);
        total++;
    }
    seats.close();

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

    //เอาไปเก็บไว้ในstring cinema
    for(int  i = 0;i < t.size();i++){
        cinema += t.at(i);
    }
   
    //หาหลัก
    int M = 0;
    for(int i = 0;i < cinema.size();i++){
        if(cinema[i] == ' ') M++;
    }
  
    //หาแถว
    int N = 0;
    for(int i = 0;i < cinema.size();i++){
        if(i%M == 0) N++;
    }


    //เก็บที่นั่งในkeep
    string keep[N][M];
    int k = 0;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            keep[i][j] = cinema[k];
            k++;
        }
    }
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            cout << keep[i][j];
        }
        cout << "\n";
    }

    int r;
    char c;
    int answer;
    do{  
        if(answer == 2){
           do{ 
                cout << "input your seat that want cancelled: ";
                cin >> c >> r ;

                //แปลงหลักเป็นเลข
                int column;
                for(int i = 0;i < 26;i++){
                if(c == 'A'+i) column = i;
                }
  
                //ขึ้นสัญลักษณ์ ยกเลิก '0'; 
                if(keep[r-1][column] == "0" || keep[r-1][column] == "X"){
                    keep[r-1][column] = "0";
                }   
                cout << "--------------------------------\n";
                cout << "1. add seat\n" << "2. cancelled seat\n" << "3. Back to cinema\n"; 
                cout << "--------------------------------\n";
                cout << "answer: ";
                cin >> answer ; 
        

            }while(answer == 2);
        }

        if(answer == 3) break;
        
        cout << "input your seat: ";
        cin >> c >> r ;

        //แปลงหลักเป็นเลข
        int column;
        for(int i = 0;i < 26;i++){
             if(c == 'A'+i) column = i;
        }

        //ขึ้นสัญลักษณ์ จอง 'X'; 
        if(keep[r-1][column] == "0" || keep[r-1][column] == "X"){
            keep[r-1][column] = "X";
        }

        cout << "--------------------------------\n";
        cout << "1. add seat\n" << "2. cancelled seat\n" << "3. Back to cinema\n"; 
        cout << "--------------------------------\n";
        cout << "answer: ";
        cin >> answer ; 
        
    }while(answer != 3);
     

    //โชว์โรงหนัง
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            cout << keep[i][j];
        }
        cout << "\n";
    }

    for(int j = 0;j < t.size();j++){
        T[j+p] = t[j];
    }

    seats_cinema.close();

    ofstream s(name_movie+file);
    for(int k = 0;k < T.size();k++){
        s << T[k] << endl;
    }
    s.close();
    
}

int main(){
    SelectSeat("theater","500");
    return 0;


    

}
