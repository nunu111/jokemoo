#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<windows.h>
#include<iomanip>
#include<vector>
#include<sstream>
using namespace std;

void SelectSeat(string filemovie,string time_movie){
    ifstream seats(filemovie);
    string select;
    vector<string> T;
    string cinema,text;
    
    while(getline(seats,select)){
        T.push_back(select);
    }
     seats.close();
    
    //เลือกโรงหนัง จากเวลาหนัง
    for(int i = 0;i < T.size();i++){
        if(T.at(i) == time_movie){
            for(int j = i+1;j < T.size();j++){
                text += T.at(j);
            }
        }
    }

    for(int k = 0;k < text.size();k++){
        if(text[k] == ' ' || text[k] == '0'){
            cinema += text[k];
        }else{
            break;
        } 
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

   
}

int main(){
    SelectSeat("theater.txt","500");
    return 0;


    

}
