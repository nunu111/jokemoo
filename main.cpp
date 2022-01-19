#include<iostream>
using namespace std;

int main(){
int N=10,M=10;
char seat[N][M];
for(int i=0; i<N ;i++){
    for(int j=0; j<M ; j++){
        if(j%3==0)seat[i][j] = 'X';
        else seat[i][j]= 'O';
    }
}
cout << seat[0][0];
return 0;
}