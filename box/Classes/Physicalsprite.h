//
//  Physicalsprite.h
//  box
//
//  Created by neworigin on 11/20/14.
//
//

#ifndef __box__Physicalsprite__
#define __box__Physicalsprite__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;
class Physicalsprite:public CCSprite
{
public:
    Physicalsprite();
    int hp;
    CCLayerColor *layer;
};
#endif /* defined(__box__Physicalsprite__) */
