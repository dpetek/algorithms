#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <cstdlib>

using namespace std;

int main (void ){

    for (int i=1;i<=10;++i){
        char command[100];
        sprintf (command, "java -jar ImageScannerVis.jar -novis -exec \"./ImageScanner2\" -seed %d", i);
        system(command);
    }

    return 0;
}
