SET installerName="DepthyOffline 160909 (Qt5.7.0 MSVC2015 64bit).exe"
SET installerFramework=QtIFW2.0.3
SET qtBinPath=C:\Qt\Qt5.7.0\5.7\msvc2015_64\bin
SET releaseBinaryPath=C:\Qt\Projects\build-DepthyOffline-Desktop_Qt_5_7_0_MSVC2015_64bit-Release\release
SET installerDataPath=C:\Qt\Projects\DepthyOffline\installer\packages\buttsex.depthyoffline\data
SET binary=DepthyOffline.exe

xcopy /s /y %releaseBinaryPath%\%binary% %installerDataPath%\

:: copying things that windeployqt won't
::xcopy /s /y %qtBinPath%\icudt54.dll %installerDataPath%
::xcopy /s /y %qtBinPath%\icuin54.dll %installerDataPath%
::xcopy /s /y %qtBinPath%\icuuc54.dll %installerDataPath%
xcopy /s /y "C:\Qt\Projects\DepthyOffline\data\_changelog.txt" %installerDataPath%

%qtBinPath%\windeployqt.exe %installerDataPath%\%binary%

cd C:\Qt\projects\DepthyOffline\installer
C:\Qt\%installerFramework%\bin\binarycreator.exe --offline-only^
 -t C:\Qt\%installerFramework%\bin\installerbase.exe -c config\config.xml -p packages %installerName%

pause