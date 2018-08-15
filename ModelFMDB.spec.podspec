
Pod::Spec.new do |s|

  s.name         = "ModelFMDB"
  s.version      = "0.0.1"
  s.summary      = "基于FMDB的model对象数据库,直接操作model对象实现数据的缓存与读取,不用直接操作SQL语句!"
  s.homepage     = "https://github.com/xiaoshuainan/ModelFMDB"
  s.social_media_url   = "https://github.com/xiaoshuainan/ModelFMDB"
  s.ios.deployment_target = "8.0"
  s.license      = "MIT"
  # s.license      = { :type => "MIT", :file => "FILE_LICENSE" }
  
  s.author             = { "xsn" => "815758971@qq.com" }
  s.source       = { :git => "https://github.com/xiaoshuainan/ModelFMDB", :tag => s.version}
  s.requires_arc = true
  s.source_files  = "ModelFMDB/*"
 #s.public_header_files = 'ModelFMDB/XSNSqliteOperation.h'
  s.dependency 'FMDB/standard', '>= 2.3'

end