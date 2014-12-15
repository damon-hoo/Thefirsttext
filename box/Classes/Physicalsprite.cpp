//
//  Physicalsprite.cpp
//  box
//
//  Created by neworigin on 11/20/14.
//
//

#include "Physicalsprite.h"
Physicalsprite::Physicalsprite()
{
    int x=CCRANDOM_0_1()<0.5 ? 0:1;
    int y=CCRANDOM_0_1()<0.5 ? 0:1;
    this->initWithFile("blocks.png",CCRectMake(x*32,y*32, 32, 32));
    hp=100;
    layer=CCLayerColor::create(ccc4(255, 255, 0, 200), 32, 1);
    addChild(layer);
}