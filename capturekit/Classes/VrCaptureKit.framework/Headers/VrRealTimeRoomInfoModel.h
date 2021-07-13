//
//  VrRealTimeRoomInfoModel.h
//  VrCaptureKit
//
//  Created by yangyongnian on 2020/5/25.
//  Copyright © 2020 Yongnian Yang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VrPoint.h"
#import "VrRealTimePerRoomInfoModel.h"

@interface VrRealTimeRoomInfoModel : NSObject
@property(nonatomic, copy) NSArray<VrPoint*> *tracks;
@property(nonatomic, copy) NSArray<VrRealTimePerRoomInfoModel*>   *rooms;
@end

