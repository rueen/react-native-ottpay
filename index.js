import { NativeModules, Platform } from 'react-native';

const { OttPay } = NativeModules;

OttPay.startPay = (str) => {
  if(Platform.OS === 'android'){
    const options = {};
    const arr = str.split('&');
    arr.forEach(item => {
      const _arr = item.split('=');
      options[_arr[0]] = _arr[1];
    });
    OttPay.pay(options);
  } else {
    OttPay.pay(str);
  }
}

export default OttPay;