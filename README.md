# grub-customizer-linux-mint


Creando el paquete deb de grub-customizer para mi primo Paco para Linux Mint 21 Vanessa

archivos necesarios:

https://launchpad.net/~danielrichter2007/+archive/ubuntu/grub-customizer

https://launchpad.net/~danielrichter2007/+archive/ubuntu/grub-customizer/+packages

https://launchpad.net/~danielrichter2007/+archive/ubuntu/grub-customizer/+sourcefiles/grub-customizer/5.2.3-0ubuntu1~ppa2l/grub-customizer_5.2.3.orig.tar.gz

https://launchpad.net/~danielrichter2007/+archive/ubuntu/grub-customizer/+sourcefiles/grub-customizer/5.2.3-0ubuntu1~ppa2l/grub-customizer_5.2.3-0ubuntu1~ppa2l.debian.tar.xz

descargo los dos tar, descomprimo:

grub-customizer_5.2.3.orig.tar.gz

y dentro de esa carpeta:

/grub-customizer_5.2.3

pongo la carpeta:

/debian

del otro paquete.

Instalo las dependencais:

$ sudo apt install debhelper cmake gcc libgtkmm-3.0-dev gettext libssl-dev libarchive-dev

Modifico el archivo:

control, y lo dejo así:

++++++++++++++++++++++++++++++++++++++++

Source: grub-customizer
Section: admin
Priority: optional
Maintainer: Washington Indacochea Delgado <wachin.id@gmail.com>
XSBC-Original-Maintainer: Daniel Richter <danielrichter2007@web.de>
Build-Depends: debhelper, libgtkmm-3.0-dev (>= 3.24.5), libssl-dev, cmake (>=3.22.1), gettext (>=0.21), libarchive-dev
Standards-Version: 5.2.3
Homepage: https://launchpad.net/grub-customizer

Package: grub-customizer
Architecture: any
Depends: ${shlibs:Depends}, ${misc:Depends}, policykit-1
Recommends: hwinfo
Description: Grub Customizer - A graphical Grub2/BURG configuration application
 Grub Customizer is a graphical configuration tool to modify the grub2/burg
 settings with focus on the individual list order - without losing the
 dynamical behavior of grub - also usable on live cds.
 Settings like the background or timeouts are also changeable using
 Grub Customizer.

+++++++++++++++++++++++++++++++++++++++++++++++

Luego en la carpeta:

/grub-customizer_5.2.3

Pongo los comandos:

$ cmake .

y luego basandome en:

Cómo crear deb con dpkg-buildpackage -rfakeroot (desde un programa compilado previamente desde código fuente)(ejemplo Inkscape 1.0) 
https://facilitarelsoftwarelibre.blogspot.com/2020/12/compilar-inkscape-1.0-deb-32-y-64-bits-mxlinux.html



sudo apt-get install build-essential autoconf automake \
autotools-dev dh-make debhelper devscripts fakeroot \
xutils lintian pbuilder

$ dh_make -e wachin.id@gmail.com --createorig


Paso 5. Compilar el paquete

Bien, así usted haya o no editado los archivos indicados igual puede avanzar, ahora es necesario poner en la terminal:

$ dpkg-buildpackage -rfakeroot




