//
//  VRCaptureInitModel.h
//  VrCaptureKit
//
//  Created by yangyongnian on 2020/4/15.
//  Copyright © 2020 Yongnian Yang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WVrCommonDesc.h"
#import "WVrCaptureView.h"

@interface VrCaptureInitModel : NSObject
//素材保存路径
@property(nonatomic, copy) NSString *materialSaveDir;
//相机高度
@property(nonatomic, assign) NSInteger cameraHeight;
//自动还是手动
@property(nonatomic, assign) BOOL autoProduct;
//db的资源路径
@property(nonatomic, copy) NSString *resourcePath;
//默认view
@property(nonatomic, strong) WVrCaptureView *captureView;
//相机类型
@property(nonatomic, assign) WVrPanoModel PanoModel;
//是否使用实时构建
@property(nonatomic, assign) BOOL useRealTimeBuild;
//实时构建资源路径
@property(nonatomic, copy) NSString *realTimeBuildResourceDir;
//业务线
@property(nonatomic, copy) NSString *hostName;

@end

