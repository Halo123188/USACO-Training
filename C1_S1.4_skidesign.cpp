/*
ID: edward.26
TASK: skidesign
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

int n, h[1010];
int minh = 105, maxh = 0;
int main(int argc, const char * argv[]) {
    
    ofstream fout ("skidesign.out");
    ifstream fin ("skidesign.in");
    
    fin>>n;
    for(int i = 1;i<=n;i++){
        fin>>h[i];
        minh = min(minh, h[i]);
        maxh = max(maxh, h[i]);
    }
    
    int ans = 1e9;
    for(int i = minh; i<= maxh;i++){
        int temp = 0;
        for(int j = 1;j<=n;j++){
            if(h[j] < i){
                temp += (i - h[j]) * (i - h[j]);
            }
            
            if(h[j] > i + 17){
                temp += (h[j] - i - 17) * (h[j] - i - 17);
            }
        }
        ans = min(ans, temp);
    }
    
    fout<<ans<<endl;
    
    
    return 0;
}
