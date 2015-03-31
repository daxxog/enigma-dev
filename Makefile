PATH := $(eTCpath)$(PATH)

.PHONY: ENIGMA tools

ENIGMA:
	$(MAKE) -j 3 -C CompilerSource
	$(MAKE) tools

clean:
	$(MAKE) -C CompilerSource clean
	$(MAKE) clean-tools

Game:
	$(MAKE) -C ENIGMAsystem/SHELL

clean-game:
	$(MAKE) -C ENIGMAsystem/SHELL clean

tools:
	cd tools && $(MAKE)

clean-tools:
	cd tools && $(MAKE) clean
