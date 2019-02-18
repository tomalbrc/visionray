//
//  CColor.h
//  trace
//
//  Created by Tom Albrecht on 23.12.18.
//  Copyright © 2018 Tom Albrecht. All rights reserved.
//

#ifndef CColor_h
#define CColor_h

#include <cstdio>
#include <string>

#include "IObject.h"

NS_VRAY_BEGIN

/**
 * Color with RGBA values
 */
class CColor : public IObject {
public:
    CColor() {};
    CColor(float r, float g, float b, float a);
    
    virtual std::string description() override;
    
    const float & red() const { return _r; }
    const float & green() const { return _g; }
    const float & blue() const { return _b; }
    const float & alpha() const { return _a; }

    void red(const float &red) { _r = red; }
    void green(const float &green) { _g = green; }
    void blue(const float &blue) { _b = blue; }
    void alpha(const float &alpha) { _a = alpha; }

private:
    float _r = 0, _g = 0, _b = 0, _a = 0;
};

NS_VRAY_END

#endif /* CColor_h */
