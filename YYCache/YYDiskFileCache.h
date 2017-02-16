//
//  YYDiskFileCache.h
//  YYCache
//
//  Created by song on 2017/2/16.
//  Copyright © 2017年 ibireme. All rights reserved.
//  模仿YYDiskCache，此处仅处理文件
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YYDiskFileCache : NSObject
#pragma mark - Attribute

@property (nullable, copy) NSString *name;

@property (readonly) NSString *path;

@property (nullable, copy) NSString *(^customFileNameBlock)(NSString *key);

#pragma mark - Limit
@property NSUInteger countLimit;
@property NSUInteger costLimit;
@property NSTimeInterval ageLimit;
@property NSUInteger freeDiskSpaceLimit;
@property NSTimeInterval autoTrimInterval;

@property BOOL errorLogsEnabled;

#pragma mark - Initializer
///=============================================================================
/// @name Initializer
///=============================================================================
- (instancetype)init UNAVAILABLE_ATTRIBUTE;
+ (instancetype)new UNAVAILABLE_ATTRIBUTE;

- (nullable instancetype)initWithPath:(NSString *)path;

#pragma mark - Access Methods
- (BOOL)containsFileForKey:(NSString *)key;
- (void)containsFileForKey:(NSString *)key withBlock:(void(^)(NSString *key, BOOL contains))block;

- (nullable NSString*)filePathForKey:(NSString *)key;
- (void)filePathForKey:(NSString *)key withBlock:(void(^)(NSString *key, NSString* _Nullable filePath))block;

- (void)addFile:(nullable NSString*)filePath forKey:(NSString *)key;
- (void)addFile:(nullable NSString*)filePath forKey:(NSString *)key withBlock:(void(^)(void))block;

- (void)deleteFileForKey:(NSString *)key;
- (void)deleteFileForKey:(NSString *)key withBlock:(void(^)(NSString *key))block;

- (void)clearAllFiles;
- (void)clearAllFilesWithBlock:(void(^)(void))block;

#pragma mark - statistics
- (NSInteger)totalCount;
- (void)totalCountWithBlock:(void(^)(NSInteger totalCount))block;

- (NSInteger)totalCost;
- (void)totalCostWithBlock:(void(^)(NSInteger totalCost))block;


#pragma mark - Trim
- (void)trimToCount:(NSUInteger)count;
- (void)trimToCount:(NSUInteger)count withBlock:(void(^)(void))block;

- (void)trimToCost:(NSUInteger)cost;
- (void)trimToCost:(NSUInteger)cost withBlock:(void(^)(void))block;

- (void)trimToAge:(NSTimeInterval)age;
- (void)trimToAge:(NSTimeInterval)age withBlock:(void(^)(void))block;


#pragma mark - Extended Data
+ (nullable NSString *)getExtFromFilePath:(NSString*)filePath;
+ (void)setExt:(nullable NSString *)ext toFilePath:(NSString*)filePath;

@end

NS_ASSUME_NONNULL_END
