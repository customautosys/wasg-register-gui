.PHONY: clean All

install:
	@cp "build-Release/bin/*" "$(DESTDIR)/"
	@cp "wasg-register-gui/python/*" "$(DESTDIR)/"
All:
	@echo "----------Building project:[ wasg-register-gui - Release ]----------"
	@cd "wasg-register-gui" && "$(MAKE)" -f  "wasg-register-gui.mk"
clean:
	@echo "----------Cleaning project:[ wasg-register-gui - Release ]----------"
	@cd "wasg-register-gui" && "$(MAKE)" -f  "wasg-register-gui.mk" clean
