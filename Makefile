.PHONY: clean All

All:
	@echo "----------Building project:[ wasg-register-gui - Release ]----------"
	@cd "wasg-register-gui" && "$(MAKE)" -f  "wasg-register-gui.mk"
clean:
	@echo "----------Cleaning project:[ wasg-register-gui - Release ]----------"
	@cd "wasg-register-gui" && "$(MAKE)" -f  "wasg-register-gui.mk" clean
install:
	@pwd
	@ls -l
	@cp "build-Release/bin/*" "$(DESTDIR)/"
	@cp "wasg-register-gui/python/*" "$(DESTDIR)/"
	@chmod +x "$(DESTDIR)/*"