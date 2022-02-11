#ifndef KEYPOINTANNOTATOR_H
#define KEYPOINTANNOTATOR_H

class KeyPointAnnotator
{
public:
	KeyPointAnnotator();
	~KeyPointAnnotator();

	void addPoolLength(int length);
	int getPoolLength();

private:
	int mPoolLength {};
};

#endif // !KEYPOINTANNOTATOR_H

