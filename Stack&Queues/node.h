#pragma once

class Node
{
public:
    Node() : data(-1), prevElement(nullptr), nextElement(nullptr){};
    Node(int _data) : data(_data), prevElement(nullptr), nextElement(nullptr) {}
    ~Node(){};
    int data;
    Node *prevElement;
    Node *nextElement;
};