# Created by: ijliao
# $FreeBSD$

PORTNAME=	argouml
PORTVERSION=	0.34
PORTREVISION=	1
CATEGORIES=	devel java
MASTER_SITES=	http://argouml-downloads.tigris.org/nonav/argouml-${PORTVERSION}/
DISTNAME=	ArgoUML-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		manual-${PORTVERSION}.pdf \
		quickguide-${PORTVERSION}.pdf
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	UML design tool with cognitive support

LICENSE=	EPL

PORTSCOUT=	limitw:1,even \
		site:${MASTER_SITES:S/argouml-${PORTVERSION}\///}

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+

SUB_FILES=	argouml.sh
SUB_LIST=	JAVA_VERSION=${JAVA_VERSION}
PORTDOCS=	manual-${PORTVERSION}.pdf quickguide-${PORTVERSION}.pdf

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

DESKTOP_ENTRIES=	"ArgoUML" \
			"Create advanced UML diagrams" \
			"${DATADIR}/icon/ArgoIcon128x128.png" \
			"argouml" \
			"Development;Building;Java;" \
			false

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/argouml.sh ${STAGEDIR}${PREFIX}/bin/argouml
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.jar ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}/ext
	${INSTALL_DATA} ${WRKSRC}/ext/*.jar ${STAGEDIR}${DATADIR}/ext
	${INSTALL_DATA} ${WRKSRC}/ext/*.xml ${STAGEDIR}${DATADIR}/ext
	@${MKDIR} ${STAGEDIR}${DATADIR}/icon
	${INSTALL_DATA} ${WRKSRC}/icon/*.png ${STAGEDIR}${DATADIR}/icon
	${INSTALL_DATA} ${WRKSRC}/icon/*.svg ${STAGEDIR}${DATADIR}/icon
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/manual-${PORTVERSION}.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/quickguide-${PORTVERSION}.pdf ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
