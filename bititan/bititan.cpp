#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

struct Node {
    list<Node*> Children;
    Node *Right;
};

Node* createGraph() {
    Node *pNode = new Node[7];
    //root    
    // add 2nd layer
    pNode[0].Children.push_back(&pNode[1]);
    pNode[0].Children.push_back(&pNode[2]);
    pNode[0].Children.push_back(&pNode[3]);
    // 3rd layer
    pNode[1].Children.push_back(&pNode[4]);
    pNode[1].Children.push_back(&pNode[5]);
    pNode[3].Children.push_back(&pNode[6]);
    return &pNode[0];
}

void bfsGraph(Node *root) {
    list<Node*> l_list;
    list<Node*> l_childlist;
    l_list.push_back(root);

    while (!l_list.empty()) {        
        while (!l_list.empty()) {
            Node* pNode = l_list.front();
            l_list.pop_front();
            for (auto &child : pNode->Children) {
                l_childlist.push_back(child);
            }
        }
        Node *sibl = nullptr;
        for_each(l_childlist.rbegin(), l_childlist.rend(), [&sibl](list<Node*>::value_type v){v->Right = sibl; sibl = v; });
        l_list.splice(l_list.begin(), l_childlist);
    }
}

void printGraph(Node *root) {
    list<Node*> l_list;
    list<Node*> l_childlist;
    l_list.push_back(root);
    cout << (long)root << std::endl;
    while (!l_list.empty()) {
        while (!l_list.empty()) {
            Node* pNode = l_list.front();
            l_list.pop_front();
            for (auto &child : pNode->Children) {
                l_childlist.push_back(child);
            }
        }
        Node *sibl = nullptr;
        for_each(l_childlist.rbegin(), l_childlist.rend(), [&sibl](list<Node*>::value_type v){v->Right = sibl; sibl = v; });
        for_each(l_childlist.begin(), l_childlist.end(), [](list<Node*>::value_type v){ cout << (long)v << "[" << (long)v->Right << "]" << " "; });
        cout << std::endl;
        l_list.splice(l_list.begin(), l_childlist);
    }

}

void bititan() {
    Node* root = createGraph();
    bfsGraph(root);
    printGraph(root);
}