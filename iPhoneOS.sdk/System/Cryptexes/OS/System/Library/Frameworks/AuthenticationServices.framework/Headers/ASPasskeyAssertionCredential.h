//
//  ASPasskeyAssertionCredential.h
//  AuthenticationServices Framework
//
//  Copyright © 2022 Apple Inc. All rights reserved.
//

#import <AuthenticationServices/ASAuthorizationCredential.h>
#import <AuthenticationServices/ASFoundation.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*! @class This class encapsulates a passkey assertion response created by a credential provider extension.
 */
AS_EXTERN API_AVAILABLE(ios(17.0), macos(14.0)) API_UNAVAILABLE(tvos, watchos)
@interface ASPasskeyAssertionCredential : NSObject <ASAuthorizationCredential>

/*! @abstract Initializes an ASPasskeyCredential object.
 @param userHandle The identifier for the account the passkey is associated with.
 @param relyingParty the relying party.
 @param signature the signature for the assertion challenge.
 */
- (instancetype)initWithUserHandle:(NSData *)userHandle relyingParty:(NSString *)relyingParty signature:(NSData *)signature clientDataHash:(NSData *)clientDataHash authenticatorData:(NSData *)authenticatorData credentialID:(NSData *)credentialID;

/*! @abstract Creates and initializes a new ASPasskeyCredential object.
 @param userHandle The identifier for the account the passkey is associated with.
 @param relyingParty the relying party.
 @param signature the signature for the assertion challenge.
 */
+ (instancetype)credentialWithUserHandle:(NSData *)userHandle relyingParty:(NSString *)relyingParty signature:(NSData *)signature clientDataHash:(NSData *)clientDataHash authenticatorData:(NSData *)authenticatorData credentialID:(NSData *)credentialID;

/*! @abstract The user handle of this passkey.
 */
@property (nonatomic, copy, readonly) NSData *userHandle;

/*! @abstract The relying party of this credential.
 */
@property (nonatomic, copy, readonly) NSString *relyingParty;

/*! @abstract The signature of this credential.
 */
@property (nonatomic, copy, readonly) NSData *signature;

/*! @abstract The hash of the client data for this assertion result.
 */
@property (nonatomic, copy, readonly) NSData *clientDataHash;

/*! @abstract The authenticator data of the application that created this credential.
 */
@property (nonatomic, copy, readonly) NSData *authenticatorData;

/*! @abstract The raw credential ID for this passkey credential.
 */
@property (nonatomic, copy, readonly) NSData *credentialID;

@end

NS_ASSUME_NONNULL_END
