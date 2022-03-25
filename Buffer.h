#ifndef BUFFER_H
#define BUFFER_H

#include "ArrayQueue.h"
#include "Response.h"
#include "Packet.h"
#include <iostream>
using namespace std;
class Buffer{

private:
    int bufferSize;
    ArrayQueue <int> finishedTimeQueue;

public:
    Buffer(int);
    Response process(const Packet &packet);
};


Buffer::Buffer(int size){
    bufferSize = size;
}

Response Buffer::process(const Packet &packet){
    
    while(!finishedTimeQueue.isEmpty()){
        
        if(finishedTimeQueue.qFront() <= packet.getArrivalTime() )
            finishedTimeQueue.dequeue();
        else
            break;
        
    }

    if(finishedTimeQueue.getSize() == bufferSize)
        return Response(true, -1);
    
    else if(finishedTimeQueue.isEmpty()){
        finishedTimeQueue.enqueue(packet.getArrivalTime() + packet.getProcessingTime());
        return Response(false, packet.getArrivalTime());
    }

    int lastValue = finishedTimeQueue.qBack();

    finishedTimeQueue.enqueue(packet.getProcessingTime() + lastValue);
    return Response(false, lastValue);
}

#endif // !BUFFER_H
