// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <iostream>
struct SYM {
  char ch;
  int prior;
};
template <typename T>
class TPQueue {
private:
  struct Node {
    T data;
    Node* next;
    Node(T val) : data(val), next(nullptr) {}
  };
  Node* head;
public:
  TPQueue() : head(nullptr) {}
  ~TPQueue() {
    while (head) {
      Node* temp = head;
      head = head->next;
      delete temp;
    }
  }
  void enqueue(T value) {
    Node* newNode = new Node(value);
    if (!head || head->data.prior < value.prior) {
      newNode->next = head;
      head = newNode;
    } else {
      Node* current = head;
      while (current->next && current->next->data.prior >= value.prior) {
        current = current->next;
      }
      newNode->next = current->next;
      current->next = newNode;
    }
  }
  T dequeue() {
    if (!head) {
      throw std::runtime_error("Queue is empty");
    }
    Node* temp = head;
    head = head->next;
    T value = temp->data;
    delete temp;
    return value;
  }
  bool isEmpty() const {
    return head == nullptr;
  }
};
#endif  // INCLUDE_TPQUEUE_H_
