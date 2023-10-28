#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "Entity/Entity.h"

class Character : public Entity
{

protected:
	bool loadAnimations() override;
};

#endif // !__CHARACTER_H__
