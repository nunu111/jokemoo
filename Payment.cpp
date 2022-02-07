
void Payment1(string name_movie,string time_movie){
    string file = ".txt";
    ifstream seats(name_movie+file);
    ifstream pay("payment1.txt");
    string select,get,X;
    vector<string> R;
    vector<string> m;
    

     //เก็บโรง
    while(getline(seats,select)){
        if(select == time_movie) break;
    }
    
    if(select == time_movie){
        for(int j = 0;getline(seats,select);j++){
            if(select == "0" || select == " " || select == "X" ){
                R.push_back(select);
            }else{
                break;
            }
        }
    }

    //เอาไปเก็บไว้ในstring
    for(int  i = 0;i < R.size();i++){
        X += R.at(i);
    }
   
    //หาหลัก
    int M = 0;
    for(int i = 0;i < X.size();i++){
        if(X[i] == ' ') M++;
    }
  
    //หาแถว
    int N = 0;
    for(int i = 0;i < X.size();i++){
        if(i%M == 0) N++;
    }

    //เก็บที่นั่งในkeep
    string keep[N][M];
    int k = 0;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            keep[i][j] = X[k];
            k++;
        }
    } 
    ///////////////////////////////////////////////////
    string type,start,add;
     //เก็บประเภท ราคาเริ่มต้น ราคาที่เพิ่ม
    while(getline(pay,get)){
        if(get == time_movie) break;
    }

    if(get == time_movie){
        for(int j = 0;getline(pay,get);j++){
            if(get == " "){
                break;
            }else{
                m.push_back(get);
            }
        }
        type = m.at(0);
        start = m.at(1);
        add = m.at(2);
    }

   

    //แปลงstring เป็น int
        int s = stoi(start.c_str());
        int a = stoi(add.c_str());
   
    /////////////////////////////////////////////////////
    
    //คิดตังค์//
    
    int total = 0,count = 0;
    for(int l = 0;l < N;l++){
        for(int o = 0;o < M;o++){
            if(keep[l][o] == "X"){
                count++;
                total += s + a*l;
            }else if(keep[l][o] == " "){
                total += s*0;
                if(o == M) l--;
            }
        }
    }
  
    cout << total;
    
}
