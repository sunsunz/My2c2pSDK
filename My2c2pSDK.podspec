#
#  Be sure to run `pod spec lint my2c2pSDK.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see http://docs.cocoapods.org/specification.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|
  s.version         = "3.1.0"
  s.name            = "my2c2pSDK"
  s.summary         = "2c2p Payment System for iOS"
  s.description     = <<-DESC
                    2c2p payment system for iOS native.
                    DESC


  s.homepage        = 'https://s.2c2p.com/Manuals/ios/index.html'
  s.license         = { :type => "MIT" }
  s.author          = { "Chatchawal Saesee" => "chatchawal@2c2p.com" }
  s.platform        = :ios, "8.0"

  # s.source          = { :git => "https://bitbucket.org/2c2p/my2c2p_ios_sdk_public.git", :tag => s.version }
  s.source          = { :git => "https://github.com/sunsunz/My2c2pSDK.git", :tag => s.version }
  s.source_files    = "My2c2pSDK/My2c2pSDK/my2c2pSDK.framework/Headers/*.h"
  s.resource        = "My2c2pSDK/My2c2pSDK/my2c2pResources.bundle"
  s.preserve_paths  = "My2c2pSDK/My2c2pSDK/my2c2pSDK.framework" , "my2c2pSDK/my2c2p/my2c2pResources.bundle"
  s.framework       = "QuartzCore" , "Security" , "PassKit"
  s.library         = "z"
  s.requires_arc    = true
  s.xcconfig        = { "OTHER_LDFLAGS" => "-ObjC -lstdc++" }
  s.ios.vendored_frameworks = "My2c2pSDK/My2c2pSDK/my2c2pSDK.framework"
end
