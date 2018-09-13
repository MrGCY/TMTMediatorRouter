//
//  TMTRouteMapModel.h
//  AboutToPlayApp
//
//  Created by Mr.GCY on 2018/9/13.
//  Copyright © 2018年 Mr.GCY. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString *ActionName NS_EXTENSIBLE_STRING_ENUM;

typedef NSString *TargetName NS_EXTENSIBLE_STRING_ENUM;

#pragma mark - TMTRouteActionModel
//action对象
@interface TMTRouteActionModel : NSObject

@property (nonatomic, copy, readonly) ActionName actionName;

@end

#pragma mark - TMTRouteTargetModel
//target对象
@interface TMTRouteTargetModel : NSObject

@property (nonatomic, copy, readonly) TargetName targetName;

- (nullable TMTRouteActionModel *)objectForKeyedSubscript:(NSString *)key;

@end

//是为了解决通过URL调用
//本地维护一张映射表 可以根据传入的字段 获取对应的对象和方法
@interface TMTRouteMapModel : NSObject
- (nullable TMTRouteTargetModel *)objectForKeyedSubscript:(NSString *)key;
/**
 创建url短链路由表的工厂方法
 
 @param filePath Plist文件路径
 @return HLRouteMapObject模型对象
 */
+ (instancetype)mapWithPlistFile:(NSString *)filePath;

@end
NS_ASSUME_NONNULL_END
