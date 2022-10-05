.PHONY: clean All

All:
	@echo "----------Building project:[ wasg-register-gui - Release ]----------"
	@cd "wasg-register-gui" && "$(MAKE)" -f  "wasg-register-gui.mk"
clean:
	@echo "----------Cleaning project:[ wasg-register-gui - Release ]----------"
	@cd "wasg-register-gui" && "$(MAKE)" -f  "wasg-register-gui.mk" clean
install:
	@mkdir -p "$(DESTDIR)"/bin
	@cp build-Release/bin/* "$(DESTDIR)"/bin/
	@cp wasg-register-gui/python/* "$(DESTDIR)"/bin/
	@chmod +x "$(DESTDIR)"/bin/*
	@pip3 install pycryptodome
	@pip3 install requests