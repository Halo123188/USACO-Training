/*
ID: edward.26
TASK: milk2
LANG: C++
 */
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;
int f[1000030], s[1000030];
int ans1, ans2;

int main(int argc, const char * argv[]) {
    
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    
    int n, end = 0, st = 100000;
    fin>>n;
    for(int i = 1;i<=n;i++){
        int x,y;
        fin>>x>>y;
        f[x]++;
        f[y]--;
        end = max(end, y);
        st = min(st, x);
    }
    for(int i = st;i<=end;i++){
        s[i] += s[i-1] + f[i];
    }
    
    for(int i = st;i<end;i++){
        int temp = 0;
        while(s[i] > 0){
            temp++;
            i++;
        }
        
        ans1 = max(ans1, temp);
    }
    
    for(int i = st;i<end;i++){
        int temp = 0;
        while(s[i] == 0){
            temp++;
            i++;
        }
        
        ans2 = max(ans2, temp);
    }
    fout<<ans1<<" "<<ans2<<endl;
    
    return 0;
}
