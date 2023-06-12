#include<bits/stdc++.h>
using namespace std;

Node* merge(Node* p, Node* q) {
    Node* merged = new Node(0); // Dummy node
    Node* tail = merged;

    while (p && q) {
        if (p->data < q->data) {
            tail->bottom = p;
            p = p->bottom;
        } else {
            tail->bottom = q;
            q = q->bottom;
        }
        tail = tail->bottom;
    }

    if (p) {
        tail->bottom = p;
    } else {
        tail->bottom = q;
    }

    return merged->bottom;
}

Node* flatten(Node* root) {
    if (!root || !root->next) {
        return root;
    }

    root->next = flatten(root->next);

    return merge(root, root->next);
}
