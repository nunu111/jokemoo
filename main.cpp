#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<windows.h>
#include<iomanip>
#include<vector>
#include<sstream>
#include<ctime>
#include<cstdlib>
#include"Password.h"
#include"time_of_movie.h"
#include"make_price.h"
#include"admin_config.h"
using namespace std;

string  file= ".txt";

string password;

void timesetting(void);
string checkAns(string &);
void runprogram();



//คล้าย main เลย แต่ต้องพิมพ์ 1 ก่อน
void admin(int &room){
    int N,M,Ans1,mode1=0,mode2=0;
    string Ans;
    vector<string> theater;
    ifstream time ("timemovie.txt");
    ifstream movie ("listmovie.txt");
    ifstream theatera ("theater.txt");
    string theatervec;
    string movietime;
    string moviename;
    vector<string> a;
    vector<int> b;

    while(1){
        //เลือกระบบที่ต้องการแก้ไข
        cout << "Which system do you want to manage ?\n1 : Theater manage\n2 : Movie manage\n3 : Time manage\n4 : Showing movie manage\n5 : make price\n9 : Reset Password\n0 : Go to Home page\nYour answer is ";
        cin >> Ans1;
        cin.ignore();
        if(Ans1==1){//ระบบจัดการโรงหนัง
            while(1){
                int count=1;
                cout << "How many theater do you want ?\nYour answer is ";
                cin >> room;
                theater.clear();
                for(int i=0; i < room ;i++){
                    showEX1(N,M);
                    string *block=new string[N*M];
                    seat(block,N,M);
                    show(block,N,M);
                    int A;
                    showEX2(A);
                    walk(block,A,N*M,M);
                    show(block,N,M);
                    comferm_seat(block,N,M);
                    showEX3(1);
                    show(block ,N,M);
                    stringstream ss;
                    ss << count;
                    string s;
                    ss >> s;
                    theater.push_back(s);
                    for(int i=0 ; i<N*M ; i++){
                        theater.push_back(*(block+i));
                    }
                    delete [] block ;
                    count++;
                }
                while(1){
                    checkAns(Ans);
                    if(Ans == "y") break;
                    else if(Ans == "n"){
                        theater.clear();
                        break;
                    }
                    else{
                        cout << "Please try again.";
                    }
                }
                if(Ans == "y"){
                    break;
                }
            }
            ofstream theater1 ("theater.txt");
                for(int i=0;i<theater.size();i++){
                    theater1 << theater[i];
                    theater1 << endl;
                }
            theater1.close();
            theater.clear();
        }else if(Ans1==2){//ระบบจัดการรอบหนัง
            int Ans5,Ans2,Ans4;
            char Ans3;
            while(1){
                cout << "Movie program today" << endl;//แสดงโปรแกรมหนังวันนี้
                for(int i =0;getline(movie,moviename);i++){
                    a.push_back(moviename);
                    cout << "- " << a[i] << endl;
                }
                for(int i =0;getline(time,movietime);i++){
                    b.push_back(stoi(movietime));
                }
                //เลือกเพิ่ม\ลบหนัง
                cout << "What do you want to do ?\n1 : Add movie\n2 : Remove movie\n0 : Go to Admin setting\nYour answer is ";
                cin >> Ans5;
                cin.ignore();
                if(Ans5 == 1){//ระบบเพิ่มหนัง
                    while(1){
                        int t;
                        string name;
                        cout << "What movie do you to add ?" << endl << "Your answer is ";
                        cin.ignore();
                        getline(cin,name);
                        cout << "How long this movie ? (minute unit)" << endl << "Your answer is ";
                        cin >> t;
                        while(1){
                            cout << "Where do you want to insert movie in the list ?" << endl;
                            ShowListMovie(a);
                            cout << "Your answer is ";
                            cin >> Ans2;
                            if(Ans2 > 0 && Ans2 <= a.size()+1){
                                a.insert(a.begin()+Ans2-1,name);
                                b.insert(b.begin()+Ans2-1,t);
                                break;
                            }
                            else{
                                cout << "Wrong!!! Please try again."<< endl;
                            }
                        }
                        ShowListMovie(a);
                        cout << "Anything else ? (Yes = y or anything,No = n)"<< endl;
                        cin >> Ans3;
                        if(Ans3 == 'n') break;
                    }
                }else if(Ans5 == 2){//ระบบลบหนัง
                    while(1){
                        while(1){    
                            cout << "Which movie do you to delete ?" << endl ;
                            ShowListMovie(a);
                            cout << "Your answer is ";
                            cin >> Ans4;
                            if(Ans4 > 0 && Ans4 <= a.size()+1){
                                a.erase(a.begin()+Ans4-1);
                                b.erase(b.begin()+Ans4-1);
                                break;
                            }
                            else{
                                cout << "Wrong!!! Please try again."<< endl;
                            }
                        }
                        ShowListMovie(a);
                        cout << "Anything else ? (Yes = y or anything,No = n)"<< endl;
                        cin >> Ans3;
                        if(Ans3 == 'n') break;
                    }
                }else if(Ans5 == 0){
                    break;
                }else {
                    cout << "Not find system manage.\nPlease try again.";
                }
            }
            ofstream movielist1 ("listmovie.txt");
                for(int i=0;i<a.size();i++){
                    movielist1 << a[i] << endl;
                }
            movielist1.close();
            ofstream timemovie1 ("timemovie.txt");
                for(int i=0;i<b.size();i++){
                    timemovie1 << b[i] << endl;
                }
            timemovie1.close();
            a.clear();
            b.clear();
        }else if(Ans1==3){
            while(1){
                char x;
                cout << "What time do you want to your cinema open ?" << endl;
                timesetting();
                break;
            }
        }else if(Ans1==4){
            int choose_therter;
            a.clear();
            for(int i = 0;getline(movie,moviename);i++){
                    a.push_back(moviename);
                }
            for(int i = 0;getline(theatera,theatervec);i++){
                    theater.push_back(theatervec);
                }
            while(1){
                string name,namecheck;
                int N;
                cout << "Movie program today :" <<endl;
                for(unsigned int i=0;i<a.size();i++){
                    cout << "- " << a[i] << endl;
                }
                cout << "what movie do want to manage ?" <<endl;
                getline(cin,name);
                for(unsigned int i=0; i < a.size();i++){
                    if(toUpperStr(name)==toUpperStr(a[i])){
                        break;
                    }
                    else if (a.size() == i+1){
                        cout << "There have not movie "<<name<<" int the list try again\n\n";
                        cout << "what movie do want to manage ?" <<endl;
                        getline(cin,name);
                        i=-1;
                        continue;
                    }
                }
                remove_movie(name+file);
                cout << "How many " << name << " show ?" << endl;
                cin >> N;
                cin.ignore();
                for(int i=0;i<N;i++){
                    int hr,min;
                    cout << "What time " << name << "show " << i+1 << "# ?"<< endl;
                    cout << "Example : 8:00am ==> hr : 8" << endl;
                    cout << "                     min : 0" << endl;
                    cout << "          3:25pm ==> hr : 15" << endl;
                    cout << "                     min : 25" << endl;
                    while(1){
                        cout << "Your anwser is :\nHr : " ;
                        cin >> hr;
                        cout << "Min : ";
                        cin >> min;
                        if(hr <= 0 || hr > 24 ){
                            cout << "Hr is wrong !!! please try again.\n";
                        }else if(min < 0 || min >= 60){
                            cout << "Min is wrong !!! please try again.\n";
                        }else break;
                    }
                    int t=timechange(hr,min);
                    
                    cout << "which therter do you want for movie\n";
                    cin >> choose_therter;
                    cin.ignore();
                    vector<string> Cmovie;
                    for(unsigned int i=0; i < theater.size();i++){
                        if(choose_therter == atoi(theater[i].c_str())){
                            for(int j=i+1; theater[j] == " "  || theater[j] == "0";j++){
                                Cmovie.push_back(theater[j]);
                            }
                            break;
                        }
                    }
                    create_movieseat(name+file,Cmovie,t);
                }
                string exit;
                while (true){
                cout << "Anything else????\nPress y to do it again  Press n to exit\n";
                cin >> exit;
                cin.ignore();
                if(toUpperStr(exit) == toUpperStr("y"))break;
                else if (toUpperStr(exit) == toUpperStr("n")) break;
                else{
                    cout << "There have not comman "<<exit<<" try again\n\n"; 
                    continue;
                    }
                }
                if (exit == toUpperStr("n") || exit == toUpperStr("y")) break;
            }
        }else if(Ans1 == 5){
            a.clear();
            for(int i = 0;getline(movie,moviename);i++){
                    a.push_back(moviename);
                }
                check_decition(a);
        }else if(Ans1 == 9){
            reset_password();
        }else if(Ans1==0) {//ออกไปหน้าหลัก(หน้าลูกค้า)
            runprogram();
            break;
        }
        else{
            cout << "Not find system manage.\nPlease try again.";
        }
    }
}



void runprogram(){
    ifstream movie ("listmovie.txt");
    string moviename;
    vector<string> a;
    ifstream input;
    string textline;
    string Ans;
    while(1){
        input.open("listmovie.txt");
        if((getline(input,textline))){
            SetConsoleTextAttribute(h,6);
            cout <<endl<<setw(80) <<"\\|-*-*-*- Hello, please choose your movie -*-*-*-|/\n\n";
            for(int i =1;getline(movie,moviename);i++){
                a.push_back(moviename);
                SetConsoleTextAttribute(h,10);
                cout <<setw(10)<<"|* " <<setw(20)<<left << a[i-1] <<setw(25)<< right <<" *|" ;
                if(i != 0 && i%2 == 0) cout << endl << endl;
            }
            break;
        }else{
            cout << "There are no movies on the list." << endl;
            cout << "Please Manage movie." << endl;
            cout << "Press y to go setting" << endl;
            cout << ">> ";
            cin >> Ans;
            while(1){
                if(toUpperStr(Ans) == toUpperStr("y")){
                    admin(room);
                    input.close();
                    break;
                }else{
                    cout << "Press y to go setting" << endl;
                    cout << ">> ";
                    cin >> Ans;
                }
            }
        }
    }
    SetConsoleTextAttribute(h,15);
    cout <<"\n>>> ";
    getline(cin,moviename);
    for(int i=0,j=0;i<a.size();i++){
        if(moviename == passwordcheck()) {
            admin(room); // ถ้าพิมพ์ 1 จะทำการสร้างโรง เหมือน main เมื่อก่อน
            break;
        }
        if(toUpperStr(moviename) == toUpperStr(a[i])){             // หาหนังแล้วเข้าหน้าเลือกที่นั่ง *ยังไม่เสร็จ*
            check_time(moviename);
            j++;
        }
        else if(i== a.size()-1 && j ==0){
            SetConsoleTextAttribute(h,04);
            cout << "We cannot found movie please try again\n"; //กรณีหาหนังไม่เจอ
            SetConsoleTextAttribute(h,15);
            cout << ">>> ";
            getline(cin,moviename);
            i = -1;
            continue;
        }
    }
}

int main(){
    if(refac == 0) passwordconfig();
    runprogram();
    return 0;
}