; ---------------------------------------------------------------------------- ;
;                                   Functions                                  ;
; ---------------------------------------------------------------------------- ;

; [DefaultStartActions]
; Custom2=[!UpdateMeterGroup PReload][!SHowMeterGroup V#VersionPage#][!UpdateMeter *][!Redraw]

[Sec.Box:S]
X=(([ContentContainer:W]-120*[Set.S])/10+20*[Set.S])r
Y=(-20*[set.s])r
Shape=Rectangle  0,0,(([ContentContainer:W]-120*[Set.S])/5),(40*[Set.S]),(#set.R#/2) | StrokeWidth 0 | Extend Fill
Fill=Fill Color #Set.Sec_Color#
MouseOverAction=[!SetOption "#CURRENTSECTION#" Fill "Fill Color #Set.Ter_Color#"][!UpdateMeter "#CURRENTSECTION#"][!Redraw]
MouseLeaveAction=[!SetOption "#CURRENTSECTION#" Fill "Fill Color #Set.Sec_Color#"][!UpdateMeter "#CURRENTSECTION#"][!Redraw]
LeftMouseUpAction=[!CommandMeasure Func """interactionBox('Lang', '[&Func:trim('#CURRENTSECTION#', 'Box', '')]')"""]
DynamicVariables=1
Container=ContentContainer
[Sec.BoxText:S]
X=(([ContentContainer:W]-120*[Set.S])/10)r
Y=(20*[set.s])r
StringAlign=CenterCenter
Text="#CURRENTSECTION#"
FontSize=(10*[Set.S])
Container=ContentContainer

[PSRM]
Measure=Plugin
Plugin=PowershellRM
DynamicVariables=1
ScriptFile=#@#Powershell\Translate.ps1

[Log]
Meter=String

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Cat]
Meter=String
Text=Current language: #Set.Lang#
MeterStyle=Set.String:S | Set.OptionCat:S
[Option01]
Meter=String
Text=Here you can choose a language to switch to!
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1388]
Meter=Shape
MeterStyle=Set.Div:S
[Option02]
Meter=String
Text=Common languages
MeterStyle=Set.String:S | Set.OptionCat:S

[DefaultBox]
Meter=Shape
X=r
Y=(20*[Set.S])R
MeterStyle=Sec.Box:S
LeftMouseUpAction=[!CommandMeasure PSRM "SetLangFile -LangFile '#@#LangExports\#JaxCore.json' -Revert 1"]
[Default]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[EnglishBox]
Meter=Shape
MeterStyle=Sec.Box:S
[English]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[Chinese SimplifiedBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Chinese Simplified]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[HindiBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Hindi]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[SpanishBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Spanish]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S

[Set.Div:S13]
Meter=Shape
X=(30*[Set.S])
MeterStyle=Set.Div:S
[Option03]
Meter=String
Text=Other languages
MeterStyle=Set.String:S | Set.OptionCat:S


[AfrikaansBox]
Meter=Shape
X=r
Y=(20*[Set.S])R
MeterStyle=Sec.Box:S
[Afrikaans]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[AlbanianBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Albanian]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[ArabicBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Arabic]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[AzerbaijaniBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Azerbaijani]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[BasqueBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Basque]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S

[BengaliBox]
Meter=Shape
X=(30*[Set.S])
Y=(20*[Set.S])R
MeterStyle=Sec.Box:S
[Bengali]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[BelarusianBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Belarusian]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[BulgarianBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Bulgarian]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[CatalanBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Catalan]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[Chinese TraditionalBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Chinese Traditional]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S

[CroatianBox]
Meter=Shape
X=(30*[Set.S])
Y=(20*[Set.S])R
MeterStyle=Sec.Box:S
[Croatian]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[CzechBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Czech]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[DanishBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Danish]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[DutchBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Dutch]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[EsperantoBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Esperanto]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S

[EstonianBox]
Meter=Shape
X=(30*[Set.S])
Y=(20*[Set.S])R
MeterStyle=Sec.Box:S
[Estonian]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[FilipinoBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Filipino]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[FinnishBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Finnish]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[FrenchBox]
Meter=Shape
MeterStyle=Sec.Box:S
[French]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[GalicianBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Galician]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S

[GeorgianBox]
Meter=Shape
X=(30*[Set.S])
Y=(20*[Set.S])R
MeterStyle=Sec.Box:S
[Georgian]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[GermanBox]
Meter=Shape
MeterStyle=Sec.Box:S
[German]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[GreekBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Greek]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[GujaratiBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Gujarati]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[HaitianBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Haitian]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S

[HebrewBox]
Meter=Shape
X=(30*[Set.S])
Y=(20*[Set.S])R
MeterStyle=Sec.Box:S
[Hebrew]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[HungarianBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Hungarian]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[IcelandicBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Icelandic]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[IndonesianBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Indonesian]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[IrishBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Irish]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S

[ItalianBox]
Meter=Shape
X=(30*[Set.S])
Y=(20*[Set.S])R
MeterStyle=Sec.Box:S
[Italian]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[JapaneseBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Japanese]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[KannadaBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Kannada]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[KoreanBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Korean]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[LatinBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Latin]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S

[LatvianBox]
Meter=Shape
X=(30*[Set.S])
Y=(20*[Set.S])R
MeterStyle=Sec.Box:S
[Latvian]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[LithuanianBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Lithuanian]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[MacedonianBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Macedonian]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[MalayBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Malay]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[MalteseBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Maltese]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S

[NorwegianBox]
Meter=Shape
X=(30*[Set.S])
Y=(20*[Set.S])R
MeterStyle=Sec.Box:S
[Norwegian]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[PersianBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Persian]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[PolishBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Polish]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[PortugueseBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Portuguese]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[RomanianBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Romanian]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S

[RussianBox]
Meter=Shape
X=(30*[Set.S])
Y=(20*[Set.S])R
MeterStyle=Sec.Box:S
[Russian]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[SerbianBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Serbian]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[SlovakBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Slovak]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[SlovenianBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Slovenian]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[SwahiliBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Swahili]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S

[SwedishBox]
Meter=Shape
X=(30*[Set.S])
Y=(20*[Set.S])R
MeterStyle=Sec.Box:S
[Swedish]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[TamilBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Tamil]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[TeluguBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Telugu]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[ThaiBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Thai]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[TurkishBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Turkish]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S

[UkrainianBox]
Meter=Shape
X=(30*[Set.S])
Y=(20*[Set.S])R
MeterStyle=Sec.Box:S
[Ukrainian]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[UrduBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Urdu]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[VietnameseBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Vietnamese]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[WelshBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Welsh]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S
[YiddishBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Yiddish]
Meter=String
MeterStyle=Set.String:S | Sec.BoxText:S


; ---------------------------------------------------------------------------- ;
;                                     Input                                    ;
; ---------------------------------------------------------------------------- ;

; ---------------------------------------------------------------------------- ;
;                                Core overrides                                ;
; ---------------------------------------------------------------------------- ;

[Auto_Refresh:M]
Measure=

[Help:Category]
Y=(#Set.H#-100*[Set.S])

[DivCat:1293s18]
Meter=
[ActiveChecker]
Measure=
[BottomButton]
Meter=
[BottomText]
Meter=