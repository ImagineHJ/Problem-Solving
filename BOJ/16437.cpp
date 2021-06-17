#include <iostream>
#include <queue>

using namespace std;
int parent[123457]; long long number[123457];
int Answer=0;

void go(int node, int num){
    int parent_node=parent[node];

    if(parent_node==1){ //1번 섬으로 도착하면 정답에 양을 더하고 함수를 빠져나온다
        Answer+=num;
        return;
    }
    
    num+=number[parent_node]; //현재 양 수에 부모 섬에 사는 양 수를 더해준다.늑대가 살면 그만큼 빼준다.
    
    if(num<0){ //양 보다 늑대 수가 많을 때
        number[parent_node]=num; //늑대 수는 (음수로) 남는다
        return; //더 이상 살아남은 양이 없으므로 함수를 빠져나온다.
        
    }
    
    else //부모 섬에 양이 살거나 늑대 수가 양의 수보다 작거나 같은 경우
        number[parent_node]=0; //부모 섬의 양을 태웠으니 부모 섬의 양의 개수를 0으로 바꿔준다. 또는 늑대 수가 0이 된다.
    
    go(parent_node, num); //부모 노드로 간다
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //faster
    
    int n; cin>>n;
    
    queue<int> lamb;
    
    for(int i=2; i<=n; i++){
        char t; int a, p;
        
        cin>>t>>a>>p;
        
        if(t=='S'){
            lamb.push(i);
            number[i]=a;
        }
        else number[i]=-a;
        
        parent[i]=p;
    }
    
    while(!lamb.empty()){
        int node, num;
        
        if(number[lamb.front()]>0){
            node=lamb.front();
            num=number[node];
            number[node]=0; //양을 데리고 갈 거라 섬에 있는 양의 수가 0이 된다.
            go(node, num); //"node에서 num마리의 양을 데리고 부모 섬으로 간다"
        }
        lamb.pop();
    }
    
    cout<<Answer;
    
    
    return 0;
}
