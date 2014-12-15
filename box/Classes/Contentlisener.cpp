//
//  Contentlisener.cpp
//  box
//
//  Created by neworigin on 11/20/14.
//
//

#include "Contentlisener.h"
#include "Physicalsprite.h"
Contentlisener::Contentlisener()
{
    CCLog("%s",__FUNCTION__);
}
Contentlisener::~Contentlisener()
{
    CCLog("%s",__FUNCTION__);
}
void Contentlisener::BeginContact(b2Contact* contact)
{
    CCLog("%s",__FUNCTION__);
}
void Contentlisener::EndContact(b2Contact* contact)
{
    CCLog("%s",__FUNCTION__);
    
}
void Contentlisener::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
{
    CCLog("%s",__FUNCTION__);
}
void Contentlisener::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse)
{
    CCLog("%s",__FUNCTION__);
    float force = impulse->normalImpulses[0];
    if (force>2) {
     Physicalsprite *spa =(Physicalsprite *)contact->GetFixtureA()->GetBody()->GetUserData();
     Physicalsprite *spb =(Physicalsprite *)contact->GetFixtureB()->GetBody()->GetUserData();
        if (spa&&spb) {
            spa->hp-=10;
            spb->hp-=10;
            CCLog("%d,%d",spa->hp,spb->hp);
        }
    }
    
}