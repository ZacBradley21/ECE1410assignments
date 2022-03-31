
#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

#include <memory>
#include <stdexcept>
#include <iostream>

/*
Program Header
Function Title: DoublyLinkedList
Summary: This file will create five functions whose purpose is to create a
doubly linked list
Inputs: None
Outputs: None
**********************
PSEUDOCODE
Begin
   Create default constructor
   Create create function
   Create retreive function
   Create update function
   Create remove function
   Create size function
End
*/


template <typename T>
class DoublyLinkedList
{
public:
    DoublyLinkedList<T>()
        : head(NULL), tail(NULL), sizeofnode(0) //Default constructor with empty parameters
    {

    }
    
    void create(T value) //create function
    {
        sizeofnode = sizeofnode + 1;
        if (head == NULL)
        {
            head = std::make_shared<node<T>>(NULL, NULL, value);
            tail = head;
        }
        else
        {
            std::make_shared<node<T>>t = tail;
            tail = std::make_shared<node<T>>(t, NULL, value);
            t->next = tail;
        }
    }

    T retreive(T value) //retreive function
    {
        for (std::shared_ptr<node<T>>(point) = head; point != NULL; point = point->next)
        {
            if (point->data == value) {
                return point->data;
            }
            throw std::runtime_error("Runtime Error");
        }
    }

    void update(T oldValue, T newValue) //update function
    {
        for (std::shared_ptr<node<T>>(point) = head; point != NULL; point = point->next)
        {
            if (point->data == oldValue)
            {
                point->data = newValue;
            }
        }
    }

    void remove(T value) //remove function
    {
        for (std::shared_ptr<node<T>>(point) = head; point != NULL; point = point->next)
        {
            if (point->data == value && point->prev)
            {
                point->prev->next = point->next;
            }
            else
            {
                head = point->next;
            }
            if (point->next)
            {
                point->next->prev = point->prev;
            }
            else
            {
                tail = point->prev;
            }

                sizeofnode = sizeofnode - 1;
            }
        }
    
    size_t size() //size function
    {
        return sizeofnode;
    }

private:
    template <typename T>
    struct node
    {
        node<T>(std::shared_ptr<node<T>>(next), std::shared_ptr<node<T>>(prev), T value)
            : next(n), prev(p), data(value)
        {

        }
        std::shared_ptr<node<T>> next;
        T data;
        std::shared_ptr<node<T>> prev;
    };

    std::shared_ptr<node<T>> head;
    size_t sizeofnode;
    std::shared_ptr<node<T>> tail;
};

#endif