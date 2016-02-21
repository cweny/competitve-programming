#include<iostream>
#include<algorithm>

#define pii pair<int, int>

using namespace std;

struct person {
  bool isMale;
  int start, end;
};
int fcount, mcount,n, msize,fsize;
pii start[5005], finish[50005];
person pep[50005];

int parse(pii * arr, int i, bool isBegin) {
    int fem = 0, male = 0;
    int atime = arr[i].first;
    if(pep[arr[i].second].isMale) {
        male++;
    } else {
        fem++;
    }
    
    i++;
    while(atime == arr[i].first && i<n) {
        if(pep[arr[i].second].isMale) {
             male++;
        } else {
            fem++;
        }
        i++;
    }
    
    if(isBegin) {
        fcount += fem;
        mcount += male;
    } else {
        fcount -= fem;
        mcount -= male;
    }
    return i;
}

int main(void) {
    msize = 0, fsize = 0;
    cin >> n;
    
    for(int i=0; i<n; i++) {
        char c; cin >> c;
        int s,e; cin >> s >> e;
        e++;
        pep[i].start = s; pep[i].end = e;
        if(c=='M') {
            pep[i].isMale = true;
            msize++;
            
        } else {
            pep[i].isMale = false;
        }
        start[i].first = s;
        start[i].second = i;
        finish[i].first = e;
        finish[i].second = i;
    }
    sort(start,start+n);
    sort(finish, finish+n);
    fsize = n-msize;
    // for(int i=0; i<n; i++) {
    //     cout << i << " " << pep[i].start << " " << pep[i].end << endl;
    // }
    // for(int i=0; i<n; i++) {
    //     cout << start[i].first << " " << start[i].second << endl;
    // }
    // cout << endl;
    // for(int i=0; i<n; i++) {
    //     cout << finish[i].first << " " << finish[i].second << endl;
    // }
    int si=0, ei=0;
    fcount = 0; mcount = 0;
    int ans = 0;
    // cout << "---------------" << endl;
    while(si<n || ei<n) {
        if(si==n) {
            int idx = parse(finish, ei, false);;
            ei = idx;
        } else if(ei==n) {
            int idx = parse(start, si, true);
            si = idx;
        } else {
            if(start[si].first < finish[ei].first) {
                int idx = parse(start, si, true);
                si = idx;
            } else if (start[si].first > finish[ei].first){
                int idx = parse(finish, ei, false);
                ei = idx;
            } else {
                int idx = parse(start, si, true);
                si = idx;
                int idx2 = parse(finish, ei, false);
                ei = idx2;
            }
        }
        // cout << si << " "  << ei << " " << fcount << " " << mcount << endl;
        
        ans = max(2*min(fcount,mcount),ans);
    }
    // cout << "---------------" << endl;
    cout << ans << endl;
    return 0;
}