#ifndef CACHECONTROLLER_H
#define CACHECONTROLLER_H

#include "BusNode.h"
#include "BusProtocol.h"
#include "StateMachine.h"
#include "Cache.h"
#include "Instruction.h"
#include "BusRequest.h"
#include <vector>
#include <assert.h>

using namespace std;

class CacheController : public BusNode {
    
public:
    
    CacheController(unsigned int adxLength, unsigned int setCount,
                   unsigned int linesPerSet, unsigned int bytesPerLine) {
        cache =  new Cache(adxLength,setCount,linesPerSet,bytesPerLine);
        pendingInstructionFlag = 0;
        awaitingBusRead = 0;
    }
    
    // Function to handle LOAD or STORE commands from the processor
    void handleMemoryAccess(Instruction* i);
        
    // BusNode functions
    bool requestsTransaction(void);
    BusRequest* initiateBusTransaction(void);
    bool hasPendingInstruction(void);
    
    virtual void Tick(void) =0;
    
protected:
    
    // The cache the controller interfaces to
    Cache* cache;
    // Cache controlling methods
    
    // This will invalidate a line in the cache that maps
    // to memoryAdx. If the line is dirty, it will also
    // issue a bus write for the memory address.
    void invalidateCacheItem(unsigned int memoryAdx);
    
    
    Instruction* currentInstruction;  // The current LOAD/STORE instruction being handled
    bool pendingInstructionFlag;      // Indicates that the controller is busy with an instruction
    
    vector<BusRequest*> busReqQueue;  // Queue of bus communications to transmit
    
    BusRequest* nextToIssue;          // Holds the very next bus communication
    bool pendingBusReqFlag;           // For the BusNode interface - indicates this controller wants to send a request (nextToIssue)
    bool awaitingBusRead;             // Indicates that a bus read was issued, and data has not returned
    BusRequest* dispatchedBusRead;    // A copy of the bus read sent out so that the response can be recognized on return
    
    bool hasQueuedBusRequest(void);  // Indicates there are BusRequests waiting in the bus request queue for issue to the bus
    void issueNextBusRequest(void);   // Sets the pendingBusReqFlag and pulls the next BusReq off of nextToIssue
    
    // Checks the bus request queue for any BusRequests that have the given properties
    bool hasBusRequestWithParams(unsigned int code, unsigned int target, unsigned int source, unsigned int payload);
    
    // Returns the bust request from the bus request queue for any instructions with the given properties
    BusRequest* getBusRequestWithParams(unsigned int code, unsigned int target, unsigned int source, unsigned int payload);
    
    // Deletes any bus requests from the bus request queue with the given properties
    void deleteBusRequestWithParams(unsigned int code, unsigned int target, unsigned int source, unsigned int payload);
    
    // Adds new bus request to the end of the bus request queue
    void addNewBusRequest(BusRequest* r);
    
};

#endif

