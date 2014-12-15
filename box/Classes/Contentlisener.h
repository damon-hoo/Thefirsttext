//
//  Contentlisener.h
//  box
//
//  Created by neworigin on 11/20/14.
//
//

#ifndef __box__Contentlisener__
#define __box__Contentlisener__

#include <iostream>
#include "Box2D.h"
#include "cocos2d.h"
USING_NS_CC;
class Contentlisener: public b2ContactListener
{
public:
    Contentlisener();
    ~Contentlisener();
    virtual void BeginContact(b2Contact* contact);
    virtual void EndContact(b2Contact* contact);
    virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);
    virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);
};
#endif /* defined(__box__Contentlisener__) */
