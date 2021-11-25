#
#  Be sure to run `pod spec lint RNOttpay.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

require 'json'

package = JSON.parse(File.read(File.join(__dir__, 'package.json')))

Pod::Spec.new do |spec|

  spec.name         = "RNOttpay"
  spec.version      = package['version'].gsub(/v|-beta/, '')
  spec.summary      = package['description']

  spec.homepage     = "https://github.com/rueen/react-native-ottpay"
  spec.platforms    = { :ios => "9.0" }
  spec.license      = "MIT"

  spec.author       = { "rueen" => "rueenli@gmail.com" }

  spec.source       = { :git => "https://github.com/rueen/react-native-ottpay.git", :tag => "#{spec.version}" }

  spec.source_files  = "ios", "ios/ottpay/*.{h,m}", "ios/*.{h,m}", "*.{h,m}"
  # spec.exclude_files = "Classes/Exclude"

  spec.dependency "React"
  spec.resources = ['ios/AlipaySDK.bundle', 'ios/AlipaySDK.framework']
  spec.vendored_libraries = "ios/libipaynowCrossBorderPlugin.a"
  spec.ios.frameworks = 'QuartzCore','CoreTelephony','CoreText','UIKit','Foundation','CoreGraphics','CoreMotion','CFNetwork','SystemConfiguration'
  spec.ios.library = 'c++','sqlite3','z'

end
