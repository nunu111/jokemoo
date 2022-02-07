#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

int timeStart,timeLong,MinniStart,timeend,minnilong,MinTimeEnd,sum,room;
string Ans;

void remove_movie(string movie_name){
    const char *str = movie_name.c_str();
    remove(str);
}

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

void seat(string a[],int N,int M){   
        for(int i=0;i<N*M;i++){
                a[i] = ".";
        }

}

void show(string a[],int N,int M){
    cout << "          ";
    for(int p=0;p<M;p++){
        cout << char('A'+p);
        cout << " ";
    }
    cout << endl;
    for(int i=0;i<N;i++){
        cout << "    ";
        int A = i+1;
        cout << setw(3) << left <<A;
        cout << "|  " ;
        for(int j=0;j<M;j++){
            cout << a[j+(i*M)];
            cout << " ";
        }
        cout << " |" <<endl; 
    }
    cout << endl;  
}

void walk(string a[],int x,int number,int M){
    for(int i=(x-1)*M;i<M*x;i++){
            a[i] = " ";
    }
}

void comferm_seat(string a[],int N,int M){
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

void settime(int &x,int &y,int &mx,int &my,int &end){
    cout << "Your answer is ( XX hr. : xx m.) ";
    cin >> x;
    cout << x << ":";
    cin >> mx;
    cout << "How long do you want to your cinema open ?" << endl;
    cout << "Your answer is ( XX hr. : XX m.) ";
    cin >> y;
    cout << y << ":";
    cin >> my;
}

void Calcu(int &x,int &y,int &mx,int &my,int &end){
    int sum;
    sum = mx + my;
        if(sum > 60 || sum == 60){
            y += 1;
            sum = sum - 60;
        }
    cout << "Open => " << x << ":" << mx << endl;
    cout << "Close => " << x+y << ":" << sum << endl;
    
    
}



void ShowListMovie(vector<string> a){
    cout << "This is your listmovie."<< endl;
    cout << "-------------------------------------------"<< endl;
    for(int i =0;i<a.size();i++){
        cout << a[i] << "   <--- " << i+1 << endl;
    }
    cout << "-------------------------------------------"<< endl;
}

void showtime_movie(){
    ifstream source;
    source.open("movietime.txt");
    string textline;
    while(getline(source,textline))
    cout << textline << "  ";
}


//--------------------------------------------------ล่าง admin


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
    sum = (timeLong*4)+(minnilong/15);
        cout << "Cienama Open - close"<< endl;
        cout << endl;
        Line(timeLong,minnilong,timeStart,MinniStart,timeend,MinTimeEnd,sum);
}



void timesetting(){
    do{
    settime(timeStart,timeLong,MinniStart,minnilong);
    Calcu(timeStart,timeLong,MinniStart,minnilong,timeend,MinTimeEnd);
    showsetting(room,timeLong,minnilong,timeStart,MinniStart,timeend,MinTimeEnd,sum);
    while(1){
        checkAns2(Ans);
        if(Ans == "y") break;
        else if(Ans == "n"){
            break;
        }else{
            cout << "Please try again.";
        }
    }

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