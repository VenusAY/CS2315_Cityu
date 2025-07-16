#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
class Codec {
private:
    int W, H, S;
    const char C[71] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890 .,-!?()";
    char M[70][70];
    char N[71];
public:
    Codec() {
        W=70;
        H=1;
        S=0;
        int c_no=0;int s_control=1;
        for(int i=0;i<W;i++){
        if(s_control%(S+1)){
            M[0][i]=C[62];
            s_control++;}
        else if(C[c_no]==C[62]){
            M[0][i]='@';
            c_no++;
            s_control++;}
        else{
            M[0][i]=C[c_no];
            c_no++;
            s_control++;}}
        int m=0;
        for(int j=0;j<W;j++){
            for(int k=0;k<H;k++){
                if(M[k][j]=='@'){
                    N[m]=C[62];
                    m++;}
                else if(M[k][j]!= C[62]){
                    N[m]=M[k][j];
                    m++;}
                }}
        
    }
    Codec(int w, int h, int s) {
        W=w;
        H=h;
        S=s;
        }
    void config(int w, int h, int s) {
        W=w;
        H=h;
        S=s;
        int c_no=0;int s_control=1;int i;
    //fill
    if(h>2&&h%2==0){
    for(i=0;i<(h/2);i++){
        for(int j=0+i;j<w-i;j++){
            if(s_control%(s+1)!=0 || c_no>=70){
                M[i][j]=C[62];
                s_control++;}
            else if(C[c_no]==C[62]){
                M[i][j]='@';
                c_no++;
                s_control++;}
            else{
                M[i][j]=C[c_no];
                c_no++;
                s_control++;}}
        
        for(int j=1+i;j<h-i;j++){
            if(s_control%(s+1)!=0|| c_no>=70){
                M[j][w-1-i]=C[62];
                s_control++;}
                
            else if(C[c_no]==C[62]){
                M[j][w-1-i]='@';
                c_no++;
                s_control++;}
            else{
                M[j][w-1-i]=C[c_no];
                c_no++;
                s_control++;}}
        
        for(int j=(w-1)-1-i;j>=(0+i);j--){
            if(s_control%(s+1)!=0|| c_no>=70){
                M[h-1-i][j]=C[62];
                s_control++;}
            else if(c_no==62){
                M[h-1-i][j]='@';
                c_no++;
                s_control++;}
            else{
                M[h-1-i][j]=C[c_no];
                c_no++;
                s_control++;}}
        for(int j=(h-1)-1-i;j>=(1+i);j--){
            if(s_control%(s+1)!=0|| c_no>=70){
                M[j][i]=C[62];
                s_control++;}
                
            else if(C[c_no]==C[62]){
                M[j][i]='@';
                c_no++;
                s_control++;}
            else{
                M[j][i]=C[c_no];
                c_no++;
                s_control++;}}}}
    else if(h>2){
    for(i=0;i<(h/2);i++){
        for(int j=0+i;j<w-i;j++){
            if(s_control%(s+1)!=0|| c_no>=70){
                M[i][j]=C[62];
                s_control++;}
                
            else if(C[c_no]==C[62]){
                M[i][j]='@';
                c_no++;
                s_control++;}
            else{
                M[i][j]=C[c_no];
                c_no++;
                s_control++;}}
        
        for(int j=1+i;j<h-i;j++){
            if(s_control%(s+1)!=0|| c_no>=70){
                M[j][w-1-i]=C[62];
                s_control++;}
            else if(C[c_no]==C[62]){
                M[j][w-1-i]='@';
                c_no++;
                s_control++;}
            else{
                M[j][w-1-i]=C[c_no];
                c_no++;
                s_control++;}}
        
        for(int j=(w-1)-1-i;j>=(0+i);j--){
            if(s_control%(s+1)!=0|| c_no>=70){
                M[h-1-i][j]=C[62];
                s_control++;}
            else if(C[c_no]==C[62]){
                M[h-1-i][j]='@';
                c_no++;
                s_control++;}
            else{
                M[h-1-i][j]=C[c_no];
                c_no++;
                s_control++;}}
        for(int j=(h-1)-1-i;j>=(1+i);j--){
            if(s_control%(s+1)!=0|| c_no>=70){
                M[j][i]=C[62];
                s_control++;}
            else if(C[c_no]==C[62]){
                M[j][i]='@';
                c_no++;
                s_control++;}
            else{
                M[j][i]=C[c_no];
                c_no++;
                s_control++;}}}
        for(int j=0+i;j<w-i;j++){
            if(s_control%(s+1)!=0|| c_no>=70){
                M[i][j]=C[62];
                s_control++;}
            else if(C[c_no]==C[62]){
                M[i][j]='@';
                c_no++;
                s_control++;}
            else{
                M[i][j]=C[c_no];
                c_no++;
                s_control++;}}
    }else if(h==2){
        for(i=0;i<w;i++){
            
        if(s_control%(s+1)|| c_no>=70){
            M[0][i]=C[62];
            s_control++;}
        else if(C[c_no]==C[62]){
                M[0][i]='@';
                c_no++;
                s_control++;}
        else{
            M[0][i]=C[c_no];
            c_no++;
            s_control++;}}
            
        for(int i=(w-1)-1;i>=0;i--){
        if(s_control%(s+1)|| c_no>=70){
            M[h-1][i]=C[62];
            s_control++;}
        else if(c_no==62){
                M[h-1][i]='@';
                c_no++;
                s_control++;}
        else{
            M[h-1][i]=C[c_no];
            c_no++;
            s_control++;}}}
    else{
        for(int i=0;i<w;i++){
        if(s_control%(s+1)|| c_no>=70){
            M[0][i]=C[62];
            s_control++;}
        else if(c_no==62){
                M[0][i]='@';
                c_no++;
                s_control++;}
        else{
            M[0][i]=C[c_no];
            c_no++;
            s_control++;}}}
        int m=0;
        for(int j=0;j<W;j++){
            for(int k=0;k<H;k++){
                if(M[k][j]=='@'){
                    N[m]=C[62];
                    m++;}
                else if(M[k][j]!= C[62]){
                    N[m]=M[k][j];
                    m++;}
                }}
        }
    void showSetting() {
        //input
         cout<<"W="<<W<<", H="<<H<<", S="<<S<<endl;
                
        for(int j=0;j<H;j++){
            for(int k=0;k<W;k++){
                if(M[j][k]=='@'){
                    cout<<C[62];}
                else{
                cout<<M[j][k];}}
            cout<<endl;}
    cout<<"Seq: ";
    
    cout<<N<<endl;
    }
    void encode(char in[], char out[]) ;
    
    void decode(char in[], char out[]);
    
};

void Codec::encode(char in[], char out[]) {
        char D[71];
        strcpy (D,C);
        
        int Num[1000];
        //char Ans[1000];
        int i;
        for(i=0;i<strlen(in)-1;i++){
            char* ch = strchr(D, in[i]);
            Num[i]= ch - D;}
        for(i=0;i<strlen(in)-1;i++){
            //cout<<Num[i];
            out[i]=N[Num[i]];}
        out[i]='@';
        //cout<<'@';
        //friend char getnumber();
    }
void Codec::decode(char in[], char out[]){
    char D[71];
    strcpy (D,C);
        
    int Num[1000];
    //char Ans[1000];
    int i;
    for(i=0;i<strlen(in);i++){
        char* ch = strchr(N, in[i]);
        Num[i]= ch - N;}
    for(i=0;i<strlen(in)-1;i++){
        cout<<Num[i];
        out[i]=D[Num[i]];}
    //out[i]='@';
        //cout<<'@';
        }
int main() {
    char cmd, inStr[1000], outStr[1000];
    bool fin=false;
    Codec C;
    
    while(!fin) {
        cout << "\nCommand: ";
        cmd = cin.get();
        switch(cmd) {
            case 'C': 
                int w,h,s;
                cin>>w>>h>>s;
                C.config(w,h,s);
                cin.ignore(1000,'\n');
                break;
            case 'Q':
                cout << "Quit\n";
                cin.ignore(1000,'\n');
                fin=true;
                break;
            case 'S':
                C.showSetting();
                cin.ignore(1000,'\n');
                break;
            case 'E':
                cin.get();
                cin.getline(inStr,1000);
                C.encode(inStr,outStr);
                cout << outStr<<endl;
                break;
            case 'D':
                cin.get();
                cin.getline(inStr,1000);
                C.decode(inStr,outStr);
                cout << outStr<<endl;
                break;
        }
    }
    return 0;}

//10/25

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
class Codec {
private:
    int W, H, S;
    const char C[71] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890 .,-!?()";
    char M[70][70];
    char N[71];
public:
    Codec() {
        W=70;
        H=1;
        S=0;
        int c_no=0;int s_control=1;
        for(int i=0;i<W;i++){
        if(s_control%(S+1)){
            M[0][i]=C[62];
            s_control++;}
        else if(C[c_no]==C[62]){
            M[0][i]='@';
            c_no++;
            s_control++;}
        else{
            M[0][i]=C[c_no];
            c_no++;
            s_control++;}}
        int m=0;
        for(int j=0;j<W;j++){
            for(int k=0;k<H;k++){
                if(M[k][j]=='@'){
                    N[m]=C[62];
                    m++;}
                else if(M[k][j]!= C[62]){
                    N[m]=M[k][j];
                    m++;}
                }}
    }
    Codec(int w, int h, int s) {
        W=w;
        H=h;
        S=s;
        }
    void config(int w, int h, int s) {
        W=w;
        H=h;
        S=s;
        int c_no=0;int s_control=1;int i;
    //fill
    if(h>2&&h%2==0){
    for(i=0;i<(h/2);i++){
        for(int j=0+i;j<w-i;j++){
            if(s_control%(s+1)!=0 || c_no>=70){
                M[i][j]=C[62];
                s_control++;}
            else if(C[c_no]==C[62]){
                M[i][j]='@';
                c_no++;
                s_control++;}
            else{
                M[i][j]=C[c_no];
                c_no++;
                s_control++;}}
        
        for(int j=1+i;j<h-i;j++){
            if(s_control%(s+1)!=0|| c_no>=70){
                M[j][w-1-i]=C[62];
                s_control++;}
                
            else if(C[c_no]==C[62]){
                M[j][w-1-i]='@';
                c_no++;
                s_control++;}
            else{
                M[j][w-1-i]=C[c_no];
                c_no++;
                s_control++;}}
        
        for(int j=(w-1)-1-i;j>=(0+i);j--){
            if(s_control%(s+1)!=0|| c_no>=70){
                M[h-1-i][j]=C[62];
                s_control++;}
            else if(c_no==62){
                M[h-1-i][j]='@';
                c_no++;
                s_control++;}
            else{
                M[h-1-i][j]=C[c_no];
                c_no++;
                s_control++;}}
        for(int j=(h-1)-1-i;j>=(1+i);j--){
            if(s_control%(s+1)!=0|| c_no>=70){
                M[j][i]=C[62];
                s_control++;}
                
            else if(C[c_no]==C[62]){
                M[j][i]='@';
                c_no++;
                s_control++;}
            else{
                M[j][i]=C[c_no];
                c_no++;
                s_control++;}}}}
    else if(h>2){
    for(i=0;i<(h/2);i++){
        for(int j=0+i;j<w-i;j++){
            if(s_control%(s+1)!=0|| c_no>=70){
                M[i][j]=C[62];
                s_control++;}
                
            else if(C[c_no]==C[62]){
                M[i][j]='@';
                c_no++;
                s_control++;}
            else{
                M[i][j]=C[c_no];
                c_no++;
                s_control++;}}
        
        for(int j=1+i;j<h-i;j++){
            if(s_control%(s+1)!=0|| c_no>=70){
                M[j][w-1-i]=C[62];
                s_control++;}
            else if(C[c_no]==C[62]){
                M[j][w-1-i]='@';
                c_no++;
                s_control++;}
            else{
                M[j][w-1-i]=C[c_no];
                c_no++;
                s_control++;}}
        
        for(int j=(w-1)-1-i;j>=(0+i);j--){
            if(s_control%(s+1)!=0|| c_no>=70){
                M[h-1-i][j]=C[62];
                s_control++;}
            else if(C[c_no]==C[62]){
                M[h-1-i][j]='@';
                c_no++;
                s_control++;}
            else{
                M[h-1-i][j]=C[c_no];
                c_no++;
                s_control++;}}
        for(int j=(h-1)-1-i;j>=(1+i);j--){
            if(s_control%(s+1)!=0|| c_no>=70){
                M[j][i]=C[62];
                s_control++;}
            else if(C[c_no]==C[62]){
                M[j][i]='@';
                c_no++;
                s_control++;}
            else{
                M[j][i]=C[c_no];
                c_no++;
                s_control++;}}}
        for(int j=0+i;j<w-i;j++){
            if(s_control%(s+1)!=0|| c_no>=70){
                M[i][j]=C[62];
                s_control++;}
            else if(C[c_no]==C[62]){
                M[i][j]='@';
                c_no++;
                s_control++;}
            else{
                M[i][j]=C[c_no];
                c_no++;
                s_control++;}}
    }else if(h==2){
        for(i=0;i<w;i++){
            
        if(s_control%(s+1)|| c_no>=70){
            M[0][i]=C[62];
            s_control++;}
        else if(C[c_no]==C[62]){
                M[0][i]='@';
                c_no++;
                s_control++;}
        else{
            M[0][i]=C[c_no];
            c_no++;
            s_control++;}}
            
        for(int i=(w-1)-1;i>=0;i--){
        if(s_control%(s+1)|| c_no>=70){
            M[h-1][i]=C[62];
            s_control++;}
        else if(c_no==62){
                M[h-1][i]='@';
                c_no++;
                s_control++;}
        else{
            M[h-1][i]=C[c_no];
            c_no++;
            s_control++;}}}
    else{
        for(int i=0;i<w;i++){
        if(s_control%(s+1)|| c_no>=70){
            M[0][i]=C[62];
            s_control++;}
        else if(c_no==62){
                M[0][i]='@';
                c_no++;
                s_control++;}
        else{
            M[0][i]=C[c_no];
            c_no++;
            s_control++;}}}
        int m=0;
        for(int j=0;j<W;j++){
            for(int k=0;k<H;k++){
                if(M[k][j]=='@'){
                    N[m]=C[62];
                    m++;}
                else if(M[k][j]!= C[62]){
                    N[m]=M[k][j];
                    m++;}
                }}
        }
    void showSetting() {
        //input
         cout<<"W="<<W<<", H="<<H<<", S="<<S<<endl;
                
        for(int j=0;j<H;j++){
            for(int k=0;k<W;k++){
                if(M[j][k]=='@'){
                    cout<<C[62];}
                else{
                cout<<M[j][k];}}
            cout<<endl;}
    cout<<"Seq: ";
    
    cout<<N<<endl;
    }
    void encode(char in[], char out[]) {
        
        char D[71];
        strcpy (D,C);
        int Num[1000];
        
        for(int i=0;i<strlen(in);i++){
            char* ch = strchr(D, in[i]);
            Num[i]= ch - D;}
        for(int i=0;i<1000;i++){
            if(i<strlen(in)){
                if(Num[i]>=0 && Num[i]<70){
                    out[i]=N[Num[i]];}
                else{
                    out[i]=in[i];}}
            else{
                out[i]=0;}}
            
    }
    
    void decode(char in[], char out[]) {
        
        char D[71];
        strcpy (D,C);
        int Num[1000];
        //char Ans[1000];
        
        for(int i=0;i<strlen(in);i++){
            char* ch = strchr(N, in[i]);
            Num[i]= ch - N;}
        for(int i=0;i<1000;i++){
            if(i<strlen(in)){
                if(Num[i]>=0 && Num[i]<70){
                    out[i]=D[Num[i]];}
                else{
                    out[i]=in[i];}}
            else{
                out[i]=0;}}
    }
};
int main() {
    char cmd, inStr[1000], outStr[1000];
    bool fin=false;
    Codec C;
    
    while(!fin) {
        cout << "\nCommand: ";
        cmd = cin.get();
        switch(cmd) {
            case 'C': 
                int w,h,s;
                cin>>w>>h>>s;
                C.config(w,h,s);
                cin.ignore(1000,'\n');
                break;
            case 'Q':
                cout << "Quit\n";
                cin.ignore(1000,'\n');
                fin=true;
                break;
            case 'S':
                C.showSetting();
                cin.ignore(1000,'\n');
                break;
            case 'E':
                cin.get();
                cin.getline(inStr,1000);
                C.encode(inStr,outStr);
                cout << outStr<<endl;
                break;
            case 'D':
                cin.get();
                cin.getline(inStr,1000);
                C.decode(inStr,outStr);
                cout << outStr<<endl;
                break;
        }
    }
    return 0;}


//17/25

#include <iostream>
#include <iomanip>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
class Codec {
private:
    int W, H, S;
    const char C[71] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890 .,-!?()";
    char M[70][70];
    char N[71];
public:
    Codec() {
        W=70;
        H=1;
        S=0;
        int c_no=0;int s_control=1;
        for(int i=0;i<W;i++){
        if(s_control%(S+1)){
            M[0][i]=C[62];
            s_control++;}
        else if(C[c_no]==C[62]){
            M[0][i]='@';
            c_no++;
            s_control++;}
        else{
            M[0][i]=C[c_no];
            c_no++;
            s_control++;}}
        int m=0;
        for(int j=0;j<W;j++){
            for(int k=0;k<H;k++){
                if(M[k][j]=='@'){
                    N[m]=C[62];
                    m++;}
                else if(M[k][j]!= C[62]){
                    N[m]=M[k][j];
                    m++;}
                }}
    }
    Codec(int w, int h, int s) {
        W=w;
        H=h;
        S=s;
        }
    void config(int w, int h, int s) {
        W=w;
        H=h;
        S=s;
        int c_no=0;int s_control=1;int i;
    //fill
    if(h>2&&h%2==0){
    for(i=0;i<(h/2);i++){
        for(int j=0+i;j<w-i;j++){
            if(s_control%(s+1)!=0 || c_no>=70){
                M[i][j]=C[62];
                s_control++;}
            else if(C[c_no]==C[62]){
                M[i][j]='@';
                c_no++;
                s_control++;}
            else{
                M[i][j]=C[c_no];
                c_no++;
                s_control++;}}
        
        for(int j=1+i;j<h-i;j++){
            if(s_control%(s+1)!=0|| c_no>=70){
                M[j][w-1-i]=C[62];
                s_control++;}
                
            else if(C[c_no]==C[62]){
                M[j][w-1-i]='@';
                c_no++;
                s_control++;}
            else{
                M[j][w-1-i]=C[c_no];
                c_no++;
                s_control++;}}
        
        for(int j=(w-1)-1-i;j>=(0+i);j--){
            if(s_control%(s+1)!=0|| c_no>=70){
                M[h-1-i][j]=C[62];
                s_control++;}
            else if(c_no==62){
                M[h-1-i][j]='@';
                c_no++;
                s_control++;}
            else{
                M[h-1-i][j]=C[c_no];
                c_no++;
                s_control++;}}
        for(int j=(h-1)-1-i;j>=(1+i);j--){
            if(s_control%(s+1)!=0|| c_no>=70){
                M[j][i]=C[62];
                s_control++;}
                
            else if(C[c_no]==C[62]){
                M[j][i]='@';
                c_no++;
                s_control++;}
            else{
                M[j][i]=C[c_no];
                c_no++;
                s_control++;}}}}
    else if(h>2){
    for(i=0;i<(h/2);i++){
        for(int j=0+i;j<w-i;j++){
            if(s_control%(s+1)!=0|| c_no>=70){
                M[i][j]=C[62];
                s_control++;}
                
            else if(C[c_no]==C[62]){
                M[i][j]='@';
                c_no++;
                s_control++;}
            else{
                M[i][j]=C[c_no];
                c_no++;
                s_control++;}}
        
        for(int j=1+i;j<h-i;j++){
            if(s_control%(s+1)!=0|| c_no>=70){
                M[j][w-1-i]=C[62];
                s_control++;}
            else if(C[c_no]==C[62]){
                M[j][w-1-i]='@';
                c_no++;
                s_control++;}
            else{
                M[j][w-1-i]=C[c_no];
                c_no++;
                s_control++;}}
        
        for(int j=(w-1)-1-i;j>=(0+i);j--){
            if(s_control%(s+1)!=0|| c_no>=70){
                M[h-1-i][j]=C[62];
                s_control++;}
            else if(C[c_no]==C[62]){
                M[h-1-i][j]='@';
                c_no++;
                s_control++;}
            else{
                M[h-1-i][j]=C[c_no];
                c_no++;
                s_control++;}}
        for(int j=(h-1)-1-i;j>=(1+i);j--){
            if(s_control%(s+1)!=0|| c_no>=70){
                M[j][i]=C[62];
                s_control++;}
            else if(C[c_no]==C[62]){
                M[j][i]='@';
                c_no++;
                s_control++;}
            else{
                M[j][i]=C[c_no];
                c_no++;
                s_control++;}}}
        for(int j=0+i;j<w-i;j++){
            if(s_control%(s+1)!=0|| c_no>=70){
                M[i][j]=C[62];
                s_control++;}
            else if(C[c_no]==C[62]){
                M[i][j]='@';
                c_no++;
                s_control++;}
            else{
                M[i][j]=C[c_no];
                c_no++;
                s_control++;}}
    }else if(h==2){
        for(i=0;i<w;i++){
            
        if(s_control%(s+1)|| c_no>=70){
            M[0][i]=C[62];
            s_control++;}
        else if(C[c_no]==C[62]){
                M[0][i]='@';
                c_no++;
                s_control++;}
        else{
            M[0][i]=C[c_no];
            c_no++;
            s_control++;}}
            
        for(int i=(w-1)-1;i>=0;i--){
        if(s_control%(s+1)|| c_no>=70){
            M[h-1][i]=C[62];
            s_control++;}
        else if(c_no==62){
                M[h-1][i]='@';
                c_no++;
                s_control++;}
        else{
            M[h-1][i]=C[c_no];
            c_no++;
            s_control++;}}}
    else{
        for(int i=0;i<w;i++){
        if(s_control%(s+1)|| c_no>=70){
            M[0][i]=C[62];
            s_control++;}
        else if(c_no==62){
                M[0][i]='@';
                c_no++;
                s_control++;}
        else{
            M[0][i]=C[c_no];
            c_no++;
            s_control++;}}}
        int m=0;
        for(int j=0;j<W;j++){
            for(int k=0;k<H;k++){
                if(M[k][j]=='@'){
                    N[m]=C[62];
                    m++;}
                else if(M[k][j]!= C[62]){
                    N[m]=M[k][j];
                    m++;}
                }}
        }
    void showSetting() {
        //input
         cout<<"W="<<W<<", H="<<H<<", S="<<S<<endl;
                
        for(int j=0;j<H;j++){
            for(int k=0;k<W;k++){
                if(M[j][k]=='@'){
                    cout<<C[62];}
                else{
                cout<<M[j][k];}}
            cout<<endl;}
    cout<<"Seq: ";
    
    cout<<N<<endl;
    }
    void encode(char in[], char out[]) {
        
        char D[71];
        strcpy (D,C);
        int Num[1000];
        
        for(int i=0;i<strlen(in);i++){
            char* ch = strchr(D, in[i]);
            Num[i]= ch - D;}
        for(int i=0;i<1000;i++){
            if(i<strlen(in)){
                if(Num[i]>=0 && Num[i]<70){
                    out[i]=N[Num[i]];}
                else{
                    out[i]=in[i];}}
            else{
                out[i]=0;}}
            
    }
    
    void decode(char in[], char out[]) {
        
        char D[71];
        strcpy (D,C);
        int Num[1000];
        //char Ans[1000];
        
        for(int i=0;i<strlen(in);i++){
            char* ch = strchr(N, in[i]);
            Num[i]= ch - N;}
        for(int i=0;i<1000;i++){
            if(i<strlen(in)){
                if(Num[i]>=0 && Num[i]<70){
                    out[i]=D[Num[i]];}
                else{
                    out[i]=in[i];}}
            else{
                out[i]=0;}}
    }
};
int main() {
    char cmd, inStr[1000], outStr[1000];
    bool fin=false;
    Codec C;
    
    while(!fin) {
        cout << "\nCommand: ";
        cmd = cin.get();
        switch(cmd) {
            case 'C': 
                int w,h,s;
                cin>>w>>h>>s;
                C.config(w,h,s);
                cin.ignore(1000,'\n');
                break;
            case 'Q':
                cout << "Quit\n";
                cin.ignore(1000,'\n');
                fin=true;
                break;
            case 'S':
                C.showSetting();
                cin.ignore(1000,'\n');
                break;
            case 'E':
                cin.get();
                cin.getline(inStr,1000);
                C.encode(inStr,outStr);
                cout << outStr<<endl;
                break;
            case 'D':
                cin.get();
                cin.getline(inStr,1000);
                C.decode(inStr,outStr);
                cout << outStr<<endl;
                break;
        }
    }
    return 0;}



 




