#
# Be sure to run `pod lib lint capturekit.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'capturekit'
  s.version          = '0.1.0'
  s.summary          = 'capturekit.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = "one"

  s.homepage         = 'https://github.com/Yyongnian/capturekit'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'Yyongnian' => 'yangyongnian@58.com' }
  s.source           = { :git => 'https://github.com/Yyongnian/capturekit.git', :tag => s.version.to_s }

  s.ios.deployment_target = '9.0'

  s.source_files = 'capturekit/Classes/**/*'
  s.frameworks = 'ARKit'
 # s.vendored_frameworks = 'VrAdapter.framework'
  s.requires_arc = true


end
