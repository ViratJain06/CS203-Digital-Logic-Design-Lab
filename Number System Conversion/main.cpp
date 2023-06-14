#include <iostream>
#include <bitset>
#include <string.h>
#include <cstdlib>

using namespace std;

bitset<32> dec2bin(unsigned int a){
   bitset<32> bset;
   int i=0;
   while(a>0){
    bset[i]=a%2;
    a=a/2;
    i++;
   }
   return bset;
}

unsigned int bin2dec(bitset<32> &a){
 int ans=0;
 int x=1;
 for (int i=0;i<32;i++){
    ans+= x*a[i];
    x*=2;
    }
    return ans;
}

char* dec2hex(unsigned int a){
    int x=1,i=0;
    static char hexa[8];
    memset(hexa, NULL, sizeof(hexa));
    while(x<=a){
        x*=16;}
    x=x/16;
    while (x>0){
        int l=a/x;
        a -=l*x;
        x/=16;
        if (l<10){
            hexa[i]=l+48;
            i++;
        }
        else{
            hexa[i]=l+55;
            i++;
        }
    }
    return hexa;
}

char* bin2hex(bitset<32> &a){
    int ans=0;
    int x=1;
    for (int i=0;i<32;i++){
        ans+= x*a[i];
        x*=2;}
    int y=1,i=0;
    static char hexa[100];
    memset(hexa, NULL, sizeof(hexa));
    while(y<=ans)
        y*=16;
    y=y/16;
    while (y>0){
        int l=ans/y;
        ans -=l*y;
        y/=16;
        if (l<10){
            hexa[i]=l+48;
            i++;
        }
        else{
            hexa[i]='A'+l-10;
            i++;
        }
    }
    return hexa;
    }

void test_func(){
    int count1=0,count2=0;
    for (int i=0;i<1000;i++){
        int a=rand();
        bitset<32> bset1(a);
        bitset<32> bset2=dec2bin(a);
        if (bset1==bset2){
            count1++;
        }
        int decimal1=bitset<32>(bset1).to_ulong();
        int decimal2=bin2dec(bset1);
        if(decimal1==decimal2){
            count2++;
        }
    }
    int efficiency1 = (count1*100)/1000;
    cout<<"Percent efficiency of dec2bin function ="<<efficiency1<<endl;
    int efficiency2 = (count1*100)/1000;
    cout<<"Percent efficiency of bin2dec function ="<<efficiency2<<endl;
    return ;
}

unsigned int dybase2dec(string n,unsigned int r){
    int len= n.length();
    int x=1,ans=0;
    for (int i=0;i<len;i++){
        if (n[i]>='0'&&n[i]<='9'){
            n[i]=int (n[i]-'0');
        }
        else{
            n[i]=int (n[i]-'A'+10);
            }
    }
    for (int i=len-1;i>=0;i--){
        if(n[i]>=r ){
            cout<<"invalid Number";
            return -1;
        }
        else{
            ans+=n[i]*x;
            x=x*r;
        }
    }
    return ans;
}

bitset<32> dybase2bin(string n ,unsigned int r){
    bitset<32> bset;
    int ans = dybase2dec(n,r);
    bset=dec2bin(ans);
    return bset;
}

int main()
{
    int sample;
    while(sample!=8){
    cout<<"Choose from the following options-"<<endl;
    cout<<"1) decimal to binary"<<endl;
    cout<<"2) binary to decimal"<<endl;
    cout<<"3) decimal to hexadecimal"<<endl;
    cout<<"4) binary to hexadecimal"<<endl;
    cout<<"5) test function"<<endl;
    cout<<"6) Any base to decimal"<<endl;
    cout<<"7) Any base to binary"<<endl;
    cout<<"8) Press 8 to exit"<<endl;
    cout<<"Operation number ";
    cin>>sample;
    switch(sample){
        case 1:{
            cout<<"Enter the Decimal no: ";
            int d;
            cin>>d;
            if (d>=0){
            cout<<"Sample output "<<dec2bin(d)<<endl;
            }
            else{
                cout<<"Sample output Enter the positive no. only"<<endl;
            }
            break;}
        case 2:{
            cout<<"Enter the binary number: ";
            string e;
            cin>>e;
            bitset<32> c(e);
            cout<<"Sample output 	"<<bin2dec(c)<<endl;
            break;}
        case 3:{
            cout<<"Enter the Decimal number: ";
            int x;
            cin>>x;
            cout<<"Sample output "<<dec2hex(x)<<endl;
            break;}
        case 4:{
            cout<<"Enter the binary number: ";
            string f;
            cin>>f;
            bitset<32> c(f);
            cout<<"Sample output 	"<<bin2hex(c)<<endl;
                break;}
        case 5:{
            cout<<"Efficiency check of bin2dec and dec2bin over 1000 random test cases"<<endl;
            test_func();
            break;}
        case 6:{
        string s;
        int n;
        cout<<"Enter Number ";
        cin>>s;
        cout<<"Enter base ";
        cin>>n;
        cout<<"Sample output  "<<dybase2dec(s, n)<<endl;
        break;
        }
        case 7:{
        string p;
        int m;
        cout<<"Enter Number ";
        cin>>p;
        cout<<"Enter base ";
        cin>>m;
        cout<<"Sample output  "<<dybase2bin(p, m)<<endl;
        break;
        }
        default:
            cout<<"Enter a valid operation number"<<endl;
    }
    cout<<endl;
    }
    return 0;
}
