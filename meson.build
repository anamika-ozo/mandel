project('mandel', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++14'])

exe = executable('index', 'src/index.cpp',
  install : false)

test('basic', exe)

meson.add_install_script('meson/linux_bundler.sh')
