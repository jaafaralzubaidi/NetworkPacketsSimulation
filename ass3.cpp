//Name: Jaafar Alzubaidi
//Class: CS300
//Task: Simulation of Processing Network Packets 
#include <iostream>
#include <vector>

#include "Packet.h"
#include "Response.h"
#include "Buffer.h"
#include "ArrayQueue.h"


using namespace std;


vector <Packet> readPackets();
vector <Response> processPackets(vector<Packet> &, Buffer *);
void printResponses(vector<Response> &);

//please don't modify main function
int main() {
        


    
    int bufferSize;
    cin >> bufferSize;
    
    
    vector<Packet> requests = readPackets(); //read packets from user

    //create buffer with the given size
    Buffer buffer(bufferSize);
    cout<<"Processing Packets:"<<endl;

    //process the packets
    vector<Response> responses = processPackets(requests, &buffer);

    cout<<"Print responses:"<<endl;
    //print responses
    printResponses(responses);

    return 0;
}

vector<Packet> readPackets(){
    vector<Packet> packets;
    int size, arrivalTime, processingTime;
    //counting the number of packets
    cin >> size;
    if(size <= 0)
        cout << "There are no Packets, the processor is Idle" << endl;
    else{
        for(int i = 0; i < size; i++){
            
            cin >> arrivalTime >> processingTime;
            //packets objects will store arrival and process time
            packets.push_back(Packet(arrivalTime, processingTime));
        }
    }    

    return packets;
}
vector <Response> processPackets(vector<Packet> &packets, Buffer *buffer){
    vector <Response> responses;
    int size = packets.size();

    for(int i = 0; i < size; i++)
        responses.push_back(buffer->process(packets[i]));
    
    // cout << "responses\n";
    return responses;
}
 void printResponses(vector<Response> &responses){

     for( int i = 0; i < responses.size(); i++)
        cout << responses[i].getStartTime() << endl;
 }