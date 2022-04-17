.PHONY: clean All

All:
	@echo "----------Building project:[ wasg-register-gui - Debug ]----------"
	@cd "wasg-register-gui" && "$(MAKE)" -f  "wasg-register-gui.mk"
clean:
	@echo "----------Cleaning project:[ wasg-register-gui - Debug ]----------"
	@cd "wasg-register-gui" && "$(MAKE)" -f  "wasg-register-gui.mk" clean
