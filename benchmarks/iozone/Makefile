# Created by: jmz
# $FreeBSD$

PORTNAME=	iozone
PORTVERSION=	3.420
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.iozone.org/src/current/
DISTNAME=	${PORTNAME}${PORTVERSION:S/./_/}
EXTRACT_SUFX=	.tar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Performance Test of Sequential File I/O

CONFLICTS=	iozone-2.* iozone21-*

WRKSRC=		${WRKDIR}/${DISTNAME}/src/current

MAKEFILE=	makefile
MAKE_ARGS=	${MAKE_ENV}
ALL_TARGET=	freebsd
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/iozone man/man1/iozone.1.gz

OPTIONS_DEFINE=	SSH THREADS
OPTIONS_DEFAULT=SSH THREADS

SSH_DESC=	Use ssh in distributed measurement
THREADS_DESC=	Enable threading (uses pthreads)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTHREADS}
CFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}
.else
CFLAGS+=	-DNO_THREADS
.endif

post-patch:
.if ${PORT_OPTIONS:MSSH}
	@${REINPLACE_CMD} -e 's|shell\,\"rsh\"|shell\,\"ssh\"|' ${WRKSRC}/iozone.c
.endif
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/iozone ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/docs/iozone.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
