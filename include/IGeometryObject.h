//
//  IGeometryObject.h
//  trace
//
//  Created by Tom Albrecht on 18.12.18.
//  Copyright © 2018 Tom Albrecht. All rights reserved.
//

#ifndef IGeometryObject_h
#define IGeometryObject_h

#include <string>
#include <memory>

#include "IObject.h"
#include "CMaterial.h"
#include "BasicTypes.h"

NS_VRAY_BEGIN

class IGeometryObject : public IObject {
public:
    using Ptr = std::shared_ptr<IGeometryObject>;
    using Intersection = struct {
		double best_t; // best t
		struct {int x; int y;} texCoords; // uv
		Vec3d point;
        Vec3d normal; // surf normal
    };
    
    IGeometryObject();
    
    virtual ~IGeometryObject() {}

    virtual std::string description() override;
    
    /**
     * Test for hit w/ geometric obj (surface)
     *
     * @param[in]   ray             ray to test against
     * @param[out]  intersection    intersection data to populate
     * @return bool if hit
     */
    virtual bool hit(const math::Ray& ray, Intersection& intersection) = 0;
    
    
    /**
	 * material setter
	 * @param material	new material to use
	 */
    virtual void material(const CMaterial::Ptr& material);
	
	/**
	 * material getter
	 * @return the current material
	 */
    virtual const CMaterial::Ptr& material() const;
    
    /// position
	
	/**
	 *
	 */
    virtual void position(const Vec3d& position);
	
	/**
	 *
	 */
    virtual const Vec3d& position() const;
    
private:
    CMaterial::Ptr _material;
    Vec3d _position;
};

NS_VRAY_END

#endif // IGeometryObject_h
