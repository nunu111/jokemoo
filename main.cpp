<<<<<<< HEAD
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
=======
 #include<iostream>
using namespace std;

void seat(char a[],int N,int M){
    for(int j = 0; j < M-2;j++){    
        for(int i=0; i<N ;i++){
            if(i == 0 || i == M){
                a[i] = '|';
            }else{
                a[i] = '.';
            }
>>>>>>> ea9fb085ebbf3e3b9a57300956e76f2f8047da87
        }
    }
}

int main(){
<<<<<<< HEAD
create_movieseat("matrix",10,10);
seat(20,20);
=======
int M = 5;
int N = 5;
char block[(N*M)+(N+M)];
seat(block,(N*M)+(N+M),M+2);

>>>>>>> ea9fb085ebbf3e3b9a57300956e76f2f8047da87
return 0;
}