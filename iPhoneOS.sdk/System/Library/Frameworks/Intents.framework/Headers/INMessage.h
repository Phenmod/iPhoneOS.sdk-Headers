//
//  INMessage.h
//  Intents
//
//  Copyright (c) 2016-2020 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@class INPerson;
@class INSpeakableString;
@class INFile;
@class INMessageLinkMetadata;
@class INMessageReaction;
@class INSticker;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, INMessageType) {
    INMessageTypeUnspecified = 0,
    INMessageTypeText,
    INMessageTypeAudio,
    INMessageTypeDigitalTouch,
    INMessageTypeHandwriting,
    INMessageTypeSticker,
    INMessageTypeTapbackLiked,
    INMessageTypeTapbackDisliked,
    INMessageTypeTapbackEmphasized,
    INMessageTypeTapbackLoved,
    INMessageTypeTapbackQuestioned,
    INMessageTypeTapbackLaughed,
    INMessageTypeMediaCalendar,
    INMessageTypeMediaLocation,
    INMessageTypeMediaAddressCard,
    INMessageTypeMediaImage,
    INMessageTypeMediaVideo,
    INMessageTypeMediaPass,
    INMessageTypeMediaAudio,
    INMessageTypePaymentSent API_AVAILABLE(ios(12.0), watchos(5.0)) API_UNAVAILABLE(macosx),
    INMessageTypePaymentRequest API_AVAILABLE(ios(12.0), watchos(5.0)) API_UNAVAILABLE(macosx),
    INMessageTypePaymentNote API_AVAILABLE(ios(12.0), watchos(5.0)) API_UNAVAILABLE(macosx),
    INMessageTypeAnimoji API_AVAILABLE(ios(12.0), watchos(5.0)) API_UNAVAILABLE(macosx),
    INMessageTypeActivitySnippet API_AVAILABLE(ios(12.0), watchos(5.0)) API_UNAVAILABLE(macosx),
    INMessageTypeFile API_AVAILABLE(ios(12.0), watchos(5.0)) API_UNAVAILABLE(macosx),
    INMessageTypeLink API_AVAILABLE(ios(12.0), watchos(5.0)) API_UNAVAILABLE(macosx),
    INMessageTypeReaction API_AVAILABLE(ios(17.0), watchos(10.0)) API_UNAVAILABLE(macosx),
    INMessageTypeMediaAnimatedImage API_AVAILABLE(ios(18.0), watchos(11.0)) API_UNAVAILABLE(macosx),
    INMessageTypeThirdPartyAttachment API_AVAILABLE(ios(18.0), watchos(11.0)) API_UNAVAILABLE(macosx),
} API_AVAILABLE(ios(11.0), watchos(4.0)) API_UNAVAILABLE(macosx, tvos);

API_AVAILABLE(ios(10.0), watchos(3.2))
API_UNAVAILABLE(macosx, tvos)
@interface INMessage : NSObject <NSCopying, NSSecureCoding>

- (id)init NS_UNAVAILABLE;

- (instancetype)initWithIdentifier:(NSString *)identifier
            conversationIdentifier:(nullable NSString *)conversationIdentifier
                           content:(nullable NSString *)content
                          dateSent:(nullable NSDate *)dateSent
                            sender:(nullable INPerson *)sender
                        recipients:(nullable NSArray<INPerson *> *)recipients
                         groupName:(nullable INSpeakableString *)groupName
                       messageType:(INMessageType)messageType
                       serviceName:(nullable NSString *)serviceName
                   attachmentFiles:(nullable NSArray<INFile *> *)attachmentFiles API_AVAILABLE(ios(17.0), watchos(10.0)) API_UNAVAILABLE(macos);

- (instancetype)initWithIdentifier:(NSString *)identifier
            conversationIdentifier:(nullable NSString *)conversationIdentifier
                           content:(nullable NSString *)content
                          dateSent:(nullable NSDate *)dateSent
                            sender:(nullable INPerson *)sender
                        recipients:(nullable NSArray<INPerson *> *)recipients
                         groupName:(nullable INSpeakableString *)groupName
                       messageType:(INMessageType)messageType
                       serviceName:(nullable NSString *)serviceName
                  audioMessageFile:(nullable INFile *)audioMessageFile API_DEPRECATED("Use initializer with attachmentFile", ios(16.0, 17.0), macos(13.0, 14.0), watchos(9.0, 10.0))  API_UNAVAILABLE(ios, macos, watchos);

- (instancetype)initWithIdentifier:(NSString *)identifier
            conversationIdentifier:(nullable NSString *)conversationIdentifier
                           content:(nullable NSString *)content
                          dateSent:(nullable NSDate *)dateSent
                            sender:(nullable INPerson *)sender
                        recipients:(nullable NSArray<INPerson *> *)recipients
                         groupName:(nullable INSpeakableString *)groupName
                       messageType:(INMessageType)messageType
                       serviceName:(nullable NSString *)serviceName NS_DESIGNATED_INITIALIZER API_AVAILABLE(ios(13.2), watchos(6.1)) API_UNAVAILABLE(macosx);

- (instancetype)initWithIdentifier:(NSString *)identifier
            conversationIdentifier:(nullable NSString *)conversationIdentifier
                           content:(nullable NSString *)content
                          dateSent:(nullable NSDate *)dateSent
                            sender:(nullable INPerson *)sender
                        recipients:(nullable NSArray<INPerson *> *)recipients
                         groupName:(nullable INSpeakableString *)groupName
messageType:(INMessageType)messageType API_DEPRECATED("Use initializer with reaction", ios(17.0, 18.0), macos(14.0, 15.0), watchos(10.0, 11.0))  API_UNAVAILABLE(ios, macos, watchos);

- (instancetype)initWithIdentifier:(NSString *)identifier
            conversationIdentifier:(nullable NSString *)conversationIdentifier
                           content:(nullable NSString *)content
                          dateSent:(nullable NSDate *)dateSent
                            sender:(nullable INPerson *)sender
                        recipients:(nullable NSArray<INPerson *> *)recipients
                       messageType:(INMessageType)messageType API_DEPRECATED("Use initializer with reaction", ios(17.0, 18.0), macos(14.0, 15.0), watchos(10.0, 11.0))  API_UNAVAILABLE(ios, macos, watchos);

- (instancetype)initWithIdentifier:(NSString *)identifier
                           content:(nullable NSString *)content
                          dateSent:(nullable NSDate *)dateSent
                            sender:(nullable INPerson *)sender
                        recipients:(nullable NSArray<INPerson *> *)recipients;

- (instancetype)initWithIdentifier:(NSString *)identifier
            conversationIdentifier:(nullable NSString *)conversationIdentifier
                           content:(nullable NSString *)content
                          dateSent:(nullable NSDate *)dateSent
                            sender:(nullable INPerson *)sender
                        recipients:(nullable NSArray<INPerson *> *)recipients
                         groupName:(nullable INSpeakableString *)groupName
                       serviceName:(nullable NSString *)serviceName
                      linkMetadata:(nullable INMessageLinkMetadata *)linkMetadata API_AVAILABLE(ios(17.0), watchos(10.0)) API_UNAVAILABLE(macos);

- (instancetype)initWithIdentifier:(NSString *)identifier
            conversationIdentifier:(nullable NSString *)conversationIdentifier
                           content:(nullable NSString *)content
                          dateSent:(nullable NSDate *)dateSent
                            sender:(nullable INPerson *)sender
                        recipients:(nullable NSArray<INPerson *> *)recipients
                         groupName:(nullable INSpeakableString *)groupName
                       serviceName:(nullable NSString *)serviceName
                       messageType:(INMessageType)messageType
               numberOfAttachments:(nullable NSNumber *)numberOfAttachments API_AVAILABLE(ios(17.0), watchos(10.0)) API_UNAVAILABLE(macos);

- (instancetype)initWithIdentifier:(NSString *)identifier
            conversationIdentifier:(nullable NSString *)conversationIdentifier
                           content:(nullable NSString *)content
                          dateSent:(nullable NSDate *)dateSent
                            sender:(nullable INPerson *)sender
                        recipients:(nullable NSArray<INPerson *> *)recipients
                         groupName:(nullable INSpeakableString *)groupName
                       serviceName:(nullable NSString *)serviceName
                       messageType:(INMessageType)messageType
                 referencedMessage:(nullable INMessage *)referencedMessage
                          reaction:(nullable INMessageReaction *)reaction API_AVAILABLE(ios(18.0), watchos(11.0)) API_UNAVAILABLE(macos);

- (instancetype)initWithIdentifier:(NSString *)identifier
            conversationIdentifier:(nullable NSString *)conversationIdentifier
                           content:(nullable NSString *)content
                          dateSent:(nullable NSDate *)dateSent
                            sender:(nullable INPerson *)sender
                        recipients:(nullable NSArray<INPerson *> *)recipients
                         groupName:(nullable INSpeakableString *)groupName
                       serviceName:(nullable NSString *)serviceName
                       messageType:(INMessageType)messageType
                 referencedMessage:(nullable INMessage *)referencedMessage
                           sticker:(nullable INSticker *)sticker
                          reaction:(nullable INMessageReaction *)reaction NS_DESIGNATED_INITIALIZER API_AVAILABLE(ios(18.0), watchos(11.0)) API_UNAVAILABLE(macos);

@property (readonly, copy, NS_NONATOMIC_IOSONLY) NSString *identifier;

@property (readonly, copy, nullable, NS_NONATOMIC_IOSONLY) NSString *conversationIdentifier API_AVAILABLE(ios(11.0), watchos(4.0)) API_UNAVAILABLE(macosx);

@property (readonly, copy, nullable, NS_NONATOMIC_IOSONLY) NSString *content;

@property (readonly, copy, nullable, NS_NONATOMIC_IOSONLY) NSDate *dateSent;

@property (readonly, copy, nullable, NS_NONATOMIC_IOSONLY) INPerson *sender;

@property (readonly, copy, nullable, NS_NONATOMIC_IOSONLY) NSArray<INPerson *> *recipients;

@property (readonly, copy, nullable, NS_NONATOMIC_IOSONLY) INSpeakableString *groupName API_AVAILABLE(ios(11.0), watchos(4.0)) API_UNAVAILABLE(macosx);

@property (readonly, NS_NONATOMIC_IOSONLY) INMessageType messageType API_AVAILABLE(ios(11.0), watchos(4.0)) API_UNAVAILABLE(macosx);

@property (readonly, copy, nullable, NS_NONATOMIC_IOSONLY) NSString *serviceName API_AVAILABLE(ios(13.2), watchos(6.1)) API_UNAVAILABLE(macosx);

@property (readonly, copy, nullable, NS_NONATOMIC_IOSONLY)  NSArray<INFile *> *attachmentFiles API_AVAILABLE(ios(17.0), watchos(10.0)) API_UNAVAILABLE(macosx);

@property (readonly, copy, nullable, NS_NONATOMIC_IOSONLY) NSNumber *numberOfAttachments API_AVAILABLE(ios(17.0), watchos(10.0)) API_UNAVAILABLE(macosx);

@property (readonly, copy, nullable, NS_NONATOMIC_IOSONLY) INFile *audioMessageFile API_DEPRECATED("Use attachmentFile instead", ios(16.0, 17.0), macos(13.0, 14.0), watchos(9.0, 10.0));

@property (readonly, copy, nullable, NS_NONATOMIC_IOSONLY) INMessageLinkMetadata *linkMetadata API_AVAILABLE(ios(17.0), watchos(10.0)) API_UNAVAILABLE(macosx);

@property (readwrite, copy, nullable, NS_NONATOMIC_IOSONLY) INSticker *sticker API_AVAILABLE(ios(18.0), watchos(11.0), macosx(15.0));

@property (readwrite, copy, nullable, NS_NONATOMIC_IOSONLY) INMessageReaction *reaction API_AVAILABLE(ios(18.0), watchos(11.0)) API_UNAVAILABLE(macosx);

@end

NS_ASSUME_NONNULL_END
