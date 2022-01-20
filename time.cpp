#include<iostream>
#include<ctime>
#include<cstring>
using namespace std;

int main(){  
    time_t t;
    
    while(1){
        time(&t);
        char *current_time = ctime(&t);
        current_time[strlen(current_time) - 1] = '\0';
        for(int i = 0;i < 1000;i++);
        cout << "\rtime : " << current_time;
    
    }
return 0;
}


