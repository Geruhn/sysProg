# Definition der Variablen

SRCDIR = src
OBJDIR = debug

BINDIR = debug

LIBDIR = lib

SHAREDLIB = ../sharedlib

## hier alle Object Files eintragen
## darauf achten, dass letzte Zeile ohne "\" eingetragen wird

OBJS = $(OBJDIR)/Buffer.o \
	$(OBJDIR)/TestBuffer.o
	#$(OBJDIR)/xx1.o \
	#$(OBJDIR)/xxn.o

## hier alle Object Files eintragen, die in der shared library enthalten sein sollen 
OBJSFORBUFFERLIB = $(LIBDIR)/Buffer.o #\


#
#		Targets zum Bauen des Tests
#

# Linken der Object-files

makeTestBuffer: $(OBJDIR)/Buffer.o 	$(OBJDIR)/TestBuffer.o
	g++ -g $(OBJDIR)/Buffer.o 	$(OBJDIR)/TestBuffer.o  -o $(BINDIR)/BufferTest
	

# compilieren der Source-files

$(OBJDIR)/Buffer.o :  $(SRCDIR)/Buffer.cpp 
	@echo "g++ $*.cpp"
	g++ -g  -c -Wall  -o $(OBJDIR)/Buffer.o  $(SRCDIR)/Buffer.cpp

$(OBJDIR)/TestBuffer.o :  $(SRCDIR)/TestBuffer.cpp 
	@echo "g++ $*.cpp"
	g++ -g  -c -Wall  -o $(OBJDIR)/TestBuffer.o  $(SRCDIR)/TestBuffer.cpp




# loeschen aller files im verzeichnis $(OBJDIR) und$(LIBDIR) und neu bauen

cleanBuffer:
	rm -rf $(OBJDIR)/*
	rm -rf $(LIBDIR)/*
	$(MAKE) makeTestBuffer
	

#	
# erstellen der shared library
#

BufferLib: $(LIBDIR)/Buffer.o
		g++ -shared  -o $(SHAREDLIB)/libBuffer.so $(LIBDIR)/Buffer.o 

	
$(LIBDIR)/Buffer.o :  $(SRCDIR)/Buffer.cpp 
#	@mkdir -p `dirname $(OBJDIR)/$*.o`
	@echo "g++ $*.cpp"
	g++ -g  -c -fPIC  -o $(LIBDIR)/Buffer.o  $(SRCDIR)/Buffer.cpp 

	