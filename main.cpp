#include<iostream>
#include<string>
#include<fstream>
using namespace std;

void create_movieseat(string movie_name,int N,int M){
    ofstream seatmovie ("selected_seat.txt");
    seatmovie << movie_name <<endl;
    for(int i =0;i <N;i++){
        for(int j =0;j <M;j++){
            seatmovie << "0" << " ";
        }
        seatmovie << endl;
    }
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
    char block[(N*M)+(N+M)];
    seat(block,(N*M)+(N+M),M+2);
    return 0;
}