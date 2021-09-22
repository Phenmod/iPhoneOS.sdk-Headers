//
//  SHSignature.h
//  ShazamKit
//
//  Copyright © 2019 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ShazamKit/SHDefines.h>

NS_ASSUME_NONNULL_BEGIN

/// @brief The @c SHSignature class is an opaque data container that can be used to store recognition data.
/// @discussion Signatures are a compact lossy representation of the original audio. The original audio cannot
/// be recreated from a Signature, there exists only enough data to confirm that the signature matches a certain piece of audio
/// when it is also converted into a Signature. It is similar in utility to a hashing function.
///
/// Signatures can be matched against any type of audio not just music. The only requirement for a match is that the reference and query
/// Signatures both contain the exact same pre recorded audio e.g. a live rendition of a song will not match against a studio recorded performance
/// of the same piece.
///
/// There are exceptions to the requirement for exactly matching audio, a signature is robust against slight changes in frequency and speed.
///
SH_EXPORT API_AVAILABLE(macos(12.0), ios(15.0), tvos(15.0), watchos(8.0))
@interface SHSignature : NSObject <NSSecureCoding, NSCopying>

/// @brief The duration of the input audio that this signature is derived from
///
/// @discussion The duration may not match the source audio duration exactly, audio that contains portions of silence may
/// report shorter durations
@property(NS_NONATOMIC_IOSONLY, assign, readonly) NSTimeInterval duration;

/// The raw data that comprises this signature, this is not audio data
@property(NS_NONATOMIC_IOSONLY, strong, readonly) NSData *dataRepresentation;

/// Create a Signature from Signature data
/// @param dataRepresentation Signature data generated by Shazam, this is not raw audio data
/// @param error Error if the data was invalid
/// @return A signature if the data contained a valid signature, nil otherwise
+ (nullable SHSignature *)signatureWithDataRepresentation:(NSData *)dataRepresentation error:(NSError **)error;

/// Create a Signature from Signature data
/// @param dataRepresentation Signature data generated by Shazam, this is not raw audio data
/// @param error Error if the data was invalid
/// @return A signature if the data contained a valid signature, nil otherwise
- (nullable instancetype)initWithDataRepresentation:(NSData *)dataRepresentation error:(NSError **)error NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
