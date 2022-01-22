#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<windows.h>
using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void remove_movie(string movie_name){
    const char *str = movie_name.c_str();
    remove(str);
}

//สร้างไฟล์ขึ้นมาเพื่อจัดเก็บข้อมูลที่นั่ง * ย้ำว่าใช้สร้างเท่านั้นหากใช้ใหม่ข้อมูลเก่าจะหาย *
void create_movieseat(string movie_name,string a[],int N,int M){
    ofstream seatmovie (movie_name);
    for(int i =0;i <N*M;i++){
        seatmovie << a[i] << "\n";
    }
    seatmovie.close();
}
//ยังไม่เสร็จ
void check_seat(string movie_name,string a[]){
    string name,num;
    int i;
    ifstream check (movie_name);
    do
    {
       getline(check,name);
       i++;
       if (i >200) break;
    } while (movie_name != name);
    for(int i=0;getline(check,num);i++){
        if( num == "0" )  a[i] = "O" ;
        else if ( num == "1" ) a[i] = "X" ;
        else;
    }
    check.close();
}

void seat(string a[],int N,int M){   
        for(int i=0;i<N*M;i++){
                a[i] = ".";
        }

}

void show(string a[],int N,int M){  
    cout << "         ";
    for(int p=0;p<M;p++){
        cout << char('A'+p);
        cout << " ";
    }
    cout << endl;
    for(int i=0;i<N;i++){
        cout << "    ";
        char A = '1'+i;
        cout << A<<' ';
        cout << "|  " ;
        for(int j=0;j<M;j++){
            cout << a[j+(i*M)];
            cout << " ";
        }
        cout << " |" <<endl; 
    }
    cout << endl;  
}

void walk(string a[],int x,int number,int M){
    for(int i=(x-1)*M;i<M*x;i++){
            a[i] = " ";
    }
}

void comferm_seat(string a[],int N,int M){
    for(int i=0;i<N*M;i++){
        if(a[i] == "."){
            a[i] = "0";
        }
    }
        
}

void showEX1(int &N,int &M){
    cout << " " << endl;
    SetConsoleTextAttribute(h,06);
    cout << "Example" << endl;
    SetConsoleTextAttribute(h,07);
    cout << "        ";
        for(int i=0;i<5;i++){
            cout << " ";
            cout << char('A'+i); 
        }
        SetConsoleTextAttribute(h,04);
        cout << "   << column";
        SetConsoleTextAttribute(h,7);
    cout << endl;
    cout << "    1 |  . . . . .  |";
    SetConsoleTextAttribute(h,06);
    cout << "               Equation" << endl;
    SetConsoleTextAttribute(h,07);
    cout << "    2 |  . . . . .  |";
    SetConsoleTextAttribute(h,06);
    cout << "        Number_of_seat =  line X column" << endl;
    SetConsoleTextAttribute(h,07);
    cout << "    3 |  . . . . .  |" << endl << endl;
    SetConsoleTextAttribute(h,04);
    cout << "         ^ ^ ^ ^ ^ ";
    SetConsoleTextAttribute(h,11);
    cout << "                 column = ";
    cin >> M;
    SetConsoleTextAttribute(h,04);
    cout << "            line";
    SetConsoleTextAttribute(h,11);
    cout << "                    line = ";
    cin >> N;
    cout << endl;
    SetConsoleTextAttribute(h,07);
}

void showEX2(int &A){
    SetConsoleTextAttribute(h,06);
    cout << "                                    Where is your aisle?" << endl;
    SetConsoleTextAttribute(h,11);
    cout << "                                    column = ";
    cin >> A;
    SetConsoleTextAttribute(h,07);
}

void showEX3(int x){
    SetConsoleTextAttribute(h,06);
    cout << "        Your cinema" << endl << endl;
    SetConsoleTextAttribute(h,07);
}

string checkAns(string &Ans){
    string sum;
    SetConsoleTextAttribute(h,06);
    cout << "                                    right or No" << endl;
    cout << "                                    (Yes = y,No = n)" << endl;
    SetConsoleTextAttribute(h,11);
    cout << "                                    Your Answer is ";
    cin >> sum;
    SetConsoleTextAttribute(h,07);
    Ans = sum;
    return "Ans";
}

int main(){
    int N;
    int M;
    string Ans;
    do{
        showEX1(N,M);
        string *block=new string[N*M];
        seat(block,N,M);
        show(block,N,M);
        int A;
        showEX2(A);
        walk(block,A,N*M,M);
        show(block,N,M);
        comferm_seat(block,N,M);
        showEX3(1);
        show(block,N,M);
        checkAns(Ans);
    }while(Ans != "y");
    return 0;
}