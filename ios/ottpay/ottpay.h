//
//  ottpay.h
//  ottpay
//
//  Created by ζηδΊ on 2021/9/18.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <React/RCTBridgeModule.h>
#import "IPNCrossBorderPluginDelegate.h"

@interface ottpay : NSObject<RCTBridgeModule, IPNCrossBorderPluginDelegate>

@end
