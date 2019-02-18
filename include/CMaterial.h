//
//  CMaterial.h
//  trace
//
//  Created by Tom Albrecht on 23.12.18.
//  Copyright © 2018 Tom Albrecht. All rights reserved.
//

#ifndef CMaterial_h
#define CMaterial_h

#include <cstdio>
#include <memory>

#include "CColor.h"

/// Maybe just make this an interface

NS_VRAY_BEGIN

/**
 * Material with color, (reflection?), (?texture?)
 */
class CMaterial {
public:
    using Ptr = std::shared_ptr<CMaterial>;
    /**
     *
     */
    CMaterial() = default;
	virtual ~CMaterial() {};
	
    /// Diffuse color
	
    virtual void diffuseColor(const CColor &diffuseColor);
    
    virtual const CColor &diffuseColor() const;
    
private:
    CColor _diffuseColor;
};

NS_VRAY_END

#endif /* CMaterial_h */
