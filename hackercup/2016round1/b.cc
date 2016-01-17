#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

#define ll long long
#define pii pair<ll, ll>


using namespace std;

struct compare {  
  bool operator()(const pii& l, const pii& r)  {  
	return l.first > r.first;  
  }  
};

struct compare2 {  
  bool operator()(const ll& l, const ll& r)  {  
	return l > r;  
  }  
};

ll num_loads,num_washers,num_dryers,dry_time;
ll wash_times[100005];
ll qsize=0;


int main(void) {
  int T, ca=0; cin >> T;
  while(T--) {
	cin >> num_loads >> num_washers >> num_dryers >> dry_time;
        
	for(ll i=0; i<num_washers; i++) {
	  cin >>wash_times[i];
	}
	priority_queue<pii, vector<pii>, compare> washers;  //<next wash end time, id>
	priority_queue<ll, vector<ll>, compare2 > dryers;            //<dry start time>
	qsize=0;
	for(int i=0; i<num_washers; i++) {
	  pii tmp; tmp.first=wash_times[i]; tmp.second=i;
	  washers.push(tmp);
	}
        
        
	for(int i=0; i<num_loads; i++) {
	  pii end_time = washers.top();
	  washers.pop();
	  ll id = end_time.second;
	  //send to dryer
	  ll dryer_start_time;
	  if(dryers.empty()) {
		dryer_start_time = 0;
	  } else {
		dryer_start_time=dryers.top();
		if(dryer_start_time>end_time.first && qsize<num_dryers) {
		  dryer_start_time = 0;
		} else {
		  dryers.pop();
		  qsize--;
		}
	  }
	  dryer_start_time = max(dryer_start_time, end_time.first) + dry_time;
	  dryers.push(dryer_start_time);
	  qsize++;
	  end_time.first += wash_times[id];
	  washers.push(end_time);
	}
        
	ll ans = -1;
	while(!dryers.empty()) {
	  ll at = dryers.top();
	  dryers.pop();
	  ans = max(ans, at);
	}
        
	cout << "Case #" << ++ca << ": " << ans << endl;
  }
  return 0;
}
