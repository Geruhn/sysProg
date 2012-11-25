# Definition der Variablen

SRCDIR = src
OBJDIR = debug

BINDIR = debug

LIBDIR = lib

SHAREDLIB = ../sharedlib

## hier alle Object Files eintragen
## darauf achten, dass letzte Zeile ohne "\" eingetragen wird

OBJS = $(OBJDIR)/Automat.o \
	$(OBJDIR)/AutomatInterface.o  \
	$(OBJDIR)/TestAutomat.o  \
	$(OBJDIR)/State.o  \
	$(OBJDIR)/states/stateStart.o \
	$(OBJDIR)/states/stateIdentifier.o \
	$(OBJDIR)/states/stateDigit.o #\
	#$(OBJDIR)/xx1.o \
	#$(OBJDIR)/xxn.o

## hier alle Object Files eintragen, die in der shared library enthalten sein sollen 
OBJSFORAUTOMATLIB =  \
	$(LIBDIR)/Automat.o #\


#
#		Targets zum Bauen des Tests
#
.PHONY: clean cleanAutomat all

makeTestAutomat: $(OBJS)
	g++ -g $^ -o $(BINDIR)/AutomatTest
	
# $^ liste der abhaengigkeiten


$(OBJDIR)/%.o :  $(SRCDIR)/%.cpp 
	@echo "g++ $*.cpp"
	g++ -g  -c -Wall  -o $@  $<

# 
# $@ name des object files
# $< erste abhaengigkeit


# loeschen aller files im verzeichnis $(OBJDIR)

cleanAutomat:
	rm -rf $(OBJDIR)
	rm -rf $(LIBDIR)
	#rm -f $(OBJDIR)/states/*
	#rm -f $(LIBDIR)/states/*
	#$(MAKE) TestAutomat
	#Legt alle Ordner wieder an, nachdem sie gelöscht wurden.
	#mkdir $(OBJDIR)
	#mkdir $(LIBDIR)
	mkdir -p $(OBJDIR)/states
	mkdir -p $(LIBDIR)/states
	
	
#
# erstellen der shared library
#

AutomatLib:$(OBJSFORAUTOMATLIB)
		g++ -shared  -o $(SHAREDLIB)/libAutomat.so $^ 

	
$(LIBDIR)/%.o :  $(SRCDIR)/%.cpp 
#	@mkdir -p `dirname $(OBJDIR)/$*.o`
	@echo "g++ $*.cpp"
	g++ -g  -c -fPIC  -o $@  $<

clean: cleanAutomat
	
all: AutomatLib	