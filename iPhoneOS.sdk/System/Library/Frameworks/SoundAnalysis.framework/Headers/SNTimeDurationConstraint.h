//
//  SNTimeDurationConstraint.h
//  SoundAnalysis
//
//  Copyright © 2020 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreMedia/CoreMedia.h>
#import <SoundAnalysis/SNDefines.h>

NS_ASSUME_NONNULL_BEGIN

/// Enumerates possible types for `SNTimeDurationConstraint`.
typedef NS_ENUM(NSInteger, SNTimeDurationConstraintType) {
    /// An 'enumerated' constraint type.
    ///
    /// In order for a duration to satisfy a constraint of this type, it must be a member of a particular set of discrete permissible values.
	SNTimeDurationConstraintTypeEnumerated = 1,

    /// A 'range' constraint type.
    ///
    /// In order for a duration to satisfy a constraint of this type, it must be a member of a particular continuous range of permissible values.
	SNTimeDurationConstraintTypeRange = 2,
} NS_REFINED_FOR_SWIFT API_AVAILABLE(macos(12.0), ios(15.0), tvos(15.0), watchos(8.0), visionos(1.0));

/// Constrains CMTime durations to a subset of legal values.
///
/// `SNTimeDurationConstraint` is a union type, which, based on the value of its `type` property, may assume one of several forms. Instance properties may be used to extract information from an object, but certain properties are only valid to exercise under certain circumstances. Before accessing a particular property, refer to its documentation to understand what `type` value is required in order for that property to be valid.
SN_EXPORT NS_REFINED_FOR_SWIFT API_AVAILABLE(macos(12.0), ios(15.0), tvos(15.0), watchos(8.0), visionos(1.0))
@interface SNTimeDurationConstraint : NSObject

/// The time constraint type.
///
/// The value of this property dictates whether or not other properties associated with this class can be validly accessed. Please refer to the documentation of other individual properties to understand their relationship to this one. This property is always valid to access.
@property (readonly, assign) SNTimeDurationConstraintType type;

/// If the constraint type is enumerated, then the set of discrete allowable time durations.
///
/// - Returns: If the constraint type is enumerated, an array of CMTime structures (boxed in NSValue instances) representing the set of allowable time durations. The durations will always be provided sorted in order of ascending time. If the constraint type is not enumerated, an empty array will be returned.
///
/// The `type` property should be queried before this property is accessed. This property will only yield meaningful values if the constraint type is considered to be 'enumerated'. The constraint type is considered to be 'enumerated' if the `type` property is equal to `SNTimeDurationConstraintTypeEnumerated`.
@property (readonly, strong) NSArray<NSValue *> *enumeratedDurations;

/// If the constraint type is range, then the range of allowable window durations.
///
/// - Returns: If the constraint type is range, a CMTimeRange representing the range of allowable window durations. If the constraint type is not range, `kCMTimeRangeInvalid`.
///
/// The `type` property should be queried before this property is accessed. This property will only yield meaningful values if the constraint type is considered to be 'range'. The constraint type is considered to be 'range' if the `type` property is equal to `SNTimeDurationConstraintTypeRange`.
@property (readonly, assign) CMTimeRange durationRange;

/// Initializes an enumerated-type constraint.
///
/// - Parameter enumeratedDurations: A discrete set of duration values (represented as CMTime values boxed in NSValue instances) permitted by this constraint.
///
/// - Returns: An instance whose `type` is `SNTimeDurationConstraintTypeEnumerated`, and which constrains duration values to the provided set of discrete values.
- (instancetype)initWithEnumeratedDurations:(NSArray<NSValue *> *)enumeratedDurations;

/// Initializes a range-type constraint.
///
/// - Parameter durationRange: A continuous range of duration values (represented as CMTime values) permitted by this constraint.
///
/// - Returns: An instance whose `type` is `SNTimeDurationConstraintTypeRange`, and which constrains durations values to the provided range.
- (instancetype)initWithDurationRange:(CMTimeRange)durationRange;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
