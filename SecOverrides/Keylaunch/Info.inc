; [mCheckforPresence]
; IfMatchAction=[!SetOption Header Text "#Skin.Name# - Currently in beta"][!SetOption Subheader Text "Join the Discord server to participate in beta tests!"][!ShowMeter DownloadButton][!DisableMouseActionGroup * Set.SideButtons][!SetOptionGroup Set.SideIcons ImageAlpha 100][!UpdateMeter *][!Redraw]
; IfNotMatchAction=[!HideMeter Obj][!HideMeter Obj.Child]

; [DownloadButton]
; Meter=

; [Obj]
; Meter=Shape
; X=(-200*[Set.S]/2)r
; Y=(10*[Set.S])R
; DynamicVariables=1
; Shape=Rectangle 0,0,200,50,(#Set.R#) | StrokeWidth 0 | Scale [Set.S],[Set.S],0,0 | Extend THis
; OverColor=88,101,242
; LeaveColor=88,101,242,200
; Leftmouseupaction=["https://discord.gg/JmgehPSDD6"]
; MeterStyle=Shape.Over:S
; Container=ContentContainer
; [Obj.Child]
; Meter=String
; X=(200/2*[Set.S])r
; y=(25*[Set.S])r
; FontSize=(10*[Set.S])
; FontFace=Poppins 
; StringAlign=CenterCenter
; Text="Join the discord server!"
; Container=ContentContainer
; MeterStyle=SEt.String:S | ButtonT:S