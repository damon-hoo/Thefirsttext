//
//  variate.h
//  gold
//
//  Created by neworigin on 14-11-9.
//
//

#ifndef gold_variate_h
#define gold_variate_h

#define Visible_Size  CCDirector::sharedDirector()->getVisibleSize()
#define Visibel_origin  CCDirector::sharedDirector()->getVisibleOrigin()
#define Visibel_mid  CCPointMake((Visibel_origin.x+Visible_Size.width)/2, (Visibel_origin.y+Visible_Size.height)/2)
#define rotate(x) 180*M_PI/(x)

#endif
