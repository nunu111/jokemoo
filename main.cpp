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
#include"create_payment.h"
#include"SelectSect.h"

using namespace std;

string  file= ".txt",directfile_movie = "all movie/",directfile_price = "all price_movie/",directfile1 = "all Theater/",th= "theater";

string password;
string Ans;

struct showing
{
    string name;
    int time1;
    int time2;
};

int time_HR,time_min;
void runprogram();

void check_time(string movie){
    string a;
    vector<string> movie_time;
    int number;
    ifstream check_list (directfile_movie+movie+file);
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
    SelectSeat(movie,movie_time[number-1]);
    runprogram();
}

string checkAns(string &);
void runprogram();

void remove_movie(string movie_name){
    const char *str = movie_name.c_str();
    remove(str);
}

//สร้างไฟล์ขึ้นมาเพื่อจัดเก็บข้อมูลที่นั่ง สร้างต่อจากเดิม
void create_movieseat(string movie_name,vector<string> a,int time){
    ofstream seatmovie (directfile_movie +movie_name,ios::app);
        seatmovie << time << endl;
        for(unsigned int j=0 ; j< a.size();j++){
            seatmovie << a[j] << "\n";
        }
    seatmovie.close();
}

int timechange(int hr,int min){
    return (hr*60)+min;
}

void timechange1(int t){
    int hr = t/60;
    int min = t%60;
    if(hr ==0){
        cout << "00:";
    }else{
        cout << hr << ":";
    }
    if(min ==0){
        cout << "00";
    }else if(min < 10){
        cout << "0" << min;
    }else{
        cout << min;
    }
}

void seat(vector<string> &a,int N,int M){   
        for(int i=0;i<N*M;i++){
                a.push_back(".");
        }

}

void walk(vector<string> &a,int x,int number,int M){
    if(x > 0 && x<M){
        for(int i=(x-1)*M;i<M*x;i++){
            a[i] = " ";
        }
    }
    else;
}

void comferm_seat(vector<string> &a,int N,int M){
    for(int i=0;i<N*M;i++){
        if(a[i] == "."){
            a[i] = "0";
        }
    }
        
}

void showEX1(int &N,int &M){
    SetConsoleTextAttribute(h,06);
    cout << "Please fill in the number of row seats in  the movie theather (including aisle) " << endl;
    SetConsoleTextAttribute(h,06);
    cout << "* Example *" << endl;
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
    cout << "        Number_of_seat =  column X line" << endl;
    SetConsoleTextAttribute(h,07);
    cout << "    3 |  . . . . .  |" << endl << endl;
    SetConsoleTextAttribute(h,04);
    cout << "    ^              ";
    SetConsoleTextAttribute(h,11);
    cout << "                 column = ";
    cin >> M;
    SetConsoleTextAttribute(h,04);
    cout << "   line         ";
    SetConsoleTextAttribute(h,11);
    cout << "                    line = ";
    cin >> N;
    cout << endl;
    SetConsoleTextAttribute(h,07);
    system("CLS");
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

void showing_theater(string name_theater,string name_movie,int time,int l){
     ofstream seatmovie (name_theater,ios::app);
        seatmovie << name_movie << ":" << time << "," << l << endl;
    seatmovie.close();
}

void show_movietheater(int r){
    for(int i = 1;i <= r ; i++){
        string b;
        stringstream ss;
            ss << i;
            string s;
            ss >> s;
        ifstream a (directfile1+th+s);
        cout << "Theater " << i << " :\n";
        while(getline(a,b)){
            char c[30];
            int n1,n2;
            sscanf(b.c_str(),"%[^:]:%d,%d",c,&n1,&n2);
            
            cout << c << "  =>  " ;
            timechange1(n1);
            cout << " - ";
            timechange1(n1+n2);
            cout << endl;
        }
    }
}
bool check_movietheater(int r,int t ,int tl,vector<showing> x){
    bool ans=true;
        string b;
        stringstream ss;
            ss << r;
            string s;
            ss >> s;
        ifstream a (directfile1+th+s);
        while(getline(a,b)){
            string s;
            char c[30];
            int n1,n2;
            sscanf(b.c_str(),"%[^:]:%d,%d",c,&n1,&n2);
            s=c;
            x.push_back({s,n1,n2});
        }
    for(unsigned int i=0 ; i < x.size() ; i++){
        if(t >= x[i].time1){
            if((x[i].time1+x[i].time2)>t){
            ans= false;
            break;
            }else if(t == x[i].time1){
                return false;
            }
        }else if(t<x[i].time1){
            if((t+tl)>x[i].time1){
            ans = false;
            break;
            }
        }
    }
    return ans;
}


void movie_theater(vector<string> &a,vector<int> &b,vector<string> &theater,int mode,string name1,int time1,int room){
    vector<showing> x;
    int choose_therter;
    do{
        string name = name1;
        int N,time = time1;
        if(mode == 0){
            SetConsoleTextAttribute(h,14);
            cout << "Movie program today :" <<endl;
            SetConsoleTextAttribute(h,11);
            for(unsigned int i=0;i<a.size();i++){
                cout << "- " << a[i] << endl;
            }
            SetConsoleTextAttribute(h,6);
             cout << "what movie do want to manage ?" <<endl;
             SetConsoleTextAttribute(h,11);
            getline(cin,name);
            for(unsigned int i=0; i < a.size();i++){
                if(toUpperStr(name)==toUpperStr(a[i])){
                    name = a[i];
                    time = b[i];
                    break;
                }
                else if (a.size() == i+1){
                    SetConsoleTextAttribute(h,4);
                    cout << setw(10) <<  "There have not movie ";
                    SetConsoleTextAttribute(h,10);
                    cout <<name;
                    SetConsoleTextAttribute(h,4);
                    cout <<" in the list try again\n\n";
                    SetConsoleTextAttribute(h,11);
                    cout << "what movie do want to manage ?" <<endl;
                    getline(cin,name);
                    i=-1;
                    system("CLS");
                    continue;
                }
            }
            remove_movie(directfile_movie+name+file);
            system("CLS");
        }
        SetConsoleTextAttribute(h,6);
        cout << "How many " << name << " show ?" << endl;
        SetConsoleTextAttribute(h,11);
        cin >> N;
        cin.ignore();
        for(int i=0;i<N;i++){
            int hr,min,t;
            while(1){
                SetConsoleTextAttribute(h,10);
                show_movietheater(room);
                SetConsoleTextAttribute(h,6);
                cout << "What time " << name << " show " << i+1 << "# ?"<< endl;
                cout << "Example : 8:00am ==> hr : 8" << endl;
                cout << "                     min : 0" << endl;
                cout << "          3:25pm ==> hr : 15" << endl;
                cout << "                     min : 25" << endl;
                while(1){
                    SetConsoleTextAttribute(h,11);
                    cout << "Your anwser is :\nHr : " ;
                    cin >> hr;
                    cout << "Min : ";
                    cin >> min;
                    if(hr <= 0 || hr > 24 ){
                        SetConsoleTextAttribute(h,4);
                        cout << "Hr is wrong !!! please try again.\n";
                        SetConsoleTextAttribute(h,11);
                    }else if(min < 0 || min >= 60){
                        SetConsoleTextAttribute(h,4);
                        cout << "Min is wrong !!! please try again.\n";
                        SetConsoleTextAttribute(h,11);
                    }else break;
                }
                t=timechange(hr,min);
                SetConsoleTextAttribute(h,6);
                cout << "which therter do you want for movie\n";
                cin >> choose_therter;
                cin.ignore();
                if(check_movietheater(choose_therter,t,time,x)){
                    break;
                }else {
                    SetConsoleTextAttribute(h,4);
                    cout << "This movie overlaps another movie.Please try again."<< endl;
                    system("pause");
                }
            
            }
            double price=0;
            SetConsoleTextAttribute(h,6);
            cout << "How cost do you want to make\n";
            cin >> price;
            vector<string> Cmovie;
            for(unsigned int i=0; i < theater.size();i++){
                if(choose_therter == atoi(theater[i].c_str())){
                    for(int j=i+1; theater[j] == " "  || theater[j] == "0";j++){
                        Cmovie.push_back(theater[j]);
                    }
                    system("CLS");
                    break;
                }
            }
            create_movieseat(name+file,Cmovie,t);
            create_payment(directfile_price+name,price,t);
            stringstream ss;
            ss << choose_therter;
            string s;
            ss >> s;
            showing_theater(directfile1+th+s,name,t,time);
        }
        if(mode == 0){
            string exit;
            while (true){
                cout << "Anything else????\nPress y to do it again  Press n to exit\n";
                SetConsoleTextAttribute(h,11);
                cin >> exit;
                cin.ignore();
                system("CLS");
                if(toUpperStr(exit) == "Y")break;
                else if (toUpperStr(exit) == toUpperStr("n")) break;
                else{
                    SetConsoleTextAttribute(h,4);
                    cout << "There have not comman ";
                    SetConsoleTextAttribute(h,11);
                    cout <<exit;
                    SetConsoleTextAttribute(h,6);
                    cout <<" try again\n\n"; 
                    continue;
                }
            }
            if (toUpperStr(exit) == "N" || toUpperStr(exit) == "Y") {
                system("CLS");
            }
            break;
        }
    }while(mode == 0);
}

void ShowListMovie(vector<string> a){
    SetConsoleTextAttribute(h,14);
    cout << "This is your listmovie."<< endl;
    SetConsoleTextAttribute(h,10);
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
    int r=0;

    while(getline(movie,moviename)){
        a.push_back(moviename);
    }
    for(int i =0;getline(time,movietime);i++){
        b.push_back(stoi(movietime));
    }
    for(int i =0;getline(theatera,theatervec);i++){
        theater.push_back(theatervec);
        if(theatervec != "0" && theatervec != " "){
            r++;
        }

    }
    while(1){
        //เลือกระบบที่ต้องการแก้ไข
        SetConsoleTextAttribute(h,14);
        cout << "Which system do you want to manage ?" ;
        SetConsoleTextAttribute(h,6);
        cout << " \n1 : Theater manage\n2 : Movie manage\n3 : Showing movie manage\n9 : Reset Password\n0 : Go to Home page";
        SetConsoleTextAttribute(h,11);
        cout << "\nYour answer is ";
        cin >> Ans1;
        cin.ignore();
        system("CLS");
        if(Ans1==1){//ระบบจัดการโรงหนัง
            while(1){
                int count=1,room;
                SetConsoleTextAttribute(h,14);
                cout << "How many theater do you want ?";
                SetConsoleTextAttribute(h,11);
                cout << "\nYour answer is ";
                cin >> room;
                r = room;
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
                        SetConsoleTextAttribute(h,4);
                        cout << "Please try again." << endl;
                    }
                }
                if(Ans == "y"){
                    system("CLS");
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
                SetConsoleTextAttribute(h,14);
                cout << "Movie program today" << endl;//แสดงโปรแกรมหนังวันนี้
                for(int i =0;i <a.size();i++){
                    cout << "- " << a[i] << endl;
                }
                //เลือกเพิ่ม\ลบหนัง
                SetConsoleTextAttribute(h,6);
                cout << "What do you want to do ?";
                SetConsoleTextAttribute(h,14);
                cout << "\n1 : Add movie\n2 : Remove movie\n0 : Go to Admin setting";
                SetConsoleTextAttribute(h,11);
                cout << "\nYour answer is ";
                cin >> Ans5;
                cin.ignore();
                system("CLS");
                if(Ans5 == 1){//ระบบเพิ่มหนัง
                    while(1){
                        int t;
                        string name;
                        SetConsoleTextAttribute(h,6);
                        cout << "What movie do you to add ?" << endl;
                        SetConsoleTextAttribute(h,11);
                        cout << "Your answer is ";
                        getline(cin,name);
                        SetConsoleTextAttribute(h,6);
                        cout << "How long this movie ?";
                        SetConsoleTextAttribute(h,4);
                        cout << "(minute unit)" << endl; 
                        SetConsoleTextAttribute(h,11);
                        cout << "Your answer is ";
                        cin >> t;
                        while(1){
                            SetConsoleTextAttribute(h,6);
                            cout << "Where do you want to insert movie in the list ?" << endl;
                            SetConsoleTextAttribute(h,13);
                            ShowListMovie(a);
                            SetConsoleTextAttribute(h,11);
                            cout << "Your answer is ";
                            cin >> Ans2;
                            if(Ans2 > 0 && Ans2 <= a.size()+1){
                                a.insert(a.begin()+Ans2-1,name);
                                b.insert(b.begin()+Ans2-1,t);
                                break;
                            }
                            else{
                                SetConsoleTextAttribute(h,4);
                                cout << "Wrong!!! Please try again."<< endl;
                            }
                        }
                        ShowListMovie(a);
                        movie_theater(a,b,theater,1,name,t,r);
                        cout << "Anything else ? (Yes = [Y] or anything,No = [N])"<< endl;
                        cin >> Ans3;
                        cin.ignore();
                        if(Ans3 == 'n') break;
                    }
                }else if(Ans5 == 2){//ระบบลบหนัง
                    while(1){
                        while(1){    
                            SetConsoleTextAttribute(h,6);
                            cout << "Which movie do you to delete ?" << endl ;
                            ShowListMovie(a);
                            SetConsoleTextAttribute(h,11);
                            cout << "Your answer is ";
                            cin >> Ans4;
                            if(Ans4 > 0 && Ans4 <= a.size()+1){
                                remove_movie(directfile_movie+a[Ans4-1]+file);
                                a.erase(a.begin()+Ans4-1);
                                b.erase(b.begin()+Ans4-1);
                                system("CLS");
                                break;
                            }
                            else{
                                SetConsoleTextAttribute(h,4);
                                cout << "Wrong!!! Please try again."<< endl;
                            }
                        }
                        ShowListMovie(a);
                        SetConsoleTextAttribute(h,6);
                        cout << "Anything else ? (Yes = y or anything,No = n)"<< endl;
                        SetConsoleTextAttribute(h,11);
                        cin >> Ans3;
                        system("CLS");
                        if(Ans3 == 'n') break;
                        
                    }
                }else if(Ans5 == 0){
                    break;
                }else {
                    SetConsoleTextAttribute(h,4);
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
            movie_theater(a,b,theater,0,"name",0,r);
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
            SetConsoleTextAttribute(h,4);
            cout << "Not find system manage.\nPlease try again.\n";
            SetConsoleTextAttribute(h,7);
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

            cout <<endl<<right<<setw(100) <<"\\|-*-*-*- Hello, please choose your movie -*-*-*-|/\n\n";
            for(int i =1;getline(movie,moviename);i++){
                a.push_back(moviename);
                SetConsoleTextAttribute(h,10);
                cout <<setw(10)<<"|* " <<setw(20)<<left << a[i-1] <<setw(40)<< right <<" *|" ;
                if(i != 0 && i%2 == 0) cout << endl << endl;
            }
            break;
        }else{
            SetConsoleTextAttribute(h,14);
            cout  << "There are no movies on the list." << endl;
            cout  << "Please Manage movie." << endl;
            SetConsoleTextAttribute(h,6);
            cout  << "Press y to go setting" << endl;
            SetConsoleTextAttribute(h,11);
            cout  << ">> ";
            cin >> Ans;
            system("CLS");
            while(1){
                if(toUpperStr(Ans) == "Y"){
                    admin();
                    input.close();
                    break;
                    system("CLS");
                }else{
                    SetConsoleTextAttribute(h,4);
                    cout << "Press y to go setting" << endl;
                    SetConsoleTextAttribute(h,11);
                    cout << ">> ";
                    cin >> Ans;
                    system("CLS");
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

