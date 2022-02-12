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
#include"make_price.h"
#include"SelectSect.h"

using namespace std;

string  file= ".txt",directfile = "all movie/";

string password;
string Ans;

int time_HR,time_min;

void check_time(string movie){
    string a;
    vector<string> movie_time;
    int number;
    ifstream check_list (directfile+movie+file);
    for (int i=0;getline(check_list,a);i++){
        if(a != "0" && a != " " && a != "X"){
            movie_time.push_back(a);
        }
    }
    cout << "this movie have time ....\n";
    for(int i=0; i<movie_time.size();i++){
        cout << "["<<i+1<<"] ";
        time_HR = atoi(movie_time[i].c_str())/60;
        time_min = atoi(movie_time[i].c_str())-(time_HR*60);
        if(time_min == 0){
            cout << time_HR <<":"<<"00"<< "     ";
        }
        else{
            cout << time_HR <<":"<<time_min<< "     ";
        }
    
    }
    cout << endl<< ">>> ";
    cin >> number;
    cin.ignore();
    SelectSeat(directfile+movie ,movie_time[number-1]);
}

string checkAns(string &);
void runprogram();

void remove_movie(string movie_name){
    const char *str = movie_name.c_str();
    remove(str);
}

//สร้างไฟล์ขึ้นมาเพื่อจัดเก็บข้อมูลที่นั่ง สร้างต่อจากเดิม
void create_movieseat(string movie_name,vector<string> a,int time){
    ofstream seatmovie (directfile +movie_name,ios::app);
        seatmovie << time << endl;
        for(unsigned int j=0 ; j< a.size();j++){
            seatmovie << a[j] << "\n";
        }
    seatmovie.close();
}

int timechange(int hr,int min){
    return (hr*60)+min;
}

void seat(vector<string> &a,int N,int M){   
        for(int i=0;i<N*M;i++){
                a.push_back(".");
        }

}

void walk(vector<string> &a,int x,int number,int M){
    for(int i=(x-1)*M;i<M*x;i++){
        a[i] = " ";;
    }
}

void comferm_seat(vector<string> &a,int N,int M){
    for(int i=0;i<N*M;i++){
        if(a[i] == "."){
            a[i] = "0";
        }
    }
        
}

void showEX1(int &N,int &M){
    cout << "Please fill in the number of row seats in  the movie theather (including aisle) " << endl;
    SetConsoleTextAttribute(h,06);
    cout << "Example" << endl;
    SetConsoleTextAttribute(h,07);
    cout << "        ";
        for(int i=0;i<5;i++){
            cout << " ";
            cout << char('A'+i); 
        }
        SetConsoleTextAttribute(h,04);
        cout << "   << column";
        SetConsoleTextAttribute(h,7);
    cout << endl;
    cout << "    1 |  . . . . .  |";
    SetConsoleTextAttribute(h,06);
    cout << "               Equation" << endl;
    SetConsoleTextAttribute(h,07);
    cout << "    2 |  . . . . .  |";
    SetConsoleTextAttribute(h,06);
    cout << "        Number_of_seat =  line X column" << endl;
    SetConsoleTextAttribute(h,07);
    cout << "    3 |  . . . . .  |" << endl << endl;
    SetConsoleTextAttribute(h,04);
    cout << "         ^ ^ ^ ^ ^ ";
    SetConsoleTextAttribute(h,11);
    cout << "                 column = ";
    cin >> M;
    SetConsoleTextAttribute(h,04);
    cout << "            line";
    SetConsoleTextAttribute(h,11);
    cout << "                    line = ";
    cin >> N;
    cout << endl;
    SetConsoleTextAttribute(h,07);
}

void showEX2(int &A){
    SetConsoleTextAttribute(h,06);
    cout << "                                    Where is your aisle?" << endl;
    SetConsoleTextAttribute(h,11);
    cout << "                                    column = ";
    cin >> A;
    SetConsoleTextAttribute(h,07);
}

void showEX3(int x){
    SetConsoleTextAttribute(h,06);
    cout << "        Your cinema" << endl << endl;
    SetConsoleTextAttribute(h,07);
}

string checkAns(string &Ans){
    string sum;
    SetConsoleTextAttribute(h,06);
    cout << "                                    right or No" << endl;
    cout << "                                    (Yes = y,No = n)" << endl;
    SetConsoleTextAttribute(h,11);
    cout << "                                    Your Answer is ";
    cin >> sum;
    SetConsoleTextAttribute(h,07);
    Ans = sum;
    return "Ans";
}

void checkAns2(string &Ans){
    string sum;
    SetConsoleTextAttribute(h,06);
    cout << "  right or No" << endl;
    cout << "  (Yes = y,No = n)" << endl;
    SetConsoleTextAttribute(h,11);
    cout << "Your Answer is ";
    cin >> sum;
    SetConsoleTextAttribute(h,07);
    Ans = sum;
}

void movie_theater(vector<string> &a,vector<int> &b,vector<string> &theater,int mode,string name1){
    int choose_therter;
    do{
        string name = name1;
        int N;
        if(mode == 0){
            cout << "Movie program today :" <<endl;
            for(unsigned int i=0;i<a.size();i++){
                cout << "- " << a[i] << endl;
            }
             cout << "what movie do want to manage ?" <<endl;
            getline(cin,name);
            for(unsigned int i=0; i < a.size();i++){
                if(toUpperStr(name)==toUpperStr(a[i])){
                    name = a[i];
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
            remove_movie(directfile+name+file);
        }
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
        if(mode == 0){
            string exit;
            while (true){
                cout << "Anything else????\nPress y to do it again  Press n to exit\n";
                cin >> exit;
                cin.ignore();
                if(toUpperStr(exit) == "Y")break;
                else if (toUpperStr(exit) == toUpperStr("n")) break;
                else{
                    cout << "There have not comman "<<exit<<" try again\n\n"; 
                    continue;
                }
            }
            if (toUpperStr(exit) == "N" || toUpperStr(exit) == "Y") break;
        }
    }while(mode == 0);
}

void ShowListMovie(vector<string> a){
    cout << "This is your listmovie."<< endl;
    cout << "-------------------------------------------"<< endl;
    for(int i =0;i<a.size();i++){
        cout << a[i] << "   <--- " << i+1 << endl;
    }
    cout << "-------------------------------------------"<< endl;
}
//คล้าย main เลย แต่ต้องพิมพ์ 1 ก่อน
void admin(){
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

    while(getline(movie,moviename)){
        a.push_back(moviename);
    }
    for(int i =0;getline(time,movietime);i++){
        b.push_back(stoi(movietime));
    }
    for(int i =0;getline(theatera,theatervec);i++){
        theater.push_back(theatervec);
    }
    while(1){
        //เลือกระบบที่ต้องการแก้ไข
        cout << "Which system do you want to manage ?\n1 : Theater manage\n2 : Movie manage\n3 : Showing movie manage\n9 : Reset Password\n0 : Go to Home page\nYour answer is ";
        cin >> Ans1;
        cin.ignore();
        if(Ans1==1){//ระบบจัดการโรงหนัง
            while(1){
                int count=1,room;
                cout << "How many theater do you want ?\nYour answer is ";
                cin >> room;
                theater.clear();
                for(int i=0; i < room ;i++){
                    showEX1(N,M);
                    vector<string> block;
                    seat(block,N,M);
                    show(block,N,M);
                    int A;
                    showEX2(A);
                    walk(block,A,N*M,M);
                    show(block,N,M);
                    comferm_seat(block,N,M);
                    showEX3(1);
                    show(block,N,M);
                    stringstream ss;
                    ss << count;
                    string s;
                    ss >> s;
                    theater.push_back(s);
                    for(int i=0 ; i<N*M ; i++){
                        theater.push_back(block[i]);
                    }
                    count++;
                    block.clear();
                }
                while(1){
                    checkAns(Ans);
                    if(toUpperStr(Ans) == "Y") break;
                    else if(toUpperStr(Ans) == "N"){
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
        }else if(Ans1==2){//ระบบจัดการรอบหนัง
            int Ans5,Ans2,Ans4;
            char Ans3;
            while(1){
                cout << "Movie program today" << endl;//แสดงโปรแกรมหนังวันนี้
                for(int i =0;i <a.size();i++){
                    cout << "- " << a[i] << endl;
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
                        movie_theater(a,b,theater,1,name);
                        cout << "Anything else ? (Yes = [Y] or anything,No = [N])"<< endl;
                        cin >> Ans3;
                        cin.ignore();
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
                                remove_movie(directfile+a[Ans4-1]+file);
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
        }else if(Ans1 ==3){
            movie_theater(a,b,theater,0,"name");
        }else if(Ans1 == 5){
                check_decition(a);
        }else if(Ans1 == 9){
            reset_password();
        }else if(Ans1==0) {//ออกไปหน้าหลัก(หน้าลูกค้า)
            a.clear();
            b.clear();
            theater.clear();
            runprogram();
            break;
        }
        else{
            cout << "Not find system manage.\nPlease try again.\n";
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
                if(toUpperStr(Ans) == "Y"){
                    admin();
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
            admin(); // ถ้าพิมพ์ 1 จะทำการสร้างโรง เหมือน main เมื่อก่อน
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

