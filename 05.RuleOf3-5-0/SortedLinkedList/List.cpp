
#include "List.h"
#include <sstream>

List::Node::Node(int value, Node* prev, Node* next) : value(value), prev(nullptr), next(nullptr) 
{}
int List::Node::getValue() const {
    return value;
}

void List::Node::setValue(int value) {
    this->value = value;
}

List::Node* List::Node::getNext() const {
    return next;
}

void List::Node::setNext(Node* next) {
    this->next = next;
}

List::Node* List::Node::getPrev() const {
    return prev;
}

void List::Node::setPrev(Node* prev) {
    this->prev = prev;
}

List::List() : head(nullptr), tail(nullptr), size(0)
{}

List::List(const List& other) : head(nullptr), tail(nullptr), size(0) {
    *this = other;
}

int List::first() const {
    return head->getValue();
}

void List::add(int value) {
    Node* newNode = new Node(value, nullptr, nullptr);

    if (head == nullptr && tail == nullptr) {
        head = tail = newNode;
        return;
    }

    if (value <= head->getValue()) {
        newNode->setNext(head);

        head->setPrev(newNode);
        head = newNode;
    }
    else if (value >= tail->getValue()) {
        newNode->setPrev(tail);

        tail->setNext(newNode);
        tail = newNode;

    } else {
        Node* cursor = head;

        while (cursor) {
            if (cursor->getValue() >= value) {
                Node* prev = cursor->getPrev();

                cursor->setPrev(newNode);
                newNode->setNext(cursor);

                prev->setNext(newNode);
                newNode->setPrev(prev);
                return;
            }

            cursor = cursor->getNext();
        }
    }
}
void List::addAll(const List& other) {
    Node* cursor = other.head;
    while (cursor) {
        add(cursor->getValue());
        cursor = cursor->getNext();
    }
}
void List::removeFirst() {
    Node* temp = head;
    head = head->getNext();
    delete temp;
}
void List::removeAll() {
    Node* cursor = head;

    while (cursor){
        Node* temp = cursor;
        cursor = cursor->getNext();
        delete temp;
    }
}

size_t List::getSize() const {
    return size;
}
bool List::isEmpty() const {
    return size == 0;
}

List List::getReversed(List l) {
    List reversed;

    Node* cursor = l.tail;

    while (cursor) {
        reversed.add(cursor->getValue());
        cursor = cursor->getPrev();
    }

    return reversed;
}
std::string List::toString() const {
    std::ostringstream ostr;

    Node* cursor = head;
    while (cursor) {
        ostr << cursor->getValue() << ' ';
        cursor = cursor->getNext();
    }

    return ostr.str();
}

List& List::operator<<(const int& value) {
    this->add(value);
    return *this;
}
List& List::operator<<(const List& other) {
    *this = other;
    return *this;
}

List& List::operator=(const List& other) {
    addAll(other);

    head = other.head;
    tail = other.tail;
    size = other.size;

    return *this;
}

List::~List() {
    removeAll();
}

