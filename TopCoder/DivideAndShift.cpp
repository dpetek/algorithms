#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cctype>
#include <cmath>
#define pb push_back
#define fs first
#define sc second
#define foreach(c,it) for(typeof(((c).begin())) it=((c).begin());(it)!=((c).end());++(it))
#define _sz(c) ((int)c.size())
#define cstr(s) ((s).c_str())
using namespace std;

bool isPrime(int n){
    if ( n == 2 ) return 1;
    if ( n % 2 == 0 ) return 0;
    for (int i=3;i*i<=n;i+=2) if ( n % i == 0 ) return 0;
    return 1;
}
map<pair<int, int> , int> memoo;
class DivideAndShift {
public:
   int getLeast( int N, int M ) {
        queue<pair<pair<int, int>, int> > Q;
        vector<int> primes;

        for (int i=2;i<=N;++i){
            if ( isPrime(i)) primes.pb(i);
        }

        memoo.clear();
        Q.push(make_pair(make_pair(N, M), 1));

        while ( !Q.empty()){
            pair<pair<int, int> ,int> curr = Q.front();
            Q.pop();
            if ( curr.fs.sc == 1 ) return curr.sc-1;

            int m = memoo[curr.fs];
            if ( m && m <= curr.sc ) continue;
            memoo[curr.fs] = curr.sc;

            for (int i=0;i<primes.size();++i){

                if ( primes[i] > curr.fs.fs ) break;


                if ( curr.fs.fs % primes[i] == 0){
                    int Nnew = curr.fs.fs / primes[i];
                    int Mnew = (curr.fs.sc-1) % (Nnew) + 1;

                    if ( Nnew == 1 ) Mnew = 1;

                    Q.push(make_pair(make_pair(Nnew, Mnew), curr.sc + 1));
                }
            }
            Q.push(make_pair(make_pair(curr.fs.fs, curr.fs.sc-1), curr.sc + 1));
            Q.push(make_pair(make_pair(curr.fs.fs, (curr.fs.sc+1)%curr.fs.fs), curr.sc + 1));

        }
        return 0;
   }
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			}
			return;
		}

		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}

		if (total == 0) {
			cerr << "No test cases run." << endl;
		} else if (correct < total) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}

	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) {
		cerr << "Example " << casenum << "... ";

		string verdict;
		vector<string> info;
		char buf[100];

		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}

		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}

		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;

		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl;
			cerr << "    Received: " << received << endl;
		}

		return verdict == "PASSED";
	}

	int run_test_case(int casenum) {
		switch (casenum) {
		case 0: {
			int N                     = 56;
			int M                     = 14;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = DivideAndShift().getLeast(N, M);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 49;
			int M                     = 5;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = DivideAndShift().getLeast(N, M);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 256;
			int M                     = 7;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = DivideAndShift().getLeast(N, M);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 6;
			int M                     = 1;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = DivideAndShift().getLeast(N, M);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 77777;
			int M                     = 22222;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = DivideAndShift().getLeast(N, M);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int N                     = ;
			int M                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DivideAndShift().getLeast(N, M);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			int M                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DivideAndShift().getLeast(N, M);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			int M                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DivideAndShift().getLeast(N, M);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}


int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE
