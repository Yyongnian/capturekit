//
//  VrRealTimePerRoomInfoModel.h
//  VrCaptureKit
//
//  Created by yangyongnian on 2020/5/25.
//  Copyright © 2020 Yongnian Yang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VrPoint.h"
#import <UIKit/UIKit.h>

@interface VrRealTimePerRoomInfoModel : NSObject
@property(nonatomic, copy) NSString             *name;
@property(nonatomic, copy) NSArray<VrPoint*>    *walls;
@property(nonatomic, copy) NSArray<VrPoint*>    *doors;
@property(nonatomic, copy) NSDictionary<NSString *, VrPoint*> *subCameras;
@property(nonatomic, strong) VrPoint            *camera;
@property(nonatomic, strong) UIImage              *floor;

@end
