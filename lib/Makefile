# TODO - Move this to a META.json file
HIERARCHY_VERSION = 0.0.1

EXTENSION = pg_hierarchy
MODULE_big = pg_hierarchy

DATA_built = pg_hierarchy--$(HIERARCHY_VERSION).sql pg_hierarchy.control

OBJS = pg_hierarchy.o

PG_CPPFLAGS = -DHIERARCHY_VERSION=$(HIERARCHY_VERSION)

PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)

pg_hierarchy--$(HIERARCHY_VERSION).sql: pg_hierarchy.sql.in
	sed 's,HIERARCHY_VERSION,$(HIERARCHY_VERSION),g' $< \
	| sed 's,MODULE_PATHNAME,$$libdir/$(MODULE_big),g' > $@;

pg_hierarchy.control: pg_hierarchy.control.in
	sed 's,HIERARCHY_VERSION,$(HIERARCHY_VERSION),g' $< > $@

clean:
	rm pg_hierarchy.control pg_hierarchy--$(HIERARCHY_VERSION).sql pg_hierarchy.o