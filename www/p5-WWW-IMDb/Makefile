# Created by: Michael L. Hostbaek (mich@freebsdcluster.org)
# $FreeBSD$

PORTNAME=	IMDb
PORTVERSION=	0.01
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	ftp://ftp.rhapsodyk.net/pub/devel/perl/
PKGNAMEPREFIX=	p5-WWW-
DISTNAME=	IMDb-current

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Perl interface to query the Internet Movie Database(IMDb)

RUN_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
