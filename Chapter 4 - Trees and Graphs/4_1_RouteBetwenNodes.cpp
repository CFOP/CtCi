#include <bits/stdc++.h>

struct Node{
    int visited;
    int data;
    std::forward_list <Node*> v;

    Node(int data):data(data){}
};

struct Graph{
    std::vector <Node*> node;

    Graph(int size){
        node.resize(size);
        for(int i=0; i<size; i++){
            node[i] = new Node(i);
        }
    }

    void addEdge(int from, int to);
    void resetVisited();
};

void Graph::addEdge(int from, int to){
    if(from<0 || from>=node.size() || to<0 || to>=node.size())
        return;
    node[from]->v.push_front(node[to]);
}

void Graph::resetVisited(){
    for(Node *p : node)
        p->visited=false;
}

bool isARoute(Node *a, Node *b){

    if(!a || !b)
        return false;
    if(a==b)
        return true;

    if(a->visited)
        return false;
    a->visited = true;

    for(Node *&p : a->v){
        if(isARoute(p, b))
            return true;
    }

    return false;
}

int main(){

    Graph g(10);
    g.addEdge(0, 1);
    g.addEdge(0, 9);
    g.addEdge(1, 3);
    g.addEdge(2, 1);
    g.addEdge(3, 4);
    g.addEdge(4, 1);
    g.addEdge(5, 2);
    g.addEdge(5, 3);
    g.addEdge(6, 7);
    g.addEdge(7, 8);
    g.addEdge(8, 6);

    g.resetVisited();
    std::cout<<isARoute(g.node[0], g.node[4])<<"\n";

    g.resetVisited();
    std::cout<<isARoute(g.node[9], g.node[4])<<"\n";

    g.resetVisited();
    std::cout<<isARoute(g.node[6], g.node[8])<<"\n";

    g.resetVisited();
    std::cout<<isARoute(g.node[5], g.node[4])<<"\n";

    g.resetVisited();
    std::cout<<isARoute(g.node[0], g.node[8])<<"\n";

    return 0;
}
