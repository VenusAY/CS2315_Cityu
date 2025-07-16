#include <iostream>
#include <iomanip>
using namespace std;

bool checkPrime(int x){
    bool check = true;
    for(int i=2; i<x && check==true ; i++){
        if( (x%i) == 0){
            check = false;}
        }
    if(x<2){check=false;}
    return check;
    }
bool findNxPrime(int Num){
    bool statement = false;
    if( (checkPrime(Num))==true){statement=false;}
    else{
        int count = 0; 
        //int Num_copy=Num;
        int N_array[8]={0};
        for(int i=0 ; i<8 && Num>0; i+=1){
            N_array[i]= Num%10;
            Num/=10;
            count++;}
        // cal the nCr
        int n=1;
        for(int k=1;k<=count;k+=1){
            n=n*k;}
        int n1=1;
        for(int k=1;k<=count-2;k+=1){
            n1=n1*k;}
        int nCr = n/(2*n1);
        
        long Data[28][8];
        long DataCopy[28][8];
        for(int a=0; a<nCr; a++){
            for(int b=0; b<count ; b++){
                Data[a][b]=N_array[b];
                DataCopy[a][b]=N_array[b];}}
        
        int y = 0;
        for(int s = 0;s<nCr;s++){
            for(int c=s+1; c<count; c++){
                int save = DataCopy[y][s];
                Data[y][s]= DataCopy[y][c];
                Data[y][c]=save;
                y++;
        }}
        int combine[28]={0};
        for(int i=0; i<nCr ;i+=1){
            int sum=0;
            int dig=1;
            for(int i=0;i<count-1;i++){dig=dig*10;}
            for (int j=count-1; j>=0;j--){ 
                if(Data[i][j] != 0){
                    sum=sum+Data[i][j]*dig;
                    dig/=10;}
                else{dig/=10;}}
            combine[i]=sum;
        }/*
        int Prime[28]={0};
        for(int i=0;i<nCr;i+=1){
            if(checkPrime(combine[i])==true){        
                Prime[i]=combine[i];}}*/
        
        for(int i=0;i<nCr && statement==false;i++){
            if(checkPrime(combine[i])==true){
                statement=true;}
        }}
        return statement;}
        
int NPrime(int Num){
    int test1 = Num; //++
    int test2 = Num; //--
    int count1=0;
    int count2=0;
    bool case1=false;
    bool case2=false;
    int Nprime;
        while(case1 == false){
            if(findNxPrime(test1) == true){
                case1 = true;}
            else{
                test1+=1;
                count1+=1;}}
                
        while(case2 == false&&test2>0){
            if(findNxPrime(test2) == true){
                case2 = true;}
            else{
                test2-=1;
                count2+=1;}}
        if(test1>9&&test2>9){        
            Nprime=(count1<count2)?test1:test2;}
        else{Nprime=test1;}
        return Nprime;}

int main(){
    int Num,Num_copy;
    cout << "Input an integer: ";
    cin>> Num;
    Num_copy=Num;
    bool S=findNxPrime(Num);
    if (S==true){
        cout<<Num_copy<<" is xPrime formed by swapping 2 digits of:"<<endl;
        int N_array[8]={0}; // ie 130 -> 0 1 3 , 1234 -> 4 3 2 1 
        long Data[28][8]; //for swapping digits
        long DataCopy[28][8];
        int combine[28]={0}; //turn the digit into integer after swapping
        int count=0;
        for(int i=0 ; i<8 && Num>0; i++){
            N_array[i]= Num%10;
            Num/=10;
            count++;}
         // cal the nCr(nC2)
        int n,n1;
        n=n1=1;
        for(int k=1;k<=count;k++){
            n=n*k;}
        for(int k=1;k<=count-2;k++){
            n1=n1*k;}
        int nCr = n/(2*n1);
        //swap digit
        for(int a=0; a<nCr; a++){    //fill all index inside first
            for(int b=0; b<count ; b++){
                Data[a][b]=N_array[b];
                DataCopy[a][b]=N_array[b];}}
        //swapping
         int y = 0;
        for(int s = 0;s<nCr;s++){
            for(int c=s+1; c<count; c++){
                int save = DataCopy[y][s];
                Data[y][s]= DataCopy[y][c];
                Data[y][c]=save;
                y++;}}
        // check the Data matric
        /*for(int i=0; i<nCr; i+=1){
            for(int j=0; j<count; j+=1){
                cout<<Data[i][j];}
            cout<<endl;
        }
    cout<<endl;*/
        //combine
        for(int i=0; i<nCr ;i++){
            int sum=0;
            int dig=1;
            for (int j=0; j<count;j++){ 
                if(Data[i][j] != 0){
                    sum=sum+Data[i][j]*dig;
                    dig*=10;}
                else{dig*=10;}}
            combine[i]=sum;}
        //convert the array to ascending order
        for(int i=0;i<nCr;i++){
            for(int j=0; j<nCr;j++){
                if (combine[i]<combine[j]){
                    int old = combine[i];
                    combine[i]=combine[j];
                    combine[j]=old;}}}
        // del repeated
        int temp[28]={0};
        int j=0;
        for (int i = 0; i < nCr; i++)
        if (combine[i] != combine[i - 1]){
            temp[j++] = combine[i];}
        /*for(int i=0;i<j;i++){
            cout<<temp[i]<<endl;}*/
    
        for(int i=0;i<j;i++){
            if(checkPrime(temp[i])==true){
                cout<< setfill('0') << setw(count)<<temp[i]<<endl;}}
        /*for(int i=0;i<nCr;i++){
            cout<<combine[i]<<endl;}*/
    }    
    else{
        cout<<Num_copy<<" is not xPrime"<<endl;
        cout<<"The nearest xPrime is: "<<NPrime(Num);
        }
    return 0;}




