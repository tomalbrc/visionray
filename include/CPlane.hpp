//
//  CPlane.hpp
//  trace
//
//  Created by Tom Albrecht on 29.01.19.
//  Copyright © 2019 Tom Albrecht. All rights reserved.
//

#ifndef CPlane_hpp
#define CPlane_hpp

#include <stdio.h>
#include "IGeometryObject.h"
#include "BasicTypes.h"

NS_VRAY_BEGIN

class CPlane : public IGeometryObject {
public:
    CPlane(const Vec3d &position, const Vec3d &normal);
    
    /**
     * detects hit w/ ray+sphere
     * @param[in]   ray ray to test for
     * @param[out]  inter intersection information
     */
    virtual bool hit(const math::Ray& ray, Intersection &inter) override;
    
private:
    Vec3d _normal;
};

NS_VRAY_END

#endif /* CPlane_hpp */
