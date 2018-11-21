
#include <iostream>
#include <vector>

#define LIMIT 5

class Multiton
{
private:
	static std::vector<Multiton *> listOfInstancePtrs;
	// Limit of Objects this class will return in cycle
	static int limit;
	// Current index of getInstance() function call
	static int currentIndex;
	// ID of each object
	int mId;
	Multiton()
	{
		mId = currentIndex + 1;
	}

public:
	int getId()
	{
		return mId;
	}
	// Reserver initial size
	static int reserverSize()
	{
		Multiton::listOfInstancePtrs.reserve(LIMIT);
		for(int i = 0; i < LIMIT; i++)
		{
			Multiton::listOfInstancePtrs[i] = NULL;
		}
		return LIMIT;
	}
	static Multiton *getInstance()
	{

		currentIndex = currentIndex % LIMIT;

		if(!Multiton::listOfInstancePtrs[currentIndex % limit])
		{
			Multiton::listOfInstancePtrs[currentIndex % limit] = new Multiton();
		}
		return Multiton::listOfInstancePtrs[currentIndex++ % limit];
	}

};

std::vector<Multiton *> Multiton::listOfInstancePtrs;
int Multiton::limit = Multiton::reserverSize();
int Multiton::currentIndex =  0;

int main()
{
	std::cout<<Multiton::getInstance()->getId()<<std::endl;
	std::cout<<Multiton::getInstance()->getId()<<std::endl;
	std::cout<<Multiton::getInstance()->getId()<<std::endl;
	std::cout<<Multiton::getInstance()->getId()<<std::endl;
	std::cout<<Multiton::getInstance()->getId()<<std::endl;

	return 0;
}
