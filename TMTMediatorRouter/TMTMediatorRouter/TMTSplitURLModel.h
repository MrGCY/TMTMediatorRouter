//
//  TMTSplitURLModel.h
//  AboutToPlayApp
//
//  Created by Mr.GCY on 2018/9/13.
//  Copyright © 2018年 Mr.GCY. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TMTSplitURLModel : NSObject
@property (nonatomic, copy, readonly) NSString *scheme;

@property (nonatomic, copy, readonly) NSString *user;

@property (nonatomic, copy, readonly) NSString *password;

@property (nonatomic, copy, readonly) NSString *target;

@property (nonatomic, copy, readonly) NSString *action;

@property (nonatomic, strong, readonly) NSDictionary *params;

+ (instancetype)splitObjectWithURL:(NSURL *)url;
@end
