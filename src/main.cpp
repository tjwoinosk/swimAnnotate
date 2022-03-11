#include <iostream>

#include "KeyPointManager.h"
#include "KeyPointData.h"
#include "PoolData.h"
#include "FrameData.h"

int main() {
    
	

    return 0;
}


// 1. get pool data from user....
// 2. create pool model from data
// 3. get frame data from user...
// 4. create frame model from data

// Loop till done
// 5. simple request or smart request
// 6. loop till stop (simple request)
//
//  Loop till stop
//  6a. Add key points
//      6aI.Loop till stop
//      6aII. Request key point class and position
//      6aIII. If valid key point, Add key point
//      6aIV. If not valid, don't add, give error
//      6aV. Stop loop?
//  6b. Delete key points
//      6bI.Loop till stop
//      6bII. Request key point class
//      6bIII. If valid key point, delete key point
//      6bIV. If not valid, don't delete, give error
//      6bV. Stop loop?
//  6c. Request information from user(add key points -or- delete key points -or- stop)

//or

// 6. Loop till stop
//  6a. Add key points
//      6aI. User given key point class user provides ( position or not present)
//      6aII. If valid position, Add key point
//      6aII. If not valid position, don't add, give error
//      6aIII. Stop loop?
//  6b. Request information from user(add / delete key points or done or switch to smart request)

// 7. Done?
// 8. Display Key Points
// 9. Exit