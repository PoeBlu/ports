# Created by: Matthew X. Economou <xenophon+fbsdports@irtnog.org>
# $FreeBSD$

PORTNAME=	django-openid-auth
PORTVERSION=	0.4
CATEGORIES=	www security python
MASTER_SITES=	http://launchpadlibrarian.net/80020365/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	xenophon+fbsdports@irtnog.org
COMMENT=	OpenID integration for django.contrib.auth

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django>=1.3.1:${PORTSDIR}/www/py-django \
		${PYTHON_PKGNAMEPREFIX}openid>=2.2.5:${PORTSDIR}/security/py-openid

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

NO_WRKSUBDIR=	yes

PORTDOCS=	*.txt *.html
PORTEXAMPLES=	example_consumer
OPTIONS_DEFINE= DOCS EXAMPLES

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.txt	${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/TODO.txt	${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/openid.html	${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/openid.txt	${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/example_consumer
	${INSTALL_MAN} ${WRKSRC}/example_consumer/* ${STAGEDIR}${EXAMPLESDIR}/example_consumer
.endif

.include <bsd.port.mk>
