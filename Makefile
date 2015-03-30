PATH := $(eTCpath)$(PATH)

.PHONY: ENIGMA

ENIGMA:
	$(MAKE) -j 3 -C CompilerSource
	cd CommandLine/programs/emake && $(MAKE) -j 3

clean:
	$(MAKE) -C CompilerSource clean
	cd CommandLine/programs/emake && $(MAKE) clean

Game:
	$(MAKE) -C ENIGMAsystem/SHELL

clean-game:
	$(MAKE) -C ENIGMAsystem/SHELL clean


