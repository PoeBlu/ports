# Created by: svmohr
# $FreeBSD$

PORTNAME=	gscmxx
PORTVERSION=	0.4.1
PORTREVISION=	9
CATEGORIES=	comms
MASTER_SITES=	SF

MAINTAINER=	svmohr@gmail.com
COMMENT=	Graphical frontend for scmxx

RUN_DEPENDS=	p5-Image-Size>=0:${PORTSDIR}/graphics/p5-Image-Size \
		p5-Gtk>=0:${PORTSDIR}/x11-toolkits/p5-Gtk
BUILD_DEPENDS=	p5-Image-Size>=0:${PORTSDIR}/graphics/p5-Image-Size \
		p5-Gtk>=0:${PORTSDIR}/x11-toolkits/p5-Gtk \
		scmxx:${PORTSDIR}/comms/scmxx \
		convert:${PORTSDIR}/graphics/ImageMagick

USES=		perl5
USE_PERL5=	configure

USE_GNOME=	gtk12

do-install:
	cd ${WRKSRC} && make install PREFIX='${STAGEDIR}${PREFIX}'

.include <bsd.port.mk>
