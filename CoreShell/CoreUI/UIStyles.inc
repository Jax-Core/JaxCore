[UI.String:S]
AntiAlias=1
FontSize=(12*#Set.S#*#Set.FontSizeM#)
FontFace=#Set.FontFace#
FontColor=#Set.Color-T1#

[UI.String.FluentIcon:S]
FontFace=Segoe Fluent Icons
FontSize=(12*#Set.S#*#Set.FontSizeM#)
; --------------------------------- UI.String -------------------------------- ;
AntiAlias=1
FontColor=#Set.Color-T1#

[UI.Shape:S]
Fill=Fill Color [&Func:LocalVar('#CURRENTSECTION#', 'LeaveColor', '#Set.Color-Hitbox#')]
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color [&Func:LocalVar('#CURRENTSECTION#', 'OverColor', '#Set.Color-T1#,50')]"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color [&Func:LocalVar('#CURRENTSECTION#', 'LeaveColor', '#Set.Color-Hitbox#')]"][!UpdateMeter #CURRENTSECTION#][!Redraw]
DynamicVariables=1