#include <iostream>

using namespace std;

template<class T>
struct LinkNode {

    explicit LinkNode(LinkNode<T>* node = nullptr) { this->next = node;}
    explicit LinkNode(const T& data, LinkNode<T>* node = nullptr) {
        this->data = data;
        this->next = node;
    }

    T data;
    LinkNode<T>* next;
};

template<class T>
class LinkList{
public:
    LinkList();
    LinkList(const LinkList<T>& link_list);
    ~LinkList();

    void MakeEmpty();
    int Length() const { return this->m_length; }
    
    bool Insert(int pos, const T& data);

    bool Insert(int pos, LinkNode<T>* node_ptr);

    bool Remove(int pos, T& data);

    void Output();

private:
    LinkNode<T>* pHead;
    int m_length;
};


template<class T>
LinkList<T>::LinkList() {
    this->pHead = new LinkNode<T>();
    this->m_length = 0;
}

template<class T>
LinkList<T>::LinkList(const LinkList<T>& link_list) {
    
    this->pHead = new LinkNode<T>();
    LinkNode<T>* dest_ptr = this->pHead;

    LinkNode<T>* src_ptr = link_list.pHead;

    while(src_ptr->next != nullptr) {
        T data = src_ptr->next->data;
        dest_ptr->next = new LinkNode<T>(data);

        dest_ptr = dest_ptr->next;
        src_ptr = src_ptr->next;

        m_length++;        
    }

    dest_ptr->next = nullptr;
}

template<class T>
LinkList<T>::~LinkList() {
    this->MakeEmpty();

    delete this->pHead;
    this->pHead = nullptr;
}

template<class T>
void LinkList<T>::MakeEmpty() {
    while(this->pHead->next != nullptr)
    {
        LinkNode<T>* delete_node_ptr = this->pHead->next;
        this->pHead->next = this->pHead->next->next;

        delete delete_node_ptr;
        this->m_length--;
    }
}

template<class T>
void LinkList<T>::Output() {
    if(this->pHead->next == nullptr) {
        cout << "Empty List" << endl;
        return;
    }

    LinkNode<T>* cur = pHead->next;
    while(cur != nullptr) {
        cout << cur->data << " ";
        cur = cur->next;
    }

    cout << endl;
}

template<class T>
bool LinkList<T>::Insert(int pos, const T& data) {
    
    if(pos < 0 || pos > this->m_length) {
        return false;
    }

    LinkNode<T>* node_ptr = new LinkNode<T>(data);

    LinkNode<T>* cur = this->pHead;
    while(pos > 0) {
        cur = cur->next;
        pos--;
    }

    node_ptr->next = cur->next;
    cur->next = node_ptr;

    m_length++;

    return true;
}

template<class T>
bool LinkList<T>::Insert(int pos, LinkNode<T>* node_ptr){
    
    if(pos < 0 || pos > this->m_length) {
        return false;
    }

    if(node_ptr == nullptr)
        return false;

    LinkNode<T>* cur = pHead;
    while(pos > 0) {
        cur = cur->next;
        pos--;
    }

    node_ptr->next = cur->next;
    cur->next = node_ptr;

    m_length++;

    return true;

}

template<class T>
bool LinkList<T>::Remove(int pos, T &data) {
    
    if(this->Length() == 0 || pos < 1 || pos > this->Length()) {
        return this;
    }

    LinkNode<T>* cur = this->pHead;
    for(int i = 1; i < pos; i++) {
        cur = cur->next;
    }

    LinkNode<T>* delete_node_ptr = cur->next;
    cur->next = delete_node_ptr->next;

    data = delete_node_ptr->data;
    this->m_length--;

    if(delete_node_ptr != nullptr) {
        delete delete_node_ptr;
    }

    return true;
}
