COMPILER  = g++
CXXFLAGS    = -g -Wall -Werror -std=c++11 -D_LINUX 
ifeq "$(shell getconf LONG_BIT)" "64"
  LDFLAGS = -L/usr/local/lib -L/usr/lib -L/server/bin -lyanapserver -L/util/bin -lyanaponlineutil 
else
  LDFLAGS = -L/usr/local/lib -L/usr/lib -L/server/bin -lyanapserver -L/util/bin -lyanaponlineutil 
endif
INCLUDE   = -I/usr/local/include -I. -I/server/include -I/util/include 
TARGETS   = bin/server.out
TARGETDIR = ./
SRCROOT   = .
OBJROOT   = ./bin/obj
SRCDIRS  := $(shell find $(SRCROOT) -type d)
SOURCES   = $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.cpp))
OBJECTS   = $(addprefix $(OBJROOT)/, $(SOURCES:.cpp=.o))
OBJDIRS   = $(addprefix $(OBJROOT)/, $(SRCDIRS))
DEPENDS   = $(OBJECTS:.o=.d)

$(TARGETS): $(OBJECTS)
	@if [ ! -e `dirname $@` ]; then mkdir -p `dirname $@`; fi
	$(COMPILER) $(OBJECTS) $(LDFLAGS) -o $(TARGETS)
	@rm -f $(OBJECTS)

$(OBJROOT)/%.o: $(SRCROOT)/%.cpp
	@if [ ! -e `dirname $@` ]; then mkdir -p `dirname $@`; fi
	$(COMPILER) $(CXXFLAGS) -MD $(INCLUDE) -o $@ -c $<

depend:
$(OBJROOT)/%.d: $(SRCROOT)/%.cpp
	@if [ ! -e `dirname $@` ]; then mkdir -p `dirname $@`; fi
	$(COMPILER) $(CXXFLAGS) -MM -MG $(INCLUDE) -o $@ -c $<

clean:
	@rm -rf obj

rebuild:
	@make clean
	@make

-include $(DEPENDS)
