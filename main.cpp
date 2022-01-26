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
using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

string password;
int refac;

void passwordcheck(){
    ifstream isthatright ("Password");
    int r;
    string ch;
    vector<char> a;
    
}

void passwordconfig(){
    srand(time(0));
    ifstream pass ("Password");
    string p,bypass;
    if(getline(pass,p)) {
        refac=1;
        pass.close();
    }
    else{
        pass.close();
        cout << "This is the first time you run this program pls input your password" << endl;
        cout <<">> ";
        getline(cin,bypass);
        ofstream by ("Password");
    
        by.close();

    }
}

//ไม่เสร็จ
void remove_movie(string movie_name){
    const char *str = movie_name.c_str();
    remove(str);
    ifstream change ("listmovie.txt");
    string check;
    getline(change,check);
    vector<string> a;
    a.push_back(check);
    change.close();
    for (int i=0;i<a.size();i++){
        if(movie_name == a[i]){
            a[i] =" ";
        }
    }
}

//สร้างไฟล์ขึ้นมาเพื่อจัดเก็บข้อมูลที่นั่ง * ย้ำว่าใช้สร้างเท่านั้นหากใช้ใหม่ข้อมูลเก่าจะหาย *
void create_movieseat(string movie_name,string a[],int N,int M){
    ofstream seatmovie (movie_name);
    for(int i =0;i <N*M;i++){
        seatmovie << a[i] << "\n";
    }
    seatmovie.close();
}
//ยังไม่เสร็จ
void check_seat(string movie_name,string a[]){
    string name,num;
    int i;
    ifstream check (movie_name);
    do
    {
       getline(check,name);
       i++;
       if (i >200) break;
    } while (movie_name != name);
    for(int i=0;getline(check,num);i++){
        if( num == "0" )  a[i] = "O" ;
        else if ( num == "1" ) a[i] = "X" ;
        else;
    }
    check.close();
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
//คล้าย main เลย แต่ต้องพิมพ์ 1 ก่อน
void admin(){
    int N,M,Ans1,room;
    string Ans;
    vector<string> theater;
    ifstream movie ("listmovie.txt");
    string moviename;
    vector<string> a;
    while(1){
        //เลือกระบบที่ต้องการแก้ไข
        cout << "Which system do you want to manage ?\n1 : Manage Theater\n2 : Manage movie\n0 : Go to Home page\nYour answer is ";
        cin >> Ans1;
        if(Ans1==1){//ระบบจัดการโรงหนัง
            do{
                int count=1;
                cout << "How many theater do you want ?\nYour answer is ";
                cin >> room;
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
                checkAns(Ans);
            }while(Ans != "y");
        }else if(Ans1==2){//ระบบจัดการรอบหนัง
            int Ans5,Ans2,Ans4;
            char Ans3;
            while(1){
                cout << "Movie program today" << endl;//แสดงโปรแกรมหนังวันนี้
                for(int i =0;getline(movie,moviename);i++){
                    a.push_back(moviename);
                    cout << "- " << a[i] << endl;
                }
                //เลือกเพิ่ม\ลบหนัง
                cout << "What do you want to do ?\n1 : Add movie\n2 : Remove movie\n0 : Go to Admin setting\nYour answer is ";
                cin >> Ans5;
                if(Ans5 == 1){//ระบบเพิ่มหนัง
                    while(1){
                        string name;
                        cout << "What movie do you to add ?" << endl << "Your answer is ";
                        cin.ignore();
                        getline(cin,name);
                        while(1){
                            cout << "Where do you want to insert movie in the list ?" << endl;
                            for(int i =0;i<a.size();i++){
                                cout << a[i] << "   <--- " << i+1 << endl;
                            }
                            cout << "Your answer is ";
                            cin >> Ans2;
                            if(Ans2 > 0 && Ans2 <= a.size()+1){
                                a.insert(a.begin()+Ans2-1,name);
                                break;
                            }
                            else{
                                cout << "Wrong!!! Please try again."<< endl;
                            }
                        }
                        for(int i =0;i<a.size();i++){
                                cout << a[i] << "   <--- " << i+1 << endl;
                        }
                        cout << "Anything else ? (Yes = y or anything,No = n)"<< endl;
                        cin >> Ans3;
                        if(Ans3 == 'n') break;
                    }
                }else if(Ans5 == 2){//ระบบลบหนัง
                    while(1){
                        cout << "Which movie do you to delete ?" << endl ;
                        for(int i =0;i<a.size();i++){
                            cout << a[i] << "<--- " << i+1 << endl;
                        }
                        cout << "Your answer is ";
                        cin >> Ans4;
                        a.erase(a.begin()+Ans4-1);
                        for(int i =0;i<a.size();i++){
                            cout << a[i] << "   <--- " << i+1 << endl;
                        }
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
        }else if(Ans1==0) {//ออกไปหน้าหลัก(หน้าลูกค้า)และsaveการตั้งค่า
             ofstream theater1 ("theater.txt");
                for(int x=0; x<room ; x++){
                    for(int i=0;i<theater.size();i++){
                        theater1 << theater[i];
                        theater1 << endl;
                    }
                }    
                theater1.close();
            ofstream movielist1 ("listmovie.txt");
                    for(int i=0;i<a.size();i++){
                        movielist1 << a[i] << endl;
                    }  
                movielist1.close();
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
            cout << "Hello, please choose your movie\n";
            for(int i =0;getline(movie,moviename);i++){
                a.push_back(moviename);
                cout << setw(25)<<left <<a[i];
                if(i==5) cout << endl;
            }
            break;
        }else{
            cout << "Now There are no movies on the list." << endl;
            cout << "Please Manage movie." << endl;
            cout << "Pass y to go to the Menu" << endl;
            cout << "Your Answer is ";
            cin >> Ans;
            while(1){
                if(Ans == "y"){
                    admin();
                    input.close();
                    break;
                }else{
                    cout << "Pass y to go to the Menu" << endl;
                    cout << "Your Answer is ";
                    cin >> Ans;
                }
            }
        }
    }
    cout <<"\n>>> ";
    getline(cin,moviename);
    for(int i=0,j=0;i<a.size();i++){
        if(moviename == "1") {
            admin(); // ถ้าพิมพ์ 1 จะทำการสร้างโรง เหมือน main เมื่อก่อน
            break;
        }
        if(moviename == a[i]){             // หาหนังแล้วเข้าหน้าเลือกที่นั่ง *ยังไม่เสร็จ*
            j++;
        }
        else if(i== a.size()-1 && j ==0){
            cout << "We cannot found movie pls try again\n>>> "; //กรณีหาหนังไม่เจอ
            getline(cin,moviename);
            i = 0;
            continue;
        }
    }
    
}

int main(){
    if(refac == 0) passwordconfig();
    
    runprogram();
    return 0;
}