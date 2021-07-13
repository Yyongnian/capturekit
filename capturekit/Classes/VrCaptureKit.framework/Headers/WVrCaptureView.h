//
//  WVrCaptureView.h
//  VRCapture
//
//  Created by yangyongnian on 2019/8/10.
//  Copyright © 2019 58. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <VrAdapter/VrAdapter.h>

#import "WVrCommonDesc.h"
@protocol WVrCaptureViewDelegate <NSObject>
- (void)vrCaptureCallbackDataInfo:(CameraPose*)pose;
@end

@interface WVrCaptureView : UIView

- (void)runWithConfiguration;

- (void)pause;

- (void)saveWorldMap;

@property(nonatomic, copy) NSString *fileUri;
@property(nonatomic, assign) BOOL isGoOnTake;

@end


