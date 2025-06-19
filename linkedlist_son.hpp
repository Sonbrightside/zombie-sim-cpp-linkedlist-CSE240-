#include<iostream>
#include <stdio.h>
#include <stdbool.h>


using std::cout;
using std::endl;



    template<typename T>
class LinkedList;

  template<typename T>
class Node{

    private:
        T data;
        Node<T>* pPrevious;
        Node<T>* pNext;

    public:
        T getData();
        void setData(T data);
        Node<T>* getNext();
        void setNext(Node<T>* node);  
        Node<T>* getPrevious();
        void setPrevious(Node<T>* node);
        friend class LinkedList<T>;

    Node()
        : data()
        , pPrevious(nullptr)
        , pNext(nullptr)
    {
    }
    
    Node(T data)
        : data(data)
        , pPrevious(nullptr)
        , pNext(nullptr)
    {

    } 

    Node(T data, Node<T>* pPrevious, Node<T>* next)
        : data(data)
        , pPrevious(pPrevious)
        , pNext(next)

    {

    }    
    //~Node();

};

   template<typename T>
class LinkedList{

private:
    Node<T>* pHead;
    Node<T>* pTail;
    int count;

public:
    void AddToFront( T _data);
    void AddToEnd(T _data);
    void AddAtIndex(T _data, int index);
    void AddBefore(Node<T>* node , T _data);
    void AddAfter(Node<T>* node,  T _data);
    T RemoveFromFront();
    T RemoveFromEnd();
    void RemoveTheFirst(T _data);
    void RemoveAllOf( T _data);
    T RemoveBefore(Node<T>* node);
    T RemoveAfter(Node<T>* node);
    bool ElementExists( T _data);
    Node<T>* Find( T _data);
    int IndexOf(T _data);
    T RetrieveFront();
    T RetrieveEnd();
    T Retrieve(int index);
    void Empty();
    int Length();
    void PrintList();
    friend class Node<T>;
    

    LinkedList()
        :pHead(nullptr)
        ,pTail(nullptr)
        ,count(0)

    {
    }
    ~LinkedList();

};
//-----------------------------------------------------

   template<typename T>
T Node<T>:: getData(){

    return this->data;

}

    template<typename T>
void Node<T>:: setData(T data){

    this->data = data;

}
 

    template<typename T>
Node<T>* Node<T>:: getNext(){

    Node<T>* curr;
    if(this->pNext != nullptr){
    
        curr = this->pNext;
        return curr;
    }
    else{
        return nullptr;
    }
}

  template<typename T>
void Node<T>:: setNext(Node<T>* node){

    
    this->pNext  = node;
    node->pPrevious = this;
    
}

template <typename T>
Node<T> *Node<T>::getPrevious(){
    Node<T>* curr;
    if(this->pPrevious != nullptr){
    
        curr = this->pPrevious;
        return curr;
    }
    else{
        return nullptr;
    }
}

template <typename T>
void Node<T>::setPrevious(Node<T> *node){
     this->pPrevious  = node;
     node->pNext = this;

}


/*template <typename T>
void Node<T>:: ~Node(){
     
     delete()

}*/

//-----------------------

    template<typename T>
void LinkedList<T>::AddToFront( T _data){
    Node<T>* pNewNode = new Node<T>(_data, nullptr, nullptr);
    if(nullptr == pHead){
        pHead = pNewNode;
        pTail = pNewNode;
    }
    else{ 
        pHead-> pPrevious = pNewNode;
        pNewNode ->pNext = pHead;
        pHead = pNewNode;      
    
    }
    ++ count;
    
}

    template<typename T>
void LinkedList<T>::AddToEnd(T _data){
    Node<T>* pNewNode = new Node<T>(_data,nullptr, nullptr);

    if(nullptr == pHead){
        pHead = pNewNode;
        pTail = pNewNode;
    }
    else{
        pNewNode->pPrevious = pTail;
        pNewNode->pNext = nullptr; 
        pTail->pNext = pNewNode;
        pTail = pNewNode;
        
    }
    ++ count;
    
}

    template<typename T>
void LinkedList<T>:: AddBefore(Node<T>* node, T _data){


    Node<T>* pNewNode = new Node<T>(_data,nullptr, nullptr);
    
    if(node == pHead){

        pHead = pNewNode;
        pNewNode -> pNext = node;
        node->pPrevious = pNewNode;
        
    }
    else{
    node->pPrevious->pNext = pNewNode;
    pNewNode -> pPrevious = node->pPrevious;
    pNewNode -> pNext = node;
    node -> pPrevious = pNewNode;

    }
    ++count;
    
}

    template<typename T>
void LinkedList<T>:: AddAfter(Node<T>* node, T _data){


    Node<T>* pNewNode = new Node<T>(_data,nullptr, nullptr);
    if(node == pTail){

        pTail-> pNext = pNewNode;
        pNewNode -> pPrevious = pTail;
        pTail = pNewNode;

    }

    else{
        node->pNext->pPrevious = pNewNode;
        pNewNode->pNext = node ->pNext;
        pNewNode -> pPrevious = node;
        node -> pNext = pNewNode;
    
    }
    
    ++count;
    

}

    template<typename T>
void LinkedList<T>::AddAtIndex(T data, int index){

    if(index < 0 || index>count){
        throw std::out_of_range("Thrown by the at method.");
    }
    else if(index == 0){
        AddToFront(data);
    }
    else if(index == count){
        AddToEnd(data); 
    }
    else{
        Node<T>* current = pHead;
        for(int i = 0; i<index; i++){ 
            current = current->pNext;
        } 
       AddBefore(current,data); 
    }
}

template <typename T>
T LinkedList<T>::RemoveFromFront(){
    if(count == 0){
        throw std::out_of_range("LinkedList is empty.");
    }
    
    Node<T>* curr = pHead;
    T value = curr->data;

    if(count > 1){
        pHead = curr->pNext;
        pHead->pPrevious = nullptr;
    }
    else{
        pHead = nullptr;
        pTail = nullptr;
    }
    
    delete curr;
    --count;
    return value;
}

 template <typename T>
T LinkedList<T>::RemoveFromEnd(){
    if(count == 0){
        throw std::out_of_range("LinkedList is empty.");
    }
    
    Node<T>* curr = pTail;
    T value = curr->data;

    if(count > 1){
        pTail = curr->pPrevious;
        pTail->pNext = nullptr;
    }
    else{
        pHead = nullptr;
        pTail = nullptr;
    }

    delete curr;
    --count;
    return value;
}
    template<typename T>
bool LinkedList<T>:: ElementExists(T data){

    Node<T>* curr = pHead;
    if(data != '\0'){
        while(curr != nullptr){
         if(curr->data == data){
            return true;           
            }
            curr = curr ->pNext;
            }
        }
    return false;
}

    template<typename T>
T LinkedList<T>:: RemoveBefore(Node<T>* node){
    T value;
    if(node == pHead){
         throw std::out_of_range("Thrown by the at method.");
    }
    else if(pHead != node->pPrevious){
        value = node->pPrevious->data;
        Node<T>* prev = node->pPrevious->pPrevious;
        Node<T>* toRemove = node->pPrevious;
        prev->pNext = node;
        node->pPrevious = prev;
        delete toRemove;
    }
    else{
        value = node->pPrevious->data;
        Node<T>* toRemove = node->pPrevious;
        pHead = node;
        node->pPrevious = nullptr;
        delete toRemove;
    }

    --count;
    return value;
}

   template<typename T>
T LinkedList<T>:: RemoveAfter(Node<T>* node){
    T value;
    if(node == pTail){
         throw std::out_of_range("Thrown by the at method.");
    }
    else if(pTail != node->pNext){
        value = node->pNext->data;
        Node<T>* after = node->pNext->pNext;
        Node<T>* toRemove = node->pNext;
        after->pPrevious = node;
        node->pNext = after;
        delete toRemove;
    }
    else{
        value = node->pNext->data;
        Node<T>* toRemove = node->pNext;
        pTail = node;
        node->pNext = nullptr;
        delete toRemove;
    }

    --count;
    return value;
}

    template<typename T>
Node<T>* LinkedList<T>:: Find(T data){

    Node<T>* curr = pHead;
    
    if(ElementExists(data)){
    while(curr != nullptr){
        if(data == curr->data){
            return curr;
        }
        curr = curr->pNext;
        }
    }

        return nullptr;


}

    template<typename T>
void LinkedList<T>::RemoveTheFirst(T data){

    Node<T>* curr = pHead;
    Node<T>* prev = nullptr;

    while(curr != nullptr && curr->data != data){
        prev = curr;
        curr = curr->pNext;
    }
    if(ElementExists(data)){
        if(curr == pHead){
            pHead = curr->pNext;
            curr->pNext->pPrevious =nullptr;
            curr->pNext = nullptr;
            delete curr;
        }
        else if(curr == pTail){
            pTail = prev;
            prev ->pNext = nullptr;
            curr->pPrevious = nullptr;
            delete curr;
        }
        else{
            prev -> pNext = curr ->pNext; 
            curr ->pNext ->pPrevious = prev;
            curr->pNext = nullptr;
            curr->pPrevious = nullptr;
            delete curr;
        }
        --count;
    }
    
}

   template<typename T>
void LinkedList<T>:: Empty(){

        Node<T>* current = pHead;
        while (current != nullptr) {
            Node<T>* next = current->pNext;
            delete current;
            current = next;
        }
        pHead = nullptr;
        pTail = nullptr;
        count = 0;
}

    template<typename T>
int LinkedList<T>:: Length(){

    return count;

}

    template<typename T>
T LinkedList<T>:: RetrieveFront(){
    if (pHead == nullptr) {
        throw std::out_of_range("Thrown by the at method.");
    }
    return pHead->getData();
}

    template<typename T>
T LinkedList<T>:: RetrieveEnd(){ 
    if (pHead == nullptr) {
        throw std::out_of_range("Thrown by the at method.");
    }
    return pTail->getData();
}

    template<typename T>
T LinkedList<T>:: Retrieve(int index){
    
    T value;
    Node<T>* curr = pHead;
    if (index < 0 || index >= count){
       throw std::out_of_range("Thrown by the at method.");
    }
    else if(index == 0){
        value = pHead->data;
        return value;
    }
    else{
        for(int i = 0 ; i<index; i++){
            curr = curr->pNext;
        }
        return curr->data;
    }    

}

    template<typename T>
int LinkedList<T>:: IndexOf(T _data){

    int index = 0;
    Node<T>* curr = pHead;

    while(curr != nullptr){
        if(curr->data == _data){
            return index;
        }
        else{
            ++index;
        }
        curr = curr->pNext;
    }

    
        return -1;
    
}

    template<typename T>
void LinkedList<T>:: RemoveAllOf( T _data){

    Node<T>* curr = pHead;
    Node<T>* prev = nullptr;
    
    if(ElementExists(_data)){
        while(curr->pNext != nullptr){
            if(  _data == curr->data){
                if(prev == nullptr){
                    pHead = curr->pNext;
                    pHead->pPrevious = nullptr;
                    --count;
                    Node<T>* temp = curr;
                    curr = curr->pNext;
                    delete temp;
                }
                else{
                    prev->pNext = curr-> pNext;
                    curr->pNext->pPrevious = prev;
                    -- count;
                    Node<T>* temp = curr;
                    curr = curr->pNext;
                    delete temp;
                }  
            }
            else{

                prev = curr;
                curr = curr->pNext;
            }    
        }
        if(_data == curr->data){
            if (prev == nullptr) {
                pHead = nullptr;
                pTail = nullptr;
                delete curr;
            } else {
                pTail = curr->pPrevious;
                prev -> pNext = nullptr;
                -- count;
                delete curr;
            }
        }

    }
}

    template<typename T>
void LinkedList<T>:: PrintList(){

    Node<T>* current = pHead;
    if (current == nullptr){
        return;
    }
    
        while(current->pNext != nullptr){
            //T data = current->data;
            std::cout << current->data << "=";
            current = current->pNext;
        }
        std::cout << current->data << std::endl;
}


   template<typename T>
LinkedList<T>::~LinkedList()
{
    
    /*if(count == 1){
        Node<T>* pDeleteNode = pHead;
        delete pDeleteNode;
    }
    else {
    Node<T>* pDeleteNode = pHead;
    Node<T>* next;
    while(pDeleteNode->pNext != nullptr){
        next = pDeleteNode->pNext ;
        //delete(pDeleteNode);
        pDeleteNode = next;
        
        

    }
    delete pDeleteNode;
    }*/

    Node<T>* current = pHead;
        
        while(current != nullptr){

            Node<T>* next = current;
            current = current -> pNext;
            delete next;
        }
        pHead = nullptr;
        pTail = nullptr;
}