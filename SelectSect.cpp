#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<windows.h>
#include<iomanip>
#include<vector>
#include<sstream>
using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void show(string a[],int N,int M){
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

    //เอาไปเก็บไว้ในstring
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
     
    
    //show ที่นั่ง
    string Show[N*M];
    int C = 0;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            Show[C] = keep[i][j] ;
            C++;
        }
    } 
    show(Show,N,M);

 
    int r;
    char c;
    int answer;
    do{  
        if(answer == 2){
           do{  
                SetConsoleTextAttribute(h,10);
                cout << "input your seat that want cancelled: ";
                cin >> c >> r ;

                c = toupper(c);

                //แปลงหลักเป็นเลข
                int column;
                for(int i = 0;i < 26;i++){
                if(c == 'A'+i) column = i;
                }
  
                //ขึ้นสัญลักษณ์ ยกเลิก '0'; 
                if(keep[r-1][column] == "0" || keep[r-1][column] == "X"){
                    keep[r-1][column] = "0";
                }   
                
                SetConsoleTextAttribute(h,7);
                //show ที่นั่ง
                C = 0;
                for(int i = 0;i < N;i++){
                  for(int j = 0;j < M;j++){
                    Show[C] = keep[i][j] ;
                    C++;
                  }
                } 
                show(Show,N,M);
                
                SetConsoleTextAttribute(h,6);
                cout << "--------------------------------\n";
                cout << "1 : add seat\n" << "2 : cancelled seat\n" << "3 : DONE\n"; 
                cout << "--------------------------------\n";
                cout << "answer: ";
                cin >> answer ; 
                cout << "--------------------------------\n";
        

            }while(answer == 2);
        }

        if(answer == 3) break;
        
        SetConsoleTextAttribute(h,10);
        cout << "input your seat: ";
        cin >> c >> r ;
        c = toupper(c);

        //แปลงหลักเป็นเลข
        int column;
        for(int i = 0;i < 26;i++){
             if(c == 'A'+i) column = i;
        }

        //ขึ้นสัญลักษณ์ จอง 'X'; 
        if(keep[r-1][column] == "0" || keep[r-1][column] == "X"){
            keep[r-1][column] = "X";
        }

        SetConsoleTextAttribute(h,7);
        C = 0;
        for(int i = 0;i < N;i++){
            for(int j = 0;j < M;j++){
                Show[C] = keep[i][j] ;
                C++;
            }
        } 
        show(Show,N,M);
   
        SetConsoleTextAttribute(h,6);
        cout << "--------------------------------\n";
        cout << "1. : add seat\n" << "2. : cancelled seat\n" << "3. : DONE  \n"; 
        cout << "--------------------------------\n";
        cout << "answer: ";
        cin >> answer ; 
        cout << "--------------------------------\n";
        
    }while(answer != 3);
    
    
    C = 0;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            Show[C] = keep[i][j] ;
            C++;
        }
    } 
    SetConsoleTextAttribute(h,7);
    show(Show,N,M);
    
    //เก็บเข้าไฟล์เดิม
    int o = 0;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            t[o] = keep[i][j];
            o++;
        }
    } 
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
