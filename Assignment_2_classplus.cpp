#include<bits/stdc++.h>
using namespace std;
bool visited[100005];
vector<int> a[100005];
unordered_map<int, int> map_ans;
void dfs(int s, int &x, int count){
    visited[s] = 1;
    map_ans[s]++;
    int i, j, k = a[s].size();
    count++;
    for(int i = 0; i < k; i++){
        j = a[s][i];
        if(!visited[j] && count <= x){
            dfs(j, x, count);
        }
    }
}
int main(){
    int n, h, x;
    cin>>n;
    cin>>h;
    cin>>x;
    //Input h integers below
    vector<int> hotspots(h);
    for(int i = 0; i < h; i++){
        cin>>hotspots[i];
    }
    //Input n-1 lines denoting roads between city u and v
    vector<vector<int>> roads(n-1, vector<int>(2));
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < 2; j++){
            cin>>roads[i][j];
        }
    }
    //Logic starts here
    for(int i = 0; i <= n; i++){ 
        a[i].clear(); 
        visited[i] = 0; 
    }
    for(int i = 0; i < n-1; i++){
        a[roads[i][0]].push_back(roads[i][1]);
        a[roads[i][1]].push_back(roads[i][0]);
    }

    map_ans.clear();
    for(int i = 0; i < h; i++){
        memset(visited, 0, sizeof(visited));
        dfs(hotspots[i], x, 0);
    }
    int solution = 0;
    for(auto itr = map_ans.begin(); itr != map_ans.end(); itr++){
        if(itr->second == h){
            solution++;
        }
    }
    cout<<solution;
    return 0;
}