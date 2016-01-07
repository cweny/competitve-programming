#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
string n1,op,n2,eq,res;
void trim(string &s) {
    for(unsigned i=0; i<s.size();i++) {
        if(s[i]==' ')
            s.erase(i,1);
    }
}
int get_val(char c) {
    if(c>='0' && c<='9') {
        return c-'0';
    }
    return c-'a'+10;
}
int convert(string s,int base) {
    //unsigned n=s.size();
    int res = 0;
    int power = 1;
    //return 1;
    //cout << s.size() << endl;
    for(int i=s.size()-1; i>=0; i--) {
        //cout << "i is:" << i << endl;
        int val =get_val(s[i]);
        //cout << val << endl;
        res += val*power;
        power*=base;
        //cout << i;
    }
    
    return res;
}
int min_base(string s) {
    char m='0';
    for(unsigned i=0;i<s.size();i++) {
        if(s[i]>m) m=s[i];
    }
    return get_val(m)+1;
}

bool ones(string s) {
    for(int i=0;i<s.size();i++) {
        if(s[i]!='1') return false;
    }
    return true;
}
int min() {
    int m=min_base(n1);
    m=max(m,min_base(n2));
    m=max(m,min_base(res));
    return m;
}
int main(void) {
    int t;cin>>t;
    //cout << convert("aaa",16) << endl;
    while(t--) {
        
        cin>>n1>>op>>n2>>eq>>res;
        //cout << n1 <<endl<<op<<endl<<n2<<endl<<eq<<endl<<res;
        trim(n1);
        trim(n2);
        trim(res);
        bool ok=false;
        
        if(ones(n1)&&ones(n2)&&ones(res)) {
            int op1 = n1.size(),op2 = n2.size(),result=res.size();
            bool flag=false;
            if(op[0]=='-' && op1-op2==result) flag=true;
            else if(op[0]=='/' && op1/op2==result)flag=true;
            else if(op[0]=='+' && op1+op2==result)flag=true;
            else if(op[0]=='*' && op1*op2==result)flag=true;
            if(flag) {
                ok=true;
                cout << 1 ;
            }
        }
        
        for(int i=min();i<=36;i++) {
            int f=convert(n1,i),s=convert(n2,i),r=convert(res,i);
            bool flag=false;
            //cout <<"here "<<op[0]<<" "<< f << " " << s << " " << r << endl;
            if(op[0]=='-' && f-s==r) flag=true;
            else if(op[0]=='/' && f==r*s) {
                flag=true;
            }
            else if(op[0]=='+' && f+s==r)flag=true;
            else if(op[0]=='*' && f*s==r)flag=true;
            //flag=false;
            if(flag) {
                ok = true;
                if(i>=2&&i<=9) cout << i;
                else if(i>=36) cout <<"0";
                else cout  << char(i-10+'a');
            }
        }
        if(ok==false) cout << "invalid";
        
        cout << endl;
    }
    return 0;
}