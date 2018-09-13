//
//  TMTTipProtocol.h
//  AboutToPlayApp
//
//  Created by Mr.GCY on 2018/9/13.
//  Copyright © 2018年 Mr.GCY. All rights reserved.
//
@protocol TMTTipProtocol <NSObject>
/**
 外部调用URL参数错误时默认的提示VC
 */
+ (nonnull UIViewController *)paramsErrorTipController;

/**
 内部调用找不到控制器时的提示VC
 */
+ (nonnull UIViewController *)notFoundTargetTipController;

/**
 内部调用无法解析参数时的提示VC
 */
+ (nonnull UIViewController *)notFoundActionTipController;
@end
