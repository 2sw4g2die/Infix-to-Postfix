/*
* lqueue.hpp
* Written by : Lana Cossettini (c3436542)
* Modified : 09/09/2023
*
* This class represents a templated Queue using a linked list as the underlying collection.
* This file should be used in conjunction with Assignment 2 for SENG1120.
*/

template <typename T>
LQueue<T>::LQueue()
{
    list = new std::list<T>();
    count = 0;
}

template <typename T>
LQueue<T>::~LQueue()
{
    delete list;
    count = 0;
}

template <typename T>
void LQueue<T>::enqueue(const T& data) 
{
    list->push_back(data); // add to back of queue
    count++;
}

template <typename T>
T LQueue<T>::dequeue() 
{
    if(empty()) {
        throw empty_collection_exception();
    }
    T data = list->front(); // Get data from front
    list->pop_front(); // Remove front
    count--;
    return data;
}

template <typename T>
T& LQueue<T>::front() 
{
    if(empty()) {
        throw empty_collection_exception();
    }
    return list->front(); // return reference to front element of queue
}

template <typename T>
int LQueue<T>::size() const
{
    return count;
}

template <typename T>
bool LQueue<T>::empty() const
{
    //checks if queue is empty
    if (count <= 0) 
        return true;
    else 
        return false;
}
