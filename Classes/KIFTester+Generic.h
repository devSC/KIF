//
//  KIFTester+Generic.h
//  KIF
//
//  Created by Brian Nickel on 12/14/12.
//  Licensed to Square, Inc. under one or more contributor license agreements.
//  See the LICENSE file distributed with this work for the terms under
//  which Square, Inc. licenses this file to you.

#import "KIFTestActor.h"

@interface KIFTestActor (Generic)

/*!
 @abstract Fails the test.
 @discussion Mostly useful for test debugging or as a placeholder when building new tests.
 */
- (void)fail;

/*!
 @abstract Waits for a certain amount of time before returning.
 @discussion In general when waiting for the app to get into a known state, it's better to use -waitForTappableViewWithAccessibilityLabel:, however this step may be useful in some situations as well.
 @param interval The number of seconds to wait before returning.
 */
- (void)waitForTimeInterval:(NSTimeInterval)timeInterval;

/*!
 @abstract Waits for a specific NSNotification.
 @discussion Useful when a test requires an asynchronous task to complete, especially when that task does not trigger a visible change in the view hierarchy.
 @param name The name of the NSNotification.
 @param object The object to which the step should listen. Nil value will listen to all objects.
 */
- (void)waitForNotificationName:(NSString*)name object:(id)object;

/*!
 @abstract Waits for a specific NSNotification, emitted during or after execution of a block.
 @discussion Useful when step execution causes a notification to be emitted, but executes too quickly for waitForNotificationName: to observe it.
 An observer will be registered for the notification before the block is executed.
 @param name The name of the NSNotification.
 @param object The object to which the step should listen. Nil value will listen to all objects.
 @param block The block of code to be executed.
 */
- (void)waitForNotificationName:(NSString *)name object:(id)object whileExecutingBlock:(void(^)())block;

/*!
 @abstract Simulates a memory warning.
 */
- (void)simulateMemoryWarning;

@end
