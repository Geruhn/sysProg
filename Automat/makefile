# Definition der Variablen

SRCDIR = src
OBJDIR = debug

BINDIR = debug

LIBDIR = lib

SHAREDLIB = ../sharedlib


#
#		Targets zum Bauen des Tests
#

# Linken der Object-files
makeTestAutomat: $(OBJDIR)/Automat.o $(OBJDIR)/TestAutomat.o  ## hier alle Object Files eintragen
	g++ -g $(OBJDIR)/Automat.o $(OBJDIR)/TestAutomat.o -o $(BINDIR)/AutomatTest
	

# compilieren der Source-Files

$(OBJDIR)/Automat.o :  $(SRCDIR)/Automat.cpp 
	@echo "g++ $*.cpp"
	g++ -g  -c -Wall $(SRCDIR)/Automat.cpp -o $(OBJDIR)/Automat.o  


$(OBJDIR)/TestAutomat.o :  $(SRCDIR)/TestAutomat.cpp 
	@echo "g++ $*.cpp"
	g++ -g  -c -Wall $(SRCDIR)/TestAutomat.cpp  -o $(OBJDIR)/TestAutomat.o  



# loeschen aller files im verzeichnis $(OBJDIR) und $(LIBDIR) und neu bauen

cleanAutomat:
	rm -rf $(OBJDIR)/*
	rm -rf $(LIBDIR)/*
	$(MAKE) makeTestAutomat
	
	
#
# erstellen der shared library
#

AutomatLib: $(LIBDIR)/Automat.o
		g++ -shared $(LIBDIR)/Automat.o  -o $(SHAREDLIB)/libAutomat.so 

	
$(LIBDIR)/Automat.o :  $(SRCDIR)/Automat.cpp 
#	@mkdir -p `dirname $(OBJDIR)/$*.o`
	@echo "g++ $*.cpp"
	g++ -g  -c -fPIC  $(SRCDIR)/Automat.cpp -o $(LIBDIR)/Automat.o   


