//
//  IPNAlixPluginAPi.h
//  iPaynowAlixSDKDemo
//
//  Created by 黄睿 on 2016/10/19.
//  Copyright © 2016年 ipaynow. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "IPNCrossBorderPluginDelegate.h"

@interface IPNCrossBorderPluginAPi : NSObject
/**
 *  设置导航栏颜色
 *
 *  @param color 颜色
 */
+ (void)setStemeColor:(UIColor *)color;

/**
 *  用户Apple Pay支付 （如不使用Apple Pay支付，可不写）
 *
 *  @param merchantID merchatID
 */
+ (void)setMerchantID:(NSString *)merchantID;


/**
 *  用户苹果应用内支付（如不使用应用内支付，可不写）
 *
 *  @param productID 产品ID
 *  @param quantity  数量
 *  @param orderNo   订单
 */
+ (void)setProductIdentifier:(NSString *)productID andQuantity:(NSInteger)quantity orderNo:(NSString *)orderNo;



/**
 *  是否在支付状态返回之前隐藏loading页面 （为防止用户重复支付不建议使用）
 *
 *  @param isHidden 是否隐藏
 */
+ (void)setBeforeReturnLoadingHidden:(BOOL)isHidden;



/**
 *  支付接口
 *
 *  @param data           参数组成的字符串
 *  @param scheme         scheme description
 *  @param viewController 所在的viewController
 *  @param delegate       接口返回代理
 *
 *  @return 是否成功
 */
+ (BOOL)pay:(NSString*)data AndScheme:(NSString*)scheme viewController:(UIViewController*)viewController delegate:(id<IPNCrossBorderPluginDelegate>)delegate universalLink:(NSString *)universalLink;


/**
 *  从第三方返回时调用，写于AppDelegate中openUrl方法中
 *
 *  @param application       application description
 *  @param url               url description
 *  @param sourceApplication sourceApplication description
 *  @param annotation        annotation description
 *
 *  @return return value description
 */
+ (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation;

+ (BOOL)application:(UIApplication *)app openURL:(NSURL *)url annotation:(id)annotation;

+ (BOOL)application:(UIApplication *)application continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void(^)(NSArray<id<UIUserActivityRestoring>> * __nullable restorableObjects))restorationHandler;

// 通过系统左上角返回app或者从后台进入app
+ (void)applicationDidBecomeActive;


/**
 *  启动app时候调用，用户微信、QQ支付
 */
+ (void)willEnterForeground;


//测试使用  发布删除
+ (void)setEnvironment:(NSInteger)environment;


@end
