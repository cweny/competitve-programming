#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int n,s;

struct rec {
    int x,y;
    string id;
};

void setQ(double &qx1, double &qx2, double &qy1, double &qy2, int q, double x1, double x2, double y1, double y2) {
    if(q == 0) {
        qx1=x1;
        qy1=y1;
        qx2=(x1+x2)/2;
        qy2=(y1+y2)/2;
    } else if(q == 1) {
        qx1=x1;
        qy1=(y1+y2)/2;
        qx2=(x1+x2)/2;
        qy2=y2;
    } else if(q == 2) {
        qx1=(x1+x2)/2;
        qy1=(y1+y2)/2;
        qx2=x2;
        qy2=y2;
    } else if(q == 3) {
        qx1=(x1+x2)/2;
        qy1=y1;
        qx2=x2;
        qy2=(y1+y2)/2;
    }
    // cout << qx1 << " " << qy1 << endl;
    // cout << qx2 << " " << qy2 << endl;
}

int quadrant(const rec &a, double x1, double x2, double y1, double y2) {
    double qx1,qx2,qy1,qy2;
    
    //0
    setQ(qx1, qx2, qy1, qy2,  0,  x1,  x2,  y1, y2);
    if(a.x >= qx1 && a.x <=qx2 && a.y >= qy1 && a.y <=qy2) {
        return 0;
    }
    
    //1
    setQ(qx1, qx2, qy1, qy2,  1,  x1,  x2,  y1, y2);
    if(a.x >= qx1 && a.x <=qx2 && a.y >= qy1 && a.y <=qy2) {
        return 1;
    }
    
    //2
    setQ(qx1, qx2, qy1, qy2,  2,  x1,  x2,  y1, y2);
    if(a.x >= qx1 && a.x <=qx2 && a.y >= qy1 && a.y <=qy2) {
        return 2;
    }
    
    //3
    return 3;
}
int getQ(int startq, int nextq, bool clock) {
    int q=startq;
    int count = 0;
    while(true) {
        if(q==nextq) break;
        if(clock) {
            q=(q+1)%4;
        } else {
            q=(q+3)%4;
        }
        count++;
    }
    if(count == 0 || count == 1 || count == 2) return startq;
    return (startq+2)%4;
}

int getPosition(int quad, int startquad, bool clock) {
    int q=startquad;
    int count = 0;
    
    while(true) {
        if(q==quad) {
            break;
        }
        if(clock) {
            q=(q+1)%4;
        } else {
            q=(q+3)%4;
        }
        count++;
    }
    return count;
}
// a<b;
// 1 2
// 0 3
bool recur(const rec &a, const rec &b, double x1, double x2, double y1, double y2, int quad, bool clock) {
    int aquad = quadrant(a,x1,x2,y1,y2);
    int bquad = quadrant(b,x1,x2,y1,y2);
    // cout << aquad << " " << bquad << endl;
    if (aquad == bquad) {
        double qx1,qx2,qy1,qy2;
        int q;
        bool c;
        setQ(qx1, qx2, qy1, qy2, aquad,  x1,  x2,  y1, y2);
        int pos = getPosition(aquad, quad, clock);
        if(pos == 0 || pos == 3) {
            c = !clock;
        } else {
            c = clock;
        }
        q = getQ(quad, aquad, clock);
        return recur(a,b,qx1,qx2,qy1,qy2,q,c);
    }
    int quadrant = quad;
    while(true) {
        if(aquad == quadrant) return true;
        else if(bquad == quadrant) return false;
        
        if(clock) quadrant = (quadrant+1)%4;
        else quadrant = (quadrant+3)%4;
    }
    return false;
}

bool comp(const rec &a, const rec &b) {
    return recur(a,b,0,n,0,n,0,1);
}

vector<rec> vec;

int main(void) {
    cin >> s >> n;
    for(int i=0; i<s; i++) {
        int x,y; cin >> x >> y;
        string str; cin >> str;
        rec r; r.x=x; r.y=y; r.id=str;
        vec.push_back(r);
    }
    sort(vec.begin(), vec.end(), comp);
    // cout << comp(vec[0],vec[1]) << endl;
    // cout << comp(vec[1],vec[0]) << endl;
    for(rec r:vec)
        cout << r.id << endl;
    return 0;
}
