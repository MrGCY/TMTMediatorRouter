//
//  TMTMediatorRouter.h
//  AboutToPlayApp
//
//  Created by Mr.GCY on 2018/9/13.
//  Copyright © 2018年 Mr.GCY. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "TMTTipProtocol.h"
#import "TMTRouteMapModel.h"
#import "TMTSplitURLModel.h"
#import "TMTMediatorConfig.h"
#import "TMTMediatorExceptionProtocol.h"
NS_ASSUME_NONNULL_BEGIN
@interface UIViewController (TMTMediatorRouter)

/**
 当mediator无法通过performTarget调用action时，通过该方法处理
 
 @param params 传递的参数
 @return performTarget需要返回的参数
 */
- (nullable id)notFound:(NSDictionary *)params;

@end

@interface TMTMediatorRouter : NSObject
/**
 MediatorRouter参数配置
 */
@property (nonatomic, strong, readonly) TMTMediatorConfig *config;

/**
 MediatorRouter异常处理代理
 */
@property (nonatomic, weak) id<TMTMediatorExceptionProtocol> exceptionDelegate;


/**
 MediatorRouter调用失败提示处理代理
 */
@property (nonatomic, weak) id<TMTTipProtocol> tipDelegate;


/**
 单例方法
 
 @return Lothar对象
 */
+ (instancetype)shared;


/**
 配置config
 
 @param config config对象
 */
+ (void)setupConfig:(void(^)(TMTMediatorConfig *config))config;

/**
 远程调用入口
 
 @param url 规则：scheme://[user]:[password]@[target]/[action]?[params]
 URL例子: myapp://user:password@targetA/actionB?id=1234
 
 @param completion 如果远程调用有回调则在此执行，回调结果在info[result]内
 @return 如果远程调用有返回值，则在此直接返回，如果无法调用，则返回@(NO)
 */
+ (nonnull id)performActionWithUrl:(NSURL *)url completion:(void(^ _Nullable)(_Nullable id result))completion;

/**
 本地组件调用入口
 
 @param targetName 调用的类名
 @param actionName 调用的方法名
 @param params 传递的参数
 @return 如果本地调用有返回值，则在此直接返回，如果无法调用，则返回@(NO)
 */
+ (nullable id)performTarget:(NSString *)targetName action:(NSString *)actionName params:(nullable NSDictionary *)params shouldCacheTarget:(BOOL)shouldCacheTarget;

/**
 远程调用入口
 
 @param url 规则：scheme://[user]:[password]@[target]/[action]?[params]
 URL例子: myapp://user:password@targetA/actionB?id=1234
 
 @param completion 如果远程调用有回调则在此执行，回调结果在info[result]内
 @return 如果远程调用有返回值，则在此直接返回，如果无法调用，则返回@(NO)
 */
- (nonnull id)performActionWithUrl:(NSURL *)url completion:(void(^ _Nullable)(_Nullable id result))completion;

/**
 本地组件调用入口
 
 @param targetName 调用的类名
 @param actionName 调用的方法名
 @param params 传递的参数
 @return 如果本地调用有返回值，则在此直接返回，如果无法调用，则返回nil
 */
- (nullable id)performTarget:(NSString *)targetName action:(NSString *)actionName params:(nullable NSDictionary *)params shouldCacheTarget:(BOOL)shouldCacheTarget;


+ (void)releaseTargetCacheWithTargetName:(NSString *)targetName;

@end
NS_ASSUME_NONNULL_END
