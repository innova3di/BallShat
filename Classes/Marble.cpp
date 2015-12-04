#include "Marble.h"
#include "Definitions.h"

USING_NS_CC;

cocos2d::Sprite* Marble::spawnMarble(int i, int positionX, int positionY, std::string file)
{
	
	Ball[i] = Sprite::create(file);
	Ball[i]->setPosition(Point(visibleSize.width / 2 + origin.x + positionX, visibleSize.height / 2 + origin.y + positionY));

	float SizeX = visibleSize.width / (visibleSize.width * 0.073);
	float SizeY = visibleSize.height / (visibleSize.height * 0.11);
	Ball[i]->setScale((SizeX * SizeY) * 0.0080);
	auto spriteBody = PhysicsBody::createCircle((SizeX * SizeY) * 0.140, PhysicsMaterial(0, 1, 0));

	spriteBody->setCollisionBitmask(1 + i);
	spriteBody->setContactTestBitmask(true);

	Ball[i]->setPhysicsBody(spriteBody);

	double Decelerate = 1.700000;
	spriteBody->setLinearDamping(Decelerate);

	return Ball[i];

}

cocos2d::Sprite* Marble::spawnPlayersBall(int i)
{

	Ball[i] = Sprite::create("Marbles/PlayersBall.png");
	// position the sprite on the center of the screen
	Ball[i]->setPosition(Point(visibleSize.width / 1 + origin.x -27, visibleSize.height / 2 + origin.y + 0));

	float SizeX = visibleSize.width / (visibleSize.width * 0.073);
	float SizeY = visibleSize.height / (visibleSize.height * 0.11);
	Ball[i]->setScale((SizeX * SizeY) * 0.0080);
	auto spriteBody = PhysicsBody::createCircle((SizeX * SizeY) * 0.140, PhysicsMaterial(0, 1, 0));
	spriteBody->setCollisionBitmask(1 + i);
	spriteBody->setContactTestBitmask(true);
	Ball[i]->setPhysicsBody(spriteBody);

	double Decelerate = 1.700000;
	spriteBody->setLinearDamping(Decelerate);

	// animate letting go of the sprite
	Ball[i]->runAction(Sequence::create(ScaleBy::create(0.125f, 1.111f), ScaleBy::create(0.125f, 0.9f), nullptr));
	
	return Ball[i];

}

cocos2d::Sprite* Marble::spawnCharges(int i, int level)
{
	static int Xposition = 12;

	Charges[i] = Sprite::create("Marbles/Charges.png");
	Charges[i]->setPosition(Point(visibleSize.width / 1 + origin.x - Xposition, visibleSize.height / 6 + origin.y - 32));

	float SizeX = visibleSize.width / (visibleSize.width * 0.0361);
	float SizeY = visibleSize.height / (visibleSize.height * 0.0541);

	Charges[i]->setScale(SizeX * SizeY * 0.0020);

	Xposition += 18;

	if (level == 1 || level == 2 || level == 3)
	{
		if (Xposition == 192)
		{
			Xposition = 12;
		}
	}

	else
	{
		int MaxPositions[7] = { 210, 246, 318, 318, 372, 426, 480 };
		for (int i = 4; i != 11;)
		{
			if (level == i)
			{
				if (Xposition == MaxPositions[i - 4])
				{
					Xposition = 12;
				}
			}
			i++;
		}
	}

		return Charges[i];
		
}
