#include <iostream>
#include <string>
#include <stdint.h>
#include<cinttypes>
#include <bitset>
#include <cmath>

using namespace std;

string dec2bin_int(long long int a){
   bitset<8> bset;
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
 for (int i=a.length()-1;i>=0;i--){
    if (a[i]=='1'){
    ans+= x*(a[i]-'0');
    }
    x=x*2;
    }
    return ans;
}

string ones_complement(string a){
    string ans="";
      string s=a;
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

    return ans;
}

string bin2hex(string a){
string binToHex="", sub_string = "0000";
    for (size_t j = 0; j < a.size(); j += 4){
        sub_string = a.substr(j, 4);
        if (sub_string.compare("0000")==0)
            binToHex += "0";
        else if (sub_string.compare("0001")==0)
            binToHex += "1";
        else if (sub_string.compare("0010")==0)
            binToHex += "2";
        else if (sub_string.compare("0011")==0)
            binToHex += "3";
        else if (sub_string.compare("0100")==0)
            binToHex += "4";
        else if (sub_string.compare("0101")==0)
            binToHex += "5";
        else if (sub_string.compare("0110")==0)
            binToHex += "6";
        else if (sub_string.compare("0111")==0)
            binToHex += "7";
        else if (sub_string.compare("1000")==0)
            binToHex += "8";
        else if (sub_string.compare("1001")==0)
            binToHex += "9";
        else if (sub_string.compare("1010")==0)
            binToHex += "A";
        else if (sub_string.compare("1011")==0)
            binToHex += "B";
        else if (sub_string.compare("1100")==0)
            binToHex += "C";
        else if (sub_string.compare("1101")==0)
            binToHex += "D";
        else if (sub_string.compare("1110")==0)
            binToHex += "E";
        else if (sub_string.compare("1111")==0)
            binToHex += "F";
        else continue;
    }
   return binToHex;
}
union Convertfloatint{
    float in;
    uint32_t out;
}convert32;

union ConvertDoubleint{
    double in;
    uint64_t out;
}convert64;



string HexToBin(string hexdec)
{

    int i = 0;
    string ans="";
    while (i<8) {
        char a=hexdec[i];
    switch (a) {
        case '0':
            ans=ans+"0000";
            break;
        case '1':
            ans=ans+"0001";
            break;
        case '2':
            ans=ans+"0010";
            break;
        case '3':
            ans=ans+"0011";
            break;
        case '4':
            ans=ans+"0100";
            break;
        case '5':
            ans=ans+"0101";
            break;
        case '6':
            ans=ans+"0110";
            break;
        case '7':
            ans=ans+"0111";
            break;
       case '8':
            ans=ans+"1000";
            break;
        case '9':
            ans=ans+"1001";
            break;
        case 'A':
            ans=ans+"1010";
            break;
        case 'B':
            ans=ans+"1011";
            break;
        case 'C':
            ans=ans+"1100";
            break;
        case 'D':
            ans=ans+"1101";
            break;
        case 'E':
            ans=ans+"1110";
            break;
        case 'F':
            ans=ans+"1111";
            break;
        default:
            printf("\nInvalid hexadecimal digit %c",hexdec[i]);
        }
        i++;
    }
    return ans;
}

string add(string str1, string str2){
   string ans_str = "";
   int carry = 0;
   int lengthof1 = str1.size() - 1;
   int lengthof2 = str2.size() - 1;
   while (lengthof1 >= 0 || lengthof2 >= 0 || carry == 1){
      carry += ((lengthof1 >= 0)? str1[lengthof1] - '0': 0);
      carry += ((lengthof2 >= 0)? str2[lengthof2] - '0': 0);

      char value= (carry%2 +'0');
      ans_str = value + ans_str;
      carry /= 2;
      lengthof1--; lengthof2--;
   }
   return ans_str;
}

string dec2IEEE754(float f){
    char sign;
    if (f<0){
       f=f*(-1);
       sign='1';
    }
    else
        sign='0';
    float  frac_f;
    long int int_f,count=0;
    long int rem, temp;
    string s="";
    int_f = (int)f;
    frac_f = f - int_f;
    while (int_f != 0) {
        rem = int_f % 2;
        if (rem==0)
            s.push_back('0');
        else
            s.push_back('1');
        int_f = int_f / 2;
        count++;
    }
    int n=s.length();
     for (int i = 0; i < n / 2; i++)
        swap(s[i], s[n - i - 1]);

    while (frac_f!= 0) {
        frac_f = frac_f* 2;
        temp = frac_f;
        if (temp == 1){
            frac_f = frac_f - temp;
            s.push_back('1');
        }
        else{
            s.push_back('0');
        }
    }
    int d=0;
    for(int i=0;i<s.length();i++){
        if (s[i]=='1'){
            d++;
            s=s.substr(i+1,23);
            break;
        }
        d++;
    }
    if (s.length()<23){
        for (int i=s.length();i<23;i++){
            s.push_back('0');
        }
    }
    int exp=count-d+127;
    if (exp>255 || exp<1){
        cout<<"Result is a Denormal number"<<endl;
    }
    string r= dec2bin_int(exp);
    string space=" ";
    string final_=sign+space+r+space+s;
    return final_;
}

string hexa2hexa(string s){
    s=s.substr(2,8);
    string binary= HexToBin(s);
    char sign=binary[0];
    string exp=binary.substr(1,8);
    string mantisa=binary.substr(9,23);
    int exp_a=bin2dec(exp);
    if (exp_a>255 || exp_a<1){
        string denormal="Result is a denormal number";
        return denormal;
    }
    exp_a=exp_a-127;
    string int_;
    if (exp_a>=0){
        for (int i=0;i<100;i++){
            mantisa.push_back('0');
        }
        int_="1";
        for (int i=0;i<exp_a;i++){
            int_.push_back(mantisa[i]);
        }
        mantisa=mantisa.substr(exp_a,23);
    }
    else{
        exp_a=exp_a*(-1);
       int_="0";
       mantisa.insert(0,"1");
       for (int i=0;i<exp_a-1;i++){
            mantisa.insert(0,"1");
       }
       mantisa=mantisa.substr(0,23);
    }
    double factor=1;
    long double ans=0;
    for (int j=0;j<mantisa.length();j++){
        factor=factor/2;
        ans+=factor*(mantisa[j]-'0');
    }
    double ans_int=bin2dec(int_);
    double final_ans=ans_int+ans;
    string bin="";
    int temp;
    while (ans!= 0) {
        ans = ans* 2;
        temp = ans;
        if (temp == 1){
            ans = ans - temp;
            bin.push_back('1');
        }
        else{
            bin.push_back('0');
        }
    }
    for (int i=bin.length();i<32;i++ ){
        bin.push_back('0');
    }
    for(int i=int_.length();i<32;i++){
        int_.insert(0,"0");
    }
    if (sign=='1'){
        final_ans= final_ans*(-1);
        bin=ones_complement(bin);
        int_=ones_complement(int_);
        //here we are using ones complement to convert negative number to positive number
    }
    string hex_int=bin2hex(int_);
    string hex_deci=bin2hex(bin);
    string final_str=hex_int+"."+hex_deci;
    return final_str;
}
string IEEE_addition(float a,float b){
    string aa=dec2IEEE754(a);
    string bb=dec2IEEE754(b);

    string exp_aa=aa.substr(2,8);
    string exp_bb=bb.substr(2,8);

    string mantisa_a=aa.substr(11,23);
    string mantisa_b=bb.substr(11,23);

    int exp_a=bin2dec(exp_aa);
    int exp_b=bin2dec(exp_bb);
    int diff=0;
    int max_power=exp_a;
    int int_a=1,int_b=1;
    if (exp_a>exp_b){
        max_power=exp_a;
        diff=exp_a-exp_b;
        mantisa_b.insert(0,"1");
        for (int i=0;i<diff-1;i++){
            mantisa_b.insert(0,"0");
        }
        int_b=0;
        mantisa_b=mantisa_b.substr(0,23);
    }
    else if (exp_b>exp_a){
        max_power=exp_b;
        diff=exp_b-exp_a;
        mantisa_a.insert(0,"1");
        for (int i=0;i<diff-1;i++){
            mantisa_a.insert(0,"0");
        }
        int_a=0;
        mantisa_a=mantisa_a.substr(0,23);
    }
    string mantisa=add(mantisa_a,mantisa_b);
    if (mantisa.length()>23 && mantisa[0]=='1'){
        if (int_a==1 && int_b==1){
           mantisa=mantisa.substr(0,23);

        }
        else{
            mantisa[0]='0';
            mantisa=mantisa.substr(0,23);
        }
        max_power+=1;
    }
    if (max_power>255 || max_power<1){
        cout<<"Result is a Denormal number"<<endl;
    }
    string exp=dec2bin_int(max_power);
    char sign='0';
    string space=" ";
    string result=sign+space+exp+space+mantisa;
    return result;
}

string IEEE_multiplication(float a,float b){
    string aa=dec2IEEE754(a);
    string bb=dec2IEEE754(b);

    string exp_aa=aa.substr(2,8);
    string exp_bb=bb.substr(2,8);

    string mantisa_a=aa.substr(11,23);
    string mantisa_b=bb.substr(11,23);
    mantisa_a.insert(0,"1");
    mantisa_b.insert(0,"1");

    int exp_a=bin2dec(exp_aa);
    int exp_b=bin2dec(exp_bb);
    int sum= exp_a+exp_b-127;
    //cout<<sum<<endl;
    int c=0;
    string ans="00000000000000000000000";

    for (int i=22;i>=0;i--){
        if (mantisa_b[i]=='1'){
            string ss=mantisa_a;
           for (int j=0;j<c;j++){
               ss.push_back('0');
           }
           ans=add(ss,ans);
        }
        c++;
    }
    //cout<<ans<<endl;
    int deci= ans.length()-46;
    sum=sum+deci;
     if (sum>255 || sum<1){
        cout<<"Result is a Denormal Number"<<endl;
    }
    ans=ans.substr(1,23);
    string exp=dec2bin_int(sum);
    string space=" ";
    char sign='0';
    string result=sign+space+exp+space+ans;
    return result;
}


int main()
{
    cout<<"1) Float/Double to Hexadecimal (Question 1)"<<endl;
    cout<<"2) Decimal to IEEE 754 Single precision floating point number (Question 2a)"<<endl;
    cout<<"3) Hexadecimal using FPR to Hexadecimal without using FPR (Question 2b)"<<endl;
    cout<<"4) Addition of Floating Point Numbers (Question 3a)"<<endl;
    cout<<"5) Multiplication of Floating Point Numbers (Question 3b)"<<endl;
    cout<<"6) Enter six to exit program"<<endl;

    int sample;
    while (sample!=6)
    {
    cout<<"Enter your Choice: ";
    cin>>sample;
    switch(sample){
    case 1:{
        cout<<"Float or Double input(f/d): ";
        char input;
        cin>>input;
        if (input=='f'){
            float f;
            cout<<"Enter Float Number: ";
            cin>>f;
            convert32.in=f;
            printf("0x%08" PRIx32,convert32.out);
            cout<<endl;
        }
        else if (input=='d'){
            double d;
            cout<<"Enter Double Number: ";
            cin>>d;
            convert64.in=d;
            printf("0x%08" PRIx64,convert64.out);
            cout<<endl;
        }
        break;
    }
    case 2:{
        cout<<"Enter a decimal Number: ";
        float deci;
        cin>>deci;
        cout<<dec2IEEE754(deci)<<endl;
        break;
    }
    case 3:{
        cout<<"Enter Hexadecimal string: ";
        string hex;
        cin>>hex;
        cout<<hexa2hexa(hex)<<endl;
        break;
    }
    case 4:{
        cout<<"Enter First unsigned Number: ";
        float first;
        cin>>first;
        cout<<"Enter Second unsigned Number: ";
        float second;
        cin>>second;
        cout<<IEEE_addition(first,second)<<endl;
        break;
    }
    case 5:{
        cout<<"Enter First unsigned Number: ";
        float fir;
        cin>>fir;
        cout<<"Enter Second unsigned Number: ";
        float sec;
        cin>>sec;
        cout<<IEEE_multiplication(fir,sec)<<endl;
        break;
    }
    case 6:
        break;
    default:
        cout<<"Enter valid choice"<<endl;
        break;
    }
    cout<<endl;
    }
    return 0;
}
