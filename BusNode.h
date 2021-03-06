#ifndef BUSNODE_H
#define BUSNODE_H

#include "BusRequest.h"
#include <iostream>

class BusNode {

public:
    
    // Called by bus controller such that BusNode receieves
    // a transaction that has been addressed to it
    virtual void acceptBusTransaction(BusRequest* d) = 0;  
    
    // Called by bus controller such that this node
    // will send a bus transaction if any are pending
    virtual BusRequest* initiateBusTransaction(void) = 0;
    
    // Indicates that this node has a pending transaction to send
    virtual bool requestsTransaction(void) =0;
    
    // Indicates that this BusNode wants to lock control
    // of the bus. If true, the next time this node is
    // checked for service, it will gain a lock on the bus.
    // It will then be the only bus allowed to initiate bus transactions
    // while the lock is maintained. The lock will be maintained as long
    // as requestsLock returns true.
    virtual bool requestsLock(void) =0;
    
    // If returns true, the bus priotiy queue
    // will automatically give this node max priority
    // and ignore the priority queue when searching
    // for bus transaction. Must be handled carefully
    // if used to avoid deadlocks.
    virtual bool requestsMaxPriority(void);
    
    // Functions for granting and releasing locks
    virtual bool hasLock(void);
    virtual void grantLock(void);
    virtual void releaseLock(void);
    
    // Returns the address of this node
    virtual unsigned int getAddress(void);
    virtual void setAddress(unsigned int address);

    
protected:
    
    BusNode () {
        nodeIsLocked = false;   
    }
    
    unsigned int nodeAddress;
    
    bool nodeIsLocked;
    
    
};

#endif //BUSNODE_H

