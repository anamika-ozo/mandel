import os, gettext, subprocess

schemadir = os.path.join(os.environ['MESON_INSTALL_PREFIX'], 'share', 'qt-5.0', 'schemas')

if not os.environ.get('DESTDIR'):
    print('Compiling schemas...')
    subprocess.call(['qt-compile-schemas', schemadir])

