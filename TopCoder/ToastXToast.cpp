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

class ToastXToast {
public:
   int bake( vector <int> under, vector <int> over ) {
        sort (under.begin(), under.end());
        sort (over.begin(), over.end());
        vector<int> u, o;
        set<vector<int> > S;

        for (int i=0;i<under.size();++i){
            vector<int>tmp;
            for (int j=0;j<over.size();++j){
                if ( under[i] < over[j]) tmp.pb (over[j]);
            }
            if ( !tmp.size()) return -1;
            if ( S.find(tmp) == S.end()){
                u.pb (under[i]);
                S.insert(tmp);
            }
        }
        S.clear();
        for (int i=0;i<over.size();++i){
            vector<int>tmp;
            for (int j=0;j<under.size();++j){
                if ( under[i] < over[j]) tmp.pb (over[j]);
            }
            if ( !tmp.size()) return -1;
            if ( S.find(tmp) == S.end()){
                o.pb (over[i]);
                S.insert(tmp);
            }
        }
        return min(o.size(), u.size());
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
			int undertoasted[]        = {2,4};
			int overtoasted[]         = {5,6,3};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = ToastXToast().bake(vector <int>(undertoasted, undertoasted + (sizeof undertoasted / sizeof undertoasted[0])), vector <int>(overtoasted, overtoasted + (sizeof overtoasted / sizeof overtoasted[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int undertoasted[]        = {5};
			int overtoasted[]         = {4};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = ToastXToast().bake(vector <int>(undertoasted, undertoasted + (sizeof undertoasted / sizeof undertoasted[0])), vector <int>(overtoasted, overtoasted + (sizeof overtoasted / sizeof overtoasted[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int undertoasted[]        = {1,2,3};
			int overtoasted[]         = {5,6,7};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = ToastXToast().bake(vector <int>(undertoasted, undertoasted + (sizeof undertoasted / sizeof undertoasted[0])), vector <int>(overtoasted, overtoasted + (sizeof overtoasted / sizeof overtoasted[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int undertoasted[]        = {1,3,5};
			int overtoasted[]         = {2,4,6};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = ToastXToast().bake(vector <int>(undertoasted, undertoasted + (sizeof undertoasted / sizeof undertoasted[0])), vector <int>(overtoasted, overtoasted + (sizeof overtoasted / sizeof overtoasted[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int undertoasted[]        = ;
			int overtoasted[]         = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ToastXToast().bake(vector <int>(undertoasted, undertoasted + (sizeof undertoasted / sizeof undertoasted[0])), vector <int>(overtoasted, overtoasted + (sizeof overtoasted / sizeof overtoasted[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int undertoasted[]        = ;
			int overtoasted[]         = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ToastXToast().bake(vector <int>(undertoasted, undertoasted + (sizeof undertoasted / sizeof undertoasted[0])), vector <int>(overtoasted, overtoasted + (sizeof overtoasted / sizeof overtoasted[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int undertoasted[]        = ;
			int overtoasted[]         = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ToastXToast().bake(vector <int>(undertoasted, undertoasted + (sizeof undertoasted / sizeof undertoasted[0])), vector <int>(overtoasted, overtoasted + (sizeof overtoasted / sizeof overtoasted[0])));
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
