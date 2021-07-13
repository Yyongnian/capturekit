//
//  WVrCapture.h
//  VRCapture
//
//  Created by yangyongnian on 2019/8/10.
//  Copyright © 2019 58. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <VrAdapter/VrAdapter.h>
#import "WVrCaptureView.h"
#import "WVrCommonDesc.h"
#import "VrCaptureInitModel.h"
#import "VrRealTimeRoomInfoModel.h"
#pragma mark -- 全景相机代理

@protocol WVrCaptureOSCDelegate <NSObject>

/**
 @brief 全景相机初始化成功
 
 @param infoDict 相机信息
 */
- (void)onInitPanoramicCameraSuccess:(NSDictionary*)infoDict;

/**
 @brief 全景相机初始化失败

 @param errorType 失败原因
 */
- (void)onInitPanoramicCameraFailed:(PanoramaInitErrorCode)errorType;

/**
 @brief 全景相机拍照后照片开始合成
 
 @param capturePoint 拍摄点位信息
 */
- (void)onComposePictureStart:(VrCapturePoint*)capturePoint;

/**
 @brief 全景相机拍照后照片合成完毕通知
 
 @param capturePoint 拍摄点位信息
 */
- (void)onComposePictureCompleted:(VrCapturePoint*)capturePoint;

/**
 @brief 全景相机拍照后照片导出进度
 
 @param capturePoint 拍摄点位信息
 @param progress       导出进度，格式为小数据两位，大小从0到1变化
 */
- (void)onPictureExporting:(VrCapturePoint*)capturePoint progress:(float)progress;

/**
 @brief 全景相机拍照成功

 @param capturePoint 拍摄点位信息 （392版本修改此处回调名称添加OSC 字段区别扩展相机）
 */
- (void)onOSCTakePictureSucceed:(VrCapturePoint*)capturePoint;

/**
 @brief 全景相机拍照失败

 @param errorType 失败原因
 @param capturePoint 拍摄点位信息
 */
- (void)onTakePictureError:(TakePictureErrorCode)errorType capturePoint:(VrCapturePoint*)capturePoint;

@end

#pragma mark -- 全景相机实时流状态回调

@protocol WVrCaptureLiveDelegate <NSObject>

/**
 @brief 实时流获取成功
 */
- (void)onPanoramaLiveViewSuccess;

/**
 @brief 开始接收实时流
 */
- (void)onPanoramaLiveViewStart;

/**
 @brief 全景相机实时流获取失败

 @param errorType 失败原因
 */
- (void)onPanoramaLiveViewFailed:(PanoramaLiveErrorCode)errorType;


@end

#pragma mark -- 手机相机位姿回调

@protocol WVrCaptureCameraDelegate <NSObject>

/**
 @brief Track状态回调，包含轨迹初始化和重定位状态，轨迹丢失和轨迹正常状态
 @param status Track状态
 */
- (void)onTrackStatus:(WVrTrackStatus)status;

/**
 @brief SDK手动/自动处理模式通知回调
 */
- (void)onAutoProductChange:(WVrAutoProductStatusCode)status;

/**
 @brief 实时构建处理模式通知回调
 */
- (void)onRealTimeBuildChange:(WVrRealTimeBuildStatusCode)status;

// @brief 拍摄流程结束
// */
- (void)onCaptureFinishSuccess;

/**
 @brief 手机相机位姿信息发生变化回调

 @param pose 手机相机的位姿信息
 */
- (void)onCameraPositionChange:(WVrPose*)pose;

///**
// @brief 当前移动速度（废弃）
//
// @param speed 当前移动速度
// */
//- (void)onCameraMovingSpeed:(float)speed;

@end

@protocol WVRCapturerTrackExtendStatusDelegate <NSObject>

/**
 * track扩展状态回调，用于在轨迹正常时亮度监测
 * @param trackLightStatus 状态
 */
- (void)onTrackExtendLightStatus:(WVrTrackLightStatus)trackLightStatus;

/**
 * track扩展状态回调，用于在轨迹正常时速度监测
 */
- (void)onTrackExtendSpeedStatus;

/**
 * track扩展状态回调，用于在轨迹正常时正常状态
 */
- (void)onTrackExtendNormalStatus;

@end

@protocol  WVrCaptureBuildDelegate <NSObject>

/// 构建完成
/// @param totalUrl 构建预览url
- (void)onLocalBuildFinish:(NSString*)totalUrl;
//构建失败
- (void)onLocalBuildError;

- (void)onRealTimeBuildStart;

- (void)onRealTimeBuildEnd:(VrRealTimeRoomInfoModel*)realTimeModel;

- (void)onRealTimeBuildCancel;

@end

@protocol  WVrCaptureExternalDelegate <NSObject>
/**
@brief 扩展相机拍摄失败
@param errorType 错误码
 @param capturePoint 点位信息（392版本修改此处回调名称添加External 字段区别理光相机回调）
*/
- (void)onExternalTakePictureFailed:(TakePictureErrorCode)errorType capturePoint:(VrCapturePoint*)capturePoint;
/**
 @brief 扩展相机拍照成功

 @param capturePoint 拍摄点位信息（392版本修改此处回调名称添加External 字段区别理光相机回调）
 */
- (void)onExternalTakePictureSucceed:(VrCapturePoint*)capturePoint;
/**
@brief 扩展相机拍照初始化 在此回调中调用sdk setExternalPreViewConfig 设置预览画面的帧率和分辨率
*/
- (void)onExternalInitPanoCamera;
/**
@brief 扩展相机拍照开始拍摄回调
*/
- (void)onExternalCaptureStart;
@end

#pragma mark -- 全景拍摄SDK提供服务接口

@interface WVrCapture : NSObject

/**
 @brief 实例化全景拍摄SDK

 @return SDK单例
 */
+ (instancetype)shared;

/**
 @brief 释放单例资源
 */
- (void)releaseCapture;

/**
 @brief 获取sdk版本
 */
- (NSString*)getSdkVersion;

/**
 @brief 初始化SDK

 @param initModel 全景初始化模型
  cameraHeight 相机高度int
  captureView 手机相机采集信息预览视图
  resourcePath dbow2资源的地址全路径
  autoProduct 是否需要追踪

 `captureView`是手机相机进行位姿、光感等信息的采集所必须的，如果在集成SDK的APP中不需要使用，可以在初始化SDK时，只调用[[WVrCaptureView alloc] init]来创建一个captureView传入即可
 */
- (int)initWithFilePath:(VrCaptureInitModel*)initModel;


- (void)closeTrack;

/**
 @brief 启动全景相机，开始会话
 */
- (void)startPanoramicCamera;

/**
 @brief 获取全景相机状态信息
 */
- (NSDictionary*)getPanoramaCameraState;
/**
 @brief 全景相机option信息(存储信息)
 */
- (NSDictionary*)getPanoramaCameraSpaceInfo;

/**
 @brief 获取全景相机的info信息
 */
- (NSDictionary*)getPanoramaCameraInfo;

/**
 @brief 初始化实时流预览视图

 @param liveView 实时流预览视图
 */
- (void)initPanoramaLiveView:(VrPanoramaLiveView*)liveView;

/**
 @brief 开始获取实时流
 */
- (void)startPanoramaLiveView;

/**
 @brief 停止获取实时流
 */
- (void)stopPanoramaLiveView;

/**
 @brief 启动手机相机数据采集
 */
- (void)runWithConfiguration;

/**
 @brief 暂停手机相机数据采集
 */
- (void)pause;

/**
 @brief 拍照
 
 @param pictureName 拍摄点位的名称（唯一不可重复）
 @param isMainDir    原始图片是否是主图目录，为yes表示在根目录下，no表示在nomedia目录下

 */
- (TakePictureErrorCode)takePicture:(NSString*)pictureName isMainDir:(BOOL)isMainDir;

/**
 @brief 删除已拍摄点位
 @param materialSaveDir 素材路径
 @param pictureName 拍摄点位的名称（唯一不可重复）
 @param isMainDir    原始图片是否是主图目录，为yes表示在根目录下，no表示在nomedia目录下

 */
- (BOOL)deleteCapturePoint:(NSString*)materialSaveDir
                 pictureName:(NSString*)pictureName isMainDir:(BOOL)isMainDir;

/**
 @brief 重命名空间
 
 @param materialSaveDir 素材路径
 @param pictureNameSrc 源房间名称
 @param isSrcMainDir    原始图片是否是主图目录，为yes表示在根目录下，no表示在nomedia目录下
 @param pictureNameDest 目标房间名称
 @param isDestMainDir    目标图片是否是主图目录，为yes表示在根目录下，no表示在nomedia目录下

 */
- (BOOL)renameCapturePoint:(NSString*)materialSaveDir
          pictureNameSrc:(NSString*)pictureNameSrc  isSrcMainDir:(BOOL)isSrcMainDir
         pictureNameDest:(NSString*)pictureNameDest isDestMainDir:(BOOL)isDestMainDir;

/**
 @brief 重命名空间
 
 @param materialSaveDir 素材路径
 @param srcList 包含需要改变名字的所有点位信息
 @param destList    目标点位信息

 */
- (BOOL)renameAllCapturePoint:(NSString*)materialSaveDir
               srcList:(NSArray<VrPictureInfo*>*)srcList destList:(NSArray<VrPictureInfo*>*)destList;

/**
 @brief 删除缓存
 
 @param materialSaveDir 全景图片存储路径

 */
- (void)clearCacheFile:(NSString*)materialSaveDir;

/**
 @brief 设置拍摄色块是否自动显示。默认色块自动显示

 @param autoShow 默认为yes

 */
- (void)setAutoColorBlockShow:(BOOL)autoShow;


/**
 @brief 设置拍摄图片处理模式

 @param filter 默认为处理模式枚举

 */
- (void)setImageProcessingFilter:(ImageProcessingFilterCode)filter;

/**
 * 设置实时构建纹理是否显示
 *
 * @param enable 是否开启，默认为false
 */
- (void)setRealTimeBuildTextureEnable:(BOOL)enable;

/**
 @brief 是否打印log默认不打印
 
 @param enable 是否打印
 */
- (void)enableLog:(BOOL)enable;

/**
 @brief 当前手机系统是否支持全景拍摄

 @return YES 支持 / NO 不支持
 */
//- (BOOL)isSupportVrCaptureKit;

/**
 @brief 完成拍摄整体流程 在单次拍摄结束时调用
 */
- (void)captureFinish;

/**
 @brief 是否需要语音播放 yes 是 no 否(默认开启)
 */
- (void)audioPlayEnable:(BOOL)enable;

/**
 @brief 是否开启图片压缩
 
 @param enable 是否压缩
 */
- (void)setImageCompressEnable:(BOOL)enable;

/**
 @brief 关闭户型图实时构建功能
  */
- (void)closeRealTimeBuild;
/**
 @brief 更新实时构建
 */
- (void)refreshRealTimeBuild;
/**
@brief 取消实时构建
*/
- (void)cancelRealTimeBuild;
/**
 @brief 本地构建
 
 @param materialSaveDir 素材目录
 @param resourceDir  沙盒目录下WBVrBuild.bundle文件路径(TIPS: bundle文件需下载或拷贝至沙盒目录中, 例如：Documents/xxx/WBVrBuild.bundle)
 */
- (BOOL)startApartmentLocalBuild:(NSString*)materialSaveDir resourceDirInDocument:(NSString *)resourceDir;

- (void)stopApartmentLocalBuild;

/**
@brief 配置预览参数

@param frameRate 帧率
@param width 图片宽度
@param height 图片高度（宽高比例2：1）
*/
- (BOOL)setExternalPreviewConfig:(NSInteger)frameRate width:(NSInteger)width height:(NSInteger)height;

/**
@brief 下载开始去掉色块
*/
- (void)externalDownloadStart;
/**
@brief 传入图片

@param pictureName 拍摄点位的名称（唯一不可重复）
@param isMainDir    原始图片是否是主图目录，为yes表示在根目录下，no表示在nomedia目录下
@param image 传入的图片
*/
- (BOOL)setExternalPanoCameraImage:(NSString*)pictureName isMainDir:(BOOL)isMainDir image:(UIImage*)image;

/**
@brief 传入实时流图片
*/
- (void)updateExternalPreviewFrame:(UIImage*)image;
/**
 @brief 全景相机代理，用于接收全景相机状态回调
 */
@property(nonatomic, weak) id<WVrCaptureOSCDelegate> OSCDelegate;
/**
 @brief 全景相机预览流回调， 用于接收全景相机的预览流数据
 */
@property(nonatomic, weak) id<WVrCaptureLiveDelegate> liveDelegate;
/**
 @brief 手机相机回调，用于接收移动点位数据、判断相机使用状态，和移动数据
 */
@property(nonatomic, weak) id<WVrCaptureCameraDelegate> cameraDelegate;
/**
 @brief 全景构建
 */
@property(nonatomic, weak) id<WVrCaptureBuildDelegate> buildDelegate;
/**
 @brief 扩展相机
 */
@property(nonatomic, weak) id<WVrCaptureExternalDelegate> externalDelegate;
/**
 @brief 日志代理
 */
@property(nonatomic, weak) id<WVRCaptureLogDelegate> logDelegate;
/**
 @brief 拍摄轨迹扩展状态代理
 */
@property(nonatomic, weak) id<WVRCapturerTrackExtendStatusDelegate> trackStatusDelegate;


@end

