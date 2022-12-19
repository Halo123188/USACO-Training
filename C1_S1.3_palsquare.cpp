/*
ID: edward.26
TASK: palsquare
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

int n;
string convert(int x){
    string s = "";
    vector<int> y;
    while(x >= n){
        y.push_back(x % n);
        x/=n;
    }
    y.push_back(x);
    
    for(int i = y.size()-1;i>=0;i--){
        if(y[i] < 10){
            s += to_string(y[i]);
        }
        else{
            s += (char)(y[i]+55);
        }
    }
    return s;
    
}
int main(int argc, const char * argv[]) {
    
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");
    fin>>n;
    for(int i = 1;i<=300;i++){
        int temp = i*i;
        string ans;
        ans = convert(temp);
        bool f = true;
        for(int j = 0;j<ans.size()/2;j++){
            if(ans[j] != ans[ans.size()-1-j]){
                f = false;
            }
        }
        if(f == true){
            fout<<convert(i)<<" "<<ans<<endl;
        }
    }
    
    return 0;
}
