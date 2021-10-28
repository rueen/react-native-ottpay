//
//  ottpay.m
//  ottpay
//
//  Created by 李瑞云 on 2021/9/18.
//

#import "ottpay.h"
#import <React/RCTLog.h>
#import "IPNCrossBorderPluginDelegate.h"
#import "IPNCrossBorderPreSignUtil.h"
#import "IPNCrossBorderPluginAPi.h"

#define kNote             @"提示"
#define kConfirm          @"确定"

@implementation ottpay

- (dispatch_queue_t)methodQueue
{
    return dispatch_get_main_queue();
}
RCT_EXPORT_MODULE(OttPay);
RCT_EXPORT_METHOD(pay:(NSString *)payInfo
                  universalLink:(NSString *)universalLink)
{
//    RCTLogInfo(@"报文信息： %@", payInfo);
    
    UIViewController *rootViewController = [UIApplication sharedApplication].keyWindow.rootViewController;
    
    [IPNCrossBorderPluginAPi pay:payInfo AndScheme:@"IPaynowCrossBorderGatherPluginDemo" viewController:rootViewController delegate:self universalLink:universalLink];
    
}

#pragma mark - SDK的回调方法
- (void)iPNCrossBorderPluginResult:(IPNCrossBorderPayResult)result erroCode:(NSString *)erroCode erroInfo:(NSString *)erroInfo{
    
    NSString *resultString = @"";
    switch (result) {
        case IPNCrossBorderPayResultFail:
            resultString = [NSString stringWithFormat:@"支付失败:\r\n错误码:%@,异常信息:%@",erroCode, erroInfo];
            break;
        case IPNCrossBorderPayResultCancel:
            resultString = @"支付被取消";
            break;
        case IPNCrossBorderPayResultSuccess:
            resultString = @"支付成功";
            break;
        case  IPNCrossBorderPayResultUnknown:
            resultString = [NSString stringWithFormat:@"支付结果未知:%@",erroInfo];
        default:
            break;
    }
    
    UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:kNote
                                                        message:resultString
                                                       delegate:self
                                              cancelButtonTitle:kConfirm
                                              otherButtonTitles:nil];
    [alertView show];
}


- (void)dealloc
{
    
}

@end
