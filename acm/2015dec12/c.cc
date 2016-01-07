#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

struct person {
    string name, hier;
    bool operator<(const person &p) const{
        int n1 = this->hier.size(), n2 = p.hier.size();
        int M=max(n1,n2);
        for(int i=1; i<=M; i++) {
            int i1 = n1-i, i2 = n2-i;
            if(i2>=0 && i1>=0) {
                if(this->hier[i1]<p.hier[i2]) return true;
                
                else if(this->hier[i1]>p.hier[i2]) return false;
            } else if(i2<0) {
                
                if(this->hier[i1]<'m') return true;
                else if(this->hier[i1]>'m') return false;
                
            } else if(i1<0) {
                
                if(p.hier[i2]<'m') return false;
                else if(p.hier[i2]>'m') return true;
                
            }
        }
        if(this->name.compare(p.name) < 0) return false;
        return true;
    }
};


int n;
vector<person> vec;

int main(void ) {
    //string tmp = "b";
    //cout << tmp.compare("a");
    
    string name;
    cin >> n;
    int ca=0;
    while(cin>>name) {
        name.pop_back();
        string hier;
        person p; p.name=name; p.hier="";
        vec.push_back(p);
        while(cin>>hier) {
            if(hier == "class") break;
            vec[ca].hier += hier[0];
        }
        ca++;
    }
    sort(vec.begin(), vec.end());
    for(int i=n-1; i>=0; i--) {
        cout << vec[i].name << endl;
    }
    
    // cout << (vec[1] < vec[2]) << endl;
    return 0;
}