# Makefile
# oberoi, sean
# ssoberoi

APPNAME=linkedList

CXX=g++
RM=rm -f

CXXFLAGS=-g -Wall -O -std=c++11
LDFLAGS=
LDLIBS=

SRCS=Main.cpp LinkedList.h LinkedList.cpp
CPP-SRCS=Main.cpp
OBJS=$(subst .cpp,.o,$(CPP-SRCS))

all: $(APPNAME)

$(APPNAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(APPNAME) $(OBJS) $(LDLIBS)

.depend: $(SRCS)
	$(RM) ./.depend
	$(CXX) $(CXXFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJS)

distclean:
	$(RM) $(APPNAME)

include .depend
