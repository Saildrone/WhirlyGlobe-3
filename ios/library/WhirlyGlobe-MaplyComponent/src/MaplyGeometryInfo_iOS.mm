/*
 *  MaplyBillboardInfo_iOS_private.h
 *  WhirlyGlobe-MaplyComponent
 *
 *  Created by Steve Gifford on 1/18/19.
 *  Copyright 2011-2019 mousebird consulting
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

#import "MaplyGeometryInfo_iOS_private.h"
#import "UIColor+Stuff.h"
#import "NSDictionary+Stuff.h"

namespace WhirlyKit {
    
GeometryInfo_iOS::GeometryInfo_iOS(NSDictionary *desc)
{
    UIColor *theColor = [desc objectForKey:@"color" checkType:[UIColor class] default:[UIColor whiteColor]];
    if (theColor) {
        colorOverride = true;
        color = [theColor asRGBAColor];
    } else
        colorOverride = false;
    boundingBox = [desc enumForKey:@"boundingbox" values:@[@"single",@"triangle",@"none"] default:GeometryBBoxSingle];
    pointSize = [desc floatForKey:@"pointSize" default:4.0];
    zBufferRead = [desc floatForKey:@"zbufferread" default:true];
    zBufferWrite = [desc floatForKey:@"zbufferwrite" default:true];
}

}
