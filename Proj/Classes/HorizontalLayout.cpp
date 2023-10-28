#include "HorizontalLayout.h"

bool HorizontalLayout::init()
{
    if (!Node::init())
    {
        log("Init Horizontal layout failed!");
        return false;
    }

    return true;
}

void HorizontalLayout::alignment()
{
    if (_parent == nullptr) return;

    Vector<Node*> children = this->getParent()->getChildren();
    children.eraseObject(this);

    float wSize = _parent->getContentSize().width;
    float xDistance = wSize / children.size();

    for (int i = 0; i < children.size(); ++i)
    {
        children.at(i)->setPositionX(xDistance * i);
    }
}
