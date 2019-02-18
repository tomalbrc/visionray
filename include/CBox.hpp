//
//  CBox.hpp
//  trace
//
//  Created by Tom Albrecht on 31.01.19.
//  Copyright © 2019 Tom Albrecht. All rights reserved.
//

#ifndef CBox_hpp
#define CBox_hpp

#include <cstdio>
#include "IGeometryObject.h"
#include "BasicTypes.h"

NS_VRAY_BEGIN

class CBox : public IGeometryObject {
public:
    CBox(const Vec3d &min, const Vec3d &max);
    
    /**
     * detects hit w/ ray+sphere
     * @param[in]   ray ray to test for
     * @param[out]  inter intersection information
     */
    virtual bool hit(const math::Ray& ray, Intersection &inter) override;
    
private:
    Vec3d _min;
    Vec3d _max;
};

NS_VRAY_END

#endif /* CBox_hpp */
