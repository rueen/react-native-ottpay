# React Native OttPay

### Installation
```
yarn add react-native-ottpay
```
or
```
npm install react-native-ottpay --save
```

### Automatically Link
```
# RN < 0.60
react-native link react-native-ottpay
```

### Manual linking
<details>
<summary>Manually linking the library for iOS</summary>

#### `Open project.xcodeproj in Xcode`
Drag `ottpay.xcodeproj` to your project on Xcode
![xcode-add](https://raw.githubusercontent.com/rueen/react-native-ottpay/main/AddToLibraries.png)

#### Link `libottpay.a` binary with libraries
Click on your main project file (the one that represents the `.xcodeproj`). Add `libottpay.a` to your project's `Build Phases` ➜ `Link Binary With Libraries`
![xcode-link](https://raw.githubusercontent.com/rueen/react-native-ottpay/main/AddToBuildPhases.png)

</details>
<details>
<summary>Manually linking the library for Android</summary>

#### `android/settings.gradle`

```js
include ':react-native-ottpay'
project(':react-native-ottpay').projectDir = new File(rootProject.projectDir, '../node_modules/react-native-ottpay/android')
```

#### `android/app/build.gradle`

```js
dependencies {
   ...
   implementation project(':react-native-ottpay')
}
```

#### `android/app/src/main/.../MainApplication.java`

On top, where imports are:

```java
import com.ottpay.OttpayPackage;
```

Add the `OttpayPackage` class to your list of exported packages.

```java
@Override
protected List<ReactPackage> getPackages() {
    return Arrays.asList(
            new MainReactPackage(),
            new OttpayPackage()
    );
}
```
</details>

### iOS Setup
Select your project. Add the following System libraries to your project's `Build Phases` -> `Link Binary With Libraries`:
  - `QuartzCore.framework`
  - `CoreTelephony.framework`
  - `CoreText.framework`
  - `UIKit.framework`
  - `Foundation.framework`
  - `CoreGraphics.framework`
  - `CoreMotion.framework`
  - `CFNetwork.framework`
  - `SystemConfiguration.framework`
  - `libc++.tbd`
  - `libsqlite3.tbd`
  - `libz.tbd`

Then add the `AlipaySDK.framework`(under your `node_modules/react-native-ottpay/ios` folder) librarie to your project's `Build Phases` -> `Link Binary With Libraries`

If `framework not found AlipaySDK` please drag the folder `node_modules/react-native-ottpay/ios` to your project's `Build Setting` -> `Framework Search Paths`
  


### Use
```js
import OttPay from 'react-native-ottpay';

const payStr = 'appId=*******&mhtAmtCurrFlag=1&mhtCharset=UTF-8&mhtCurrencyType=USD&mhtOrderAmt=1&mhtOrderDetail=mhtOrderDetail&mhtOrderName=merchantTest&mhtOrderNo=20211026105613&mhtOrderStartTime=20211026105530&mhtOrderTimeOut=3600&mhtOrderType=01&notifyUrl=http%3A%2F%2Flocalhost%3A10802%2F&payChannelType=90&mhtSignType=MD5&mhtSignature=c0fbeceaf63331b60b908d0526fc3f82';

OttPay.startPay(payStr);
```

[海带跨境](https://cloud.seatent.com/)