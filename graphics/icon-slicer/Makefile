# Created by: Jean-Yves Lefort <jylefort@FreeBSD.org>
# $FreeBSD$

PORTNAME=	icon-slicer
PORTVERSION=	0.3
PORTREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	http://www.freedesktop.org/software/icon-slicer/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility for generating icon and cursor themes

LICENSE=	GPLv2

LIB_DEPENDS=	libpopt.so:${PORTSDIR}/devel/popt

USES=		pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	AUTHORS ChangeLog README
OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/ s|examples||' ${WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
