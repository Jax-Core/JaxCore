; ---------------------------------------------------------------------------- ;
;                                   Specials                                   ;
; ---------------------------------------------------------------------------- ;

[MeasureChoose]
Measure=Plugin
Plugin=FileChoose
UseNewStyle=0
;	If set to 1, will use the Common Item Dialog of new type.
; 	Do not set "UseNewStyle = 1" unless your skin is only designed for win10.
GetTarget=0
;	If set to 1, will get the target of the ".lnk" and ".url" file.
AllowNonstorageFolder=1
;	If set to 1, will allow to choose nonstorage folder, such as "My Computer".
; 	"AllowNonstorageFolder = 1" is only effected when "UseNewStyle = 1".
CopyLink=1
;	If set to 1, when fail to get the target of the ".lnk" file,
;	copy the ".lnk" file to LinkCache instead.
;	"CopyLink = 1" is only effected when "GetTarget = 1".
LinkCache=#CurrentPath#LinkCache\
; 	The cache folder path should contain a "\" at the last.
GetIcon=0
;	If set to 1, will get the icon and save it to IconCache as a ".png" file.
IconCache=#CurrentPath#IconCache\
; 	The cache folder path should contain a "\" at the last.
; 	IconCache folder should contain a "folder.png".
IconSize=1
;	3 -- extralarge, 256x256
ReturnValue=WholePath
FileInitialDirectory=
;	The initial folder when choosing file and folder.
ImageInitialDirectory=#CurrentPath#IconCache\
;	The initial folder when choosing images.
Command1=[!WriteKeyvalue Variables ImageName "$Path$" "#Sec.SaveLocation#"][!SetVariable ImageName "$Path$"][!UpdateMeasure MM][!CommandMeasure MM "Reload Image"][!Delay 100][!CommandMeasure mWH "Dimensions"][!Log U]
; 


[MM]
Measure=Plugin
Plugin=MagickMeter
DynamicVariables=1
Image=File #ImageName# | RenderSize (#Img.W#/4),(#Img.H#/4) | Blur #BlurMatrix#
ExportTo=#SKINSPATH##Skin.Name#\@Resources\Export\Blur.png
UpdateDivider=-1
Disabled=1
Group=NUOL | MM

[mWH]
Measure=Plugin
Plugin=PowershellRM
DynamicVariables=1
ScriptFile=#@#Powershell\ImgWH.ps1

[ExportWH]
Measure=Calc
DynamicVariables=1
OnUpdateAction=[!WriteKeyvalue Variables Img.W #IMGW# "#Sec.SaveLocation#"][!WriteKeyvalue Variables Img.H #IMGH# "#Sec.SaveLocation#"][!Delay 1000][!Refresh][!UpdateMeasure Auto_Refresh:M]
Disabled=1
Group=NUOL

; ---------------------------------------------------------------------------- ;
;                                    Options                                   ;
; ---------------------------------------------------------------------------- ;

[Option01]
Meter=String
X=r
Y=(15*#Set.S#)R
FontSize=(10*#Set.S#)
Text=Wallpaper (Used for blurring)
InlinePattern=.*(\[.*\])
InlineSetting=Size | 8
InlinePattern2=.*(\[.*\])
InlineSetting2=Color | 150,150,150
MeterStyle=Set.String:S
Container=ContentContainer
[Option011]
Meter=String
X=r
Y=(15*#Set.S#)R
FontSize=(10*#Set.S#)
Text=Current image: #ImageName#
MeterStyle=Set.String:S
Container=ContentContainer
[Set.Div:S19131238]
Meter=Shape
MeterStyle=Set.Div:S
[Option02]
Meter=String
X=r
Y=(15*#Set.S#)R
FontSize=(10*#Set.S#)
Text=Blur matrix
MeterStyle=Set.String:S
Container=ContentContainer
; ---------------------------------------------------------------------------- ;
;                                 Interactions                                 ;
; ---------------------------------------------------------------------------- ;

[Button01]
Meter=Shape
MeterStyle=Set.Button:S
; OverColor=0,255,10,200
; LeaveColor=0,255,10,100
Y=([Option01:Y]-#Set.P#+(-30/2+8)*#Set.S#)
Act=[!CommandMeasure MeasureChoose "ChooseImage 1"]
[Value01]
Meter=String
Text=Select image...
MeterStyle=Set.String:S | Set.Value:S

[BlurMatrix]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option02:Y]-#Set.P#+(-30/2+8)*#Set.S#)
[Value02]
Meter=String
Text=#BlurMatrix#
MeterStyle=Set.String:S | Set.Value:S