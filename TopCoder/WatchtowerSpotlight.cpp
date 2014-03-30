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

class WatchtowerSpotlight {
public:
   int quickestEscape( string start, string end, string watchtower ) {

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
			string start              = "0 0";
			string end                = "10 10";
			string watchtower         = "7 3 10 5";
			int expected__            = 20;

			clock_t start__           = clock();
			int received__            = WatchtowerSpotlight().quickestEscape(start, end, watchtower);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string start              = "0 0";
			string end                = "10 10";
			string watchtower         = "3 7 9 4";
			int expected__            = 20;

			clock_t start__           = clock();
			int received__            = WatchtowerSpotlight().quickestEscape(start, end, watchtower);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string start              = "0 0";
			string end                = "10 10";
			string watchtower         = "9 9 3 5";
			int expected__            = 32;

			clock_t start__           = clock();
			int received__            = WatchtowerSpotlight().quickestEscape(start, end, watchtower);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string start              = "0 0";
			string end                = "49 49";
			string watchtower         = "24 24 5 40";
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = WatchtowerSpotlight().quickestEscape(start, end, watchtower);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string start              = "0 0";
			string end                = "26 26";
			string watchtower         = "24 24 20 30";
			int expected__            = 52;

			clock_t start__           = clock();
			int received__            = WatchtowerSpotlight().quickestEscape(start, end, watchtower);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			string start              = "10 13";
			string end                = "10 11";
			string watchtower         = "5 10 70 6";
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = WatchtowerSpotlight().quickestEscape(start, end, watchtower);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 6: {
			string start              = "20 20";
			string end                = "21 20" ;
			string watchtower         = "0 0 4 50";
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = WatchtowerSpotlight().quickestEscape(start, end, watchtower);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 7: {
			string start              = "0 0";
			string end                = "0 1";
			string watchtower         = "0 1 99 10";
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = WatchtowerSpotlight().quickestEscape(start, end, watchtower);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 8: {
			string start              = ;
			string end                = ;
			string watchtower         = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WatchtowerSpotlight().quickestEscape(start, end, watchtower);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			string start              = ;
			string end                = ;
			string watchtower         = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WatchtowerSpotlight().quickestEscape(start, end, watchtower);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 10: {
			string start              = ;
			string end                = ;
			string watchtower         = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WatchtowerSpotlight().quickestEscape(start, end, watchtower);
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
