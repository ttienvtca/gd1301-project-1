#ifndef __HORIZONTAL_LAYOUT_H__
#define __HORIZONTAL_LAYOUT_H__

#include "cocos2d.h"

USING_NS_CC;

class HorizontalLayout : public Node
{
public:
	bool init() override;

	void alignment();
	CREATE_FUNC(HorizontalLayout);
};

#endif // !__HORIZONTAL_LAYOUT_H__
