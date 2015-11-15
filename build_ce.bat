echo "SETTING VARIABLES FOR BUILD"
:: Varibables to be set by user
:: SDK
set OSVERSION=WCE600
set PLATFORM=YOUR_SDK
set TARGETCPU=x86
:: Visual Studio
set VSROOT=C:\Program Files (x86)\Microsoft Visual Studio 9.0
:: STLPort (could be deduced form script location)
set STLP=C:\stlport

:: variables that should be not need to be modified 
set SDK_ROOT=C:\Program Files (x86)\Windows CE Tools\%OSVERSION%
set PLATFORM_ROOT=%SDK_ROOT%\%PLATFORM%
set PLATFORM_INC=%PLATFORM_ROOT%\Include
set PLATFORM_LIB=%PLATFORM_ROOT%\Lib

:: Set variables for VS
setlocal
call "%VSROOT%\VC\vcvarsall.bat"

:: modify include and lib directories so the files of the SDK are used
set INCLUDE=%PLATFORM_INC%;%PLATFORM_INC%\%TARGETCPU%;%INCLUDE%
set LIB=%PLATFORM_LIB%;%PLATFORM_LIB%\%TARGETCPU%;%LIB%

echo "RUNNING CONFIGURE"
cd %STLP%
call configure evc9 ^
    --extra-cxxflag /D_STLP_USE_WINCE_CRT_FUNCTIONS ^
    --extra-cxxflag /D_STLP_NO_CSTD_FUNCTION_IMPORTS

echo "RUNNING NMAKE"
cd %STLP%\build\lib
nmake clean install

echo "BUILD FINISHED"
pause

:: create link - you need to be admin
:: mklink /D "%STLP%\%TARGETCPU%" "%PLATFORM_ROOT%\Include\%TARGETCPU%"
