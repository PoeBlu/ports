# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libXt
PORTVERSION=	1.1.4
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	x11-toolkits

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Toolkit library

XORG_CAT=	lib
USE_XORG=	x11 sm xproto:both kbproto
CONFIGURE_ARGS=	--disable-specs

post-patch:
	@${REINPLACE_CMD} 's/test.*-traditional.*;/true;/' \
		${WRKSRC}/configure

.include <bsd.port.mk>
