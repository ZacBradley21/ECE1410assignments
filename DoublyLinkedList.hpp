#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

#include <memory>
#include <stdexcept>

template <typename T>
class DoublyLinkedList
{
public:
  // grader
    DoublyLinkedList<T>();

    void create(T value)

    T retreive(T value)

    void update(T oldValue, T newValue)

    void remove(T value)
  

    size_t size()

private:
    template <typename T1>
    struct Node
    {
        Node<T1>(std::shared_ptr<Node<T1>> previous,
            std::shared_ptr<Node<T1>> next,
            T1 value)
            : m_previous(previous), m_next(next), m_value(value)
        {
        }

        std::shared_ptr<Node<T1>> m_previous;
        std::shared_ptr<Node<T1>> m_next;
        T1 data;
    };

    size_t size;
    std::shared_ptr<Node<T>> head;
    std::shared_ptr<Node<T>> tail;
};

#endif


/*
#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

#include <memory>
#include <stdexcept>

template <typename T>
class DoublyLinkedList
{
public:
    // grader
    DoublyLinkedList<T>() : m_size(0), m_head(nullptr), m_tail(nullptr)
    {
    }

    void create(T value)
    {
        m_size++;
        if (!m_head)
        {
            m_head = std::make_shared<Node<T>>(nullptr, nullptr, value);
            m_tail = m_head;
            return;
        }

        auto tail = m_tail;
        m_tail = std::make_shared<Node<T>>(tail, nullptr, value);
        tail->m_next = m_tail;
    }

    T retreive(T value)
    {
        for (auto p = m_head; p != nullptr; p = p->m_next)
        {
            if (p->m_value == value)
                return p->m_value;
        }
        throw std::runtime_error("Element not found");
    }

    void update(T oldValue, T newValue)
    {
        for (auto p = m_head; p != nullptr; p = p->m_next)
        {
            if (p->m_value == oldValue)
            {
                p->m_value = newValue;
                return;
            }
        }
    }

    void remove(T value)
    {
        for (auto p = m_head; p != nullptr; p = p->m_next)
        {
            if (p->m_value == value)
            {
                if (p->m_previous)
                    p->m_previous->m_next = p->m_next;
                else
                    m_head = p->m_next;

                if (p->m_next)
                    p->m_next->m_previous = p->m_previous;
                else
                    m_tail = p->m_previous;

                m_size--;
                return;
            }
        }
    }

    size_t size()
    {
        return m_size;
    }

private:
    template <typename T1>
    struct Node
    {
        Node<T1>(std::shared_ptr<Node<T1>> previous,
            std::shared_ptr<Node<T1>> next,
            T1 value)
            : m_previous(previous), m_next(next), m_value(value)
        {
        }

        std::shared_ptr<Node<T1>> m_previous;
        std::shared_ptr<Node<T1>> m_next;
        T1 m_value;
    };

    size_t m_size;
    std::shared_ptr<Node<T>> m_head;
    std::shared_ptr<Node<T>> m_tail;
};

#endif
*/