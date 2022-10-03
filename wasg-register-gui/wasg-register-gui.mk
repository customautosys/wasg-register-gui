##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=wasg-register-gui
ConfigurationName      :=Release
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=/home/walfin/Dokumentujo/Github/wasg-register-gui
ProjectPath            :=/home/walfin/Dokumentujo/Github/wasg-register-gui/wasg-register-gui
IntermediateDirectory  :=../build-$(ConfigurationName)/wasg-register-gui
OutDir                 :=../build-$(ConfigurationName)/wasg-register-gui
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Wilson Foo Yu Kang
Date                   :=03/10/22
CodeLitePath           :=/home/walfin/.codelite
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
OutputFile             :=../build-$(ConfigurationName)/bin/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)NDEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            :=  $(shell wx-config --libs)
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -O2 -Wall $(shell wx-config --cflags) $(Preprocessors)
CFLAGS   :=  -O2 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=../build-$(ConfigurationName)/wasg-register-gui/wxcrafter_bitmaps.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/wasg-register-gui/wxcrafter.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/wasg-register-gui/MainFrame.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/wasg-register-gui/main.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/wasg-register-gui/.d $(Objects) 
	@mkdir -p "../build-$(ConfigurationName)/wasg-register-gui"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "../build-$(ConfigurationName)/wasg-register-gui"
	@mkdir -p ""../build-$(ConfigurationName)/bin""

../build-$(ConfigurationName)/wasg-register-gui/.d:
	@mkdir -p "../build-$(ConfigurationName)/wasg-register-gui"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/wasg-register-gui/wxcrafter_bitmaps.cpp$(ObjectSuffix): wxcrafter_bitmaps.cpp ../build-$(ConfigurationName)/wasg-register-gui/wxcrafter_bitmaps.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/walfin/Dokumentujo/Github/wasg-register-gui/wasg-register-gui/wxcrafter_bitmaps.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/wasg-register-gui/wxcrafter_bitmaps.cpp$(DependSuffix): wxcrafter_bitmaps.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/wasg-register-gui/wxcrafter_bitmaps.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/wasg-register-gui/wxcrafter_bitmaps.cpp$(DependSuffix) -MM wxcrafter_bitmaps.cpp

../build-$(ConfigurationName)/wasg-register-gui/wxcrafter_bitmaps.cpp$(PreprocessSuffix): wxcrafter_bitmaps.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/wasg-register-gui/wxcrafter_bitmaps.cpp$(PreprocessSuffix) wxcrafter_bitmaps.cpp

../build-$(ConfigurationName)/wasg-register-gui/wxcrafter.cpp$(ObjectSuffix): wxcrafter.cpp ../build-$(ConfigurationName)/wasg-register-gui/wxcrafter.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/walfin/Dokumentujo/Github/wasg-register-gui/wasg-register-gui/wxcrafter.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/wxcrafter.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/wasg-register-gui/wxcrafter.cpp$(DependSuffix): wxcrafter.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/wasg-register-gui/wxcrafter.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/wasg-register-gui/wxcrafter.cpp$(DependSuffix) -MM wxcrafter.cpp

../build-$(ConfigurationName)/wasg-register-gui/wxcrafter.cpp$(PreprocessSuffix): wxcrafter.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/wasg-register-gui/wxcrafter.cpp$(PreprocessSuffix) wxcrafter.cpp

../build-$(ConfigurationName)/wasg-register-gui/MainFrame.cpp$(ObjectSuffix): MainFrame.cpp ../build-$(ConfigurationName)/wasg-register-gui/MainFrame.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/walfin/Dokumentujo/Github/wasg-register-gui/wasg-register-gui/MainFrame.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MainFrame.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/wasg-register-gui/MainFrame.cpp$(DependSuffix): MainFrame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/wasg-register-gui/MainFrame.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/wasg-register-gui/MainFrame.cpp$(DependSuffix) -MM MainFrame.cpp

../build-$(ConfigurationName)/wasg-register-gui/MainFrame.cpp$(PreprocessSuffix): MainFrame.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/wasg-register-gui/MainFrame.cpp$(PreprocessSuffix) MainFrame.cpp

../build-$(ConfigurationName)/wasg-register-gui/main.cpp$(ObjectSuffix): main.cpp ../build-$(ConfigurationName)/wasg-register-gui/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/walfin/Dokumentujo/Github/wasg-register-gui/wasg-register-gui/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/wasg-register-gui/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/wasg-register-gui/main.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/wasg-register-gui/main.cpp$(DependSuffix) -MM main.cpp

../build-$(ConfigurationName)/wasg-register-gui/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/wasg-register-gui/main.cpp$(PreprocessSuffix) main.cpp


-include ../build-$(ConfigurationName)/wasg-register-gui//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


