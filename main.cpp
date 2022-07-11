#include <bits/stdc++.h>

class Node {
private:
    int info;
    Node* prev;
    Node* next;
    friend class DLL;
public:
    Node();
    explicit Node(int);
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

Node::~Node() = default;

class DLL {
private:
    Node* header;
    Node* trailer;

public:
    DLL();
    ~DLL();
    DLL(const DLL &src);
    void remove();
    Node* get_end() const;
    Node *get_ptr(int index) const;
    bool pushidx(int index, int val) const;
    bool removeidx(int index) const;
    int get(int index, int error) const;
    bool set(int index, int val);
    void push1(int val, DLL &rhs);
    void push2(int val);
    DLL operator+(const DLL& rhs);
    friend std::istream operator >>(std::istream &input, DLL &a);
    friend std::ostream operator <<(std::ostream &output, const DLL &a);
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

DLL::DLL(const DLL &src): header(NULL), trailer(NULL) {
    *this = src;
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
        p = p->get_next();
        index--;
    }
    return p;
}

bool DLL::pushidx(int index, int val) const {
    Node *p = get_ptr(index);
    if (p == nullptr)
        return true;
     else {
        Node *n = new Node(val, p, p->get_next());
        p->set_next(n);
        (p->get_next())->set_prev(n);
        return false;
    }
}

bool DLL::removeidx(int index) const {
    Node *x = get_ptr(index);
    if (x == nullptr)
        return true;
     else {
        Node *n = x->get_next();
        Node *p = x->get_prev();
        if (p != nullptr)
            p->set_next(n);
        if (n != nullptr)
            n->set_prev(p);
        delete x;
        return false;
    }
}

int DLL::get(int index, int error = 0) const {
    Node *p = get_ptr(index);
    if (p == nullptr)
        return error;
     else
        return p->get_val();
}

bool DLL::set(int index, int val) {
    Node *p = get_ptr(index);
    if (p == nullptr)
        return true;
     else {
        p->set_val(val);
        return false;
    }
}
void DLL::push1(int val, DLL &rhs) {
    Node *n = new Node(val);
    n->prev = rhs.trailer;
    if(!rhs.header)
        rhs.header = n;
    if(rhs.trailer)
        rhs.trailer->next = n;
    rhs.trailer = n;
}

void DLL::push2(int val) {
    Node *n = new Node(val);
    n->prev = trailer;
    if(!header)
        header = n;
    if(trailer)
        trailer->next = n;
    trailer = n;
}

DLL DLL::operator+(const DLL &rhs) {
    DLL temp;
    Node *n = temp.header;
    while(n) {
        temp.push1(n->info, temp);
        n = n->next;
    }
    n = rhs.header;
    while(n) {
        temp.push2(n->info);
        n = n->next;
    }
    return temp;
}

std::istream operator >>(std::istream &input, DLL &a) {

}

std::ostream  operator <<(std::ostream &output, const DLL &a) {

}
int main() {

    return 0;
}
