struct edge{
int u,v;
long weight;
bool operator<(const edge& other) const{
return weight < other.weight;
}
};
int find_set(int v, vector<int> &parent){
// cout << v<< " " << parent[v] << endl;
if(v==parent[v]){
return v;
}
return parent[v] = find_set(parent[v],parent);
}
void union_sets(int a,int b,vector<int>& parent, vector<int>& rank){
a = find_set(a,parent);
b = find_set(b,parent);
if(a!=b){
if(rank[a]<rank[b]){
swap(a,b);
}
parent[b]=a;
if(rank[a]==rank[b]){
rank[a]++;
}
}
}
long getMinMaxLatency(int g_nodes, vector<int> g_from, vector<int> g_to,
vector<int> g_weight, int k) {
vector<edge> edges;
map<int,int> node_map;
int next_index = 0;
for(int i=0;i<g_from.size();i++){
if(node_map.find(g_from[i])==node_map.end()){
node_map[g_from[i]] = next_index++;
}
if(node_map.find(g_to[i])==node_map.end()){
node_map[g_to[i]] = next_index++;
}
edges.push_back({node_map[g_from[i]],node_map[g_to[i]],g_weight[i]});
}
vector<int> parent (next_index), rank(next_index,0);
for(int i=0;i<next_index;i++){
parent[i] = i;
}
sort(edges.rbegin(),edges.rend());
int components = next_index;
long maxweight = 0;
for(edge e: edges){
if(find_set(e.u,parent)!=find_set(e.v,parent)){
if(components<=k) break;
union_sets(e.u,e.v,parent,rank);
components--;
maxweight = e.weight;
}
}
return maxweight;
}