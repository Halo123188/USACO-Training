/*
ID: edward.26
TASK: dualpal
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

int n, m;
string convert(int x, int base){
    string s = "";
    vector<int> y;
    while(x >= base){
        y.push_back(x % base);
        x/=base;
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

bool test(string s){
    bool f = true;
    for(int j = 0;j<s.size()/2;j++){
        if(s[j] != s[s.size()-1-j]){
                f = false;
        }
    }
    return f;
}
int main(int argc, const char * argv[]) {
    
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");
    fin>>n>>m;
    
    while(n > 0){
        m++;
        int t = 0;
        for(int i = 2;i<=10;i++){
            string a = convert(m , i);
            if(test(a)){
                t++;
            }
        }
        if(t >= 2){
            fout<<m<<endl;
            n--;
        }
        
    }
//    for(int i = 1;i<=300;i++){
//        int temp = i*i;
//        string ans;
//        ans = convert(temp);
//        bool f = true;
//        for(int j = 0;j<ans.size()/2;j++){
//            if(ans[j] != ans[ans.size()-1-j]){
//                f = false;
//            }
//        }
//        if(f == true){
//            fout<<convert(i)<<" "<<ans<<endl;
//        }
//    }
    
    return 0;
}
