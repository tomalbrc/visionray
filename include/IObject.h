//
//  IObject.h
//  trace
//
//  Created by Tom Albrecht on 18.12.18.
//  Copyright © 2018 Tom Albrecht. All rights reserved.
//

#ifndef IObject_h
#define IObject_h 

#include <string>

#include "BasicTypes.h"

NS_VRAY_BEGIN

class IObject {
public:
    virtual ~IObject() {}
    virtual std::string description();
};

NS_VRAY_END

#endif // IObject_h
