##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=CodeForLectures
ConfigurationName      :=Debug
WorkspacePath          :=/Users/Ben/Dropbox/UniversityOfCambridgeDrive/Cambridge/IB/FirstTerm/ProgrammingInC/coding/Cexamples
ProjectPath            :=/Users/Ben/Dropbox/UniversityOfCambridgeDrive/Cambridge/IB/FirstTerm/ProgrammingInC/coding/Cexamples/CodeForLectures
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Ben Philps
Date                   :=21/08/2018
CodeLitePath           :="/Users/Ben/Library/Application Support/CodeLite"
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -dynamiclib -fPIC
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
ObjectsFileList        :="CodeForLectures.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
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
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/Applications/codelite.app/Contents/SharedSupport/
Objects0=$(IntermediateDirectory)/Lecture6.c$(ObjectSuffix) $(IntermediateDirectory)/Lecture5.c$(ObjectSuffix) $(IntermediateDirectory)/Lecture1.c$(ObjectSuffix) $(IntermediateDirectory)/Lecture3.c$(ObjectSuffix) $(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/Lecture2.c$(ObjectSuffix) $(IntermediateDirectory)/example4code.c$(ObjectSuffix) $(IntermediateDirectory)/Lecture4.c$(ObjectSuffix) 



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
$(IntermediateDirectory)/Lecture6.c$(ObjectSuffix): Lecture6.c $(IntermediateDirectory)/Lecture6.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/Ben/Dropbox/UniversityOfCambridgeDrive/Cambridge/IB/FirstTerm/ProgrammingInC/coding/Cexamples/CodeForLectures/Lecture6.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Lecture6.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Lecture6.c$(DependSuffix): Lecture6.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Lecture6.c$(ObjectSuffix) -MF$(IntermediateDirectory)/Lecture6.c$(DependSuffix) -MM Lecture6.c

$(IntermediateDirectory)/Lecture6.c$(PreprocessSuffix): Lecture6.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Lecture6.c$(PreprocessSuffix) Lecture6.c

$(IntermediateDirectory)/Lecture5.c$(ObjectSuffix): Lecture5.c $(IntermediateDirectory)/Lecture5.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/Ben/Dropbox/UniversityOfCambridgeDrive/Cambridge/IB/FirstTerm/ProgrammingInC/coding/Cexamples/CodeForLectures/Lecture5.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Lecture5.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Lecture5.c$(DependSuffix): Lecture5.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Lecture5.c$(ObjectSuffix) -MF$(IntermediateDirectory)/Lecture5.c$(DependSuffix) -MM Lecture5.c

$(IntermediateDirectory)/Lecture5.c$(PreprocessSuffix): Lecture5.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Lecture5.c$(PreprocessSuffix) Lecture5.c

$(IntermediateDirectory)/Lecture1.c$(ObjectSuffix): Lecture1.c $(IntermediateDirectory)/Lecture1.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/Ben/Dropbox/UniversityOfCambridgeDrive/Cambridge/IB/FirstTerm/ProgrammingInC/coding/Cexamples/CodeForLectures/Lecture1.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Lecture1.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Lecture1.c$(DependSuffix): Lecture1.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Lecture1.c$(ObjectSuffix) -MF$(IntermediateDirectory)/Lecture1.c$(DependSuffix) -MM Lecture1.c

$(IntermediateDirectory)/Lecture1.c$(PreprocessSuffix): Lecture1.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Lecture1.c$(PreprocessSuffix) Lecture1.c

$(IntermediateDirectory)/Lecture3.c$(ObjectSuffix): Lecture3.c $(IntermediateDirectory)/Lecture3.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/Ben/Dropbox/UniversityOfCambridgeDrive/Cambridge/IB/FirstTerm/ProgrammingInC/coding/Cexamples/CodeForLectures/Lecture3.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Lecture3.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Lecture3.c$(DependSuffix): Lecture3.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Lecture3.c$(ObjectSuffix) -MF$(IntermediateDirectory)/Lecture3.c$(DependSuffix) -MM Lecture3.c

$(IntermediateDirectory)/Lecture3.c$(PreprocessSuffix): Lecture3.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Lecture3.c$(PreprocessSuffix) Lecture3.c

$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c $(IntermediateDirectory)/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/Ben/Dropbox/UniversityOfCambridgeDrive/Cambridge/IB/FirstTerm/ProgrammingInC/coding/Cexamples/CodeForLectures/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM main.c

$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) main.c

$(IntermediateDirectory)/Lecture2.c$(ObjectSuffix): Lecture2.c $(IntermediateDirectory)/Lecture2.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/Ben/Dropbox/UniversityOfCambridgeDrive/Cambridge/IB/FirstTerm/ProgrammingInC/coding/Cexamples/CodeForLectures/Lecture2.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Lecture2.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Lecture2.c$(DependSuffix): Lecture2.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Lecture2.c$(ObjectSuffix) -MF$(IntermediateDirectory)/Lecture2.c$(DependSuffix) -MM Lecture2.c

$(IntermediateDirectory)/Lecture2.c$(PreprocessSuffix): Lecture2.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Lecture2.c$(PreprocessSuffix) Lecture2.c

$(IntermediateDirectory)/example4code.c$(ObjectSuffix): example4code.c $(IntermediateDirectory)/example4code.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/Ben/Dropbox/UniversityOfCambridgeDrive/Cambridge/IB/FirstTerm/ProgrammingInC/coding/Cexamples/CodeForLectures/example4code.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/example4code.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/example4code.c$(DependSuffix): example4code.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/example4code.c$(ObjectSuffix) -MF$(IntermediateDirectory)/example4code.c$(DependSuffix) -MM example4code.c

$(IntermediateDirectory)/example4code.c$(PreprocessSuffix): example4code.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/example4code.c$(PreprocessSuffix) example4code.c

$(IntermediateDirectory)/Lecture4.c$(ObjectSuffix): Lecture4.c $(IntermediateDirectory)/Lecture4.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/Ben/Dropbox/UniversityOfCambridgeDrive/Cambridge/IB/FirstTerm/ProgrammingInC/coding/Cexamples/CodeForLectures/Lecture4.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Lecture4.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Lecture4.c$(DependSuffix): Lecture4.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Lecture4.c$(ObjectSuffix) -MF$(IntermediateDirectory)/Lecture4.c$(DependSuffix) -MM Lecture4.c

$(IntermediateDirectory)/Lecture4.c$(PreprocessSuffix): Lecture4.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Lecture4.c$(PreprocessSuffix) Lecture4.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


