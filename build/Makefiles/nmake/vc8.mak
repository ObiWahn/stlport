
CFLAGS_COMMON = /nologo /W4 /Wp64 /GR /EHsc
CXXFLAGS_COMMON = /nologo /W4 /Wp64 /GR /EHsc

DEFS = $(DEFS) /D_CRT_SECURE_NO_DEPRECATE
DEFS_STLDBG = /GS
DEFS_STATIC_STLDBG = /GS

OPT_REL = $(OPT_REL) /GL
LDFLAGS_REL = $(LDFLAGS_REL) /LTCG


!include vc-common.mak

