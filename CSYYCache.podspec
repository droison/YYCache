Pod::Spec.new do |s|
  s.name         = 'CSYYCache'
  s.summary      = '个人针对YYCache的修改，主要处理大文件load到内存的问题，大文件只以地址的形式返回，源代码请参考 https://github.com/ibireme/YYCache'
  s.version      = '11.0.1'
  s.license      = { :type => 'MIT', :file => 'LICENSE' }
  s.authors      = { 'droison' => 'chaisong.cn@gmail.com' }
  s.social_media_url = 'http://www.chaisong.xyz'
  s.homepage     = 'https://github.com/droison/YYCache'
  s.platform     = :ios, '8.0'
  s.ios.deployment_target = '8.0'
  s.source       = { :git => 'https://github.com/droison/YYCache.git', :tag => s.version.to_s }
  
  s.requires_arc = true
  s.source_files = 'YYCache/*.{h,m}'
  s.public_header_files = 'YYCache/*.{h}'
  
  s.libraries = 'sqlite3'
  s.frameworks = 'UIKit', 'CoreFoundation', 'QuartzCore' 

end
