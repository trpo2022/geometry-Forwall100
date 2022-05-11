CC = g++

APP_NAME = geometry
LIB_NAME = geometry_lib

CFLAGS = -Wall -Wextra -lstdc++
CPPFLAGS = -I src -MP -MMD

APP_PATH = bin/$(APP_NAME)
LIB_PATH = obj/src/$(LIB_NAME)/$(LIB_NAME).a

APP_SOURCES = $(shell find src/$(APP_NAME) -name '*.cpp')
APP_OBJECTS = $(APP_SOURCES:src/%.cpp=obj/src/%.o)

LIB_SOURCES = $(shell find src/$(LIB_NAME) -name '*.cpp')
LIB_OBJECTS = $(LIB_SOURCES:src/%.cpp=obj/src/%.o)

.PHONY: all
all: $(APP_PATH)

$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS)

$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $@ $^

obj/%.o: %.cpp
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

.PHONY: clean
clean:
	$(RM) $(APP_PATH) $(LIB_PATH)
	find obj -name '*.o' -exec $(RM) '{}' \;
	find obj -name '*.d' -exec $(RM) '{}' \;
