/*
 *  MaplySphericalQuadEarthWithTexGroup.h
 *  WhirlyGlobe-MaplyComponent
 *
 *  Created by Steve Gifford on 1/24/13.
 *  Copyright 2011-2015 mousebird consulting
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

#import "MaplyViewControllerLayer.h"

/** @brief Spherical quad earth layer is an older style of base map
    @details The Spherical quad earth layer fires up an older style of image map generated by the ImageChopper program.  It can be either an image pyramid or a flat grid of images.  In general, we recommend using the MaplyQuadImageTilesLayer instead.
  */
@interface MaplySphericalQuadEarthWithTexGroup : MaplyViewControllerLayer

/** @brief Initialize wth the name of a texture group plist info file.
    @details This initializer wants the name of a texture group file as created by the ImageChopper program.  That's a plist and a group of images to go with it.
    @details Seriously, go use MaplyQuadImageTilesLayer instead.
  */
- (id)initWithWithTexGroup:(NSString *)texGroupName;

@end