//
//  CSphere.h
//  trace
//
//  Created by Tom Albrecht on 23.12.18.
//  Copyright © 2018 Tom Albrecht. All rights reserved.
//

#ifndef CSphere_h
#define CSphere_h

#include <stdio.h>

#include "IGeometryObject.h"

NS_VRAY_BEGIN

class CSphere : public IGeometryObject {
public:
    CSphere(float diameter);
    
    /**
     * detects hit w/ ray+sphere
     * @param[in]   ray ray to test for
     * @param[out]  inter intersection information
     */
    virtual bool hit(const math::Ray& ray, Intersection &inter) override;
    
private:
    float _diameter;
};

NS_VRAY_END

#endif /* CSphere_h */
