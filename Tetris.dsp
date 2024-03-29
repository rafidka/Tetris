# Microsoft Developer Studio Project File - Name="Tetris" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Tetris - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Tetris.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Tetris.mak" CFG="Tetris - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Tetris - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Tetris - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Tetris - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
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

!ELSEIF  "$(CFG)" == "Tetris - Win32 Debug"

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
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib winmm.lib ddraw.lib dinput.lib dxguid.lib vfw32.lib dsound.lib /nologo /subsystem:windows /debug /machine:I386 /out:"Program/Tetris.exe" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Tetris - Win32 Release"
# Name "Tetris - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Main.cpp
# End Source File
# Begin Source File

SOURCE=.\resource.rc
# End Source File
# Begin Source File

SOURCE=.\TFigure.cpp
# End Source File
# Begin Source File

SOURCE=.\TMap.cpp
# End Source File
# Begin Source File

SOURCE=.\TPlayer.cpp
# End Source File
# Begin Source File

SOURCE=.\TWindow.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Group "Game Class Lib Header Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE="..\..\Game Class Lib Ex\Include\BWindow.hpp"
# End Source File
# Begin Source File

SOURCE="..\..\Game Class Lib\include\GActiveObject.hpp"
# End Source File
# Begin Source File

SOURCE="..\..\Game Class Lib\include\GApplication.hpp"
# End Source File
# Begin Source File

SOURCE="..\..\Game Class Lib\include\Gbitmap.hpp"
# End Source File
# Begin Source File

SOURCE="..\..\Game Class Lib Ex\Include\GButton.hpp"
# End Source File
# Begin Source File

SOURCE="..\..\Game Class Lib\include\Gcl.h"
# End Source File
# Begin Source File

SOURCE="..\..\Game Class Lib Ex\Include\GclEx.h"
# End Source File
# Begin Source File

SOURCE="..\..\Game Class Lib\include\GFont.hpp"
# End Source File
# Begin Source File

SOURCE="..\..\Game Class Lib Ex\Include\GFontEx.hpp"
# End Source File
# Begin Source File

SOURCE="..\..\Game Class Lib\include\Ggroup.hpp"
# End Source File
# Begin Source File

SOURCE="..\..\Game Class Lib Ex\Include\GInput.hpp"
# End Source File
# Begin Source File

SOURCE="..\..\Game Class Lib Ex\Include\GMessageBox.hpp"
# End Source File
# Begin Source File

SOURCE="..\..\Game Class Lib\include\GPalette.hpp"
# End Source File
# Begin Source File

SOURCE="..\..\Game Class Lib\include\GPaletteAnimation.hpp"
# End Source File
# Begin Source File

SOURCE="..\..\Game Class Lib\include\Gplane.hpp"
# End Source File
# Begin Source File

SOURCE="..\..\Game Class Lib\include\GSound.hpp"
# End Source File
# Begin Source File

SOURCE="..\..\Game Class Lib\include\Gsprite.hpp"
# End Source File
# Begin Source File

SOURCE="..\..\Game Class Lib\include\GSpriteEx.hpp"
# End Source File
# Begin Source File

SOURCE="..\..\Game Class Lib\include\GString.hpp"
# End Source File
# Begin Source File

SOURCE="..\..\Game Class Lib\include\Gsurface.hpp"
# End Source File
# Begin Source File

SOURCE="..\..\Game Class Lib\include\GText.hpp"
# End Source File
# Begin Source File

SOURCE="..\..\Game Class Lib Ex\Include\GTime.hpp"
# End Source File
# Begin Source File

SOURCE="..\..\Game Class Lib\include\Gview.hpp"
# End Source File
# Begin Source File

SOURCE="..\..\Game Class Lib\include\Gwindow.hpp"
# End Source File
# Begin Source File

SOURCE="..\..\Game Class Lib Ex\Include\Sprite.hpp"
# End Source File
# Begin Source File

SOURCE="..\..\Game Class Lib Ex\Include\Text.hpp"
# End Source File
# Begin Source File

SOURCE="..\..\Game Class Lib Ex\Include\View.hpp"
# End Source File
# End Group
# Begin Source File

SOURCE=.\Main.h
# End Source File
# Begin Source File

SOURCE=.\TFigure.h
# End Source File
# Begin Source File

SOURCE=.\TMap.h
# End Source File
# Begin Source File

SOURCE=.\TPlayer.h
# End Source File
# Begin Source File

SOURCE=.\TWindow.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\Res\cursor1.cur
# End Source File
# Begin Source File

SOURCE=.\Res\icon.ico
# End Source File
# Begin Source File

SOURCE=.\icon1.ico
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\RealGo\Lib\RealGO.lib
# End Source File
# End Target
# End Project
