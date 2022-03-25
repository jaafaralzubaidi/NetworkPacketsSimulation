#ifndef RESPONSE_H
#define RESPONSE_H


#include <iostream>
using namespace std;
// will check if the packed is dropped and keep track of the staring time
class Response{

private:
    bool m_dropped;
    int m_startTime;

public:
    Response(bool, int);
    bool isDropped();
    int getStartTime();

};

Response::Response(bool dropped, int startTime){
    m_dropped = m_dropped;
    m_startTime = startTime;
    cout << "packet " << startTime << endl;
}
bool Response::isDropped(){
    return m_dropped;
}
int Response::getStartTime(){
    return m_startTime;
}



#endif // !RESPONSE_H

