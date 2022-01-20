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

void seat(int N,int M){
    char seat[N][M];
    for(int i=0; i<N ;i++){
        for(int j=0; j<M ; j++){
            if(i == 0 || i == N)seat[i][j] = '-';
            else if(j == 0 || j == M) seat[i][j]= '|';
            else seat[i][j]=' ';
        }
    }
}

int main(){
create_movieseat("matrix",10,10);
seat(20,20);
return 0;
}