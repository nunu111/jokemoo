#include <iostream>
#include <algorithm>
#include <vector>
#include<fstream>
#include<cstdlib>
#include <math.h>
#include<windows.h>
using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

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
string Ans;
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

void checkAns(string &Ans){
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



void timesetting(){

    do{
    settime(timeStart,timeLong,MinniStart,minnilong);
    Calcu(timeStart,timeLong,MinniStart,minnilong,timeend,MinTimeEnd);
    showsetting(room,timeLong,minnilong,timeStart,MinniStart,timeend,MinTimeEnd,sum);
    checkAns(Ans);
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

int main(){
timesetting();
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
return 0;
}


