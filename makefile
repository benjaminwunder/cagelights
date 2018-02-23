CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := bin/setLights

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -g 
LIB := -lwiringPi
INC := -I include

$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@echo " $(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning...";
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)



#setLights: setLights.o Relay.o
#	g++ -o setLights setLights.o Relay.o RelayTime.o -lwiringPi
#
#setLights.o: setLights.cpp
#	g++ -c setLights.cpp -lwiringPi
#
#Relay.o: Relay.cpp Relay.h
#	g++ -c Relay.cpp -lwiringPi
#
#RelayTime.o: RelayTime.cpp RelayTime.h
	g++ -c RelayTime.cpp
