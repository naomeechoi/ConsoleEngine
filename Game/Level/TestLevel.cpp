#include "TestLevel.h"
#include "Actor/Player.h"
#include "Actor/Box.h"

TestLevel::TestLevel()
{
	AddNewActor(new Player());
}
