//
//  CArtboard.cpp
//  trace
//
//  Created by Tom Albrecht on 18.12.18.
//  Copyright © 2018 Tom Albrecht. All rights reserved.
//


#ifndef CArtboard_h
#define CArtboard_h 

#include <string>
#include <map>
#include "IObject.h"
#include "CColor.h"
#include "IScene.h"

NS_VRAY_BEGIN

class CArtboard : public IObject {
public:
    using Callback = std::function<bool(int, int, CColor)>;
    
    CArtboard() = default;
    CArtboard(unsigned width, unsigned height);
    
    virtual ~CArtboard() {}
    
    virtual std::string description() override;
    
    void render(const IScene::Ptr &scene);
    
    void draw(const int &x, const int &y, const CColor & color);
    
    const Callback& pixelCallback() const;
    
    void pixelCallback(const Callback& newCallback);
    
private:
    unsigned _width = 0;
    unsigned _height = 0;
    Callback _pixelCB;
};

NS_VRAY_END

#endif // CArtboard_h
