#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
using namespace std;

void remove_movie(string movie_name){
    const char *str = movie_name.c_str();
    remove(str);
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
    cout << "    ";
    for(int p=0;p<M;p++){
        cout << char('A'+p);
    }
    cout << endl;
    for(int i=0;i<N;i++){
        char A = '1'+i;
        cout << A<<' ';
        cout << "| " ;
        for(int j=0;j<M;j++){
            cout << a[j+(i*M)];
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


int main(){
    int N = 5;
    int M = 5;
    string *block=new string[N*M];
    seat(block,N,M);
    show(block,N,M);
    int A = 3;
    walk(block,A,N*M,M);
    show(block,N,M);
    comferm_seat(block,N,M);
    show(block,N,M);
    delete [] block;
    return 0;
}