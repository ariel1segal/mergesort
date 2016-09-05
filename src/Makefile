# Project: Merge Sort Algorithm in C 
# Version: 1.0 
# File: Makefile 
# Author: Ariel Segal 
# Date:  Sep 02, 2016 

CC := gcc
SRCDIR := .
BUILDDIR := ../bin
CFLAGS := -g -Wall
TARGET := $(BUILDDIR)/sort
 
SRCEXT := c
SOURCES := $(wildcard $(SRCDIR)/*.c)
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
DEPS := $(OBJECTS:.o=.deps)

all: $(TARGET)
$(TARGET): $(OBJECTS)
	@echo " Linking..."; $(CC) $(CFLAGS) $^ -o $(TARGET)
 
$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@echo " CC $<"; $(CC) $(CFLAGS) -MD -MF $(@:.o=.deps) -c -o $@ $<
 
clean:
	@echo " Cleaning..."; rm -f $(BUILDDIR)/*.o $(BUILDDIR)/*.deps $(BUILDDIR)/$(TARGET)
 
-include $(DEPS)
 
.PHONY: clean
