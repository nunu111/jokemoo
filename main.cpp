#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
using namespace std;

void remove_movie(string movie_name){
    const char *str = movie_name.c_str();
    remove(str);
}

//สร้างไฟล์ขึ้นมาเพื่อจัดเก็บข้อมูลที่นั่ง * ย้ำว่าใช้สร้างเท่านั้นหากใช้ใหม่ข้อมูลเก่าจะหาย *
void create_movieseat(string movie_name,int N,int M){
    ofstream seatmovie (movie_name);
    seatmovie << movie_name <<endl;
    for(int i =0;i <N*M;i++){
        seatmovie << "0" << "\n";
    }
    seatmovie.close();
}
//ยังไม่เสร็จ
void check_seat(string movie_name){
    string name,num;
    int i;
    ifstream check (movie_name);
    do
    {
       getline(check,name);
       i++;
       if (i >200) break;
    } while (movie_name != name);
    while(getline(check,num)){
        if( num == "0" ) cout << 'O';
        else if ( num == "1" ) cout << 'X';
        else;
    }
    check.close();
}

void seat(char a[],int N,int M){
    for(int j = 0; j < M-2;j++){  
        for(int i=0; i<N ;i++){
            if(i == 0 || i == M){
                a[i] = '|';
            }else{
                a[i] = '.';
            }
        }
    }
}

int main(){
    int M = 5;
    int N = 5;
    create_movieseat("matrix",N,M);
    check_seat("matrix");
    remove_movie("matrix");
    char block[(N*M)+(N+M)];
    seat(block,(N*M)+(N+M),M+2);
    return 0;
}