#include "init.h"

player& currentplayer()
{
	static player cplay;
	return cplay;
}

int& lastplayed()
{
	static int laststone;
	return laststone;
}

int& ruleused()
{
	static int lastrule;
	return lastrule;
}