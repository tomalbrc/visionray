//
//  BasicTypes.h
//  trace
//
//  Created by Tom Albrecht on 23.12.18.
//  Copyright © 2018 Tom Albrecht. All rights reserved.
//

#ifndef BasicTypes_h
#define BasicTypes_h

#include <cmath>
#include "Void.hpp"

#define NS_VRAY_BEGIN	namespace vray {
#define NS_VRAY_END		}

using Vec3d = Void::Vec3<float>;

NS_VRAY_BEGIN
namespace math {
	struct Vec4 { // TODO: Remove, legacy code
		float x = 0;
		float y = 0;
		float z = 0;
		float w = 0;
	};
	
    struct Ray {
        Vec3d origin;
        Vec3d direction;
        double length;
    };
    
    struct BBox {
        
    };
}
NS_VRAY_END

#endif /* BasicTypes_h */
