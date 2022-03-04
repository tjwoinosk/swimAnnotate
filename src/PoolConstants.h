#ifndef POOLCONSTANTS_H
#define POOLCONSTANTS_H

namespace PoolConstants
{
	constexpr int LCM{ 50 };
	constexpr int SCM{ 25 };
	constexpr int possibleNumberLanes[3]{ 6, 8, 10 };
	constexpr int sixLanes{ possibleNumberLanes[0] };
	constexpr int eightLanes{ possibleNumberLanes[1] };
	constexpr int tenLanes{ possibleNumberLanes[2] };
	constexpr int maxVerticalPoints{ 13 };
	const int topBumper{ 11 };
	const int bottomBumper{ 1 };
	constexpr int maxHorizontalPoints{ 9 };
	constexpr int horizontalPointAlwaysPresent[4]{ 0,1,7,8 };
	constexpr int bulkheadRemovedPoint{ 4 };
}

#endif // !POOLCONSTANTS_H
