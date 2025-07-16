#include <iostream> 
#include <iomanip> 

using namespace std; 
int timediff_day(int a,int b, int c){
    // part_c be year, part_a be year 
    int year1, year2; 
    if (c <50){ 
        year1 = 20*100 + c; 
    }else{ 
        year1 = 19*100 + c;}  
    if (a < 50){ 
        year2 = 20*100 + a; 
    }else{ 
        year2 = 19*100 + a;} 
        
    int test1 = (c > a)? year1 : year2;
    int test2 = (c <= a)? year1 : year2;
    int control = 0;
    //if((test1%4==0) && (b> 2)){control += 1;}
    if((test2%4==0) && (b<=2)){control += 1;}
    int x= test1;
    while(x != test2){
        if (x%4 == 0){
            control += 1;}
        x -= 1;}
    if ((test1%4==0)&&  ( b<=2 )){
        control-=1;}
    
    int timediff;
    if (c > a){       
        timediff = (year1-year2-control)*365 + control*366 + (a-c);
        int count = 0;
        int test_t = timediff;
        while (test_t != 0){
            count +=1;
            test_t /= 10;
        }
        cout.width(52+count);
        cout<< setfill('#')<<"#"<<endl;
        cout<<"# The ambiguity causes a time difference of "<<timediff << " days! #"<< endl ;
        cout.width(52+count);
        cout<< setfill('#')<<"#"<<endl;
    }else if(a > c){       
        timediff = (year2-year1-control)*365 + control*366 + (c-a);
        int count = 0;
        int test_t = timediff;
        while (test_t != 0){
            count +=1;
            test_t /= 10;
        }
        cout.width(52+count);
        cout<< setfill('#')<<"#"<<endl;
        cout<<"# The ambiguity causes a time difference of "<<timediff << " days! #"<< endl ;
        cout.width(52+count);
        cout<< setfill('#')<<"#"<<endl;
    }else {
        cout<<"";
    }
    return 0;}

int print_day(int month_day, int part_a, int part_b,int part_c, int date_num, string month){
    int year1, year2; 
    if (part_c < 50){ 
        year1 = 20*100 + part_c; 
    }else{ 
        year1 = 19*100 + part_c;} 
     
    if (part_a < 50){ 
        year2 = 20*100 + part_a; 
    }else{ 
        year2 = 19*100 + part_a;} 
    
        if(part_a <= month_day || part_c <= month_day){
            if(part_a==0 && part_c==0){
                cout <<setfill('0')<<setw(6) << date_num << " is not a valid date.";
            }else if(part_a == 0){
                cout <<setfill('0')<<setw(6)<< date_num << " should be " << setfill('0') << setw(2) << part_c << "-" << month << "-" << year2; 
            }else if(part_c == 0){
                cout <<setfill('0')<<setw(6)<< date_num << " should be " << setfill('0') << setw(2) << part_a << "-" << month << "-" << year1;
            }else if(part_a > month_day){
                cout <<setfill('0')<<setw(6)<< date_num << " should be " << setfill('0') << setw(2) << part_c << "-" << month << "-" << year2;
            }else if(part_c> month_day){
                cout <<setfill('0')<<setw(6)<< date_num << " should be " << setfill('0') << setw(2) << part_a << "-" << month << "-" << year1;
            }else if(part_a>part_c){ 
                cout <<setfill('0')<<setw(6)<< date_num << " could be " << setfill('0') << setw(2) << part_a << "-" << month << "-" << year1<<" or "<< setfill('0') << setw(2) << part_c <<"-"<< month << "-" << year2<<endl;
                timediff_day(part_a,part_b,part_c);
            }else if(part_c>part_a){ 
                cout <<setfill('0')<<setw(6)<< date_num << " could be " << setfill('0') << setw(2) << part_c << "-" << month << "-" << year2 <<" or "<< setfill('0') << setw(2) << part_a <<"-"<< month << "-" << year1<<endl;
                timediff_day(part_a,part_b,part_c);
            }else{
                cout <<setfill('0')<<setw(6)<< date_num << " should be " << setfill('0') << setw(2) << part_c << "-" << month << "-" << year2; 
            }
        }else{
            cout <<setfill('0')<<setw(6)<< date_num << " is not a valid date.";}
    return 0; }

int main() { 
    setprecision(2); 
    int date_num; 
    cout << "Input the six-digit date: "; 
    cin >> date_num; 
    int a = date_num; 
    int part_c = a%100; 
    a /= 100; 
    int part_b = a%100; 
    a /= 100; 
    int part_a = a; 
 
    string  month; 
    switch (part_b) { 
        case 1: month = "JAN" ; break; case 2: month = "FEB" ; break; case 3: month = "MAR" ; break; case 4: month = "APR" ; break; 
        case 5:  month = "MAY" ; break; case 6:  month = "JUN" ; break; case 7: month = "JUL" ; break; case 8: month = "AUG" ; break; 
        case 9: month = "SEP" ; break; case 10:month = "OCT" ; break; case 11: month = "NOV" ; break; case 12:  month = "DEC" ; break; 
        default: cout << setfill('0')<<setw(6)<<date_num << " is not a valid date."; }     
// part_c be year, part_a be year 
    int year1, year2; 
        if (part_c < 50){ 
            year1 = 20*100 + part_c; 
        }else{ 
            year1 = 19*100 + part_c;} 
     
    if (part_a < 50){ 
        year2 = 20*100 + part_a; 
    }else{ 
        year2 = 19*100 + part_a;} 
             
    if(part_b > 12 || part_b < 1 ){ 
        cout << ""; 
    }else if (part_b == 4 || part_b == 6 ||part_b == 9 ||part_b == 11){
        print_day(30,part_a,part_b, part_c, date_num, month);
        
    }else if(part_b == 2){
        if(year1%4 ==0 || year2%4 ==0){
            print_day(29,part_a,part_b, part_c, date_num, month);}
        else {
            print_day(28,part_a,part_b, part_c, date_num, month);}
    }else{ 
        print_day(31,part_a,part_b, part_c, date_num, month);}
    return 0;
}





