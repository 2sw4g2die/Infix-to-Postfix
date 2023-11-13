/*
* lstack.hpp
* Written by : Lana Cossettini (c3436542)
* Modified : 09/09/2023
*
* This class represents a templated Stack using a linked list as the underlying collection.
* This file should be used in conjunction with Assignment 2 for SENG1120.
*/

template <typename T>
LStack<T>::LStack()
{
    list = new std::list<T>();
    count = 0;
}

template <typename T>
LStack<T>::~LStack() 
{
    delete list;
    count = 0;
}

template <typename T>
void LStack<T>::push(const T& data) 
{
    // Insert at the top
    list->push_front(data);
    count++; 
}

template <typename T>
T LStack<T>::pop() 
{
    if (empty()) {
        throw empty_collection_exception();
    }
     T data = list->front();// get data from front
    list->pop_front(); //remove front
    count--;
    return data;
}

template <typename T>
T& LStack<T>::top()
{
    if(empty()) {
        throw empty_collection_exception();
    }
    return list->front(); // return reference to top element
}

template <typename T>
int LStack<T>::size() const
{
    return count;
}

template <typename T>
bool LStack<T>::empty() const
{
    //checks if stack is empty
    if (count <= 0) 
        return true;
    else 
        return false;
}
