//
//  IPNAlixPreSignUtil.h
//  iPaynowAlixSDKDemo
//
//  Created by 黄睿 on 2016/10/19.
//  Copyright © 2016年 ipaynow. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IPNCrossBorderPreSignUtil : NSObject

/**
 *  商户appId
 */
@property (nonatomic,strong) NSString *appId;

/**
 *  商户订单号
 */
@property (nonatomic,strong) NSString *mhtOrderNo;

/**
 *  商户商品名称
 */
@property (nonatomic,strong) NSString *mhtOrderName;

/**
 *  商户交易类型
 */
@property (nonatomic,strong) NSString *mhtOrderType;

/**
 *  商户订单币种类型
 */
@property (nonatomic,strong) NSString *mhtCurrencyType;

/**
 *  商户订单交易金额
 */
@property (nonatomic,strong) NSString *mhtOrderAmt;

/**
 *  商户订单详情
 */
@property (nonatomic,strong) NSString *mhtOrderDetail;

/**
 *  商户订单开始时间
 */
@property (nonatomic,strong) NSString *mhtOrderStartTime;

/**
 *  支付通知URL
 */
@property (nonatomic,strong) NSString *notifyUrl;


@property (nonatomic,strong) NSString *mhtAmtCurrFlag;

/**
 *  商户交易字符编码
 */
@property (nonatomic,strong) NSString *mhtCharset;
@property (nonatomic,strong) NSString *consumerId;
@property (nonatomic,strong) NSString *consumerName;
@property (nonatomic,strong) NSString *mhtSubAppId;


/**
 *  商户订单超时时间
 */
@property (nonatomic,strong) NSString *mhtOrderTimeOut;

/**
 *  商户保留域（商户可以自己定义其中内容）
 */
@property (nonatomic,strong) NSString *mhtReserved;

/**
 *  商户所选渠道类型
 */
@property (nonatomic,strong) NSString *payChannelType;


/**
 *  进行签名串的生成
 *
 *  @return 签名串
 */
- (NSString *)generatePresignMessage;


@end
