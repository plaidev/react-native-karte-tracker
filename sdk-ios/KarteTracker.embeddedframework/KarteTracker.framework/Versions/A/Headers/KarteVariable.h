//
//  Variables.h
//  KarteTracker
//
//  Created by rei.ishikawa on H30/08/20.
//

#import <Foundation/Foundation.h>


@interface KarteVariable : NSObject
@property (nonatomic, copy, nullable, readonly) NSString *campaignId;
@property (nonatomic, copy, nullable, readonly) NSString *shortenId;
@property (nonatomic, assign, readonly) BOOL isDefined;

@property (nonatomic, copy, readonly, nullable) NSString *string;
@property (nonatomic, copy, readonly, nullable) NSArray *array;
@property (nonatomic, copy, readonly, nullable) NSDictionary *dictionary;

- (nonnull NSString *)stringWithDefaultValue:(nonnull NSString *)defaultValue NS_SWIFT_NAME(string(defaultValue:));
- (NSInteger)integerWithDefaultValue:(NSInteger)defaultValue NS_SWIFT_NAME(integer(defaultValue:));
- (double)doubleWithDefaultValue:(double)defaultValue NS_SWIFT_NAME(double(defaultValue:));
- (BOOL)boolWithDefaultValue:(BOOL)defaultValue NS_SWIFT_NAME(boolean(defaultValue:));
- (nonnull NSArray *)arrayWithDefaultValue:(nonnull NSArray *)defaultValue NS_SWIFT_NAME(array(defaultValue:));
- (nonnull NSDictionary *)dictionaryWithDefaultValue:(nonnull NSDictionary *)defaultValue NS_SWIFT_NAME(dictionary(defaultValue:));
@end
