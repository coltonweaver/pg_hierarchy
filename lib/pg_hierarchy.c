/*
 * pg_hierarchy: lib/hierarchy.c
 */

#include "postgres.h"
#include "fmgr.h"
#include "utils/builtins.h"

PG_MODULE_MAGIC;

#ifdef HIERARCHY_VERSION
/* macro trick to stringify a macro expansion */
#define xstr(s) str(s)
#define str(s) #s
#define LIBRARY_VERSION xstr(HIERARCHY_VERSION)
#else
#define LIBRARY_VERSION "unknown"
#endif

PG_FUNCTION_INFO_V1(hierarchy_version);

Datum hierarchy_version(PG_FUNCTION_ARGS)
{
    return CStringGetTextDatum("pg_hierarchy " LIBRARY_VERSION);
}