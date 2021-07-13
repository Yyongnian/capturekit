#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "VrCaptureInitModel.h"
#import "VrCaptureKit.h"
#import "VrPoint.h"
#import "VrRealTimePerRoomInfoModel.h"
#import "VrRealTimeRoomInfoModel.h"
#import "WVrCapture.h"
#import "WVrCaptureView.h"
#import "WVrCommonDesc.h"

FOUNDATION_EXPORT double capturekitVersionNumber;
FOUNDATION_EXPORT const unsigned char capturekitVersionString[];

