# Created by: Simon Barner <barner@gmx.de>
# $FreeBSD$

PORTNAME=	valgrind
DISTVERSIONPREFIX=	freebsd-
DISTVERSION=	3.9.0.rc1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	http://cdn.bitbucket.org/stass/valgrind-freebsd/downloads/ \
		http://mirror.shatow.net/freebsd/${PORTNAME}/
PKGNAMESUFFIX=	-devel

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Memory debugging and profiling tool

LICENSE=	GPLv2

CONFLICTS=	valgrind-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64

LIB32_PATH?=	${DESTDIR}/usr/lib32/libc.so

BUILD_DEPENDS+=		docbook-xsl>=0:${PORTSDIR}/textproc/docbook-xsl \
			xsltproc:${PORTSDIR}/textproc/libxslt

OPTIONS_DEFINE=		MPI DOCS
OPTIONS_DEFINE_amd64=	32BIT
#.if exists(${LIB32_PATH})
#OPTIONS_DEFAULT_amd64=	32BIT
#.endif
32BIT_DESC=	Enable debugging of 32-bit programs (requires lib32)
MPI_DESC=	Enable build of MPI wrappers

MPI_LIB_DEPENDS=	libmpich.so:${PORTSDIR}/net/mpich2

OPTIONS_SUB=	yes
USES=		pathfix pkgconfig gmake perl5 shebangfix tar:bzip2
USE_PERL5=	build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PORTDOCS=	html

WRKSRC=		${WRKDIR}/${DISTNAME}

CONFIGURE_ENV+=	ac_cv_path_PERL=${PERL}

BROKEN_amd64=	Fails to build

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:M32BIT}
BROKEN=	Currently does not build with 32bit support
.endif

.if ${ARCH} == "amd64"
PLIST_SUB+=	AMD64="" ARCH=amd64
. if !${PORT_OPTIONS:M32BIT}
CONFIGURE_ARGS+=	--enable-only64bit
PLIST_SUB+=	X86="@comment "
. else
.  if !exists(${LIB32_PATH})
IGNORE=The lib32 distribution was not found. Please install the lib32\
distribution or run 'make config' and uncheck 32BIT option
.  endif
PLIST_SUB+=	X86=""
. endif
.else
PLIST_SUB+=	X86="" ARCH=x86
PLIST_SUB+=	AMD64="@comment "
.endif

.if !${PORT_OPTIONS:MDOCS}
post-patch:
	@${RM} -rf ${WRKSRC}/docs/html
.endif

do-build: do-man-pages

do-man-pages:
	cd ${WRKSRC}/docs && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} man-pages
.if ${PORT_OPTIONS:MDOCS}
	cd ${WRKSRC}/docs && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} html-docs
.endif

.include <bsd.port.mk>
