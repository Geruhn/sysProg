# Definition der Variablen

SRCDIR = src
OBJDIR = debug

BINDIR = debug

LIBDIR = lib

SHAREDLIB = ../sharedlib

## hier alle Object Files eintragen
## darauf achten, dass letzte Zeile ohne "\" eingetragen wird

OBJS = $(OBJDIR)/Symboltable.o \
	$(OBJDIR)/TestSymboltable.o
	#$(OBJDIR)/xx1.o \
	#$(OBJDIR)/xxn.o

OBJSFORSYMBOLTABLELIB =  \
	$(LIBDIR)/Symboltable.o #\


#
#		Targets zum Bauen des Tests
#

# Linken der Object-Files
makeTestSymboltable: $(OBJDIR)/Symboltable.o $(OBJDIR)/TestSymboltable.o
	g++ -g $(OBJDIR)/Symboltable.o $(OBJDIR)/TestSymboltable.o -o $(BINDIR)/SymboltableTest

	
# compilieren der Source-files

$(OBJDIR)/Symboltable.o :  $(SRCDIR)/Symboltable.cpp 
	@echo "g++ $*.cpp"
	g++ -g  -c -Wall  -o $(OBJDIR)/Symboltable.o  $(SRCDIR)/Symboltable.cpp


$(OBJDIR)/TestSymboltable.o :  $(SRCDIR)/TestSymboltable.cpp 
	@echo "g++ $*.cpp"
	g++ -g  -c -Wall  -o $(OBJDIR)/TestSymboltable.o  $(SRCDIR)/TestSymboltable.cpp



# loeschen aller files im verzeichnis $(OBJDIR)

cleanSymboltable:
	rm -rf $(OBJDIR)/*
	rm -rf $(LIBDIR)/*
	$(MAKE) makeTestSymboltable
	
#	
# erstellen der shared library
#

SymboltableLib:$(LIBDIR)/Symboltable.o
		g++ -shared  -o $(SHAREDLIB)/libSymboltable.so $(LIBDIR)/Symboltable.o 

	
$(LIBDIR)/Symboltable.o :  $(SRCDIR)/Symboltable.cpp 
#	@mkdir -p `dirname $(OBJDIR)/$*.o`
	@echo "g++ $*.cpp"
	g++ -g  -c -fPIC  -o $(LIBDIR)/Symboltable.o  $(SRCDIR)/Symboltable.cpp 

	