/*
 *  MaplyBaseViewController_private.h
 *  MaplyComponent
 *
 *  Created by Steve Gifford on 12/14/12.
 *  Copyright 2012 mousebird consulting
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

#import <UIKit/UIKit.h>

#import "MaplyBaseViewController.h"
// Note: Porting
//#import "MaplyViewControllerLayer_private.h"
#import "MaplyComponentObject_private.h"
#import "MaplyInteractionLayer_private.h"
// Note: Porting
//#import "PanDelegateFixed.h"
//#import "PinchDelegateFixed.h"
#import "MaplyBaseInteractionLayer_private.h"
#import "MaplyVectorObject_private.h"
#import "MaplyShader_private.h"
#import "EAGLView.h"
// Note: Porting
//#import "MaplyActiveObject_private.h"

@interface MaplyBaseViewController()
{
@public
    WhirlyKitEAGLView *glView;
    WhirlyKit::MaplySceneRendererES2 *sceneRenderer;
    
    WhirlyKitLayerThread *baseLayerThread;
    // Note: Porting
//    WhirlyKitLayoutLayer *layoutLayer;
    NSMutableArray *layerThreads;

    // Our own interaction layer does most of the work
    MaplyBaseInteractionLayer *interactLayer;

    // Layers (and associated data) created for the user
    NSMutableArray *userLayers;
    
    // List of views we're tracking for location
    NSMutableArray *viewTrackers;
        
    // General rendering and other display hints
    NSDictionary *hints;
        
    // Clear color we're using
    UIColor *theClearColor;
    
    /// Pointer to the scene.  The subclasses are keeping pointers with their specific subclass.
    WhirlyKit::Scene *scene;
    
    /// A pointer to the 3D view.  The subclasses are keeping points with the right subclass.
    WhirlyKit::View *visualView;
    
    /// Active lights
    NSMutableArray *lights;
    
    /// Active shaders
    NSMutableArray *shaders;
    
    /// Active models
    NSMutableArray *activeObjects;
    
    /// Current draw priority if we're assigning them ourselves
    int layerDrawPriority;
    
    /// Set if we're dumping out performance output
    bool _performanceOutput;
}

/// This is called by the subclasses.  Don't call it yourself.
- (void) clear;

/// LoadSetup is where the Component does all the WhirlyGlobe/Maply specific setup.  If you override this,
///  be sure to call [super loadSetup] first and then do your thing.
- (void) loadSetup;

/// Create the EAGLView
- (void) loadSetup_glView;

/// If you have your own WhirlyGlobeView or MaplyView subclass, set it up here
- (WhirlyKit::View *) loadSetup_view;

/// For loading the Maply or Globe view.  The subclasses call this, but you shouldn't
- (WhirlyKit::Scene *) loadSetup_scene;

/// Override this to set up the default lighting scheme (e.g. the shaders).
/// The base class provides an adequate default
- (void) loadSetup_lighting;

/// The base classes fill this in to return their own interaction layer subclass
- (MaplyBaseInteractionLayer *) loadSetup_interactionLayer;

/// Make the renderer's GL context active.  This is used internally.
- (void) useGLContext;

@end
