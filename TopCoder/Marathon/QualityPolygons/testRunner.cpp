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
            printf ("[SEED %d]\n", i);
            sprintf (command, "java -jar Tester.jar -novis -exec \"./QualityPolygons\" -seed %d -novis | grep Score", i);
            system(command);
        }

    return 0;
}
