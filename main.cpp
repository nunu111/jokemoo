#include<iostream>
using namespace std;

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
seat(20,20);
return 0;
}