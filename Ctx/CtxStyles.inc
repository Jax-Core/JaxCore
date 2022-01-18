
[Ctx.String:S]
FontFace=#Set.Font#
AntiAlias=1
FontSize=(12*[Set.S])
FontColor=#Set.Text_Color#
SolidColor=0,0,0,1

[CtxBox:S]
X=#Ctx.P#
Y=(24/2*#Ctx.S#+#Ctx.P#)r
Shape=Rectangle 0,0,(#Ctx.W#-#Ctx.P#*2),(#Ctx.P#+(24-4)*#Ctx.S#),(#Ctx.R#/2),(#Ctx.R#/2) | StrokeWidth 0 | Extend Fill
DynamicVariables=1
Group=Ctx.SideButtons
Fill=Fill Color #Set.Pri_Color#,0
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Ter_Color#"][!SetOption #CURRENTSECTION#Icon ImageTint "#Set.Accent_Color#"][!SetOption #CURRENTSECTION#Text FontColor "#Set.Accent_Color#"][!UpdateMeter *][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Sec_color#,0"][!SetOption #CURRENTSECTION#Icon ImageTint "#Set.Text_Color#"][!SetOption #CURRENTSECTION#Text FontColor "#Set.Text_Color#"][!UpdateMeter *][!Redraw]

[CtxIcon:S]
ImageName=#@#Icons\Context\#CURRENTSECTION#.png
X=(#Ctx.P#*1.5)
Y=(((#Ctx.P#+(24-4)*#Ctx.S#)/2-24/2*#Ctx.S#))r
W=(19*#Ctx.S#)
H=(19*#Ctx.S#)
Padding=(2.5*#Ctx.S#),(2.5*#Ctx.S#),(2.5*#Ctx.S#),(2.5*#Ctx.S#)
DynamicVariables=1
GreyScale=1
ImageTint=#Set.Text_Color#
Group=Ctx.SideButtons | Ctx.SideIcons

[CtxText:S]
X=(5*#Ctx.S#)R
Y=(24/2*#Ctx.S#)r
StringAlign=LeftCenter
FontColor=#Set.Text_Color#
FontSize=(10*#Ctx.S#)
Group=Ctx.SideButtons

[Ctx.Div:S]
X=#Ctx.P#
Y=(24*#Ctx.S#+#Ctx.P#)r
Shape=Line 0,0,(#Ctx.W#-#Ctx.P#*2),0 | StrokeWidth 1 | Fill Color #Set.Pri_Color#,0 | Stroke Color #Set.Pri_Color#,50