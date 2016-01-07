#include<iostream>
#include<string>

using namespace std;

string s;
int n;

void printMin(int sz) {
  for(int i=0; i<sz/2; i++) {
	cout << 4;
  }
  for(int i=sz/2; i<sz; i++) {
	cout << 7;
  }
  cout << endl;
}

inline bool ok() {
  for(int i=0; i<n/2; i++) {
	if(s[i] == '4')
	  return true;
  }
  return false;
}

inline void balance(int bal) {
  if(!ok()) {
	printMin(n+2);
	return;
  }
  int mark = 0;
  int fours = 0;
  //cout << s << endl;
  for(int i=n-1; i>=0; i--) {
  	fours++;
		if(s[i] == '7') {
		  s[i] = '4';
		  bal -= 2;
		  mark = i;
		}
		if(bal == -2)
		  break;
  }
  if(bal!=-2) {
  	printMin(n+2);
  	return;
  }
  //cout << s << " " <<bal << " " << mark << endl;
  int i = mark-1;
  for(; i>=0; i--) {
		if(s[i] == '4') {
		  s[i] = '7';
		  bal += 2;
		  break;
		}
  }
  i++;
  for(int count = 0; count < fours; count++) {
  	s[i] = '4';
  	i++;
  }
  for(;i<n; i++) {
  	s[i] = '7';
  }
  
  if(bal == 0) {
		cout << s << endl;
  } else {
		printMin(n+2);
  }
}

int main (void) {
  cin >> s;
  n=s.size();
  if(n%2 == 1) {
	printMin(n+1);
	return 0;
  }
  int bal = 0,idx=0,mark;
  bool flag = false;
  for(;idx<n; idx++) {
	if(s[idx]=='4') {
	  //bal--;
	  continue;
	} else if( s[idx] == '7')  {
	  //bal++;
	  continue;
	} else if( s[idx] < '4' ) {
	  s[idx] = '4'; mark = idx+1;
	  //bal--;
	  break;
	} else if(s[idx] <'7') {
	  s[idx] = '7'; mark = idx+1;
	  //bal++;
	  break;
	} else {
	  flag = true;
	  mark = idx-1;
	  idx--;
	  break;
	}
  }
  //cout << s << " " <<mark << endl;
  //mark == where to start changing to 4
  //mark == where to look for 4
  if(flag) {
	//cout << "here " << endl;
	for(; mark>=0; mark--) {
	  if(s[mark] == '4') {
		s[mark] = '7';
		//cout << "change: " << s << endl;
		flag = false;
		mark++;
		break;
		
	  }
	}
  }
  if(flag) {
	printMin(n+2);
	return 0;
  }
  for(; mark<n; mark++) {
	s[mark]='4';
  }
  //cout << "here: " << s << endl;
  bal=0;
  for(int index=0; index<n; index++) {
	if(s[index] == '4') {
	  bal--;
	} else if (s[index] == '7'){
	  bal++;
	}
  }
  if(bal==0) {
	cout << s << endl;
	return 0;
  } else if (bal < 0) {
	for(int i=n-1; i>=0; i--) {
	  if(s[i] == '4') {
		s[i] = '7';
		bal += 2;
	  }
	  if(bal == 0)
		break;
	}
	cout << s << endl;
  } else {
	balance(bal);
  }
  return 0;
}
