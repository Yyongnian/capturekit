//
//  WVrCommonDesc.h
//  VRCapture
//
//  Created by yangyongnian on 2019/8/10.
//  Copyright © 2019 58. All rights reserved.
//

#ifndef WVrCommonDesc_h
#define WVrCommonDesc_h

typedef NS_ENUM(NSInteger, WVrTrackStatus){
    
    TRACK_INIT_START                   = 0,   //轨迹初始化开始
    TRACK_INIT_FINISH                     ,   //轨迹初始化结束
    TRACK_INIT_FAILED                     ,   //轨迹初始化失败
    RELOCATION_INIT_START                 ,   //轨迹重定位初始化开始
    RELOCATION_INIT_FINISH                ,   //轨迹重定位初始化结束
    RELOCATION_INIT_SUCCESS               ,   //轨迹重定位成功
    TRACKING_NORMAL                       ,   //轨迹跟踪正常
    TRACKING_LOST                         ,   //轨迹丢失
};

//typedef NS_ENUM(NSInteger, WVrTrackExtendStatus){
//    TRACKING_EXTEND_STATUS_NORMAL             = 0,   //正常
//    TRACKING_EXTEND_STATUS_LIGHT_STRONG      ,   //光线太亮
//    TRACKING_EXTEND_STATUS_LIGHT_DIM         ,   //光线太暗
//    TRACKING_EXTEND_STATUS_WALK_FAST         ,   //走得太快了请放慢脚步
//};

typedef NS_ENUM(NSInteger, WVrTrackLightStatus){
    TRACKING_EXTEND_STATUS_LIGHT_STRONG      ,   //光线太亮
    TRACKING_EXTEND_STATUS_LIGHT_DIM         ,   //光线太暗
};

typedef NS_ENUM(NSInteger, WVrCallbackStateType){
    
    WVrCallbackStateNormal             = 0,   //正常
    WVrCallbackStateLost                  ,   //轨迹丢失
    WVrCallbackStateRelocalizing          ,   //追踪受限，重新定位
    WVrCallbackStateNotAvailable          ,   //不可用
    WVrCallbackStateReasonNone            ,
    WVrCallbackStateInitializing          ,   //初始化
};

typedef NS_ENUM(NSInteger, WVrPanoModel){
    RICOH               = 1 ,      //理光（默认）
    EXTERNAL                ,   //扩展相机
};

typedef NS_ENUM(NSInteger, ImageProcessingFilterCode){
    OFF               = 0 ,      //
    DR_COMP                 ,   //
    NOISE_REDUCTION         ,
    HDR                     ,
};

typedef NS_ENUM(NSInteger, PanoramaInitErrorCode){
    PanoramaInitErrorUnusual               = 1 ,      //异常（网络不稳定等）
    PanoramaInitErrorNoConnect                 ,   //连接网络失败
};

typedef NS_ENUM(NSInteger, PanoramaLiveErrorCode){
    PanoramaLiveErrorUnusual                   = 1,//异常
    PanoramaLiveErrorReStartCamera            ,   //相机连接失败，需要重启相机
    PanoramaLiveErrorConnect            ,   //相机连接失败
};

typedef NS_ENUM(NSInteger, TakePictureErrorCode){
    TakePictureErrorNoConnect                 = 1,   //连接网络失败
    TakePictureErrorImageCompoundCFail                ,      //图片合成失败
    TakePictureErrorPictureDownFail             ,   //图片下载失败
    TakePictureErrorInputParams,                    //参数有误
    TakePictureErrorTrackLost                    ,   //拍摄中轨迹丢失
    TakePictureSuccess
//    TakePictureErrorPanoramaLive             ,   //拍摄成功但下载失败
};

typedef NS_ENUM(NSInteger, WVrCallbackLocalBuildErrorType){
    
    WVrCallbackLocalBuildFail             = 0,   //构建失败
    WVrCallbackLocalBuildInitFail       ,       //初始化失败（查看手机型号是否7、系统版本是否在iOS12以后,WBVrBuild.framework是否存在）
};

typedef NS_ENUM(NSInteger, WVrCallbackRealBuildErrorType){
    
    WVrCallbackRealBuildFail             = 0,   //构建失败
    WVrCallbackRealBuildRunTime       ,       //构建超时
};

typedef NS_ENUM(NSInteger, WVrAutoProductStatusCode){
    AUTO_PRODUCT               = 0 ,
    NOT_AUTO_PRODUCT_NOT_NEED                ,    //App不需要自动构建
    NOT_AUTO_PRODUCT_MOBILE_LIMIT                ,   //此设备不支持自动构建
    NOT_AUTO_PRODUCT_CAMERA_LIMIT                 ,   //此全景相机不支持自动构建
    NOT_AUTO_PRODUCT_CLOSE_TRACK_IN_RECAPTURE                 ,  //补拍时关闭轨迹，不支持自动构建
};

typedef NS_ENUM(NSInteger, WVrRealTimeBuildStatusCode){
    USE_REALTIME_BUILD               = 0 ,    //App需要实时构建
    APP_NOT_USE_REALTIME_BUILD                ,    //App不需要实时构建
    NOT_SUPPORT_REALTIME_BUILD                ,   //上次已关闭实时构建
    NO_USE_TRACK_REALTIME_BUILD                 ,   //已关闭轨迹，实时构建也取消
    REALTIME_BUILD_LOST_MODULE                 ,  //缺少必须的依赖
};



#endif /* WVrCommonDesc_h */
