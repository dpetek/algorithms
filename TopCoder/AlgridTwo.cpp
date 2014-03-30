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
#define MOD 1000000007LL
using namespace std;

class AlgridTwo {
public:
   pair<int, char> numWays ( string s1, char start, char end){
        if ( s1 == "WW"){
            if ( start == 'Z' && end == 'B') return make_pair(1,'Z');
            if ( start == 'Z' && end == 'W') return make_pair(1,'Z');
            if ( start == 'W' && end == 'B') return make_pair(0,'Z');
            if ( start == 'W' && end == 'W') return make_pair(2,'Z');
            if ( start == 'B' && end == 'W') return make_pair(0,'Z');
            if ( start == 'B' && end == 'B') return make_pair(2,'Z');
        }
        if ( s1 == "BW"){
            if ( start == 'Z' && end == 'B') return make_pair(2,'B');
            if ( start == 'Z' && end == 'W') return make_pair(0,'Z');
            if ( start == 'W' && end == 'B') return make_pair(2,'B');
            if ( start == 'W' && end == 'W') return make_pair(0,'Z');
            if ( start == 'B' && end == 'W') return make_pair(0,'Z');
            if ( start == 'B' && end == 'B') return make_pair(2,'B');
        }
        if ( s1 == "WB"){
            if ( start == 'Z' && end == 'B') return make_pair(0,'Z');
            if ( start == 'Z' && end == 'W') return make_pair(2,'W');
            if ( start == 'W' && end == 'B') return make_pair(0,'Z');
            if ( start == 'W' && end == 'W') return make_pair(2,'W');
            if ( start == 'B' && end == 'W') return make_pair(2,'W');
            if ( start == 'B' && end == 'B') return make_pair(0,'Z');
        }
        if ( s1 == "BB"){
            if ( start == 'Z' && end == 'B') return make_pair(1,'Z');
            if ( start == 'Z' && end == 'W') return make_pair(1,'Z');
            if ( start == 'W' && end == 'B') return make_pair(1,'W');
            if ( start == 'W' && end == 'W') return make_pair(1,'W');
            if ( start == 'B' && end == 'W') return make_pair(1,'B');
            if ( start == 'B' && end == 'B') return make_pair(1,'B');
        }
        return make_pair(1, 'Z');
   }

   int makeProgram( vector <string> output ) {
        long long ret = 1LL;
        char carry = 'Z';
        for (int i=0;i+1<output.size();++i){
            for (int j=0;j+1<output[0].size();++j){
                if ( j + 2 == output[0].size()){
                    string s1, s2;
                    s1.pb ( output[i][j]);s1.pb(output[i][j+1]);
                    s2.pb ( carry);s2.pb(output[i+1][j+1]);
                    if ( s1 == "BW" && s2[1] == 'W') ret = 0;
                    if ( s1 == "WB" && s2[1] == 'B' ) ret = 0;
                }else{
                    string s1;
                    s1.pb ( output[i][j]);s1.pb(output[i][j+1]);
                    pair<int, char> tmp = numWays(s1, carry, output[i+1][j]);
                    ret*=(long long)tmp.fs;ret%=MOD;
                    carry= tmp.sc;
                }

            }
        }
        return ret;
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
			string output[]           = {"BB",
 "WB"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = AlgridTwo().makeProgram(vector <string>(output, output + (sizeof output / sizeof output[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string output[]           = {"BBWBBB",
 "WBWBBW"};
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = AlgridTwo().makeProgram(vector <string>(output, output + (sizeof output / sizeof output[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string output[]           = {"BWBWBW",
 "WWWWWW",
 "WBBWBW"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = AlgridTwo().makeProgram(vector <string>(output, output + (sizeof output / sizeof output[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string output[]           = {"WWBWBWBWBWBWBWBW",
 "BWBWBWBWBWBWBWBB",
 "BWBWBWBWBWBWBWBW"};
			int expected__            = 73741817;

			clock_t start__           = clock();
			int received__            = AlgridTwo().makeProgram(vector <string>(output, output + (sizeof output / sizeof output[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

      case 4: {
			string output[]           = {"WWW", "BWB"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = AlgridTwo().makeProgram(vector <string>(output, output + (sizeof output / sizeof output[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
      case 5: {
			string output[]           ={"BBB", "BWB"} ;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = AlgridTwo().makeProgram(vector <string>(output, output + (sizeof output / sizeof output[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
/*      case 6: {
			string output[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = AlgridTwo().makeProgram(vector <string>(output, output + (sizeof output / sizeof output[0])));
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
