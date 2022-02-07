#include<fstream>
#include<iostream>

using namespace std;

string toUpperStr(string x){ //code เปลี่ยนตัวเป็นตัวใหญ่ทั้งหมด ของอาจารย์เห็นว่ามันใช้ได้
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

int refac;

void reset_password(){
    string newpassword,conf;
    cout << "Input your new password\n";
    cout << ">>> ";
    cin >> newpassword;
    cin.ignore();
    cout << newpassword << " is your new password are you sure?\n[Y]Yes   [N]No\n";
    cin >> conf;
    if(conf == "y"){
        ofstream password ("Password");
        password << newpassword;
        password.close();
    }

}

string passwordcheck(){
    string p;
    ifstream isthatright ("Password");
    getline(isthatright,p);
    isthatright.close();
    return p;
}

void passwordconfig(){
    ifstream pass ("Password");
    string p,bypass;
    if(getline(pass,p)) {
        refac=1;
        pass.close();
    }
    else{
        pass.close();
        cout << "This is the first time you run this program please input your password" << endl;
        cout <<">> ";
        getline(cin,bypass);
        ofstream by ("Password");
        by << bypass;
        by.close();

    }
}