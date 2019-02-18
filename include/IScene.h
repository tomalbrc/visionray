//
//  IScene.h
//  trace
//
//  Created by Tom Albrecht on 24.12.18.
//  Copyright © 2018 Tom Albrecht. All rights reserved.
//

#ifndef IScene_h
#define IScene_h

#include <cstdio>
#include <vector>
#include "IGeometryObject.h"
#include "ILight.hpp"
#include "CCamera.h"

NS_VRAY_BEGIN

class IScene : public IObject {
public:
    using Ptr = std::shared_ptr<IScene>;
    
    virtual ~IScene() {}
    
    virtual void load() {};
    
    // camera
    
    virtual const CCamera::Ptr &camera() const;
    
    virtual void camera(const CCamera::Ptr &camera);
    
    // lights
    
    virtual void addLight(const ILight &lightSrc);

    virtual const std::vector<ILight> &lights() const;
    
    // objects
    
    virtual void addObject(const IGeometryObject::Ptr &object);
    
    virtual const std::vector<IGeometryObject::Ptr>& objects() const;
    
private:
    CCamera::Ptr _camera;
    std::vector<IGeometryObject::Ptr> _objects;
    std::vector<ILight> _lights;
};

NS_VRAY_END

#endif /* IScene_h */
