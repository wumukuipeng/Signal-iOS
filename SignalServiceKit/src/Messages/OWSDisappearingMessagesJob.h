//
//  Copyright (c) 2022 Open Whisper Systems. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

@class SDSAnyWriteTransaction;
@class SignalServiceAddress;
@class TSMessage;
@class TSThread;

@protocol ContactsManagerProtocol;

@interface OWSDisappearingMessagesJob : NSObject

- (instancetype)init NS_DESIGNATED_INITIALIZER;

- (void)startAnyExpirationForMessage:(TSMessage *)message
                 expirationStartedAt:(uint64_t)expirationStartedAt
                         transaction:(SDSAnyWriteTransaction *_Nonnull)transaction;

- (void)scheduleRunByTimestamp:(uint64_t)timestamp;

// Clean up any messages that expired since last launch immediately
// and continue cleaning in the background.
- (void)startIfNecessary;

- (void)cleanupMessagesWhichFailedToStartExpiringWithTransaction:(SDSAnyWriteTransaction *)transaction;
- (void)schedulePass;

#ifdef TESTABLE_BUILD
- (void)syncPassForTests;
#endif

@end

NS_ASSUME_NONNULL_END
