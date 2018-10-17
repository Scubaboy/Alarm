.PHONY: clean All

All:
	@echo "----------Building project:[ Alarm - Debug ]----------"
	@cd "Alarm" && "$(MAKE)" -f  "Alarm.mk"
clean:
	@echo "----------Cleaning project:[ Alarm - Debug ]----------"
	@cd "Alarm" && "$(MAKE)" -f  "Alarm.mk" clean
