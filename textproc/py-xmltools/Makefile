# Created by: ijliao
# $FreeBSD$

PORTNAME=	xmltools
PORTVERSION=	1.4.0
PORTREVISION=	8
CATEGORIES=	textproc python
MASTER_SITES=	LOGILAB
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High level XML tools for Python

RUN_DEPENDS=	${PYXML}

USE_GNOME=	pygtk2
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-patch:
	${REINPLACE_CMD} 's/from.*import.*nested_scopes//' ${WRKSRC}/setup.py

.include <bsd.port.mk>
