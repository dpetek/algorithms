#include <queue>
#include <iostream>
#include <map>

#define x first
#define y second

using namespace std;

typedef pair<int,int> P;

typedef unsigned long long ulint;

int main()
{

	map<int,map<int,int> > T;
	map<int,vector<P> > g;

	T[0][0]=1;
	T[1][1]=1;
	T[1][0]=1;

	g[1].push_back(P(0,0));
	for(int i=2;i<=4500;i++){
		T[i][0]=1;
		for(int j=1;j<i;j++){
			T[i][j]=T[i-1][j-1]+T[i-1][j];
			if(T[i][j]>10000000){ T[i][j]=10000001; break; }
			else if(j>1)g[T[i][j]].push_back(P(i,j));
		}
		T[i][i]=1;
	}

	map<int,vector<P> >::iterator it;

	map<int,int> MIN;

	for(int i=0;i<4500;i++) MIN[i]=i;


	for(it=g.begin();it!=g.end();it++)
		for(int i=0;i<it->second.size();i++)
			if(MIN[it->first]>it->second[i].first)
				MIN[it->first]=it->second[i].first;

	MIN[1]=1;
	MIN[0]=1;

	//for(int i=0;i<16;i++) cout<<"["<<i<<"]="<<MIN[i]<<endl;


	int c=1, N, S;

	cin>>N;

	while(c<=N){
		cin>>S;

		int ans=0;

		for(int i=1;i*i<=S;i++)
			if(S%i==0){
				int j=S/i;
				int T=0;
				if(i<4500) T=MIN[i];else T=i;
				if(j<4500) T+=MIN[j];else T+=j;
				if(ans==0 || T<ans) ans=T;
			}

		cout<<"Case #"<<c<<": "<<ans<<endl;
		c++;
	}

	return 0;
}
