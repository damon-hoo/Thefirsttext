#include "HelloWorldScene.h"
#include "Contentlisener.h"
USING_NS_CC;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    this->creatworld();
    this->setTouchEnabled(true);
    this->setTouchMode(kCCTouchesOneByOne);
     this->scheduleUpdate();
    Contentlisener *contentlisener=new Contentlisener();
    world->SetContactListener(contentlisener);//增加监听事件
    
    
    return true;
}
void HelloWorld::creatworld()
{
    b2Vec2 gravity;
    gravity.Set(0, -10);
    world=new b2World(gravity);
    world->SetAllowSleeping(true);
    world->SetContinuousPhysics(true);
    
    b2BodyDef def;
    def.position.Set(0, 0);
    b2Body *body = world->CreateBody(&def);
    
    b2EdgeShape shape;
    shape.Set(b2Vec2(Visibel_origin.x/32, Visibel_origin.y/32), b2Vec2((Visible_Size.width+Visibel_origin.x)/32,Visibel_origin.y/32));
    body->CreateFixture(&shape, 0);
    
    shape.Set(b2Vec2(Visibel_origin.x/32, Visibel_origin.y/32), b2Vec2(Visibel_origin.x/32,Visible_Size.height/32));
    body->CreateFixture(&shape, 0);
    
    shape.Set(b2Vec2(Visibel_origin.x/32, (Visibel_origin.y+Visible_Size.height)/32), b2Vec2((Visible_Size.width+Visibel_origin.x)/32,(Visibel_origin.y+Visible_Size.height)/32));
    body->CreateFixture(&shape, 0);
    
    shape.Set(b2Vec2((Visibel_origin.x+Visible_Size.width)/32, (Visibel_origin.y+Visible_Size.height)/32), b2Vec2((Visible_Size.width+Visibel_origin.x)/32,Visibel_origin.y/32));
    body->CreateFixture(&shape, 0);
    
    
    
}
bool HelloWorld::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    CCLog("%s",__FUNCTION__);
    return true;
}
void HelloWorld::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
    
}
void HelloWorld::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
    this->addnewsprite(pTouch->getLocation());
}
void HelloWorld::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent)
{
    
}
void HelloWorld::addnewsprite(CCPoint position)
{
    Physicalsprite *sp=new Physicalsprite();
    sp->setPosition(position);
    addChild(sp);
    
    b2BodyDef def;
    def.userData=sp;
    def.position.Set(position.x/32, position.y/32);
    def.type=b2_dynamicBody;
    b2Body*body = world->CreateBody(&def);
    
    b2PolygonShape shap;
    shap.SetAsBox(0.5, 0.5);
    //关联定义
    b2FixtureDef fixturedef;
    fixturedef.shape=&shap;
    fixturedef.density=2.0;
    fixturedef.friction=0.5;
    fixturedef.restitution=0.5;
    body->CreateFixture(&fixturedef);
    //body->ApplyLinearImpulse(b2Vec2(20,20), def.position);
    //body->ApplyAngularImpulse(20);
    
    sp->release();
}
void HelloWorld::update(float t)
{
    world->Step(t, 8, 3);
    for (b2Body *b=world->GetBodyList(); b; b=b->GetNext()) {
        if (b->GetUserData()!=NULL) {
            Physicalsprite *sp=(Physicalsprite *)b->GetUserData();
            if (sp->hp<=0) {
                sp->removeFromParent();
                world->DestroyBody(b);
            }
            else
            {
            sp->setPosition(ccp(b->GetPosition().x*32, b->GetPosition().y*32));
            sp->setRotation(-1*CC_RADIANS_TO_DEGREES(b->GetAngle()));
                sp->layer->setPosition(0,sp->hp/100.0*32.0);
                sp->layer->setContentSize(CCSizeMake(32, (100.0-sp->hp)/100.0*32.0));
            
            }
        }
    }
    
}
void HelloWorld::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}
