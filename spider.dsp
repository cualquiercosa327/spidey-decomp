# Microsoft Developer Studio Project File - Name="spider" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=spider - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "spider.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "spider.mak" CFG="spider - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "spider - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "spider - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "spider - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /Op /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "spider - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "spider - Win32 Release"
# Name "spider - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\baddy.cpp
# End Source File
# Begin Source File

SOURCE=.\bit.cpp
# End Source File
# Begin Source File

SOURCE=.\bit2.cpp
# End Source File
# Begin Source File

SOURCE=.\blackcat.cpp
# End Source File
# Begin Source File

SOURCE=.\camera.cpp
# End Source File
# Begin Source File

SOURCE=.\carnage.cpp
# End Source File
# Begin Source File

SOURCE=.\chopper.cpp
# End Source File
# Begin Source File

SOURCE=.\cop.cpp
# End Source File
# Begin Source File

SOURCE=.\docock.cpp
# End Source File
# Begin Source File

SOURCE=.\exp.cpp
# End Source File
# Begin Source File

SOURCE=.\friction.cpp
# End Source File
# Begin Source File

SOURCE=.\front.cpp
# End Source File
# Begin Source File

SOURCE=.\hostage.cpp
# End Source File
# Begin Source File

SOURCE=.\jonah.cpp
# End Source File
# Begin Source File

SOURCE=.\lizard.cpp
# End Source File
# Begin Source File

SOURCE=.\lizman.cpp
# End Source File
# Begin Source File

SOURCE=.\m3d.cpp
# End Source File
# Begin Source File

SOURCE=.\m3dcolij.cpp
# End Source File
# Begin Source File

SOURCE=.\m3dinit.cpp
# End Source File
# Begin Source File

SOURCE=.\m3dutils.cpp
# End Source File
# Begin Source File

SOURCE=.\m3dzone.cpp
# End Source File
# Begin Source File

SOURCE=.\main.cpp
# End Source File
# Begin Source File

SOURCE=.\mem.cpp
# End Source File
# Begin Source File

SOURCE=.\mj.cpp
# End Source File
# Begin Source File

SOURCE=.\mysterio.cpp
# End Source File
# Begin Source File

SOURCE=.\ob.cpp
# End Source File
# Begin Source File

SOURCE=.\platform.cpp
# End Source File
# Begin Source File

SOURCE=.\ps2funcs.cpp
# End Source File
# Begin Source File

SOURCE=.\ps2m3d.cpp
# End Source File
# Begin Source File

SOURCE=.\ps2redbook.cpp
# End Source File
# Begin Source File

SOURCE=.\pshell.cpp
# End Source File
# Begin Source File

SOURCE=.\quat.cpp
# End Source File
# Begin Source File

SOURCE=.\rhino.cpp
# End Source File
# Begin Source File

SOURCE=.\scorpion.cpp
# End Source File
# Begin Source File

SOURCE=.\shell.cpp
# End Source File
# Begin Source File

SOURCE=.\simby.cpp
# End Source File
# Begin Source File

SOURCE=.\spclone.cpp
# End Source File
# Begin Source File

SOURCE=.\spool.cpp
# End Source File
# Begin Source File

SOURCE=.\submarin.cpp
# End Source File
# Begin Source File

SOURCE=.\superock.cpp
# End Source File
# Begin Source File

SOURCE=.\thug.cpp
# End Source File
# Begin Source File

SOURCE=.\torch.cpp
# End Source File
# Begin Source File

SOURCE=.\turret.cpp
# End Source File
# Begin Source File

SOURCE=.\utils.cpp
# End Source File
# Begin Source File

SOURCE=.\validate.cpp
# End Source File
# Begin Source File

SOURCE=.\vector.cpp
# End Source File
# Begin Source File

SOURCE=.\venom.cpp
# End Source File
# Begin Source File

SOURCE=.\web.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\baddy.h
# End Source File
# Begin Source File

SOURCE=.\bit.h
# End Source File
# Begin Source File

SOURCE=.\bit2.h
# End Source File
# Begin Source File

SOURCE=.\blackcat.h
# End Source File
# Begin Source File

SOURCE=.\camera.h
# End Source File
# Begin Source File

SOURCE=.\carnage.h
# End Source File
# Begin Source File

SOURCE=.\chopper.h
# End Source File
# Begin Source File

SOURCE=.\cop.h
# End Source File
# Begin Source File

SOURCE=.\docock.h
# End Source File
# Begin Source File

SOURCE=.\exp.h
# End Source File
# Begin Source File

SOURCE=.\export.h
# End Source File
# Begin Source File

SOURCE=.\friction.h
# End Source File
# Begin Source File

SOURCE=.\front.h
# End Source File
# Begin Source File

SOURCE=.\hostage.h
# End Source File
# Begin Source File

SOURCE=.\jonah.h
# End Source File
# Begin Source File

SOURCE=.\lizard.h
# End Source File
# Begin Source File

SOURCE=.\lizman.h
# End Source File
# Begin Source File

SOURCE=.\m3d.h
# End Source File
# Begin Source File

SOURCE=.\m3dcolij.h
# End Source File
# Begin Source File

SOURCE=.\m3dinit.h
# End Source File
# Begin Source File

SOURCE=.\m3dutils.h
# End Source File
# Begin Source File

SOURCE=.\m3dzone.h
# End Source File
# Begin Source File

SOURCE=.\mem.h
# End Source File
# Begin Source File

SOURCE=.\mj.h
# End Source File
# Begin Source File

SOURCE=.\mysterio.h
# End Source File
# Begin Source File

SOURCE=.\ob.h
# End Source File
# Begin Source File

SOURCE=.\platform.h
# End Source File
# Begin Source File

SOURCE=.\ps2funcs.h
# End Source File
# Begin Source File

SOURCE=.\ps2m3d.h
# End Source File
# Begin Source File

SOURCE=.\ps2redbook.h
# End Source File
# Begin Source File

SOURCE=.\pshell.h
# End Source File
# Begin Source File

SOURCE=.\quat.h
# End Source File
# Begin Source File

SOURCE=.\rhino.h
# End Source File
# Begin Source File

SOURCE=.\scorpion.h
# End Source File
# Begin Source File

SOURCE=.\shell.h
# End Source File
# Begin Source File

SOURCE=.\simby.h
# End Source File
# Begin Source File

SOURCE=.\spclone.h
# End Source File
# Begin Source File

SOURCE=.\spool.h
# End Source File
# Begin Source File

SOURCE=.\submarin.h
# End Source File
# Begin Source File

SOURCE=.\superock.h
# End Source File
# Begin Source File

SOURCE=.\thug.h
# End Source File
# Begin Source File

SOURCE=.\torch.h
# End Source File
# Begin Source File

SOURCE=.\turret.h
# End Source File
# Begin Source File

SOURCE=.\utils.h
# End Source File
# Begin Source File

SOURCE=.\validate.h
# End Source File
# Begin Source File

SOURCE=.\vector.h
# End Source File
# Begin Source File

SOURCE=.\venom.h
# End Source File
# Begin Source File

SOURCE=.\web.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
