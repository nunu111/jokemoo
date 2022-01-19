 #include<iostream>
using namespace std;

void seat(char a[],int N,int M){
    for(int j = 0; j < M-2;j++){    
        for(int i=0; i<N ;i++){
            if(i == 1 || i == M){
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
char block[(N*M)+(N+M)];
seat(block,(N*M)+(N+M),M+2);

return 0;
}