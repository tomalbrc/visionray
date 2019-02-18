//
//  CColor.cpp
//  trace
//
//  Created by Tom Albrecht on 23.12.18.
//  Copyright © 2018 Tom Albrecht. All rights reserved.
//

#include "CColor.h"

NS_VRAY_BEGIN

CColor::CColor(float r, float g, float b, float a)
{
    _r = r;
    _g = g;
    _b = b;
    _a = a;
}

std::string CColor::description()
{
    using namespace std::literals::string_literals;
    return "<CColor RGBA(" +
    std::to_string(_r)+", "+
    std::to_string(_g)+", "+
    std::to_string(_b)+", "+
    std::to_string(_a)+
    ")>";
}

NS_VRAY_END
