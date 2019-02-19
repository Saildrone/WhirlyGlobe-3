/*
 *  MaplyQuadLoader.h
 *
 *  Created by Steve Gifford on 2/12/19.
 *  Copyright 2012-2019 Saildrone Inc
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

#import <Foundation/Foundation.h>
#import "MaplyViewControllerLayer.h"
#import "MaplyCoordinateSystem.h"
#import "MaplyTileSourceNew.h"
#import "MaplyRenderController.h"
#import "MaplyQuadSampler.h"
#import "MaplyRemoteTileFetcher.h"

/**
 Passed in to and returned by the Loader Interpreter.
 
 We pass this into the interpreter with the unparsed data.  It parses it and passes that
 data back, possibly with an error.
 */
@interface MaplyLoaderReturn : NSObject

/// Tile this is the image for
@property (nonatomic) MaplyTileID tileID;

/// If set, the frame.  -1 by default
@property (nonatomic) int frame;

/// Data returned from a tile request.  Unparsed.
/// You can add multiple of these, but the interpreter should be expecting that
- (void)addTileData:(NSData *__nonnull) tileData;

/// Return the tile NSData objects as an array
- (NSArray<NSData *> * __nonnull)getTileData;

/// If this is set, the tile failed to parse
/// You can set it and the system will deal with the results
@property (nonatomic,strong) NSError * __nullable error;

@end

/**
    This version of the loader return is used by the MaplyQuadObjectLoader.

    The Object pager is only expecting Component Objects and will manage
    those as things are loaded in and out.
  */
@interface MaplyObjectLoaderReturn : MaplyLoaderReturn

/// If any component objects are associated with the tile, these are them.
/// They need to start disabled.  The system will enable and delete them when it is time.
- (void)addCompObjs:(NSArray<MaplyComponentObject *> * __nonnull)compObjs;

/// Return an array of component objects that were added to this loader return
- (NSArray * __nonnull)getCompObjs;

@end

/**
 Loader Interpreter converts raw data into images and objects.
 
 Converts data returned from a remote source (or cache) into images and/or
 MaplyComponentObjects that have already been added to the view (disabled).
 */
@protocol MaplyLoaderInterpreter<NSObject>

/**
 Parse the data coming back from a remote request and turn it into something we can use.
 
 Convert the NSData passed in to image and component objects (e.g. add stuff to the view controller).
 Everything added should be disabled to start.
 */
- (void)dataForTile:(MaplyLoaderReturn * __nonnull)loadReturn;

@end

/** Base class for the quad loaders.
 
 All the quad loader (image, frame, data) implement these same bounding box methods.  No reason
 */
@interface MaplyQuadLoaderBase : NSObject

/**
 Control how tiles are indexed, either from the lower left or the upper left.
 
 If set, we'll use the OSM approach (also Google Maps) to y indexing.  That's that default and it's normally what you're run into.
 
 Strictly speaking, TMS addressing (the standard) is flipped the other way.  So if you're tile source looks odd, try setting this to false.
 
 Default value is true.
 */
@property (nonatomic) bool flipY;

/// Set for a lot of debugging output
@property (nonatomic,assign) bool debugMode;

/**
 Calculate the bounding box for a single tile in geographic.
 
 This is a utility method for calculating the extents of a given tile in geographic (e.g. lon/lat).
 
 @param tileID The ID for the tile we're interested in.
 
 @return The lower left and upper right corner of the tile in geographic coordinates. Returns kMaplyNullBoundingBox in case of error
 */
- (MaplyBoundingBox)geoBoundsForTile:(MaplyTileID)tileID;

/**
 Calculate the bounding box for a single tile in geographic using doubles.
 
 This is a utility method for calculating the extents of a given tile in geographic (e.g. lon/lat).
 
 @param tileID The ID for the tile we're interested in.
 
 @return The lower left and upper right corner of the tile in geographic coordinates. Returns kMaplyNullBoundingBoxD in case of error
 */
- (MaplyBoundingBoxD)geoBoundsForTileD:(MaplyTileID)tileID;

/**
 Calculate the bounding box for a single tile in the local coordinate system.
 
 This utility method calculates the bounding box for a tile in the coordinate system used for the layer.
 
 @param tileID The ID for the tile we're interested in.
 
 @return The lower left and upper right corner of the tile in geographic coordinates.
 */
- (MaplyBoundingBox)boundsForTile:(MaplyTileID)tileID;

/**
 Calculate the bounding box for a single tile in the local coordinate system using doubles.
 
 This utility method calculates the bounding box for a tile in the coordinate system used for the layer.
 
 @param tileID The ID for the tile we're interested in.
 
 @return The lower left and upper right corner of the tile in geographic coordinates.
 */
- (MaplyBoundingBoxD)boundsForTileD:(MaplyTileID)tileID;

@end