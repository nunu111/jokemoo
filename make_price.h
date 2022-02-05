#include<iostream>
#include<fstream>
#include<vector>
using namespace std;



void check_decition(vector<string> a){
    string name;
    cout << "what movie do you want to make price";
    for(unsigned int i=0;i<a.size();i++){
        cout << "- " << a[i] << endl;
    }
    cin >> name;
}