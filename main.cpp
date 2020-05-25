#include<bits/stdc++.h>

using namespace std;

long long ans=0;

typedef struct MyStruct{
    int root;
    int rnk;
}mystruct;
mystruct arr[100005];

typedef struct Node{
    int u;
    int v;
    long long weight;

    bool operator<(const struct Node &other)
    {
        return weight < other.weight;
    }
}node;
vector<node> a;

mystruct find(int ver){
    if(arr[ver].root==ver){
        return arr[ver];
    }
    else{
        arr[ver]=find(arr[ver].root);
        return arr[ver];
    }
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){

        a.clear();

        int n, m;
        long long x;
        mystruct ru, rv;
        node temp;
        scanf("%d %d", &n, &m);
        for(int i=1;i<=n;i++){
            arr[i].rnk=1;
            arr[i].root=i;
        }
        while(m--){
            scanf("%d %d %lld", &temp.u, &temp.v, &temp.weight);
            temp.weight=log2(temp.weight);
            a.push_back(temp);
        }

        sort(a.begin(), a.end());
        ans=0;

        for(int i=0;i<a.size();i++){
            ru=find(a[i].u);
            rv=find(a[i].v);
            if(ru.root==rv.root){
                continue;
            }
            else{
                if(ru.rnk > rv.rnk){
                    arr[rv.root].root=ru.root;
                }
                else if(ru.rnk < rv.rnk){
                    arr[ru.root].root=rv.root;
                }
                else{
                    arr[rv.root].root=ru.root;
                    arr[rv.root].rnk++;
                }
                ans+=a[i].weight;
            }
        }
        printf("%lld\n", ans+1);
    }
    return 0;
}
