# Created by: Eyal Soha <esoha@attbi.com>
# $FreeBSD$

PORTNAME=	noip
PORTVERSION=	2.1.9
PORTREVISION=	2
CATEGORIES=	dns
MASTER_SITES=	http://www.no-ip.com/client/linux/ \
		CRITICAL

MAINTAINER=	sthalik@tehran.lain.pl
COMMENT=	No-IP.com's dynamic DNS update client

LICENSE=	GPLv2

ALL_TARGET=	noip2
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
USE_RC_SUBR=	noip

USERS=		noip
GROUPS=		noip

PLIST_SUB+=	USER="${USERS}"

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/noip2 ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.FIRST ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/COPYING ${STAGEDIR}${DOCSDIR}

conf:
	(cd ${PREFIX}/etc && ${PREFIX}/bin/noip2 -C)
	${CHOWN} noip:noip ${PREFIX}/etc/no-ip2.conf
	${CHMOD} 0600 ${PREFIX}/etc/no-ip2.conf

.include <bsd.port.mk>
