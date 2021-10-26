//
//  IPNAlixPluginDelegate.h
//  iPaynowAlixSDKDemo
//
//  Created by 黄睿 on 2016/10/19.
//  Copyright © 2016年 ipaynow. All rights reserved.
//

#import <Foundation/Foundation.h>

//        A00H    订单处理中
//        A00I    订单未处理
//        A001    订单支付成功
//        A002    订单支付失败
//        A003    支付结果未知
//        A004    订单受理成功
//        A005    订单受理失败

typedef NS_ENUM (NSInteger , IPNCrossBorderPayResult){
    IPNCrossBorderPayResultFail,      // 失败
    IPNCrossBorderPayResultSuccess,   // 成功
    IPNCrossBorderPayResultCancel,    // 取消
    IPNCrossBorderPayResultUnknown,   // 未知
};

@protocol IPNCrossBorderPluginDelegate <NSObject>

/**
 *  支付完成的回调
 *
 *  @param result   支付状态
 *  @param erroCode 错误代码
 *  @param erroInfo 错误信息
 */
- (void)iPNCrossBorderPluginResult:(IPNCrossBorderPayResult)result erroCode:(NSString *)erroCode erroInfo:(NSString *)erroInfo;

@end

