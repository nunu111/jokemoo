#include<fstream>
#include<iostream>
#include<direct.h>

using namespace std;
    HANDLE t = GetStdHandle(STD_OUTPUT_HANDLE);
string toUpperStr(string x){ //code เปลี่ยนตัวเป็นตัวใหญ่ทั้งหมด ของอาจารย์เห็นว่ามันใช้ได้
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

int refac;

void make_file(){
    bool a=mkdir("all movie");
    bool b=mkdir("all Theater");
    bool c=mkdir("all price_movie");
    if(!a && !b && !c){
        cout << "create file complete\n";
    }
    else{
        cout << "ERROR cannot create all file (you can make it manual)\n";
    }
}

void reset_password(){
    string newpassword,conf;
    while(1){
        SetConsoleTextAttribute(t,6);
        cout << "Input your new password\n";
        SetConsoleTextAttribute(t,11);
        cout << ">>> ";
        cin >> newpassword;
        cin.ignore();
        cout << newpassword;
        SetConsoleTextAttribute(t,6);
        cout << " is your new password are you sure?\nInput your password again to confirm\n";
        while(true){
            SetConsoleTextAttribute(t,11);
            cout << ">>> ";
            cin >> conf;
            if(conf == newpassword){
                ofstream password ("Password");
                password << newpassword;
                password.close();
                break;
            }
            else if(conf != newpassword) break;
            else{
                SetConsoleTextAttribute(t,4);
                cout << "You worng password confrim\n";
                continue;
            }
        }
        if(conf == newpassword) {
            system("CLS");
            SetConsoleTextAttribute(t,6);
            break;
        }
        else if(conf != newpassword) continue;
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
    string p,bypass,conf;
    if(getline(pass,p)) {
        refac=1;
        pass.close();
    }
    else{
            pass.close();
            ofstream by ("Password");
            while(true){
            cout << "This is the first time you run this program please input your password" << endl;
            cout <<">>> ";
            getline(cin,bypass);
            cout << bypass << " is your new password are you sure?\n[Y]Yes   [N]No\n";
            while(true){
                cout << ">>> ";
                cin >> conf;
                cin.ignore();
                if(toUpperStr(conf) == "Y"){
                    ofstream password ("Password");
                    password << bypass;
                    password.close();
                    break;
                }
                else if(toUpperStr(conf) == "N") break;
                else{
                    cout << "You type worng command\n";
                    continue;
                }
            }
            if(toUpperStr(conf) == "Y") break;
            else if(toUpperStr(conf) == "N") continue;
        }
        make_file();
    }

}