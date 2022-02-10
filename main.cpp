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

string  file= ".txt";

string password;
string Ans;
int time_HR,time_min;
int timeStart,timeLong,MinniStart;
int minnilong=0;
int timeend=0;
int MinTimeEnd;
int sum;
int Ans2;
int room;
int dotCal =0;
int dotEnd = 0;
int dotspace = 0;
int Run = 0;
int Round = 0;
int Break = 0;
int Haze = 0;
string Ans3;
vector<int> Mtime;
vector<string> line;
vector<string> order;
vector<int> close;

void settime(int &x,int &y,int &mx,int &my){
    cout << "START ";
    cin >> x;
    cout << x << ":";
    cin >> mx;
    cout << "howlong ";
    cin >> y;
    cout << y << ":";
    cin >> my;
}

void Calcu(int &x,int &y,int &mx,int &my,int &end,int &mend){
    int sum = 0;
    sum = mx + my;
        if(sum > 60 || sum == 60){
            y += 1;
            sum = sum - 60;
        }
    cout << "star " << x << ":" << mx << endl;
    cout << "End " << x+y << ":" << sum << endl;
    end = x+y;
    mend = sum;
    
}

void Line(int timeLong,int minnilong,int timeStart,int MinniStart,int timeend,int MinTimeEnd,int sum){
    for(int i = 0;i<sum;i++){
        cout << "-" ;
    }
    cout << endl;
    cout << timeStart << ":" << MinniStart;
        for(int i=0;i<sum - 8;i++){
            cout << " ";
        } 
        cout << timeend << ":" << MinTimeEnd << endl;

}  

void showsetting(int x,int timeLong,int minnilong ,int timeStart,int MinniStart,int timeend,int MinTimeEnd,int &sum){
    sum = 0;
    sum += (timeLong*12);
    sum += (minnilong/5);
    cout << "Open - Close" << endl;
        Line(timeLong,minnilong,timeStart,MinniStart,timeend,MinTimeEnd,sum);
}

void checkAnsBOBA(string &Ans){
    string sum;
    cout << "                                    right or No" << endl;
    cout << "                                    (Yes = y,No = n)" << endl;
    cout << "                                    Your Answer is ";
    cin >> sum;
    Ans = sum;
}

string checkAns3(string &Ans3){
return Ans3;
}



void timesetting1(){
    do{
    settime(timeStart,timeLong,MinniStart,minnilong);
    Calcu(timeStart,timeLong,MinniStart,minnilong,timeend,MinTimeEnd);
    showsetting(room,timeLong,minnilong,timeStart,MinniStart,timeend,MinTimeEnd,sum);
    checkAnsBOBA(Ans);
        }while(Ans != "y");
        ofstream Outputfile("Timeline.txt");
        for(int j=0;j<room;j++){   
            for(int i=0;i<sum;i++){
                Outputfile << "-";
            }
        Outputfile << endl;    
        }
        Outputfile.close();
}

void dot(int timeStart,int MinniStart){
    dotCal = (timeStart*60)+(MinniStart);
    dotEnd = (timeend*60)+MinTimeEnd;
    dotspace = dotEnd - dotCal;
}

void addMtive2Vec(){
    ifstream input;
    input.open("movietime.txt");
    string textline;
    int sum;
    while(getline(input, textline)){
        sum = stoi(textline);
        Mtime.push_back(sum+Break);
    }
}

void addline2Vec(){
    ifstream input;
    input.open("Timeline.txt");
    string textline;
    while(getline(input, textline)){
        line.push_back(textline);
    }
}

void dot2int(int dot){
    int Hsum = 0;
    int sum = 0;
    while(dot >= 60){
        dot -= 60;
        Hsum++;
    }sum = dot;
     for(int i;i<Run;i++){
        cout << " ";
    }
    cout << Hsum << ":" << sum;
}

void dotspace2int(int dot){
    for(int i;i<(dot/5);i++){
        cout << " ";
    }
}


void Timebar(int dotCal,int dotEnd,int dotspace){
    dot2int(dotCal);
    dotspace2int(dotspace);
    if(Round == 0){
    dot2int(dotEnd);
    Round = 1;
    }
}

void movieBar(){
    ifstream input;
    input.open("listmovie.txt");
    string textline;
    ifstream input2;
    input2.open("movietime.txt");
    string textline2;
    while(getline(input, textline)){
        getline(input2, textline2);
        int sum = stoi(textline2);
        sum = sum +Break;
        cout << textline << " "<< sum << " ";
        }
    cout << endl;
}

void Askadd(){
    cout << endl;
    cout << "what movie do you add" << endl;
    cout << "your answer is ";
}

void Editline(int Ans,int i,int &Run){
    int sum = Mtime[Ans];
    int dod = 0;
    int stan = dotEnd;
    dod += sum;
    dotCal = dotCal+dod;;
        if(dotCal >= dotEnd){
            dotCal = dotCal - dotEnd;
            dod = sum/5;
                for(int l=0;l<line[0].size();l++){
                    line[i][l] = '*';
                }
                    for(int k=0;k<(dotCal/5);k++){
                        line[i].push_back('*');
                    }
                dotCal = stan+(dotCal/5)*5;
        }else{
            dod = sum/5;
            for(int j=0;j<dod;j++){
                line[i][j+Run] = '*';
            }
        }
    Run += sum/5;
    cout << line[i] << endl;

}

void Continew(){
    cout << endl << "Continew " << endl;
    cout << "                                    right or No" << endl;
    cout << "                                    (Yes = y,No = n)" << endl;
    cout << "                                    Your Answer is ";
}

void SetZero(){
dot(timeStart,MinniStart);
Run = 0;
}

void numbercini(int i){
    cout << endl << "CIneMA " << i+1 << endl;
}

void pushOrder(int x){
    string sum = to_string(x);
    order.push_back(sum);
}

void pushOrderNew(){
    order.push_back("\n");

}

void setBreak(int &Break){
    cout << "How many time Break Betaween Movie" << endl;
        while(1){
            cin >> Break;
            if(Break %5 == 0){
                break;
            }else{
            cout << "plse cout 5/5 = 1" << endl;;
            }
        }
}


void addOrder2text(){
    ofstream dest;
    dest.open("Order.txt");
    for(int i=0;i<order.size();i++){
        dest << order[i];
        Haze++;
    }
    dest.close();
}

void Overtime(int dotCal,int dotEnd){
    int BreakCal,BreakEnd;
    int Hour = 0;
    BreakCal =dotCal;
    BreakEnd=dotEnd;
    int sum = BreakCal-BreakEnd;
        while(sum >= 60){
            sum -=60;
            Hour++;
        }
    cout << Hour << ":" << sum;
    close.push_back(sum);
}
void Runtime(int x){
    int sum = 0;
    sum = (Mtime[x]/5)-(Break/5);
    SetConsoleTextAttribute(h,11);
        for(int i=0;i<sum;i++){
            cout << "*";
        }
    SetConsoleTextAttribute(h,7);
}
   
void RunBreak(){
    int sum = Break/5;
    SetConsoleTextAttribute(h,14);
    for(int i=0;i<sum;i++){
        cout << "*";
    }
    SetConsoleTextAttribute(h,7);
}

void RunBreakTime(){
    int sum = Break/5;
        for(int i=0;i<sum;i++){
        cout << " ";}
}

void Timbar(int x,int y){
    int hours = 0;
    while(x >= 60){
        x -= 60;
        hours++;
    }
    cout << hours << ":" << x << "[" << y << "]";
}


void ComfermOrder(){
    int sum = 0;
    string y;
    ifstream input;
    input.open("Order.txt");
    string textline;
        for(int j=0;j<room;j++){
            getline(input, textline);
            cout << endl;
            for(int i =0;i<textline.size();i++){
                y = textline[i];
                sum = stoi(y);
                RunBreak();
                Runtime(sum-1);
            }
        cout << endl;
        cout << "TimeLine  ";
            for(int k=0;k<textline.size();k++){
                RunBreakTime();
                Timbar(dotCal,sum);
                dotCal += (Mtime[sum-1] + Break);
            }
            dotCal = (timeStart*60)+(MinniStart);
        }
}

void checkAns2(){
    int aum;
    while(1){
        cin >> aum;
        if(aum > Mtime.size() || aum <= 0){
            Askadd();
            cout << "Try again" << endl;
            continue;
        }else{
            break;
        }
    }
    Ans2 = aum;
}

void checkAns3_1(){
    string aum;
    while(1){
        cin >> aum;
        if(aum == "n" || aum == "y"){
            break;
        }else{
            cout << endl << "Try again" << endl;
            cout << "Continew " << endl << "Your Ans ";
            continue;
        }
    }
    Ans3 = aum;
}


void check_time(string movie){
    string a;
    vector<string> movie_time;
    int number;
    ifstream check_list (movie+file);
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
}

void timesetting(void);
string checkAns(string &);
void runprogram();

//ไม่เสร็จ
void remove_movie(string movie_name){
    const char *str = movie_name.c_str();
    remove(str);
}

//สร้างไฟล์ขึ้นมาเพื่อจัดเก็บข้อมูลที่นั่ง สร้างต่อจากเดิม
void create_movieseat(string movie_name,vector<string> a,int time){
    ofstream seatmovie (movie_name,ios::app);
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




void ShowListMovie(vector<string> a){
    cout << "This is your listmovie."<< endl;
    cout << "-------------------------------------------"<< endl;
    for(int i =0;i<a.size();i++){
        cout << a[i] << "   <--- " << i+1 << endl;
    }
    cout << "-------------------------------------------"<< endl;
}
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
        cout << "Which system do you want to manage ?\n1 : Theater manage\n2 : Movie manage\n3 : Time manage\n4 : Showing movie manage\n9 : Reset Password\n0 : Go to Home page\nYour answer is ";
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
                                remove_movie(a[Ans4-1]+file);
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
                timesetting1();
                    dot(timeStart,MinniStart);
                    setBreak(Break);
                    addMtive2Vec();
                    addline2Vec();
                        for(int i = 0;i<room;i++){
                            do{
                            numbercini(i);
                            movieBar();
                            cout << line[i] << endl;
                            Timebar(dotCal,dotEnd,dotspace);
                            Askadd();
                            checkAns2();
                            pushOrder(Ans2);
                            Editline(Ans2-1,i,Run);
                            Timebar(dotCal,dotEnd,dotspace);
                                if(dotCal > dotEnd){
                                    cout << endl << "Overtime" << endl;
                                    Overtime(dotCal,dotEnd);
                                    SetZero();
                                    break;
                                }
                                Continew();
                                checkAns3_1();
                                if(checkAns3(Ans3) == "n"){
                                    SetZero();
                                    close.push_back(dotCal);
                                    break;
                                }else if(checkAns3(Ans3) == "y"){
                                    continue;
                                }
                            }while(true);
                        pushOrderNew();
                        }
                    addOrder2text();
                    ComfermOrder();
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
                if(toUpperStr(exit) == "Y")break;
                else if (toUpperStr(exit) == toUpperStr("n")) break;
                else{
                    cout << "There have not comman "<<exit<<" try again\n\n"; 
                    continue;
                    }
                }
                if (toUpperStr(exit) == "N" || toUpperStr(exit) == "Y") break;
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

void showtime_movie(){
    ifstream source;
    source.open("movietime.txt");
    string textline;
    while(getline(source,textline))
    cout << textline << "  ";
}


int main(){
    if(refac == 0) passwordconfig();
    runprogram();
    return 0;
}