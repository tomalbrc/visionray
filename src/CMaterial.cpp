//
//  CMaterial.cpp
//  trace
//
//  Created by Tom Albrecht on 23.12.18.
//  Copyright © 2018 Tom Albrecht. All rights reserved.
//

#include "CMaterial.h"

NS_VRAY_BEGIN

void CMaterial::diffuseColor(const CColor &diffuseColor)
{
    _diffuseColor = diffuseColor;
}

const CColor &CMaterial::diffuseColor() const
{
    return _diffuseColor;
}

NS_VRAY_END
