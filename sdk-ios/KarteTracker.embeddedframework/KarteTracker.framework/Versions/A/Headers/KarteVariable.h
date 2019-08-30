//
//  KarteVariable.h
//  KarteTracker
//
//  Copyright (c) 2018 PLAID inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@interface KarteVariable : NSObject
@property (nonatomic, copy, nullable, readonly) NSString *campaignId;
@property (nonatomic, copy, nullable, readonly) NSString *shortenId;
@property (nonatomic, assign, readonly) BOOL isDefined;

@property (nonatomic, copy, readonly, nullable) NSString *string;
@property (nonatomic, copy, readonly, nullable) NSArray *array;
@property (nonatomic, copy, readonly, nullable) NSDictionary *dictionary;

- (NSString *)stringWithDefaultValue:(NSString *)defaultValue NS_SWIFT_NAME(string(defaultValue:));
- (NSInteger)integerWithDefaultValue:(NSInteger)defaultValue NS_SWIFT_NAME(integer(defaultValue:));
- (double)doubleWithDefaultValue:(double)defaultValue NS_SWIFT_NAME(double(defaultValue:));
- (BOOL)boolWithDefaultValue:(BOOL)defaultValue NS_SWIFT_NAME(boolean(defaultValue:));
- (NSArray *)arrayWithDefaultValue:(NSArray *)defaultValue NS_SWIFT_NAME(array(defaultValue:));
- (NSDictionary *)dictionaryWithDefaultValue:(NSDictionary *)defaultValue NS_SWIFT_NAME(dictionary(defaultValue:));
@end

NS_ASSUME_NONNULL_END
