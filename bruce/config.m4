PHP_ARG_ENABLE(bruce,
    [Whether to enable the "walu" extension],
    [  enable-walu        Enable "walu" extension support])

if test $PHP_BRUCE != "no"; then
    PHP_SUBST(BRUCE_SHARED_LIBADD)
    PHP_NEW_EXTENSION(bruce, bruce.c, $ext_shared)
fi
