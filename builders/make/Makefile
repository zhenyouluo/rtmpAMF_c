
.PHONY: default clean 

ifndef PRJ_DIR
PRJ_DIR = ../..
endif

SRC_DIR = $(PRJ_DIR)/sources/src
INC_DIR = $(PRJ_DIR)/sources/include

CXX = g++
INCFLAGS = 
INCFLAGS += -I$(INC_DIR)
CXXFLAGS = -fPIC -Wall -Werror -g -O0 -Wformat=2
FLAGS = 
FLAGS += $(CXXFLAGS)
FLAGS += $(INCFLAGS)

#LINKFLAGS = 

SRC = $(shell find $(SRC_DIR) -type f -iname '*.cpp' -printf '%f\n')
OBJS = $(patsubst %.cpp, %.o, $(SRC))

vpath %.cpp $(SRC_DIR)

default: rtmpserver
	@echo "rtmpserver generated"

rtmpserver: $(OBJS)
	@echo "generate rtmpserver"
	$(CXX) $(OBJS) $(LINKFLAGS) -o rtmpserver
	@chmod 755 rtmpserver

include $(SRC:.cpp=.d)

%.d: %.cpp
	@set -e; rm -f $@; \
	$(CXX) -MM $(FLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

%.o: %.cpp
	$(CXX) -c $(FLAGS) $< -o $@

clean:
	@echo "cleaning"	
	@-rm -f *.o *.d 
	@-rm -f rtmpserver
	@-rm -f logs/*

