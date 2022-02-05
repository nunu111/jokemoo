#include<iostream>
#include<fstream>
#include<vector>
#include<cstdlib>
using namespace std;

string file_txt = ".txt";
int time_HR,time_min;

string a;
vector<string> movie_time;
void check_time(string movie){
    ifstream check_list (movie+file_txt);
    for (int i=0;getline(check_list,a);i++){
        if(a != "0" && a != " "){
            movie_time.push_back(a);
        }
    }
    cout << "this movie have time ....\n";
    for(int i=0; i<movie_time.size();i++){
        time_HR = atoi(movie_time[i].c_str())/60;
        time_min = atoi(movie_time[i].c_str())-(time_HR*60);
        if(time_min == 0){
            cout << time_HR <<":"<<"00"<< "     ";
        }
        else{
            cout << time_HR <<":"<<time_min<< "     ";
        }
    
    }
}