package com.ottpay;

import android.app.Activity;
import android.widget.Toast;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import java.util.HashMap;
import java.util.Map;

import com.ipaynow.unionpay.plugin.api.CrossUnionPayPlugin;
import com.ipaynow.unionpay.plugin.conf.PluginConfig;
import com.ipaynow.unionpay.plugin.manager.route.dto.ResponseParams;
import com.ipaynow.unionpay.plugin.manager.route.impl.ReceivePayResult;
import com.ipaynow.unionpay.plugin.utils.PreSignMessageUtil;
import static com.facebook.react.bridge.UiThreadUtil.runOnUiThread;
import com.facebook.react.bridge.ReadableMap;

public class OttpayModule extends ReactContextBaseJavaModule implements ReceivePayResult {
  private static ReactApplicationContext reactContext;

  private static final String DURATION_SHORT_KEY = "SHORT";
  private static final String DURATION_LONG_KEY = "LONG";

    private PreSignMessageUtil preSign;

  public OttpayModule(ReactApplicationContext context) {
    super(context);
    reactContext = context;
  }

  @Override
  public String getName() {
    return "OttPay";
  }

  @Override
  public Map<String, Object> getConstants() {
    final Map<String, Object> constants = new HashMap<>();
    constants.put(DURATION_SHORT_KEY, Toast.LENGTH_SHORT);
    constants.put(DURATION_LONG_KEY, Toast.LENGTH_LONG);
    return constants;
  }

//    private static String preSignStr;

  @ReactMethod
  public void pay(ReadableMap options) {
    runOnUiThread(new Runnable() {
      public void run() {
        PluginConfig.configIpaynowEnv(PluginConfig.IpaynowEnv.ReleaseCn);
        preSign = new PreSignMessageUtil();

        preSign.appId=options.getString("appId");
        preSign.mhtAmtCurrFlag=options.getString("mhtAmtCurrFlag");
        preSign.mhtCharset=options.getString("mhtCharset");
        preSign.mhtCurrencyType=options.getString("mhtCurrencyType");
        preSign.mhtOrderAmt=options.getString("mhtOrderAmt");
        preSign.mhtOrderDetail=options.getString("mhtOrderDetail");
        preSign.mhtOrderName=options.getString("mhtOrderName");
        preSign.mhtOrderNo=options.getString("mhtOrderNo");
        preSign.mhtOrderStartTime=options.getString("mhtOrderStartTime");
        preSign.mhtOrderTimeOut=options.getString("mhtOrderTimeOut");
        preSign.mhtOrderType=options.getString("mhtOrderType");
        preSign.notifyUrl=options.getString("notifyUrl");
        preSign.payChannelType=options.getString("payChannelType");
        preSign.mhtSignature=options.getString("mhtSignature");
        
        // preSign.appId="1627353991468111";
        // preSign.mhtAmtCurrFlag="1";
        // preSign.mhtCharset="UTF-8";
        // preSign.mhtCurrencyType="USD";
        // preSign.mhtOrderAmt="100";
        // preSign.mhtOrderDetail="test";
        // preSign.mhtOrderName="鼠标";
        // preSign.mhtOrderNo="20211023162825";
        // preSign.mhtOrderStartTime="20211023162825";
        // preSign.mhtOrderTimeOut="3600";
        // preSign.mhtOrderType="01";
        // preSign.notifyUrl="http://localhost:10802/";
        // preSign.payChannelType="90";
        // preSign.mhtSignature="7b8afe9218e924791f38b95a1d6e23ed";

        Activity currentActivity = getCurrentActivity();
        CrossUnionPayPlugin.getInstance().setCallResultReceiver(OttpayModule.this).pay(preSign, currentActivity);// 传入请求数据
      };
    });
  }

  @Override
  public void onIpaynowTransResult(ResponseParams resp) {
      if (resp == null) {
          return;
      }
      String respCode = resp.respCode;
      String errorCode = resp.errorCode;
      String respMsg = resp.respMsg;
      StringBuilder temp = new StringBuilder();
      if (respCode.equals("00")) {
          temp.append("交易状态:成功");
      } else if (respCode.equals("02")) {
          temp.append("交易状态:取消");
      } else if (respCode.equals("01")) {
          temp.append("交易状态:失败").append("\n").append("错误码:").append(errorCode).append("原因:" + respMsg);
      } else if (respCode.equals("03")) {
          temp.append("交易状态:未知").append("\n").append("原因:" + respMsg);
      } else {
          temp.append("respCode=").append(respCode).append("\n").append("respMsg=").append(respMsg);
      }
      Toast.makeText(getReactApplicationContext(), temp.toString(), Toast.LENGTH_LONG).show();
  }
}