# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	bittorrent-libutp
PORTVERSION=	0.20130514
DISTVERSION=	7c4f19a
CATEGORIES=	net devel
MASTER_SITES=	https://github.com/bittorrent/libutp/tarball/${DISTVERSION}/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	The uTorrent Transport Protocol library

LICENSE=	MIT

USES=		dos2unix uidfix
MAKEFILE=	${FILESDIR}/BSDmakefile
USE_LDCONFIG=	yes

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/libutp

.include <bsd.port.mk>
