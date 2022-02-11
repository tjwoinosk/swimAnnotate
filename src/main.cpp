#include <iostream>
#include "KeyPointAnnotator.h"

int main() {
    
	KeyPointAnnotator aPool;
	aPool.addPoolLength(25);
	std::cout << "Bla: " << aPool.getPoolLength() << std::endl; 
	
    return 0;
}