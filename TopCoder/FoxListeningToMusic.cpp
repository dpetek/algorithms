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

int cnt[1600002][51];
set<int> dp[51];

class FoxListeningToMusic {
public:
   vector <double> getProbabilities( vector <int> length, int T ) {

        for (int i=0;i<length.size();++i){
            for (int j=length[i];j<=2*T;++j){

            }
        }

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

	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ(double expected, double result) { if (isnan(expected)) { return isnan(result); } else if (isinf(expected)) { if (expected > 0) { return result > 0 && isinf(result); } else { return result < 0 && isinf(result); } } else if (isnan(result) || isinf(result)) { return false; } else if (fabs(result - expected) < MAX_DOUBLE_ERROR) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error(double expected, double result) { if (isnan(expected) || isinf(expected) || isnan(result) || isinf(result) || expected == 0) return 0; return fabs(result-expected) / fabs(expected); }
	static bool topcoder_fequ(const vector<double> &a, const vector<double> &b) { if (a.size() != b.size()) return false; for (size_t i=0; i<a.size(); ++i) if (!topcoder_fequ(a[i], b[i])) return false; return true; }
	double moj_relative_error(const vector<double> &expected, const vector<double> &result) { double ret = 0.0; for (size_t i=0; i<expected.size(); ++i) { ret = max(ret, moj_relative_error(expected[i], result[i])); } return ret; }

	template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <double> &expected, const vector <double> &received, clock_t elapsed) {
		cerr << "Example " << casenum << "... ";

		string verdict;
		vector<string> info;
		char buf[100];

		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}

		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received);
			if (rerr > 0) {
				sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			int length[]              = {1, 2};
			int T                     = 1;
			double expected__[]       = {0.25, 0.75 };

			clock_t start__           = clock();
			vector <double> received__ = FoxListeningToMusic().getProbabilities(vector <int>(length, length + (sizeof length / sizeof length[0])), T);
			return verify_case(casenum, vector <double>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int length[]              = {1, 10, 100, 1000, 10000};
			int T                     = 0;
			double expected__[]       = {0.2, 0.2, 0.2, 0.2, 0.2 };

			clock_t start__           = clock();
			vector <double> received__ = FoxListeningToMusic().getProbabilities(vector <int>(length, length + (sizeof length / sizeof length[0])), T);
			return verify_case(casenum, vector <double>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int length[]              = {5, 8, 4, 7};
			int T                     = 10;
			double expected__[]       = {0.1875, 0.3125, 0.1875, 0.3125 };

			clock_t start__           = clock();
			vector <double> received__ = FoxListeningToMusic().getProbabilities(vector <int>(length, length + (sizeof length / sizeof length[0])), T);
			return verify_case(casenum, vector <double>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int length[]              = {10, 1};
			int T                     = 9;
			double expected__[]       = {0.9990234375, 9.765625E-4 };

			clock_t start__           = clock();
			vector <double> received__ = FoxListeningToMusic().getProbabilities(vector <int>(length, length + (sizeof length / sizeof length[0])), T);
			return verify_case(casenum, vector <double>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int length[]              = {58, 47, 36, 25, 14, 3};
			int T                     = 100;
			double expected__[]       = {0.32895835374381194, 0.26291497538241776, 0.18463894970453887, 0.1312301113062895, 0.07518634032025856, 0.017071269542683242 };

			clock_t start__           = clock();
			vector <double> received__ = FoxListeningToMusic().getProbabilities(vector <int>(length, length + (sizeof length / sizeof length[0])), T);
			return verify_case(casenum, vector <double>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int length[]              = ;
			int T                     = ;
			double expected__[]       = ;

			clock_t start__           = clock();
			vector <double> received__ = FoxListeningToMusic().getProbabilities(vector <int>(length, length + (sizeof length / sizeof length[0])), T);
			return verify_case(casenum, vector <double>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int length[]              = ;
			int T                     = ;
			double expected__[]       = ;

			clock_t start__           = clock();
			vector <double> received__ = FoxListeningToMusic().getProbabilities(vector <int>(length, length + (sizeof length / sizeof length[0])), T);
			return verify_case(casenum, vector <double>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			int length[]              = ;
			int T                     = ;
			double expected__[]       = ;

			clock_t start__           = clock();
			vector <double> received__ = FoxListeningToMusic().getProbabilities(vector <int>(length, length + (sizeof length / sizeof length[0])), T);
			return verify_case(casenum, vector <double>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
