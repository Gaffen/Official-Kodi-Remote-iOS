/*
 This module is licenced under the BSD license.
 
 Copyright (C) 2011 by raw engineering <nikhil.jain (at) raweng (dot) com, reefaq.mohammed (at) raweng (dot) com>.
 
 All rights reserved.
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions
 are met:
 
 * Redistributions of source code must retain the above copyright
 notice, this list of conditions and the following disclaimer.
 
 * Redistributions in binary form must reproduce the above copyright
 notice, this list of conditions and the following disclaimer in the
 documentation and/or other materials provided with the distribution.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
//
//  StackScrollViewController.h
//  StackScrollView
//
//  Created by Reefaq Mohammed Mac Pro on 5/10/11.
//  Copyright 2011 raw engineering. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface StackScrollViewController : UIViewController <UIScrollViewDelegate, UIGestureRecognizerDelegate> {
	
	UIView* slideViews;
	UIView* borderViews;
	
	UIView* viewAtLeft;
	UIView* viewAtRight;
	UIView* viewAtLeft2;
	UIView* viewAtRight2;	
	UIView* viewAtRightAtTouchBegan;
	UIView* viewAtLeftAtTouchBegan;
	
	NSMutableArray* viewControllersStack;
	
	NSString* dragDirection;
	
	CGFloat viewXPosition;		
	CGFloat displacementPosition;
	CGFloat lastTouchPoint;
	CGFloat slideStartPosition;
	
	CGPoint positionOfViewAtRightAtTouchBegan;
	CGPoint positionOfViewAtLeftAtTouchBegan;
    
    CGRect originalFrame;
    BOOL stackScrollIsFullscreen;
    
    UIView *fullscreenView;
    BOOL hideToolbar;
    
    CGFloat bottomPadding;
}

- (void)offView;
- (void)enablePanGestureRecognizer;
- (void)disablePanGestureRecognizer:(UIView*)fallbackView;
- (void)addViewInSlider:(UIViewController*)controller invokeByController:(UIViewController*)invokeByController isStackStartView:(BOOL)isStackStartView;
- (void)bounceBack:(NSString*)animationID finished:(NSNumber*)finished context:(void*)context;

@property (nonatomic, strong) UIView *slideViews;
@property (nonatomic, strong) UIView *borderViews;
@property (nonatomic, assign) CGFloat slideStartPosition;
@property (nonatomic, strong) NSMutableArray *viewControllersStack;



@end
