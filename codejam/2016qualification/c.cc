#include<iostream>
#include<unordered_set>
#include<bitset>
#include<vector>
#include<cmath>
#define int long long
using namespace std;


int primes[] =  {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541};
unordered_set<int> us;
int n,j,T;

int getb(int b, string s) {
    int p=1;
    int sz = s.size();
    int ans = 0;
    for(int i=sz-1; i>=0; i--) {
        if(s[i] == '1') {
            ans += p;
        }
        p *= b;
    }
    return ans;
}

int getfactor(int x) {
    for(int i=0; primes[i] <= sqrt(x)+1; i++) {
        // cout << "prime: " << primes[i] << " x: " << x << " ";
        if(x%primes[i] == 0) return primes[i];
    }
    return -1;
}

bool check(int x) {
    string s = bitset< 64 >( x ).to_string();
    s = s.substr(s.size()-n+2);
    s = "1" + s + "1";
    // cout << s << endl;
    vector<int> vec;
    for(int i=2; i<=10; i++) {
        int fac = getfactor(getb(i,s));
        if(fac<0) return false;
        vec.push_back(fac);
    }
    cout << s << " ";
    for(int xx:vec) {
        cout << xx << " ";
    }
    cout << endl;
    return true;
}
#undef int
int main(void) {
#define int long long
    for(int i=0; i<100; i++) {
        us.insert(primes[i]);
    }
    cin >> T;
    int ca=0;
    while(T--) {
        cout << "Case #" << ++ca << ": " << endl;
        cin >> n >> j;
        int got = 0;
        for(int num=0; num<(1<<(n-2)); num++) {
            
            if(check(num)) {
                got++;
            }
            if(got >= j) {
                break;
            }
        }
    }
    return 0;
}