#ifndef KEYPOINTANNOTATOR_H
#define KEYPOINTANNOTATOR_H

#include "PoolData.h"

class KeyPointAnnotator
{
public:

	void SetPool(PoolData* thePool) { mThePool = thePool; }

private:
	PoolData* mThePool;
};

#endif // !KEYPOINTANNOTATOR_H

