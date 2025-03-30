CFLAGS  := -Iinclude
LDFLAGS := -lSDL2

SOURCES := $(wildcard src/*.cpp)
OBJECTS := $(patsubst src/%.cpp,%.o,$(SOURCES))
TARGET  := cmac

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $(@) $(^)

%.o: src/%.cpp
	$(CXX) $(CFLAGS) -c -o $(@) $(<)

clean:
	$(RM) $(OBJECTS) $(TARGET)

.PHONY: all clean
