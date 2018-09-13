//
//  TMTMediatorConfig.h
//  AboutToPlayApp
//
//  Created by Mr.GCY on 2018/9/13.
//  Copyright © 2018年 Mr.GCY. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TMTMediatorConfig : NSObject
/**
 用于验证的URLScheme
 */
@property (nonatomic, copy) NSString *URLScheme;

/**
 用于验证的URLUser
 */
@property (nonatomic, copy) NSString *URLUser;

/**
 用于验证的URLPassword
 */
@property (nonatomic, copy) NSString *URLPassword;

/**
 APP的URL路由映射表的路径
 */
@property (nonatomic, copy) NSString *URLRouteMapFilePath;

/**
 跳过URL验证
 */
@property (nonatomic, assign) BOOL URLVerifySkip;
@end
