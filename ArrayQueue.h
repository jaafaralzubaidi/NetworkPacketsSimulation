#ifndef QUEUE_H
#define QUEUE_H

template <class T>
class ArrayQueue{

private:
    T * array;
    int size, count;
    int front, back;

public:
    ArrayQueue(int  = 10);
    ~ArrayQueue();
    
    void enqueue(const T&);
    void dequeue();
    T qFront();
    T qBack();
    bool isEmpty();
    bool isFull();
    int getSize();
    
    

};

template <class T>
ArrayQueue<T>::ArrayQueue(int newSize){
    size = newSize;
    array = new T[size];
    count = 0;
    front = 0;
    back = size -1;
}
template <class T>
ArrayQueue<T>::~ArrayQueue(){
    delete[] array;
}

template <class T>
void ArrayQueue<T>::enqueue(const T &data){
    if(!isFull()){
        back = (back + 1) % size;
        array[back] = data;
        count++;
    }
}

template <class T>
void ArrayQueue<T>::dequeue(){
    if(!isEmpty()){
        front = (front + 1) % size;
        count--;
    }

}
template <class T>
T ArrayQueue<T>::qFront(){
    if(!isEmpty())
        return array[front];
    return NULL;
}

template <class T>
T ArrayQueue<T>::qBack(){
    if(!isEmpty())
        return array[back];
    return NULL;
}

template <class T>
bool ArrayQueue<T>::isEmpty(){
    return count == 0;
}

template <class T>
bool ArrayQueue<T>::isFull(){
    return count == size;
}

template <class T>
int ArrayQueue<T>::getSize(){
    return count;
}

#endif // !QUEUE_H
