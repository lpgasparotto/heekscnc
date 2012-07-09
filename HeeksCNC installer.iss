; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{FE583F3D-8863-438B-AD81-790FD54A7113}
AppName=HeeksCNC
AppVerName=HeeksCNC 0.22.0
AppPublisher=Heeks Software
AppPublisherURL=http://heeks.net/
AppSupportURL=http://code.google.com/p/heekscnc/
AppUpdatesURL=http://code.google.com/p/heekscnc/
DefaultDirName={pf}\HeeksCNC
DefaultGroupName=HeeksCNC
DisableProgramGroupPage=yes
OutputBaseFilename=HeeksCNC 0.22.0
Compression=lzma
SolidCompression=yes

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"
Name: de; MessagesFile: "compiler:Languages\German.isl"
Name: fr; MessagesFile: "compiler:Languages\French.isl"
Name: it; MessagesFile: "compiler:Languages\Italian.isl"

[Files]
Source: "C:\Dev\HeeksCADSVN\HeeksCAD.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Dev\HeeksCADSVN\bitmaps\*.png"; DestDir: "{app}\bitmaps"; Flags: ignoreversion
Source: "C:\Dev\HeeksCADSVN\bitmaps\angle\*.png"; DestDir: "{app}\bitmaps\angle"; Flags: ignoreversion
Source: "C:\Dev\HeeksCADSVN\bitmaps\font.glf"; DestDir: "{app}\bitmaps"; Flags: ignoreversion
Source: "C:\Dev\HeeksCADSVN\icons\*.png"; DestDir: "{app}\icons"; Flags: ignoreversion
Source: "C:\Dev\OCC dlls for HeeksCAD\*"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Dev\HeeksCADSVN\de\*"; DestDir: "{app}\de"; Flags: ignoreversion
Source: "C:\Dev\HeeksCADSVN\it\*"; DestDir: "{app}\it"; Flags: ignoreversion
Source: "C:\Dev\HeeksCADSVN\fr\*"; DestDir: "{app}\fr"; Flags: ignoreversion
Source: "C:\Dev\HeeksCADSVN\sk\*"; DestDir: "{app}\sk"; Flags: ignoreversion
Source: "C:\Dev\HeeksCADSVN\wxmsw28u_gl_vc_custom.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Dev\HeeksCADSVN\wxmsw28u_core_vc_custom.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Dev\HeeksCADSVN\wxmsw28u_aui_vc_custom.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Dev\HeeksCADSVN\wxbase28u_vc_custom.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Dev\HeeksCNCSVN\post for installer.bat"; DestDir: "{app}\HeeksCNC"; DestName: "post.bat"; Flags: ignoreversion
Source: "C:\Dev\HeeksCNCSVN\nc_read for installer.bat"; DestDir: "{app}\HeeksCNC"; DestName: "nc_read.bat"; Flags: ignoreversion
Source: "C:\Dev\HeeksCNCSVN\backplot.py"; DestDir: "{app}\HeeksCNC"; Flags: ignoreversion
Source: "C:\Dev\HeeksCNCSVN\area_funcs.py"; DestDir: "{app}\HeeksCNC"; Flags: ignoreversion
Source: "C:\Dev\libarea\Release\area.pyd"; DestDir: "{app}\HeeksCNC\Boolean"; Flags: ignoreversion
Source: "C:\Dev\HeeksCNCSVN\subdir.manifest"; DestDir: "{app}\HeeksCNC\Boolean"; DestName: "Microsoft.VC90.CRT.manifest"; Flags: ignoreversion
Source: "C:\Dev\HeeksCNCSVN\kurve_funcs.py"; DestDir: "{app}\HeeksCNC"; Flags: ignoreversion
Source: "C:\Dev\HeeksCNCSVN\area_funcs.py"; DestDir: "{app}\HeeksCNC"; Flags: ignoreversion
Source: "C:\Dev\libarea\ClipperRelease\area.pyd"; DestDir: "{app}\HeeksCNC\Clipper"; Flags: ignoreversion
Source: "C:\Dev\HeeksCNCSVN\subdir.manifest"; DestDir: "{app}\HeeksCNC\Clipper"; DestName: "Microsoft.VC90.CRT.manifest"; Flags: ignoreversion
Source: "C:\Dev\HeeksCNCSVN\ocl_funcs.py"; DestDir: "{app}\HeeksCNC"; Flags: ignoreversion
Source: "C:\Dev\HeeksCNCSVN\ocl.pyd"; DestDir: "{app}\HeeksCNC"; Flags: ignoreversion
Source: "C:\Dev\HeeksCNCSVN\*.speeds"; DestDir: "{app}\HeeksCNC"; Flags: ignoreversion
Source: "C:\Dev\HeeksCNCSVN\*.tooltable"; DestDir: "{app}\HeeksCNC"; Flags: ignoreversion
Source: "C:\Dev\HeeksCNCSVN\nc\*.py"; DestDir: "{app}\HeeksCNC\nc"; Flags: ignoreversion
Source: "C:\Dev\HeeksCNCSVN\nc\*.txt"; DestDir: "{app}\HeeksCNC\nc"; Flags: ignoreversion
Source: "C:\Dev\HeeksCNCSVN\src\Unicode Release\HeeksCNC.dll"; DestDir: "{app}\HeeksCNC"; Flags: ignoreversion
Source: "C:\Dev\HeeksCNCSVN\bitmaps\*.png"; DestDir: "{app}\HeeksCNC\bitmaps"; Flags: ignoreversion
Source: "C:\Dev\HeeksCNCSVN\bitmaps\pocket\*.png"; DestDir: "{app}\HeeksCNC\bitmaps\pocket"; Flags: ignoreversion
Source: "C:\Dev\HeeksCNCSVN\icons\*.png"; DestDir: "{app}\HeeksCNC\icons"; Flags: ignoreversion
Source: "C:\Program Files (x86)\Microsoft Visual Studio 9.0\VC\redist\x86\Microsoft.VC90.CRT\*"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Program Files (x86)\Microsoft Visual Studio 8\VC\redist\x86\Microsoft.VC80.CRT\*"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Program Files (x86)\Microsoft Visual Studio 9.0\VC\redist\x86\Microsoft.VC90.CRT\*"; DestDir: "{app}\HeeksCNC"; Flags: ignoreversion
Source: "C:\Dev\HeeksCNCSVN\dist\*"; DestDir: "{app}\HeeksCNC"; Flags: ignoreversion
Source: "C:\python26\python.exe"; DestDir: "{app}\HeeksCNC"; Flags: ignoreversion
; copy all the voxelcut files into the same place as HeeksCNC, to re-use some of the files
Source: "C:\Dev\voxelcut\voxelcut.bat"; DestDir: "{app}\HeeksCNC"; Flags: ignoreversion
Source: "C:\Dev\voxelcut\area.pyd"; DestDir: "{app}\HeeksCNC"; Flags: ignoreversion
Source: "C:\Dev\voxelcut\voxelcut.pyd"; DestDir: "{app}\HeeksCNC"; Flags: ignoreversion
Source: "C:\Dev\voxelcut\*.py"; DestDir: "{app}\HeeksCNC"; Flags: ignoreversion
Source: "C:\Dev\voxelcut\bitmaps\*.png"; DestDir: "{app}\HeeksCNC\bitmaps"; Flags: ignoreversion
Source: "C:\Program Files (x86)\VoxelCut\wx.*.pyd"; DestDir: "{app}\HeeksCNC"; Flags: ignoreversion
Source: "C:\Program Files (x86)\VoxelCut\wx*.dll"; DestDir: "{app}\HeeksCNC"; Flags: ignoreversion
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{group}\HeeksCNC"; Filename: "{app}\HeeksCAD.exe"; WorkingDir: "{app}"; Parameters: "HeeksCNC/HeeksCNC.dll"

[Run]
Filename: "{app}\HeeksCAD.exe"; WorkingDir: "{app}"; Parameters: "HeeksCNC/HeeksCNC.dll"; Description: "{cm:LaunchProgram,HeeksCNC}"; Flags: nowait postinstall skipifsilent

[Registry]
Root: HKCU; Subkey: "Software\HeeksCAD"; Flags: uninsdeletekeyifempty
Root: HKCU; Subkey: "Software\HeeksCNC"; Flags: uninsdeletekeyifempty


