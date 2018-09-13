Pod::Spec.new do |s|

  s.name         = "TMTMediatorRouter"
  s.version      = "1.0.0"
  s.summary      = "TMTMediatorRouter."

  s.description  = <<-DESC
                    this is TMTMediatorRouter
                   DESC

  s.homepage     = "https://github.com/MrGCY/TMTMediatorRouter"

  s.license      = { :type => "MIT", :file => "FILE_LICENSE" }

  s.author       = "Mr.GCY"

  s.platform     = :ios, "8.0"

  #  When using multiple platforms
  # s.ios.deployment_target = "5.0"
  # s.osx.deployment_target = "10.7"
  # s.watchos.deployment_target = "2.0"
  # s.tvos.deployment_target = "9.0"

  s.source       = { :git => "https://github.com/MrGCY/TMTMediatorRouter.git", :tag => s.version.to_s }

  s.source_files  = "TMTMediatorRouter/TMTMediatorRouter/**/*.{h,m}"
  # s.exclude_files = "Classes/Exclude"

  # s.public_header_files = "Classes/**/*.h"

  # s.resources  = "TMTMediatorRouter/TMTMediatorRouter/**/*.{storyboard,xib}", "TMTMediatorRouter/Assets.xcassets"
  # s.resources = "Resources/*.png"

  # s.preserve_paths = "FilesToSave", "MoreFilesToSave"

  # s.framework  = "SomeFramework"
  # s.frameworks = "SomeFramework", "AnotherFramework"

  # s.library   = "iconv"
  # s.libraries = "iconv", "xml2"

  s.requires_arc = true

  # s.xcconfig = { "HEADER_SEARCH_PATHS" => "$(SDKROOT)/usr/include/libxml2" }
  # s.dependency "HLNetworking"
  # s.dependency "HLNetworking+Lovek12"
  # s.dependency "HLBaseUser"
  # s.dependency "Lothar"
  # s.dependency "UMengUShare/Social/Sina"
  # s.dependency "UMengUShare/Social/WeChat"
  # s.dependency "UMengUShare/Social/QQ""
end
