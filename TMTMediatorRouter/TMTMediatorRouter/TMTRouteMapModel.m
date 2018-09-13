//
//  TMTRouteMapModel.m
//  AboutToPlayApp
//
//  Created by Mr.GCY on 2018/9/13.
//  Copyright © 2018年 Mr.GCY. All rights reserved.
//

#import "TMTRouteMapModel.h"

#pragma mark - TMTRouteActionModel

@implementation TMTRouteActionModel

- (instancetype)initWithAction:(NSString *)actionName {
     self = [super init];
     if (self) {
          _actionName = actionName;
     }
     return self;
}

@end
#pragma mark - TMTRouteTargetModel

@interface TMTRouteTargetModel ()
@property (nonatomic, strong, readwrite) NSMutableDictionary<NSString *, TMTRouteActionModel *> *actionMap;
@end

@implementation TMTRouteTargetModel

- (instancetype)initWithDictionary:(NSDictionary *)dict {
     self = [super init];
     if (self) {
          _targetName = [dict valueForKey:@"name"];
          NSMutableDictionary *tmp = [NSMutableDictionary dictionary];
          [[dict valueForKey:@"actions"] enumerateKeysAndObjectsUsingBlock:^(id  _Nonnull key, id  _Nonnull obj, BOOL * _Nonnull stop) {
               tmp[key] = [[TMTRouteActionModel alloc] initWithAction:obj];
          }];
          _actionMap = [tmp copy];
     }
     return self;
}

- (nullable TMTRouteActionModel *)objectForKeyedSubscript:(NSString *)key {
     return _actionMap[key];
}
@end

@interface TMTRouteMapModel ()
@property (nonatomic, strong, readwrite) NSDictionary<NSString *, TMTRouteTargetModel *> *routeMap;
@end
@implementation TMTRouteMapModel
+ (instancetype)mapWithPlistFile:(NSString *)filePath {
     NSDictionary *plist = [NSDictionary dictionaryWithContentsOfFile:filePath];
     return [[self alloc] initWithDictionary:plist];
}

- (instancetype)initWithDictionary:(NSDictionary *)dict {
     self = [super init];
     if (self) {
          NSMutableDictionary *tmp = [NSMutableDictionary dictionary];
          [dict enumerateKeysAndObjectsUsingBlock:^(id  _Nonnull key, id  _Nonnull obj, BOOL * _Nonnull stop) {
               tmp[key] = [[TMTRouteTargetModel alloc] initWithDictionary:obj];
          }];
          _routeMap = [tmp copy];
     }
     return self;
}

- (nullable TMTRouteTargetModel *)objectForKeyedSubscript:(NSString *)key {
     return _routeMap[key];
}
@end
