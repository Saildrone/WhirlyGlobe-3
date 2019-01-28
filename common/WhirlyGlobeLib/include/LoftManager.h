/*
 *  LoftManager.h
 *  WhirlyGlobeLib
 *
 *  Created by Steve Gifford on 7/30/13.
 *  Copyright 2011-2017 mousebird consulting. All rights reserved.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 */

#import <math.h>
#import <set>
#import <map>
#import "Identifiable.h"
#import "BaseInfo.h"
#import "Dictionary.h"
#import "Scene.h"
#import "BasicDrawable.h"
#import "SelectionManager.h"
#import "VectorData.h"

namespace WhirlyKit
{
    
// Used to describe the drawables we want to construct for a given vector
class LoftedPolyInfo : public BaseInfo
{
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
    
    LoftedPolyInfo();
    LoftedPolyInfo(const Dictionary &dict);
    
    float       height;
    float       base;
    int         outlineDrawPriority;
    bool        top,side;
    bool        layered;
    bool        outline,outlineSide,outlineBottom;
    RGBAColor   color,outlineColor;
    float       outlineWidth;
    bool        readZBuffer;
    bool        writeZBuffer;
};

/** Representation of one or more lofted polygons.
 Used to keep track of the assets we create.
 */
class LoftedPolySceneRep : public WhirlyKit::Identifiable
{
public:
    LoftedPolySceneRep() : triMesh(VectorTriangles::createTriangles()) { }
    LoftedPolySceneRep(SimpleIdentity theId) : Identifiable(theId) { }
    ~LoftedPolySceneRep() { }
    
    WhirlyKit::SimpleIDSet drawIDs;  // Drawables created for this
    WhirlyKit::ShapeSet shapes;    // The shapes for the outlines
    std::vector<WhirlyKit::VectorRing>  outlines;  // If we're displaying outlines, the shapes for that
    WhirlyKit::GeoMbr shapeMbr;       // Overall bounding box
    float fade;            // Fade out, used for delete
    VectorTrianglesRef triMesh;  // The post-clip triangle mesh, pre-loft
};
typedef std::set<LoftedPolySceneRep *,IdentifiableSorter> LoftedPolySceneRepSet;

#define kWKLoftedPolyManager "kWKLoftedPolyManager"
    
/** The Loft Manager handles the geometr associated with lofted polygons.
    It's entirely thread safe (except for destruction).
  */
class LoftManager : public SceneManager
{
public:
    LoftManager();
    virtual ~LoftManager();

    /// Add lofted polygons
    SimpleIdentity addLoftedPolys(WhirlyKit::ShapeSet *shapes,const Dictionary &desc,float gridSize,ChangeSet &changes);

    /// Enable/disable lofted polys
    void enableLoftedPolys(const SimpleIDSet &polyIDs,bool enable,ChangeSet &changes);
    
    /// Remove lofted polygons
    void removeLoftedPolys(const SimpleIDSet &polyIDs,ChangeSet &changes);
        
protected:
    void addGeometryToBuilder(LoftedPolySceneRep *sceneRep,LoftedPolyInfo *polyInfo,GeoMbr &drawMbr,Point3d &center,bool centerValid,Point2d &geoCenter,ChangeSet &changes);
    
    pthread_mutex_t loftLock;
    LoftedPolySceneRepSet loftReps;
};

}