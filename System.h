#include "Processor.h"
#include "Interconnect.h"
#include "Memory.h"
#include <vector>

using namespace std;

class System {

private:
    
    vector<Processor*>* processors;
    Memory* memory;
    Interconnect* interconnect;
    
    unsigned long tickNumber;
    
    
public:
    
    System(unsigned int numProcessors, unsigned int controllerType, unsigned int memoryLatency, unsigned int burstLength) {
        processors = new vector<Processor*>;
        memory = new Memory(memoryLatency, burstLength);
        interconnect = new Interconnect;
        
        for(int i = 0; i < numProcessors; i++) {
            Processor* p = new Processor(controllerType,burstLength);
            processors->push_back(p);
            interconnect->addNode(p, i+1);
        }
        
        interconnect->addNode(memory, numProcessors + 1);
        tickNumber = 0;
    }
    
    void insertInstruction(Instruction* i, unsigned int processorNum);
    
    bool hasPendingInstructions(unsigned int processorNum);
    
    void reportMemoryOpStatistics(void);
    
    
    void Tick(void);

};