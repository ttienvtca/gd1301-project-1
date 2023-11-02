#include "DemoScrollView.h"
#include "ui/CocosGUI.h"

bool DemoScrollView::init()
{
    if (!Scene::init())
    {
        return false;
    }

    ui::ScrollView* scrollview = ui::ScrollView::create();
    scrollview->setDirection(ui::ScrollView::Direction::VERTICAL);
    scrollview->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    scrollview->setScrollBarEnabled(true);
    scrollview->setBounceEnabled(true);
    scrollview->setContentSize(Size(500, 300));
    scrollview->setBackGroundImage("inv-background.png");

    auto inner = Sprite::create("ivn-inner.png");
    inner->setPosition(inner->getContentSize() / 2);
    scrollview->setInnerContainerSize(inner->getContentSize());
    scrollview->addChild(inner);

    scrollview->setPosition(Director::getInstance()->getVisibleSize() / 2);
    this->addChild(scrollview);
    return true;
}
