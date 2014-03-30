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

class Zoo {
public:
    long long myPow(long long a , int b){
        if ( !b ) return 1LL;
        if ( b == 1LL ) return a;

        long long tmp = myPow(a, b/2);
        if ( b&1 ) return a * tmp *tmp;
        return tmp * tmp;
    }

   long long theCount( vector <int> v ) {
        sort(v.begin(), v.end(), greater<int>());

        for (int i = 0;i<=v.size();++i){
            int r = i, c = v.size() - i;
            int _r = r, _c = c;
            vector<bool> used(v.size(), false);
            --r;--c;
            for (int j=0;j<v.size();++j){
                if ( v[j] == r ){
                    used[j] = true;
                    --r;
                }
                if ( v[j] == c && !used[j]){
                    used[j] = true;
                    --c;
                }
            }
            bool ok = true;
            for (int j=0;j<v.size();++j)if ( !used[j] ) ok = false;

            if ( ok ){
                return 2LL * myPow( 2LL, min(_r, _c));
            }
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

	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) {
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
			int answers[]             = {0, 1, 2, 3, 4};
			long long expected__      = 2;

			clock_t start__           = clock();
			long long received__      = Zoo().theCount(vector <int>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int answers[]             = {5, 8};
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = Zoo().theCount(vector <int>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int answers[]             = {0, 0, 0, 0, 0, 0};
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = Zoo().theCount(vector <int>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int answers[]             = {1, 0, 2, 0, 1};
			long long expected__      = 8;

			clock_t start__           = clock();
			long long received__      = Zoo().theCount(vector <int>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int answers[]             = {1, 0, 1};
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = Zoo().theCount(vector <int>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int answers[]             = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = Zoo().theCount(vector <int>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int answers[]             = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = Zoo().theCount(vector <int>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int answers[]             = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = Zoo().theCount(vector <int>(answers, answers + (sizeof answers / sizeof answers[0])));
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
