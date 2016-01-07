#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<limits>

using namespace std;

int n,arr[20005];
bool isComposite[145];
vector<int> comp[20005];
int memo[20005][105];
//int at[20005];
//int reg[20005][20005];

void runEratosthenesSieve() {
  int upperBound = 145;
  int upperBoundSquareRoot = (int)sqrt((double)upperBound);
  memset(isComposite, 0, sizeof(bool) * (upperBound + 1));
  for (int m = 2; m <= upperBoundSquareRoot; m++) {
    if (!isComposite[m]) {
      for (int k = m * m; k <= upperBound; k += m)
	isComposite[k] = true;
    }
  }
}
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
void decomp() {
  for(int i=0; i<n; i++) {
    int num=arr[i];
    //cout << (int)sqrt((double)num) << endl;
    for(int p=2; p<=(int)sqrt((double)num); p++) {
      //cout << "p " << p << " num: " << num << endl;
      if(isComposite[p]) continue;
      //cout << "p " << p << " num: " << num << endl;
      if(num%p==0) {
	comp[i].push_back(p);
	while(num%p ==0) {
	  num /= p;
	}
      }
    }

    if(num>1) comp[i].push_back(num);
  }
}

// bool whithin(int s, int e) {
//   for(int i=s; i<=e; i++) {
//     if(at[i] >= comp[i].size())
//       return false;
//   }
//   return true;
// }

int region(int s, int e) {
  int num=arr[s];
  for(int i=s+1; i<=e; i++) {
    num=gcd(num,arr[i]);
    if(num==1) return 0;
  }
  int ans=0;
  for(int p=2; p<=(int)sqrt((double)num); p++) {
      //cout << "p " << p << " num: " << num << endl;
      if(isComposite[p]) continue;
      //cout << "p " << p << " num: " << num << endl;
      if(num%p==0) {
        ans=p;
	while(num%p ==0) {
	  num /= p;
	}
      }
  }

  if(num>1) return num;
  return ans;
  // if(reg[s][e]!=-1) return reg[s][e];
  // if(s==e) {
  //   return comp[s][0];
  // }
  // for(int i=s; i<=e; i++) at[i]=0;
  // int M=0;
  // bool ok=true;
  // while(whithin(s,e)) {
  //   M=0;
  //   for(int i=s; i<e; i++) {
  //     if(comp[i][at[i]] != comp[i+1][at[i+1]] ) 
  // 	ok = false;
  //     M=max(M, max(comp[i][at[i]], comp[i+1][at[i+1]]));
  //   }
  //   for( int i=s; i<=e; i++ ) {
  //     if(comp[i][at[i]] == M) {
  // 	at[i]++;
  // 	break;
  //     }
  //   }
  //   if(ok) return reg[s][e]= M;
  // }
  
  // return reg[s][e]=0;
}
int f(int s, int k) {
  if(k==0 && s<n) {
    return 10000000;
  }
  if(k==1) {
    return region(s,n-1);
  }
  if(s==n) {
    if(k>0)
      return 10000000;
    else
      return 0;
  }

  if(memo[s][k]!=-1) return memo[s][k];
  //cout << "   lkjhdf" << s << " " << k << endl;
  int M=0;
  for( int i=s; i<=n-1; i++ ) {
    //int first = region(s,i);
    //int second = f(i+1, k-1);
    //if(k==2)
      //cout << "i: " << i << " " << first << " " << second << endl;
    M=max(M,min(region(s,i), f(i+1, k-1)));
  }
  return memo[s][k]=M;
}

int main(void) {
  ios_base::sync_with_stdio(0);
  int k;
  cin >> n >> k;
  for(int i=0; i<n; i++) {
    cin >> arr[i];
  }
  runEratosthenesSieve();
  //decomp();
  // for(int i=0; i<n; i++) {
  //   reverse(comp[i].begin(), comp[i].end());
  // }
  // for( int i=0; i<n; i++ ) {
  //   for( int k:comp[i] ) {
  //     cout << k << " ";
  //   }cout << endl;
  // }
  for(int i=0; i<=n; i++) {
      for( int q; q<=k; q++ ) {
	memo[i][q] = -1;
      }
  }
  memset(memo, -1, sizeof memo);
  //memset(reg, -1, sizeof reg);
  // out << region(0,1) << endl;
  // cout << region(2,3) << endl;
  // cout << region(4,4) << endl;
  cout << f(0,k)<< endl;
  return 0;
}
