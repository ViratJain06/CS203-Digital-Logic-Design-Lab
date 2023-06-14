#include <iostream>
#include <string.h>
#include <bitset>
#include <cmath>

using namespace std;

string dec2bin(long long int a){
   bitset<32> bset;
   int i=0;
   while(a>0){
    bset[i]=a%2;
    a=a/2;
    i++;
   }
   string s=bset.to_string();
   return s;
}
int bin2dec(string a){
 int ans=0;
 int x=1;
 for (int i=31;i>=0;i--){
    if (a[i]=='1'){
    ans+= x*(a[i]-'0');
    }
    x=x*2;
    }
    return ans;
}

string ones_complement(long long int a){
    string ans="";
    if (a>0){
       ans= dec2bin(a);
    }
    else{
      long long int c=a/(-1);
      string s=dec2bin(c);
      for (int i=0;i<32;i++){
        if (s[i]=='1'){
                ans.push_back('0');
        }
        else if (s[i]=='0'){
            ans.push_back('1');
        }
        else{
            cout<<"Fail";
        }
      }
    }
    return ans;
}

string twos_complement(long long int a){
    string ans=ones_complement(a);
    if (a>0){
        return ans;
    }
    int i;
    for (i=31;i>=0;i--){
        if (ans[i]=='1'){
            ans[i]='0';
        }
        else{
            ans[i]='1';
            break;
        }
    }
   if (i==-1)
        ans='1'+ans;
   return ans;
}

string spacedstring(string bin){
    string f;
    for (int i=0;i<bin.length();i++){
        if((i+1)%4==0){
           f=f+bin[i]+" ";
        }
        else{
            f=f+bin[i];
        }
    }
    return f;
}

int min_size(int a){
    int c=1,i=0;
    if (a<0){
        a=a*(-1);
        i++;
    }
    while (c<=a){
     c*=2;
     i++;
    }
    return i;
}

string ones_mapping(int a){
    string ans="";
    if (a>0){
       ans= dec2bin(a);
    }
    else{
      int c=a/(-1);
      double b= pow(2.0,32.0)-c-1;
      ans=dec2bin(b);
    }
    return ans;
}

string twos_mapping(int a){
    string ans="";
    if (a>0){
       ans= dec2bin(a);
    }
    else{
      int c=a/(-1);
      double b= pow(2.0,32.0)-c;
      ans=dec2bin(b);
    }
    return ans;
}
void binAdd(long long int a,long long int b){
    string s1=twos_complement(a);
    string s2=twos_complement(b);
    string ans;
    char carry ='0';
    char prev_carry='0';
    for (int i=31;i>=0;i--){
        if(s1[i]=='1'&&s2[i]=='1'){
            if  (carry=='1'){
                ans.push_back('1');
                carry='1';
                prev_carry='1';
            }
            else{
                ans.push_back('0');
                carry='1';
                prev_carry='0';
            }
        }
        else if(s1[i]=='0'&&s2[i]=='0'){
            if  (carry=='1'){
                ans.push_back('1');
                carry='0';
                prev_carry='1';
            }
            else{
                ans.push_back('0');
                carry='0';
                prev_carry='0';
            }
        }
        else if (s1[i]!=s2[i]){
           if  (carry=='1'){
                ans.push_back('0');
                carry='1';
                prev_carry='1';
            }
            else{
                ans.push_back('1');
                carry='0';
                prev_carry='0';
            }
        }
    }
    for(int j=0;j<=16;j++){
        swap(ans[j],ans[31-j]);
    }
    int ans1=bin2dec(ans);
    if (ans[0]=='1'){
        string deci=twos_complement(ans1);
        ans1=bin2dec(deci);
    }
    ans=spacedstring(ans);
    if (carry==prev_carry){
            cout<<"Final result (in binary): "<< ans<<endl;
    }
    else{
        cout<<"overflow"<<endl;
        cout<<"Final result (in binary): "<< ans<<endl;
    }
    cout<<"Final result (in decimal): "<<ans1<<endl;
    return;
}

void binSub(long long int a,long long int b){
    b=(-1)*b;
    binAdd(a,b);
    return;
}

int main()
{
    int sample;
    while(sample!=5){
        cout<<"1) 1's Complement of a Decimal Number"<<endl;
        cout<<"2) 2's Complement of a Decimal Number"<<endl;
        cout<<"3) Binary Addition of two Decimal Numbers"<<endl;
        cout<<"4) Binary Subtraction of two Decimal Numbers"<<endl;
        cout<<"5) Enter 5 to Exit Program"<<endl<<endl;
        cout<<"Enter Your Choice: ";
        cin>>sample;
        switch(sample){
            case 1:{
                cout<<"Enter Decimal Number: ";
                int num;
                cin>>num;
                cout<<"Minimum size Required: "<<min_size(num)<<endl;
                string r=ones_complement(num);
                cout<<"1's complement using bitflip function: "<<spacedstring(r)<<endl;
                string s=ones_mapping(num);
                cout<<"1's complement using mapping function: "<<spacedstring(s)<<endl;
                cout<<"Mapping function implementation is easier"<<endl<<endl;
                break;
            }
            case 2:{
                cout<<"Enter Decimal Number: ";
                int num1;
                cin>>num1;
                cout<<"Minimum size Required: "<<min_size(num1)<<endl;
                string t=twos_complement(num1);
                cout<<"2's complement using bitflip function: "<<spacedstring(t)<<endl;
                string v=twos_mapping(num1);
                cout<<"2's complement using mapping function: "<<spacedstring(v)<<endl;
                cout<<"Mapping function implementation is easier"<<endl<<endl;
                break;
            }
            case 3:{
                cout<<"Enter Decimal Number 1: ";
                int num;
                cin>>num;
                cout<<"Enter Decimal Number 2: ";
                int num1;
                cin>>num1;
                string s=twos_complement(num);
                string r=twos_complement(num1);
                cout<<"Binary representation of 1st number: "<<spacedstring(s)<<endl;
                cout<<"Binary representation of 2st number: "<<spacedstring(r)<<endl;
                binAdd(num,num1);
                cout<<endl;
                break;
            }
            case 4:{
                cout<<"Enter Decimal Number 1: ";
                int num;
                cin>>num;
                cout<<"Enter Decimal Number 2: ";
                int num1;
                cin>>num1;
                string s=twos_complement(num);
                string r=twos_complement(num1);
                cout<<"Binary representation of 1st number: "<<spacedstring(s)<<endl;
                cout<<"Binary representation of 2st number: "<<spacedstring(r)<<endl;
                binSub(num,num1);
                cout<<endl;
                break;
            }
            case 5:
                break;
            default:
                cout<< "Enter a valid input"<<endl;
                break;

        }
    }
    return 0;
}

