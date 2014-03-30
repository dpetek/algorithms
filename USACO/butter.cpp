/*
ID:
PROG:butter
LANG:C++
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <cmath>
#define pb push_back
#define fs first
#define sc second
#define INF -1

using namespace std;

int shortest[1002][1002];
bool used[1001][1002];

vector<pair<int, int> > graph[1002];


void dijkstra(int start)
{
    priority_queue<pair<int,int> , vector<pair<int,int> > , greater<pair<int,int> > > Q;
    Q.push(make_pair(0, start));
    used[start][start] = true;
    shortest[start][start] = 0;
    while(!Q.empty())
    {
        int currentNode = Q.top().sc;
        int totalDistance = Q.top().fs;
        Q.pop();

        used[start][currentNode] = true;
        for (int i=0;i<graph[currentNode].size();++i)
        {
            int nextNode = graph[currentNode][i].fs;
            int nextDist = totalDistance + graph[currentNode][i].sc;
            if (!used[start][nextNode] )
            {
                if ( shortest[start][nextNode] == INF || nextDist < shortest[start][nextNode])
                {
                    shortest[start][nextNode] = nextDist;
                    Q.push(make_pair(nextDist, nextNode));
                }
            }
        }

    }
}


int main(void){
    freopen("butter.in", "r", stdin);
    freopen("butter.out", "w", stdout);
    int N, P, C, tmp, a, b, c;

    scanf("%d %d %d", &N, &P, &C);
    vector<int> cows;
    bool calculated[1001] = {false};

    for (int i=0;i<=800;++i)
    {
        for (int j=0;j<=800;++j)
        {
            shortest[i][j] = INF;
        }
    }

    for (int i=0;i<N;++i)
    {
        scanf("%d", &tmp);
        cows.push_back(tmp);
    }

    for (int i=0;i<C;++i)
    {
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }

    for (int i=0;i<cows.size();++i)
    {
        if ( !calculated[cows[i]] )
        {
            dijkstra(cows[i]);
            calculated[cows[i]] = true;
        }
    }

    int s = 1000000000;
    for (int i=1;i<=P;++i)
    {
        bool valid = true;
        int sum = 0;
        for (int j=0;j<cows.size();++j)
        {
            if ( shortest[cows[j]][i] == INF)
            {
                valid = false;
                break;
            }
            sum+=shortest[cows[j]][i];
        }
        if ( valid )
        {
            if ( sum < s ) s = sum;
        }
    }

    cout << s << endl;

	return 0;
}
