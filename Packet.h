#ifndef PACKET_H
#define PACKET_H

// packet will keep track of arrival and processing time
class Packet{

private:
    int m_arrivalTime;
    int m_processingTime;

public:
    Packet(int, int);
    void setArrivalTime(int);
    void setProcessingTime(int);
    int getArrivalTime() const;
    int getProcessingTime() const;
};

Packet::Packet(int arrivalTime, int processingTime){
    m_arrivalTime = arrivalTime;
    m_processingTime = processingTime;
}

void Packet::setArrivalTime(int arrivalTime){
    m_arrivalTime = arrivalTime;
}
void Packet::setProcessingTime(int processingTime){
    m_processingTime = processingTime;
}
int Packet::getArrivalTime()const{
    return m_arrivalTime;
}
int Packet::getProcessingTime()const{
    return m_processingTime;
}


#endif // !PACKET_H
