//
//  AlipaySDK.h
//  AlipaySDK
//
//  Created by 方彬 on 14-4-28.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//


////////////////////////////////////////////////////////
////////////////version:2.1  motify:2014.12.24//////////
///////////////////Merry Christmas=。=//////////////////
////////////////////////////////////////////////////////


#import "APayAuthInfo.h"
typedef enum {
    ALIPAY_TIDFACTOR_IMEI,
    ALIPAY_TIDFACTOR_IMSI,
    ALIPAY_TIDFACTOR_TID,
    ALIPAY_TIDFACTOR_CLIENTKEY,
    ALIPAY_TIDFACTOR_VIMEI,
    ALIPAY_TIDFACTOR_VIMSI,
    ALIPAY_TIDFACTOR_CLIENTID,
    ALIPAY_TIDFACTOR_APDID,
    ALIPAY_TIDFACTOR_MAX
} AlipayTidFactor;

typedef void(^CompletionBlock)(NSDictionary *resultDic);

@interface AlipaySDK : NSObject

/**
 *  创建支付单例服务
 *  the service to create singleton Service of payment
 *
 *  @return 返回单例对象
 */
+ (AlipaySDK *)defaultService;

/**
 *  用于设置SDK使用的window，如果没有自行创建window无需设置此接口
 *  Used to set the window for SDK,not necessary if no window created
 */
@property (nonatomic, weak) UIWindow *targetWindow;

/**
 *  支付接口
 *  payment interface
 *
 *  @param orderStr       订单信息order info
 *  @param schemeStr      调用支付的app注册在info.plist中的scheme  call the scheme registered in info.plist by app
 *  @param compltionBlock 支付结果回调Block，用于wap支付结果回调（非跳转钱包支付）Block the payment result callback,used in wap payment result callback(not pay via Alipay wallet app)
 */
- (void)payOrder:(NSString *)orderStr
      fromScheme:(NSString *)schemeStr
        callback:(CompletionBlock)completionBlock;

/**
 *  处理钱包或者独立快捷app支付跳回商户app携带的支付结果Url
 *  deal with returned Url when the Alipay wallet redirected to merchant's app
 *
 *  @param resultUrl        支付结果url return url
 *  @param completionBlock  支付结果回调 return callback
 */
- (void)processOrderWithPaymentResult:(NSURL *)resultUrl
                      standbyCallback:(CompletionBlock)completionBlock;



/**
 *  获取交易token。
 *  get the token
 *
 *  @return 交易token，若无则为空。
 */
- (NSString *)fetchTradeToken;

/**
 *  是否已经使用过
 *  when has been used
 *
 *  @return YES为已经使用过，NO反之
 */
- (BOOL)isLogined;

/**
 *  当前版本号
 * the current version
 *
 *  @return 当前版本字符串
 */
- (NSString *)currentVersion;

/**
 *  当前版本号
 * the current version
 *
 *  @return tid相关信息
 */
- (NSString*)queryTidFactor:(AlipayTidFactor)factor;

/**
 *  測試所用，realse包无效
 *  used on test ,invalid for release 
 *
 *  @param url  测试环境
 */
- (void)setUrl:(NSString *)url;


//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////h5 拦截支付入口Intercept payment entry///////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

/**
 *  url order 获取接口get the interface
 *
 *  @param urlStr     拦截的 url string
 *
 *  @return 获取到的url order info
 */
- (NSString*)fetchOrderInfoFromH5PayUrl:(NSString*)urlStr;


/**
 *  url支付接口url payment interface
 *
 *  @param orderStr       订单信息order info
 *  @param schemeStr      调用支付的app注册在info.plist中的scheme call the scheme registered in info.plist by app
 *  @param compltionBlock 支付结果回调Block Block the payment result callback
 */
- (void)payUrlOrder:(NSString *)orderStr
         fromScheme:(NSString *)schemeStr
           callback:(CompletionBlock)completionBlock;


//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////授权1.0 authorize1.0//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

/**
 *  快登授权
 *  @param authInfo         需授权信息Authorization information
 *  @param completionBlock  授权结果回调，若在授权过程中，调用方应用被系统终止，则此block无效，
                            需要调用方在appDelegate中调用processAuthResult:standbyCallback:方法获取授权结果
 * The authorization result callback, the block is invalid if the caller application is terminated by the system during the authorization process
 * It's necessary for the caller to call the method processAuthResult:standbyCallback: in appDelegate to get the authorization result
 */
- (void)authWithInfo:(APayAuthInfo *)authInfo
             callback:(CompletionBlock)completionBlock;


/**
 *  处理授权信息Url
 * deal with the authorization information url
 *
 *  @param resultUrl        钱包返回的授权结果url  The authorization result url return by Alipay wallet
 *  @param completionBlock  授权结果回调 Authorization result callback
 */
- (void)processAuthResult:(NSURL *)resultUrl
          standbyCallback:(CompletionBlock)completionBlock;

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////授权2.0 authorize2.0//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

/**
 *  快登授权2.0 
 *
 *  @param infoStr          授权请求信息字符串 string of authorization request information
 *  @param schemeStr        调用授权的app注册在info.plist中的scheme  scheme call the scheme registered in info.plist 
 *  @param completionBlock  授权结果回调，若在授权过程中，调用方应用被系统终止，则此block无效，
                            需要调用方在appDelegate中调用processAuth_V2Result:standbyCallback:方法获取授权结果
* The authorization result callback, the block is invalid if the caller application is terminated by the system during the authorization process
* It's necessary for the caller to call the method processAuth_V2Result:standbyCallback: in appDelegate to get the authorization result
 */
- (void)auth_V2WithInfo:(NSString *)infoStr
             fromScheme:(NSString *)schemeStr
               callback:(CompletionBlock)completionBlock;

/**
 *  处理授权信息Url
 *
 *  @param resultUrl        钱包返回的授权结果url  The authorization result url return by Alipay wallet
 *  @param completionBlock  授权结果回调 Authorization result callback
 */
- (void)processAuth_V2Result:(NSURL *)resultUrl
             standbyCallback:(CompletionBlock)completionBlock;

@end
