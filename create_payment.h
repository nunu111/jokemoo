#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

string p="_price",sgun= ".txt"; 

void create_payment(string movie_name,double price,int time){
    ofstream payment (movie_name + p+sgun,ios::app);
            payment << time << endl;
            payment << price << "\n \n";
    payment.close();
}