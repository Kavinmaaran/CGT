#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

#define edge pair<int, int>
fstream mst;
fstream mg;

class Graph {
   private:
    vector<pair<int, edge> > MG;
    vector<pair<int, edge> > MST;  
    int *parent;
    int vertex;
   public:
    Graph(int vertex) {
  parent = new int[vertex];

  for (int i = 0; i < vertex; i++)
    parent[i] = i;

  MG.clear();
  MST.clear();
  }
    void AddWeightedEdge(int u, int v, int w){
  MG.push_back(make_pair(w, edge(u, v)));
}
    int findParent(int i){
  if (i == parent[i])
    return i;
  else
    return findParent(parent[i]);
}
    void setParent(int u, int v){
  parent[u] = parent[v];
}
    void kruskal() {
  int i, uRep, vRep;
  sort(MG.begin(), MG.end());
  for (i = 0; i < MG.size(); i++) {
    uRep = findParent(MG[i].second.first);
    vRep = findParent(MG[i].second.second);
    if (uRep != vRep) {
      MST.push_back(MG[i]);
      setParent(uRep, vRep);
    }
  }
}
    void printGraph(){
  for (int i = 0; i < MST.size(); i++) {
    mst << MST[i].second.first << "-" << MST[i].second.second << "-"
       << MST[i].first;
    mst << endl;
  }
}
};
int main() {
  mst.open("txt/mst", ios::out);
  mg.open("txt/mg", ios::out);
  int node;
  int ed;
  cout << "Enter number of nodes: ";
  cin >> node;
  cout<< "Enter number of edges: ";
  cin >> ed;
  Graph g(node);
  cout << "Enter as <vertex_1><vertex_2><weight>"<<endl;
  for (int i=0;i<ed;i++){
    cout << "Edge " << i+1 << " : ";
    int v1,v2,w;
    cin >> v1;
    cin >> v2;
    cin >> w;
    mg <<v1<<"-"<<v2<<"-"<<w;
    mg <<endl;
    g.AddWeightedEdge(v1, v2, w);
  }
  g.kruskal();
  g.printGraph();
  system("python3 net.py");
  return 0;
}