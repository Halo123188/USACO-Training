/*
ID: edward.26
TASK: castle
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
#include <cstdio>
using namespace std;

int m, n, numOfCom = 0;
int a[55][55], com[55][55], siz[4000];
queue<pair<int,int>> b;

void cal(){
    while(b.size() != 0){
        int x = b.front().first;
        int y = b.front().second;
        b.pop();
        
        if(com[x][y] != 0){
            continue;
        }
        com[x][y] = numOfCom;
        siz[numOfCom]++;
        if(a[x][y] == 1 || a[x][y] == 3 || a[x][y] == 5 || a[x][y] == 9 || a[x][y] == 7 || a[x][y] == 11 || a[x][y] == 13 || a[x][y] == 15){
            if(y > 1 && com[x][y-1] == 0){
                b.push({x, y-1});
            }
        }
        if(a[x][y] == 2 || a[x][y] == 3 || a[x][y] == 6 || a[x][y] == 10 || a[x][y] == 7 || a[x][y] == 11 || a[x][y] == 14 || a[x][y] == 15){
            if(x > 1 && com[x-1][y] == 0){
                b.push({x-1, y});
            }
        }
        
        if(a[x][y] == 4 || a[x][y] == 5 || a[x][y] == 6 || a[x][y] == 12 || a[x][y] == 7 || a[x][y] == 13 || a[x][y] == 14 || a[x][y] == 15){
            if(y < m && com[x][y+1] == 0){
                b.push({x, y+1});
            }
        }
        
        if(a[x][y] == 8 || a[x][y] == 9 || a[x][y] == 10 || a[x][y] == 12 || a[x][y] == 11 || a[x][y] == 13 || a[x][y] == 14 || a[x][y] == 15){
            if(x < n && com[x+1][y] == 0){
                b.push({x+1, y});
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    
    ofstream fout ("castle.out");
    ifstream fin ("castle.in");
    
    fin>>m>>n;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            fin>>a[i][j];
            a[i][j] = 15-a[i][j];
        }
    }
    
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(com[i][j] == 0){
                numOfCom++;
                b.push({i, j});
                cal();
            }
        }
    }
    
    fout<<numOfCom<<endl;
    int ans = 0;
    for(int i = 1;i<=numOfCom;i++){
        //cout<<"TEST "<<siz[i]<<endl;
        ans = max(ans, siz[i]);
    }
    fout<<ans<<endl;
    
    ans = 0;
    int ansx = 55, ansy = 0;
    char anso;
    for(int i = n;i>=1;i--){
        for(int j = 1;j<=m;j++){
            int temp = 15 - a[i][j];
            if(temp == 2 || temp == 3 || temp == 6 || temp == 10 || temp == 7 || temp == 11 || temp == 14 || temp == 15){
                if(i > 2){
                    if(com[i][j] != com[i-1][j]){
                        int sum = siz[com[i][j]] + siz[com[i-1][j]];
                        if(sum > ans){
                            ans = sum;
                            ansx = i;
                            ansy = j;
                            anso = 'N';
                        }
                        else if(sum == ans){
                            if(j < ansy){
                                ansy = j;
                                ansx = i;
                                anso = 'N';
                            }
                            else if(j == ansy && i > ansx){
                                ansx = i;
                                anso = 'N';
                            }
                        }
                    }
                    
                    
                }
            }
            
            if(temp == 4 || temp == 5 || temp == 6 || temp == 12 || temp == 7 || temp == 13 || temp == 14 || temp == 15){
                if(j < m){
                    if(com[i][j] != com[i][j+1]){
                        int sum = siz[com[i][j]] + siz[com[i][j+1]];
                        if(sum > ans){
                            ans = sum;
                            ansx = i;
                            ansy = j;
                            anso = 'E';
                        }
                        else if(sum == ans){
                            if(j < ansy){
                                ansy = j;
                                ansx = i;
                                anso = 'E';
                            }
                            else if(j == ansy && i > ansx){
                                ansx = i;
                                anso = 'E';
                            }
                        }
                    }
                }
            }
        }
    }
    
    fout<<ans<<endl;
    fout<<ansx<<" "<<ansy<<" "<<anso<<endl;
    return 0;
}
