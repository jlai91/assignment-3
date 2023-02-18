#include "linked_list.h"
#include <iostream>

template<class T>
void LinkedList<T>::push_front(const T &value) {
    /*
     * TODO: homework
     */
    ListNode<T> *pPtr = new ListNode<T>(value);
    pPtr->next=head->next;
    head->next=pPtr;
    num_of_element++;
}

template<class T>
void LinkedList<T>::push_back(const T &value) {
    /*
     * TODO: homework
     */
    ListNode<T> *nPtr = head;
    while(nPtr->next!=NULL)nPtr=nPtr->next;
    nPtr->next=new ListNode<T>(value);
    nPtr->next->next=NULL;
    num_of_element++;
}

template<class T>
void LinkedList<T>::pop_back() {
    /*
     * TODO: homework
     */

    if(head->next==NULL);
    else{
        ListNode<T> *nPtr = head;
        while(nPtr->next->next!=NULL)nPtr=nPtr->next;
        delete nPtr->next;
        nPtr->next=NULL;
        num_of_element--;
    }


}

template<class T>
void LinkedList<T>::pop_front() {
    /*
     * TODO: homework
     */
    if(head->next==NULL);
    else{
        ListNode<T> *nPtr = head->next;
        head->next=nPtr->next;
        delete nPtr;
        num_of_element--;
    }

}

template<class T>
void LinkedList<T>::remove(T &val) {
    /*
     * TODO: homework
     */
    if(head->next==NULL);
    else{
        ListNode<T> *nPtr = head;
        while(nPtr->next!=NULL){
            if(nPtr->next->val==val){
                ListNode<T> *rPtr = nPtr->next;
                nPtr->next=rPtr->next;
                delete rPtr;
                num_of_element--;
            }
            else nPtr=nPtr->next;
        }
    }
}

/*
 * merge in ascending order
 */
template<class T>
void LinkedList<T>::merge(const List<T> &ot) {
    /*
     * TODO: homework
     */
    const List<T> *lPtr = &ot;
    const LinkedList<T> * ll = dynamic_cast<const LinkedList<T>*>(lPtr);

    ListNode<T> *nPtr1 = head;
    ListNode<T> *nPtr2 = ll->head;

    std::cout << "List 1: ";
    while(nPtr1->next!=NULL){
        nPtr1=nPtr1->next;
        std::cout << nPtr1->val;
    }
    std::cout << "\n";
    nPtr1 = head;

    std::cout << "List 2: ";
    while(nPtr2->next!=NULL){
        nPtr2=nPtr2->next;
        std::cout << nPtr2->val;
    }
    std::cout << "\n";
    nPtr2 = ll->head;

    if(nPtr2->next==NULL);
    else{
        while(nPtr1->next!=NULL&&nPtr2->next!=NULL){
            if(nPtr1->next->val<=nPtr2->next->val)nPtr1=nPtr1->next;
            else{
                ListNode<T> *pPtr = new ListNode<T>(nPtr2->next->val);
                pPtr->next=nPtr1->next;
                nPtr1->next=pPtr;
                nPtr1=nPtr1->next;
                nPtr2=nPtr2->next;
                num_of_element++;
            }

        }
        while(nPtr2->next!=NULL){
            nPtr1->next=new ListNode<T>(nPtr2->next->val);
            nPtr1=nPtr1->next;
            nPtr1->next=NULL;
            nPtr2=nPtr2->next;
            num_of_element++;
        }
    }

    std::cout << "List Final: ";
    nPtr1 = head;
    for(nPtr1;nPtr1->next!=NULL;nPtr1=nPtr1->next)std::cout << nPtr1->next->val;
    std::cout << "\n";


}

template<class T>
void LinkedList<T>::reverse_iterative() {
    /*
     * TODO: homework
     */
    T temp[num_of_element];
    int index = 0;

    std::cout << "List Contents: ";
    while(head->next!=NULL){
        std::cout << head->next->val << " ";
        temp[index]=head->next->val;
        index++;
        pop_front();
    }
    std::cout << "\n";

    std::cout << "# of Elements: " << index << "\n";
    std::cout << "Elements Saved: ";
    for(index=0;index<num_of_element;index++){
        std::cout << temp[index] << " ";
        push_front(temp[index]);
    }
    std::cout << "\n";

    std::cout << "New List Contents: ";
    ListNode<T> *nPtr = head;
    while(nPtr->next!=NULL){
        std::cout << nPtr->next->val << " ";
        nPtr=nPtr->next;
    }
    std::cout << "\n";




}