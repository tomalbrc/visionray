//
//  CCamera.h
//  trace
//
//  Created by Tom Albrecht on 18.12.18.
//  Copyright © 2018 Tom Albrecht. All rights reserved.
//

#include "IObject.h"

NS_VRAY_BEGIN

class CCamera : public IObject {
public:
    using Ptr = std::shared_ptr<CCamera>;
    
    CCamera(const Vec3d &position = Vec3d{}, const math::Vec4 &orientation = math::Vec4{});
    
    /// Position
    
    virtual void position(const Vec3d &position);
    
    virtual const Vec3d &position() const;
    
    
    /// Orientation
    
    virtual void orientation(const math::Vec4 &orientation);
    
    virtual const math::Vec4 &orientation() const;
    
    
private:
    math::Vec4 _orientation;
    Vec3d _position;
};

NS_VRAY_END
