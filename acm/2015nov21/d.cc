#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;

const int inf = 1000000000;



int di(int time, int C) {
  if(time==0) return 0;
  if(time>=1 && time<=10) return -1*C;
  return (time-10)*(time-10);
}

int dp(int num_topics, int num_lec, int time, int N, int L, int C, int minutes[1009], bool seen[1009][1009], int memo[1009][1009]) {
  if(num_lec==0 && num_topics==0) { 
    return 0;
  }
  if(num_lec<=0) return inf;
  if(num_topics<=0) {
    return 0;
  }

  if(seen[num_topics][num_lec]) return memo[num_topics][num_lec];

  int current_time = L;
  int ans = inf;
  int at = num_topics;
  while(current_time>0 && at>0) {
    current_time -= minutes[N-at];
    if(current_time<0) break;
    //int first = dp(at, num_lec-1, L, N, L, C, minutes, seen, memo) ;
    int tmp = dp(at-1, num_lec-1, L, N, L, C, minutes,seen,memo) + di(current_time, C);
    ans = min(ans, tmp);
    at--;
  }
  seen[num_topics][num_lec] = true;
  return memo[num_topics][num_lec]=ans;
}

int main(void) {
  int N,L,C,minL;
  int minutes[1009];
  static bool seen[1009][1009];
  static int memo[1009][1009];
  ios_base::sync_with_stdio(0);
  
  cin>>N;
  int ca = 0;
  bool flag=false;
  while(N>0) {
    if(flag) {
      cout << endl;
    }
    flag=true;
    cin >> L >> C;
    minL = 1;
    int at = 0;
    for( int i=0; i<N; i++ ) {
      cin >> minutes[i];
      if( at + minutes[i] <= L ) {
	      at += minutes[i];
      } else {
      	at = minutes[i];
      	minL++;
      }
    }
    if( at == 0 ) minL--;
    memset(seen,0,sizeof seen);

    cout << "Case " << ++ca << ":\n";
    cout << "Minimum number of lectures: " << minL << endl;
   
    cout << "Total dissatisfaction index: " << dp(N,minL,L,N,L,C,minutes,seen,memo) << endl;
    cin>>N;
  }

  
  
  return 0;
}
