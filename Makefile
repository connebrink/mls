PRJNAME=mls

MAINSRC=src/$(PRJNAME).cpp

DEPDIR=bin
OUTDIR=trg
OUTDIRBIN=$(OUTDIR)/bin
TSTDIR=tst/check

CXX=g++
CXXFLAGS=-std=c++20 -pedantic -Wall -Wextra -Werror
CXXFLAGSREL=$(CXXFLAGS) -static -O2 -s -g0 -DNDEBUG
CXXFLAGSDEB=$(CXXFLAGS) -O0 -g -DDEBUG

.PHONY: all

all: debug

debug:
	@mkdir -p $(OUTDIRBIN)
	@echo "Compile : $(MAINSRC) -> $(OUTDIRBIN)/$(PRJNAME)"
	@ $(CXX) $(CXXFLAGSDEB) -o $(OUTDIRBIN)/$(PRJNAME) $(MAINSRC)
	@mkdir -p $(DEPDIR)
	@ cp $(OUTDIRBIN)/$(PRJNAME) $(DEPDIR) 

release:clean
	@mkdir -p $(OUTDIRBIN)
	@echo "Compile : $(MAINSRC) -> $(OUTDIRBIN)/$(PRJNAME)"
	@ $(CXX) $(CXXFLAGSREL) -o $(OUTDIRBIN)/$(PRJNAME) $(MAINSRC)
	@mkdir -p $(DEPDIR)
	@ cp $(OUTDIRBIN)/$(PRJNAME) $(DEPDIR) 

tests:  debug
	@echo "  Tests : Begin"
	@tst/test_01_ls.sh $(TSTDIR) $(OUTDIRBIN)/$(PRJNAME)
	@tst/test_02_ls.sh $(TSTDIR) $(OUTDIRBIN)/$(PRJNAME)
	@echo "  Tests : End"

clean:
	@rm -rf $(OUTDIR)
