#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<windows.h>
#include<iomanip>
#include<vector>
#include<sstream>
using namespace std;

void SelectSeat(){
    ifstream seats("thearter.txt");
    string select;
    vector<string> T;
    int cinema,r;
    string keep[5][5];
    string thearter;
   
    cout << "input your cinema: ";
    cin >> cinema;

    while(getline(seats,select)){
        int start = select.find_first_of("1");
        int y = select.find_first_of("2");
        cout << select.substr(start+1,y-1);
    }
    
    //ยังไม่เสร็จอีก

    //เลือกโรงหนังที่ต้องการ
    for(int i = 0;i < ;i++){
        if(T.at(i) == 0 |T.at(i) == " "){
            string thearter += T.at(i);
        }
        if(T.at(i) != cinema) break;
        }
    
    //เก็บที่นั่งในkeep
    int k = 0;
    for(int i = 0;i < 5;i++){
        for(int j = 0;j < 5;j++){
            keep[i][j] = thearter[k];
            k++;
        }
    }
    //ยังไม่เสร็จ

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
    for(int i = 0;i < 5;i++){
        for(int j = 0;j < 5;j++){
            cout << keep[i][j];
        }
        cout << "\n";
    }

    seats.close();
}

int main(){
    SelectSeat();

    
    return 0;


    

}
