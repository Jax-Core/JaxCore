[StartActions]
Measure=calc
OnUpdateAction=[!CommandMeasure mParseTimer "Execute 1"]

[Variables]
Parse=1

[mParseTimer]
Measure=Plugin
Plugin=ActionTimer
ActionList1=Wait 100 | StartBuffer | Repeat Enable,500,7 | Wait 1000 | Done
; ActionList1=Wait 100 | StartBuffer
StartBuffer=[!CommandMeasure Buffer "start()"]
Enable=[!EnableMeasure "Image000[#Parse]"][!SetVariable Parse (#Parse#+1)][!UpdateMeasureGroup Parsers][!Log "Parsed #Parse#"]
DynamicVariables=1
Group=Parsers
Done=[!Log "Finished parsing items."][!UpdateMeterGroup ParsedDisplay][!Redraw][!CommandMeasure Buffer "stop()"][!EnableMeasure CheckIfFailed][!UpdateMeasure CheckIfFailed]

[Buffer]
Measure=Script
ScriptFile=#@#Lua\WebParseBuffer.lua

[CheckIfFailed]
Measure=String
String=[Image0001] [Image0007]
ifmatch=^\s*$
IfMatchAction=[!ShowMeterGroup Connecterror][!Redraw]
Disabled=1
IfMatchMode=1
DynamicVariables=1

; ---------------------------------- Parser ---------------------------------- ;

[Image0001]
Measure=WebParser
URL=https://raw.githubusercontent.com/EnhancedJax/-JaxCore/mClocks3/.DeveloperResources/WebResources/Clocks/Page1/[#CURRENTSECTION].png
Download=1
Group=Parsers
;DownloadFile=Image[#CURRENTSECTION].png
Disabled=1

[Image0002]
Measure=WebParser
URL=https://raw.githubusercontent.com/EnhancedJax/-JaxCore/mClocks3/.DeveloperResources/WebResources/Clocks/Page1/[#CURRENTSECTION].png
Download=1
Group=Parsers
;DownloadFile=Image[#CURRENTSECTION].png
Disabled=1

[Image0003]
Measure=WebParser
URL=https://raw.githubusercontent.com/EnhancedJax/-JaxCore/mClocks3/.DeveloperResources/WebResources/Clocks/Page1/[#CURRENTSECTION].png
Download=1
Group=Parsers
;DownloadFile=Image[#CURRENTSECTION].png
Disabled=1

[Image0004]
Measure=WebParser
URL=https://raw.githubusercontent.com/EnhancedJax/-JaxCore/mClocks3/.DeveloperResources/WebResources/Clocks/Page1/[#CURRENTSECTION].png
Download=1
Group=Parsers
;DownloadFile=Image[#CURRENTSECTION].png
Disabled=1

[Image0005]
Measure=WebParser
URL=https://raw.githubusercontent.com/EnhancedJax/-JaxCore/mClocks3/.DeveloperResources/WebResources/Clocks/Page1/[#CURRENTSECTION].png
Download=1
Group=Parsers
;DownloadFile=Image[#CURRENTSECTION].png
Disabled=1

[Image0006]
Measure=WebParser
URL=https://raw.githubusercontent.com/EnhancedJax/-JaxCore/mClocks3/.DeveloperResources/WebResources/Clocks/Page1/[#CURRENTSECTION].png
Download=1
Group=Parsers
;DownloadFile=Image[#CURRENTSECTION].png
Disabled=1

[Image0007]
Measure=WebParser
URL=https://raw.githubusercontent.com/EnhancedJax/-JaxCore/mClocks3/.DeveloperResources/WebResources/Clocks/Page1/[#CURRENTSECTION].png
Download=1
Group=Parsers
;DownloadFile=Image[#CURRENTSECTION].png
Disabled=1

[Image0008]
Measure=WebParser
URL=https://raw.githubusercontent.com/EnhancedJax/-JaxCore/mClocks3/.DeveloperResources/WebResources/Clocks/Page1/[#CURRENTSECTION].png
Download=1
Group=Parsers
;DownloadFile=Image[#CURRENTSECTION].png
Disabled=1

[Image0009]
Measure=WebParser
URL=https://raw.githubusercontent.com/EnhancedJax/-JaxCore/mClocks3/.DeveloperResources/WebResources/Clocks/Page1/[#CURRENTSECTION].png
Download=1
Group=Parsers
;DownloadFile=Image[#CURRENTSECTION].png
Disabled=1

[Image00010]
Measure=WebParser
URL=https://raw.githubusercontent.com/EnhancedJax/-JaxCore/mClocks3/.DeveloperResources/WebResources/Clocks/Page1/[#CURRENTSECTION].png
Download=1
Group=Parsers
;DownloadFile=Image[#CURRENTSECTION].png
Disabled=1

[Image00011]
Measure=WebParser
URL=https://raw.githubusercontent.com/EnhancedJax/-JaxCore/mClocks3/.DeveloperResources/WebResources/Clocks/Page1/[#CURRENTSECTION].png
Download=1
Group=Parsers
;DownloadFile=Image[#CURRENTSECTION].png
Disabled=1

[Image00012]
Measure=WebParser
URL=https://raw.githubusercontent.com/EnhancedJax/-JaxCore/mClocks3/.DeveloperResources/WebResources/Clocks/Page1/[#CURRENTSECTION].png
Download=1
Group=Parsers
;DownloadFile=Image[#CURRENTSECTION].png
Disabled=1

[Image00013]
Measure=WebParser
URL=https://raw.githubusercontent.com/EnhancedJax/-JaxCore/mClocks3/.DeveloperResources/WebResources/Clocks/Page1/[#CURRENTSECTION].png
Download=1
Group=Parsers
;DownloadFile=Image[#CURRENTSECTION].png
Disabled=1

[Image00014]
Measure=WebParser
URL=https://raw.githubusercontent.com/EnhancedJax/-JaxCore/mClocks3/.DeveloperResources/WebResources/Clocks/Page1/[#CURRENTSECTION].png
Download=1
Group=Parsers
;DownloadFile=Image[#CURRENTSECTION].png
Disabled=1

[Image00015]
Measure=WebParser
URL=https://raw.githubusercontent.com/EnhancedJax/-JaxCore/mClocks3/.DeveloperResources/WebResources/Clocks/Page1/[#CURRENTSECTION].png
Download=1
Group=Parsers
;DownloadFile=Image[#CURRENTSECTION].png
Disabled=1

[Image00016]
Measure=WebParser
URL=https://raw.githubusercontent.com/EnhancedJax/-JaxCore/mClocks3/.DeveloperResources/WebResources/Clocks/Page1/[#CURRENTSECTION].png
Download=1
Group=Parsers
;DownloadFile=Image[#CURRENTSECTION].png
Disabled=1

[Image00017]
Measure=WebParser
URL=https://raw.githubusercontent.com/EnhancedJax/-JaxCore/mClocks3/.DeveloperResources/WebResources/Clocks/Page1/[#CURRENTSECTION].png
Download=1
Group=Parsers
;DownloadFile=Image[#CURRENTSECTION].png
Disabled=1

[Image00018]
Measure=WebParser
URL=https://raw.githubusercontent.com/EnhancedJax/-JaxCore/mClocks3/.DeveloperResources/WebResources/Clocks/Page1/[#CURRENTSECTION].png
Download=1
Group=Parsers
;DownloadFile=Image[#CURRENTSECTION].png
Disabled=1

[Image00019]
Measure=WebParser
URL=https://raw.githubusercontent.com/EnhancedJax/-JaxCore/mClocks3/.DeveloperResources/WebResources/Clocks/Page1/[#CURRENTSECTION].png
Download=1
Group=Parsers
;DownloadFile=Image[#CURRENTSECTION].png
Disabled=1