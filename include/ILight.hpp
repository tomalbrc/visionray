//
//  ILight.hpp
//  trace
//
//  Created by Tom Albrecht on 28.01.19.
//  Copyright © 2019 Tom Albrecht. All rights reserved.
//

#ifndef ILight_hpp
#define ILight_hpp

#include <stdio.h>
#include "CColor.h"
#include "BasicTypes.h"

NS_VRAY_BEGIN

/**
 * iface for light sources
 */
class ILight {
public:
    using Ptr = std::shared_ptr<ILight>;

    /// why is this supposed to be good again?
    virtual ~ILight() = default;
    
    virtual const Vec3d& position() const noexcept;
    
    virtual void position(const Vec3d& position) noexcept;

    virtual const CColor &color() const noexcept;
    
    virtual void color(const CColor &color) noexcept;
    
    virtual const double &intensity() const noexcept;

    virtual void intensity(double intensity) noexcept;
    
private:
    Vec3d _pos;
    double _intensity;
    CColor _color;
};

NS_VRAY_END

#endif /* ILight_hpp */
