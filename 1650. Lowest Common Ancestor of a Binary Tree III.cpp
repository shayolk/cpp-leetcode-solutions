/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node* pp = p;
        Node* qq = q;
        
        while (pp != qq) {
            pp = (pp == nullptr) ? q : pp->parent;
            qq = (qq == nullptr) ? p : qq->parent;
        }
        
        return pp;
    }
};
