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

using namespace std;

class Card
{
    public:
        int value;
        int color;
        Card(string s)
        {
            if ( s[0] >= '2' && s[0] <= '9') value = s[0] - '0';
            else
            {
                if ( s[0] == 'T') value = 10;
                if ( s[0] == 'J') value = 11;
                if ( s[0] == 'Q') value = 12;
                if ( s[0] == 'K') value = 13;
                if ( s[0] == 'A') value = 14;
            }

            switch(s[1])
            {
                case 'H':
                    color = 0;
                    break;
                case 'C':
                    color = 1;
                    break;
                case 'S':
                    color = 2;
                    break;
                case 'D':
                    color = 3;
                    break;
            }
        }
};

bool cmp(const Card &c1, const Card &c2)
{
    return c1.value < c2.value;
}

class Hand
{
    public:
    vector<Card> cards;
    vector<int> pairsValue;
    vector<int> threeValue;
    vector<int> fourValue;

    int rank;
        Hand(vector<string> cards)
        {
            for (int i=0;i<cards.size();++i)
            {
                this->cards.push_back(Card(cards[i]));
            }
            rank = 1;
        }

        void EvalCards()
        {
            pairsValue.clear();
            threeValue.clear();
            fourValue.clear();
            int used[4][20];
            for (int i=0;i<cards.size();++i)
            {
                used[cards[i].color][cards[i].value] = 1;
            }

            int pairsCount = 0, threeCount = 0, fourCount = 0;
            for (int v=2;v<=14;++v)
            {
                int cnt = 0;
                for(int i=0;i<4;++i) cnt+=used[i][v];
                if ( cnt == 2 ) {++pairsCount;pairsValue.pb(v);}
                if ( cnt == 3 ) {++threeCount;threeValue.pb(v);}
                if ( cnt == 4 ) {++fourCount;fourValue.pb(v);}
            }
            sort(pairsValue.begin(), pairsValue.end(), greater<int>());

            if ( pairsCount == 2) rank = max(rank, 3);
            if ( pairsCount == 1 && threeCount == 1) rank = max(rank, 7);
            if ( pairsCount == 0 && threeCount == 1) rank = max(rank, 4);
            if ( pairsCount == 1 && threeCount == 0) rank = max(rank, 2);
            if ( fourCount == 1 ) rank = max(rank, 8);

            bool isFlush = true;
            for (int i=1;i<cards.size();++i)
            {
                if ( cards[i].color != cards[i-1].color)
                {
                    isFlush = false;
                    break;
                }
            }

            if ( isFlush ) rank = max(rank, 6);

            sort(cards.begin(), cards.end(), cmp);
            bool isStraight = true;
            for (int i=1;i<cards.size();++i)
            {
                if ( cards[i].value != cards[i-1].value + 1)
                {
                    isStraight = false;
                }
            }

            if ( isStraight && isFlush ) rank = max(rank, 9);
            if ( isStraight && !isFlush ) rank = max(rank, 5);
            if ( isStraight && isFlush && cards[0].value==10) rank = max(rank, 10);
        }
};

int cmp(Hand &h1, Hand &h2)
{
    h1.EvalCards();h2.EvalCards();
    if ( h1.rank != h2.rank) {
        if ( h1.rank > h2.rank ) return -1;
        return 1;
    }

    switch(h1.rank)
    {
        case 10:
            return 0;
        case 1:case 4:case 5:case 9:
            for (int i=4;i>=0;--i)
            {
                if ( h1.cards[i].value > h2.cards[i].value) return -1;
                if ( h1.cards[i].value < h2.cards[i].value) return 1;
            }
            return 0;
            break;
        case 2:
            if ( h1.pairsValue[0] != h2.pairsValue[0])
            {
                if ( h1.pairsValue[0] > h2.pairsValue[0])return -1;
                return 1;
            }
            for (int i=4;i>=0;--i)
            {
                if ( h1.cards[i].value > h2.cards[i].value) return -1;
                if ( h1.cards[i].value < h2.cards[i].value) return 1;
            }
            return 0;
            break;
        case 3:

            break;
    }

}


int main(void){

	return 0;
}
