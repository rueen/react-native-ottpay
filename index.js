import { NativeModules, Platform } from 'react-native';

const { OttPay } = NativeModules;

OttPay.startPay = ({ payInfo, universalLink}) => {
  if(Platform.OS === 'android'){
    const options = {};
    const arr = payInfo.split('&');
    arr.forEach(item => {
      const _arr = item.split('=');
      options[_arr[0]] = (typeof(_arr[1]) === 'string' ? _arr[1] : _arr[1].toString());
    });
    OttPay.pay(options);
  } else {
    OttPay.pay(payInfo, universalLink);
  }
}

export default OttPay;