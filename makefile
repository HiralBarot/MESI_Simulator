

all: System.cpp Processor.cpp Memory.cpp Interconnect.cpp BusNode.cpp CacheController.cpp MI_Controller.cpp MSI_Controller.cpp MESI_Controller.cpp Cache.cpp CacheSet.cpp CacheLine.cpp test_system.cpp
	g++ System.cpp Processor.cpp Memory.cpp Interconnect.cpp BusNode.cpp CacheController.cpp MI_Controller.cpp MSI_Controller.cpp MESI_Controller.cpp Cache.cpp CacheSet.cpp CacheLine.cpp test_system.cpp -o test_system
    
interconnect: DummyNode.cpp System.cpp Processor.cpp Memory.cpp Interconnect.cpp BusNode.cpp CacheController.cpp MI_Controller.cpp MSI_Controller.cpp MESI_Controller.cpp Cache.cpp CacheSet.cpp CacheLine.cpp test_interconnect.cpp
	g++ DummyNode.cpp System.cpp Processor.cpp Memory.cpp Interconnect.cpp BusNode.cpp CacheController.cpp MI_Controller.cpp MSI_Controller.cpp MESI_Controller.cpp Cache.cpp CacheSet.cpp CacheLine.cpp test_interconnect.cpp -o test_interconnect
    