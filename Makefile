.PHONY: clean All

All:
	@echo "----------Building project:[ Alarm - Release ]----------"
	@cd "Alarm" && "$(MAKE)" -f  "Alarm.mk"
clean:
	@echo "----------Cleaning project:[ Alarm - Release ]----------"
	@cd "Alarm" && "$(MAKE)" -f  "Alarm.mk" clean
