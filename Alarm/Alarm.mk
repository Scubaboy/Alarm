##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Alarm
ConfigurationName      :=Debug
WorkspacePath          :=/home/pi/Documents/ShedAlarm
ProjectPath            :=/home/pi/Documents/ShedAlarm/Alarm
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=
Date                   :=15/10/18
CodeLitePath           :=/home/pi/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Alarm.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)./Interfaces $(IncludeSwitch)./Sensors $(IncludeSwitch)./DataTypes $(IncludeSwitch)./Loggers $(IncludeSwitch)/usr/local/include/raspicam $(IncludeSwitch)./Controllers $(IncludeSwitch)./DeviceControllers $(IncludeSwitch)./Parsers 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)wiringPi $(LibrarySwitch)raspicam $(LibrarySwitch)boost_regex 
ArLibs                 :=  "wiringPi" "raspicam" "boost_regex" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)/usr/local/lib $(LibraryPathSwitch)/usr/lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/DataTypes_ReceivedMessage.cpp$(ObjectSuffix) $(IntermediateDirectory)/DataTypes_Command.cpp$(ObjectSuffix) $(IntermediateDirectory)/Sensors_PIRSensor.cpp$(ObjectSuffix) $(IntermediateDirectory)/cameras_IRCamera.cpp$(ObjectSuffix) $(IntermediateDirectory)/Loggers_FileLogger.cpp$(ObjectSuffix) $(IntermediateDirectory)/Controllers_CommandController.cpp$(ObjectSuffix) $(IntermediateDirectory)/Controllers_SystemStateCmdController.cpp$(ObjectSuffix) $(IntermediateDirectory)/Controllers_PiBaudLookUpController.cpp$(ObjectSuffix) $(IntermediateDirectory)/Controllers_PiWiringGPIOController.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/Controllers_IRCameraController.cpp$(ObjectSuffix) $(IntermediateDirectory)/Controllers_PassiveActionController.cpp$(ObjectSuffix) $(IntermediateDirectory)/Controllers_ActiveActionController.cpp$(ObjectSuffix) $(IntermediateDirectory)/DeviceControllers_SerialPortConfigController.cpp$(ObjectSuffix) $(IntermediateDirectory)/DeviceControllers_CommsGSMDeviceDriver.cpp$(ObjectSuffix) $(IntermediateDirectory)/Parsers_ATResponseStringParser.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/pi/Documents/ShedAlarm/Alarm/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/DataTypes_ReceivedMessage.cpp$(ObjectSuffix): DataTypes/ReceivedMessage.cpp $(IntermediateDirectory)/DataTypes_ReceivedMessage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/pi/Documents/ShedAlarm/Alarm/DataTypes/ReceivedMessage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/DataTypes_ReceivedMessage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DataTypes_ReceivedMessage.cpp$(DependSuffix): DataTypes/ReceivedMessage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DataTypes_ReceivedMessage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/DataTypes_ReceivedMessage.cpp$(DependSuffix) -MM DataTypes/ReceivedMessage.cpp

$(IntermediateDirectory)/DataTypes_ReceivedMessage.cpp$(PreprocessSuffix): DataTypes/ReceivedMessage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DataTypes_ReceivedMessage.cpp$(PreprocessSuffix) DataTypes/ReceivedMessage.cpp

$(IntermediateDirectory)/DataTypes_Command.cpp$(ObjectSuffix): DataTypes/Command.cpp $(IntermediateDirectory)/DataTypes_Command.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/pi/Documents/ShedAlarm/Alarm/DataTypes/Command.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/DataTypes_Command.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DataTypes_Command.cpp$(DependSuffix): DataTypes/Command.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DataTypes_Command.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/DataTypes_Command.cpp$(DependSuffix) -MM DataTypes/Command.cpp

$(IntermediateDirectory)/DataTypes_Command.cpp$(PreprocessSuffix): DataTypes/Command.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DataTypes_Command.cpp$(PreprocessSuffix) DataTypes/Command.cpp

$(IntermediateDirectory)/Sensors_PIRSensor.cpp$(ObjectSuffix): Sensors/PIRSensor.cpp $(IntermediateDirectory)/Sensors_PIRSensor.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/pi/Documents/ShedAlarm/Alarm/Sensors/PIRSensor.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Sensors_PIRSensor.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Sensors_PIRSensor.cpp$(DependSuffix): Sensors/PIRSensor.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Sensors_PIRSensor.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Sensors_PIRSensor.cpp$(DependSuffix) -MM Sensors/PIRSensor.cpp

$(IntermediateDirectory)/Sensors_PIRSensor.cpp$(PreprocessSuffix): Sensors/PIRSensor.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Sensors_PIRSensor.cpp$(PreprocessSuffix) Sensors/PIRSensor.cpp

$(IntermediateDirectory)/cameras_IRCamera.cpp$(ObjectSuffix): cameras/IRCamera.cpp $(IntermediateDirectory)/cameras_IRCamera.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/pi/Documents/ShedAlarm/Alarm/cameras/IRCamera.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cameras_IRCamera.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cameras_IRCamera.cpp$(DependSuffix): cameras/IRCamera.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cameras_IRCamera.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/cameras_IRCamera.cpp$(DependSuffix) -MM cameras/IRCamera.cpp

$(IntermediateDirectory)/cameras_IRCamera.cpp$(PreprocessSuffix): cameras/IRCamera.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cameras_IRCamera.cpp$(PreprocessSuffix) cameras/IRCamera.cpp

$(IntermediateDirectory)/Loggers_FileLogger.cpp$(ObjectSuffix): Loggers/FileLogger.cpp $(IntermediateDirectory)/Loggers_FileLogger.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/pi/Documents/ShedAlarm/Alarm/Loggers/FileLogger.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Loggers_FileLogger.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Loggers_FileLogger.cpp$(DependSuffix): Loggers/FileLogger.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Loggers_FileLogger.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Loggers_FileLogger.cpp$(DependSuffix) -MM Loggers/FileLogger.cpp

$(IntermediateDirectory)/Loggers_FileLogger.cpp$(PreprocessSuffix): Loggers/FileLogger.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Loggers_FileLogger.cpp$(PreprocessSuffix) Loggers/FileLogger.cpp

$(IntermediateDirectory)/Controllers_CommandController.cpp$(ObjectSuffix): Controllers/CommandController.cpp $(IntermediateDirectory)/Controllers_CommandController.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/pi/Documents/ShedAlarm/Alarm/Controllers/CommandController.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Controllers_CommandController.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Controllers_CommandController.cpp$(DependSuffix): Controllers/CommandController.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Controllers_CommandController.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Controllers_CommandController.cpp$(DependSuffix) -MM Controllers/CommandController.cpp

$(IntermediateDirectory)/Controllers_CommandController.cpp$(PreprocessSuffix): Controllers/CommandController.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Controllers_CommandController.cpp$(PreprocessSuffix) Controllers/CommandController.cpp

$(IntermediateDirectory)/Controllers_SystemStateCmdController.cpp$(ObjectSuffix): Controllers/SystemStateCmdController.cpp $(IntermediateDirectory)/Controllers_SystemStateCmdController.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/pi/Documents/ShedAlarm/Alarm/Controllers/SystemStateCmdController.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Controllers_SystemStateCmdController.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Controllers_SystemStateCmdController.cpp$(DependSuffix): Controllers/SystemStateCmdController.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Controllers_SystemStateCmdController.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Controllers_SystemStateCmdController.cpp$(DependSuffix) -MM Controllers/SystemStateCmdController.cpp

$(IntermediateDirectory)/Controllers_SystemStateCmdController.cpp$(PreprocessSuffix): Controllers/SystemStateCmdController.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Controllers_SystemStateCmdController.cpp$(PreprocessSuffix) Controllers/SystemStateCmdController.cpp

$(IntermediateDirectory)/Controllers_PiBaudLookUpController.cpp$(ObjectSuffix): Controllers/PiBaudLookUpController.cpp $(IntermediateDirectory)/Controllers_PiBaudLookUpController.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/pi/Documents/ShedAlarm/Alarm/Controllers/PiBaudLookUpController.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Controllers_PiBaudLookUpController.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Controllers_PiBaudLookUpController.cpp$(DependSuffix): Controllers/PiBaudLookUpController.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Controllers_PiBaudLookUpController.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Controllers_PiBaudLookUpController.cpp$(DependSuffix) -MM Controllers/PiBaudLookUpController.cpp

$(IntermediateDirectory)/Controllers_PiBaudLookUpController.cpp$(PreprocessSuffix): Controllers/PiBaudLookUpController.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Controllers_PiBaudLookUpController.cpp$(PreprocessSuffix) Controllers/PiBaudLookUpController.cpp

$(IntermediateDirectory)/Controllers_PiWiringGPIOController.cpp$(ObjectSuffix): Controllers/PiWiringGPIOController.cpp $(IntermediateDirectory)/Controllers_PiWiringGPIOController.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/pi/Documents/ShedAlarm/Alarm/Controllers/PiWiringGPIOController.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Controllers_PiWiringGPIOController.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Controllers_PiWiringGPIOController.cpp$(DependSuffix): Controllers/PiWiringGPIOController.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Controllers_PiWiringGPIOController.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Controllers_PiWiringGPIOController.cpp$(DependSuffix) -MM Controllers/PiWiringGPIOController.cpp

$(IntermediateDirectory)/Controllers_PiWiringGPIOController.cpp$(PreprocessSuffix): Controllers/PiWiringGPIOController.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Controllers_PiWiringGPIOController.cpp$(PreprocessSuffix) Controllers/PiWiringGPIOController.cpp

$(IntermediateDirectory)/Controllers_IRCameraController.cpp$(ObjectSuffix): Controllers/IRCameraController.cpp $(IntermediateDirectory)/Controllers_IRCameraController.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/pi/Documents/ShedAlarm/Alarm/Controllers/IRCameraController.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Controllers_IRCameraController.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Controllers_IRCameraController.cpp$(DependSuffix): Controllers/IRCameraController.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Controllers_IRCameraController.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Controllers_IRCameraController.cpp$(DependSuffix) -MM Controllers/IRCameraController.cpp

$(IntermediateDirectory)/Controllers_IRCameraController.cpp$(PreprocessSuffix): Controllers/IRCameraController.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Controllers_IRCameraController.cpp$(PreprocessSuffix) Controllers/IRCameraController.cpp

$(IntermediateDirectory)/Controllers_PassiveActionController.cpp$(ObjectSuffix): Controllers/PassiveActionController.cpp $(IntermediateDirectory)/Controllers_PassiveActionController.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/pi/Documents/ShedAlarm/Alarm/Controllers/PassiveActionController.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Controllers_PassiveActionController.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Controllers_PassiveActionController.cpp$(DependSuffix): Controllers/PassiveActionController.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Controllers_PassiveActionController.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Controllers_PassiveActionController.cpp$(DependSuffix) -MM Controllers/PassiveActionController.cpp

$(IntermediateDirectory)/Controllers_PassiveActionController.cpp$(PreprocessSuffix): Controllers/PassiveActionController.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Controllers_PassiveActionController.cpp$(PreprocessSuffix) Controllers/PassiveActionController.cpp

$(IntermediateDirectory)/Controllers_ActiveActionController.cpp$(ObjectSuffix): Controllers/ActiveActionController.cpp $(IntermediateDirectory)/Controllers_ActiveActionController.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/pi/Documents/ShedAlarm/Alarm/Controllers/ActiveActionController.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Controllers_ActiveActionController.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Controllers_ActiveActionController.cpp$(DependSuffix): Controllers/ActiveActionController.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Controllers_ActiveActionController.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Controllers_ActiveActionController.cpp$(DependSuffix) -MM Controllers/ActiveActionController.cpp

$(IntermediateDirectory)/Controllers_ActiveActionController.cpp$(PreprocessSuffix): Controllers/ActiveActionController.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Controllers_ActiveActionController.cpp$(PreprocessSuffix) Controllers/ActiveActionController.cpp

$(IntermediateDirectory)/DeviceControllers_SerialPortConfigController.cpp$(ObjectSuffix): DeviceControllers/SerialPortConfigController.cpp $(IntermediateDirectory)/DeviceControllers_SerialPortConfigController.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/pi/Documents/ShedAlarm/Alarm/DeviceControllers/SerialPortConfigController.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/DeviceControllers_SerialPortConfigController.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DeviceControllers_SerialPortConfigController.cpp$(DependSuffix): DeviceControllers/SerialPortConfigController.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DeviceControllers_SerialPortConfigController.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/DeviceControllers_SerialPortConfigController.cpp$(DependSuffix) -MM DeviceControllers/SerialPortConfigController.cpp

$(IntermediateDirectory)/DeviceControllers_SerialPortConfigController.cpp$(PreprocessSuffix): DeviceControllers/SerialPortConfigController.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DeviceControllers_SerialPortConfigController.cpp$(PreprocessSuffix) DeviceControllers/SerialPortConfigController.cpp

$(IntermediateDirectory)/DeviceControllers_CommsGSMDeviceDriver.cpp$(ObjectSuffix): DeviceControllers/CommsGSMDeviceDriver.cpp $(IntermediateDirectory)/DeviceControllers_CommsGSMDeviceDriver.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/pi/Documents/ShedAlarm/Alarm/DeviceControllers/CommsGSMDeviceDriver.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/DeviceControllers_CommsGSMDeviceDriver.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DeviceControllers_CommsGSMDeviceDriver.cpp$(DependSuffix): DeviceControllers/CommsGSMDeviceDriver.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DeviceControllers_CommsGSMDeviceDriver.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/DeviceControllers_CommsGSMDeviceDriver.cpp$(DependSuffix) -MM DeviceControllers/CommsGSMDeviceDriver.cpp

$(IntermediateDirectory)/DeviceControllers_CommsGSMDeviceDriver.cpp$(PreprocessSuffix): DeviceControllers/CommsGSMDeviceDriver.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DeviceControllers_CommsGSMDeviceDriver.cpp$(PreprocessSuffix) DeviceControllers/CommsGSMDeviceDriver.cpp

$(IntermediateDirectory)/Parsers_ATResponseStringParser.cpp$(ObjectSuffix): Parsers/ATResponseStringParser.cpp $(IntermediateDirectory)/Parsers_ATResponseStringParser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/pi/Documents/ShedAlarm/Alarm/Parsers/ATResponseStringParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Parsers_ATResponseStringParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Parsers_ATResponseStringParser.cpp$(DependSuffix): Parsers/ATResponseStringParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Parsers_ATResponseStringParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Parsers_ATResponseStringParser.cpp$(DependSuffix) -MM Parsers/ATResponseStringParser.cpp

$(IntermediateDirectory)/Parsers_ATResponseStringParser.cpp$(PreprocessSuffix): Parsers/ATResponseStringParser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Parsers_ATResponseStringParser.cpp$(PreprocessSuffix) Parsers/ATResponseStringParser.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


