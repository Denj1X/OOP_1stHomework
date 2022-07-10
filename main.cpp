#include <bits/stdc++.h>

class Node {
private:
    int info;
    Node* prev;
    Node* next;
    friend class DLL;
public:
    Node();
    Node(int);
    Node(int, Node*, Node*);

    virtual ~Node();

    void set_val(int val);
    int get_val() const;

    void set_next(Node *);
    Node *get_next() const;

    void set_prev(Node *);
    Node *get_prev() const;
};

Node::Node() {
    info = 0;
    prev = NULL;
    next = NULL;
}

Node::Node(int elem) {
    info = elem;
    prev = NULL;
    next = NULL;
}

Node::Node(int elem, Node* _prev, Node* _next):
info(elem), prev(_prev), next(_next) {}

void Node::set_val(int val) {
    this->info = val;
}

int Node::get_val() const {
    return info;
}

void Node::set_prev(Node *pre) {
    this->prev = pre;
}

Node* Node::get_prev() const {
    return prev;
}

void Node::set_next(Node *nex) {
    this->next = nex;
}

Node* Node::get_next() const{
    return next;
}

Node::~Node() {

}

class DLL {
private:
    Node* header;
    Node* trailer;
public:
    DLL();
    ~DLL();
    void remove();
    Node* get_end() const;
    Node *get_ptr(int index) const;
    bool pushidx(int index, int val);
    bool removeidx(int index);
    int get(int index, int error) const;
    bool set(int index, int val);
};

void DLL::remove() {
    Node* xd = trailer->prev->prev;
    delete trailer->prev;
    trailer->prev = xd;
    xd->next = trailer;
}

DLL::DLL() {
    header = new Node;
    trailer = new Node;
    header->next = trailer;
    trailer->prev = header;
    header->prev = NULL;
    trailer->next = NULL;
}

DLL::~DLL() {
    while (header -> next != trailer){
        remove();
    }
    delete header;
    delete trailer;
}

Node* DLL::get_end() const {
    if (header == nullptr)
        return nullptr;
     else {
        Node *p = header;
        while (p->get_next() != nullptr)
            p = p->get_next();
        return p;
    }
}

Node* DLL::get_ptr(int index) const {
    Node *p = header;
    while ((index > 0) && (p != nullptr)) {
        if (p == nullptr)
            break;
        else
            p = p->get_next();
        index--;
    }
    return p;
}

int main() {

    return 0;
}
